// BuilderLib.h

#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include <iostream>
#include <memory>

using namespace std;

namespace Builder
{

// "Product"
class Pizza
{
  public:
    void setDough(const string &dough);
    void setSauce(const string &sauce);
    void setTopping(const string &topping);
    void open() const;

  private:
    string m_dough;
    string m_sauce;
    string m_topping;
};

// "Abstract Builder"
class PizzaBuilder
{
  public:
    virtual ~PizzaBuilder(){};

    Pizza *getPizza() { return m_pizza.get(); }
    void createNewPizzaProduct();
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;

  protected:
    // std::unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.
    unique_ptr<Pizza> m_pizza;
};

//----------------------------------------------------------------
// similar to Interface C#
class HawaiianPizzaBuilder : public PizzaBuilder
{
  public:
    virtual ~HawaiianPizzaBuilder(){};

    virtual void buildDough();
    virtual void buildSauce();
    virtual void buildTopping();
};

class SpicyPizzaBuilder : public PizzaBuilder
{
  public:
    virtual ~SpicyPizzaBuilder(){};

    virtual void buildDough();
    virtual void buildSauce();
    virtual void buildTopping();
};

class Cook
{
  public:
    void openPizza();
    // PizzBuilder: single responsibility, liscov substitution. realized by pure virutal funs in base class vs Interface in C#
    void makePizza(PizzaBuilder *pb);

  private:
    PizzaBuilder *m_pizzaBuilder;
};
}

#endif