// FactoryLib.h

#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include <iostream>

using namespace std;

namespace factory
{
class Computer
{
public:
  virtual void Run() = 0;
  virtual void Stop() = 0;
  void GetDescription() const { cout << description; };

  virtual ~Computer(){}; /* without this, you do not call Laptop or Desktop destructor in this example! */
  Computer(const string desc) { description = desc; }
private:
  string description;
};

class Laptop : public Computer
{
public:
  void Run() override { mHibernating = false; };
  void Stop() override { mHibernating = true; };
  virtual ~Laptop(){}; /* because we have virtual functions, we need virtual destructor */
  Laptop(const string desc) : Computer(desc){};

private:
  bool mHibernating; // Whether or not the machine is hibernating
};

class Desktop : public Computer
{
public:
  void Run() override { mOn = true; };
  void Stop() override { mOn = false; };
  virtual ~Desktop(){};
  Desktop(const string desc) : Computer(desc){};

private:
  bool mOn; // Whether or not the machine has been turned on
};

class ComputerFactory
{
public:
  enum ComputerType
  {
    LaptopComputer,
    DesktopComputer
  };
  static Computer *NewComputer(const ComputerType &computerType);
};
}

#endif