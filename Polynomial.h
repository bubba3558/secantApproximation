#ifndef SAS_POLYNOMIAL_H
#define SAS_POLYNOMIAL_H
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
class Polynomial
{
    uint32_t degree;
    std::vector<double> coefficients; //[0]=a0, [1]=a1 ...
public:
    Polynomial( std::vector<double> coefficients );
    double getFunctionValue(double x);
    double getRootInRange(double bottom, double top, double approx, int max);
    void printRootFromRange(double bottom, double top, double approx, int max);
private:
    double getPower(double base, uint32_t exponent);
};

#endif //SAS_POLYNOMIAL_H
