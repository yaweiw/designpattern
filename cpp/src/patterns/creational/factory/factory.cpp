#include "factory.h"

using namespace std;

namespace factory
{
Computer *ComputerFactory::NewComputer(const ComputerType &computerType)
{
    switch (computerType)
    {
    case LaptopComputer:
        return new Laptop("laptop");
    case DesktopComputer:
        return new Desktop("desktop");
    }
    throw "invalid computer type.";
    return NULL;
}
}
