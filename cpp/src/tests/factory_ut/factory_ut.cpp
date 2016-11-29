// MyExecRefsLib.cpp
// compile with: cl /EHsc MyExecRefsLib.cpp /link MathFuncsLib.lib

#include <stdio.h>
#include <stdlib.h>
#include "..\patterns\creational\factory\factory.h"

using namespace std;
using namespace factory;

int main(int argc,char *argv[])
{
    Computer* c = ComputerFactory::NewComputer(ComputerFactory::LaptopComputer);
    c->GetDescription();
    return 0;
}