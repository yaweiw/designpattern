// MyExecRefsLib.cpp
// compile with: cl /EHsc MyExecRefsLib.cpp /link MathFuncsLib.lib

#include <stdio.h>
#include <stdlib.h>
#include "..\patterns\creational\builder\builder.h"

using namespace std;
using namespace Builder;

int main(int argc,char *argv[])
{
    Cook cook;
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    SpicyPizzaBuilder spicyPizzaBuilder;

    //cook.makePizza(&hawaiianPizzaBuilder);
    //cook.openPizza();

    cook.makePizza(&spicyPizzaBuilder);
    cook.openPizza();

    return 0;
}