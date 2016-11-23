#ifndef CREATIONAL_H
#define CREATIONAL_H

#include <string>
#include <iostream>
#include <memory>

// "Product"
class Pizza
{
public:
	void setDough(const string& dough);
	void setSauce(const string& sauce);
	void setTopping(const string& topping);
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
	Pizza* getPizza();
	void createNewPizzaProduct();
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
protected:
	unique_ptr<Pizza> m_pizza;
};


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
	void makePizza(PizzaBuilder* pb);
private:
	PizzaBuilder* m_pizzaBuilder;
};

#endif