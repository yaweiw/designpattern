#include "builder.h"

using namespace std;

namespace Builder
{

void Pizza::setDough(const string &dough)
{
    m_dough = dough;
}
void Pizza::setSauce(const string &sauce)
{
    m_sauce = sauce;
}
void Pizza::setTopping(const string &topping)
{
    m_topping = topping;
}
void Pizza::open() const
{
    cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
         << m_topping << " topping. Mmm." << endl;
}

void PizzaBuilder::createNewPizzaProduct()
{
    // Constructs an object of type T and wraps it in a std::unique_ptr.
    m_pizza = make_unique<Pizza>();
}

void HawaiianPizzaBuilder::buildDough()
{
    m_pizza->setDough("cross");
}
void HawaiianPizzaBuilder::buildSauce()
{
    m_pizza->setSauce("mild");
}
void HawaiianPizzaBuilder::buildTopping()
{
    m_pizza->setTopping("ham+pineapple");
}

void SpicyPizzaBuilder::buildDough()
{
    m_pizza->setDough("pan baked");
}

void SpicyPizzaBuilder::buildSauce()
{
    m_pizza->setSauce("hot");
}

void SpicyPizzaBuilder::buildTopping()
{
    m_pizza->setTopping("pepperoni+salami");
}

//----------------------------------------------------------------
void Cook::openPizza()
{
    m_pizzaBuilder->getPizza()->open();
}
// PizzBuilder: single responsibility, liscov substitution. realized by pure virutal funs in base class vs Interface in C#
void Cook::makePizza(PizzaBuilder *pb)
{
    m_pizzaBuilder = pb;
    m_pizzaBuilder->createNewPizzaProduct();
    m_pizzaBuilder->buildDough();
    m_pizzaBuilder->buildSauce();
    m_pizzaBuilder->buildTopping();
}

}
