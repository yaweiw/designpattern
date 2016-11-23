#include "creational.h"

using namespace std;

// "Product"
    void Pizza::setDough(const string& dough)
    {
        m_dough = dough;
    }
    void Pizza::setSauce(const string& sauce)
    {
        m_sauce = sauce;
    }
    void Pizza::setTopping(const string& topping)
    {
        m_topping = topping;
    }
    void Pizza::open() const
    {
        cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
            << m_topping << " topping. Mmm." << endl;
    }

// "Abstract Builder"
    Pizza* PizzaBuilder::getPizza()
    {
        return m_pizza.get();
    }
    void PizzaBuilder::createNewPizzaProduct()
    {
        m_pizza = make_unique<Pizza>();
    }

//----------------------------------------------------------------

    virtual void HawaiianPizzaBuilder::buildDough()
    {
        m_pizza->setDough("cross");
    }
    virtual void HawaiianPizzaBuilder::buildSauce()
    {
        m_pizza->setSauce("mild");
    }
    virtual void HawaiianPizzaBuilder::buildTopping()
    {
        m_pizza->setTopping("ham+pineapple");
    }

    virtual void SpicyPizzaBuilder::buildDough()
    {
        m_pizza->setDough("pan baked");
    }
    virtual void SpicyPizzaBuilder::buildSauce()
    {
        m_pizza->setSauce("hot");
    }
    virtual void SpicyPizzaBuilder::buildTopping()
    {
        m_pizza->setTopping("pepperoni+salami");
    }

//----------------------------------------------------------------
void Cook::openPizza()
{
    m_pizzaBuilder->getPizza()->open();
}

void Cook::makePizza(PizzaBuilder* pb)
{
    m_pizzaBuilder = pb;
    m_pizzaBuilder->createNewPizzaProduct();
    m_pizzaBuilder->buildDough();
    m_pizzaBuilder->buildSauce();
    m_pizzaBuilder->buildTopping();
}

