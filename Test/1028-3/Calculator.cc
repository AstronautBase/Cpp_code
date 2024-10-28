#include "Calculator.h"
#include <iomanip>
ostream &operator<<(ostream &out, const BaseCalculator *cal)
{
    // TODO
    out << cal->oss.str();
    return out;
}

void AddCalculator::calculate(double a, double b)
{
    // TODO
    double result = a + b;
    oss << fixed << setprecision(2) << result << endl;
}

void SubCalculator::calculate(double a, double b)
{
    // TODO
    double result = a - b;
    oss << fixed << setprecision(2) << result << endl;
}
