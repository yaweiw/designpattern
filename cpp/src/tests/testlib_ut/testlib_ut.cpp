// MyExecRefsLib.cpp
// compile with: cl /EHsc MyExecRefsLib.cpp /link MathFuncsLib.lib

#include <stdio.h>
#include <stdlib.h>
#include "..\patterns\testlib\testlib.h"

using namespace std;

int main(int argc,char *argv[])
{
    double m, n, x;
    m = atof(argv[1]); /* convert strings to integers */
    n = atof(argv[2]);

    switch(*argv[3])
    {
        case '+':
            x = MathFuncs::MyMathFuncs::Add(m, n);
            break;
        case '-':
            x = MathFuncs::MyMathFuncs::Subtract(m, n);
            break;
        case '*':
            x = MathFuncs::MyMathFuncs::Multiply(m, n);
            break;
        case '/':
            x = MathFuncs::MyMathFuncs::Divide(m, n);
            break;
        default:
            return 0;
    }

    fprintf(stdout, "%f %c %f is %f", m, *argv[3], n, x);
    return 0;
}