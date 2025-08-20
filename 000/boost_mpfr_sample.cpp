#include <boost/multiprecision/mpfr.hpp>
#include <iostream>
#include <iomanip>

using namespace boost::multiprecision;

// Define variable precision floating point type
typedef mpfr_float mpfr_float_var;

int main() {
    // Set default precision to 150 decimal digits
    mpfr_float_var::default_precision(500); // bits (approximately 150 decimal digits)

    // Set output precision
    std::cout << std::fixed << std::setprecision(50);

    // Basic arithmetic operations
    mpfr_float_var a = 1;
    mpfr_float_var b = 3;

    std::cout << "=== Basic Arithmetic ===" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
    std::cout << std::endl;

    // High precision pi calculation using Leibniz formula
    std::cout << "=== Pi Calculation (Leibniz formula) ===" << std::endl;
    mpfr_float_var pi_approx = 0;
    mpfr_float_var sign = 1;

    for (int i = 0; i < 1000000; ++i) {
        pi_approx += sign / (2 * i + 1);
        sign *= -1;
    }
    pi_approx *= 4;

    std::cout << "Pi approximation: " << pi_approx << std::endl;

    // Using built-in mathematical functions
    std::cout << std::endl << "=== Mathematical Functions ===" << std::endl;
    mpfr_float_var x = 2;
    std::cout << "x = " << x << std::endl;
    std::cout << "sqrt(x) = " << sqrt(x) << std::endl;
    std::cout << "exp(x) = " << exp(x) << std::endl;
    std::cout << "log(x) = " << log(x) << std::endl;
    std::cout << "sin(x) = " << sin(x) << std::endl;
    std::cout << "cos(x) = " << cos(x) << std::endl;

    // Precision demonstration
    std::cout << std::endl << "=== Precision Comparison ===" << std::endl;
    double regular_calc = 1.0 / 3.0;
    mpfr_float_var precise_calc = mpfr_float_var(1) / mpfr_float_var(3);

    std::cout << "Regular double precision (1/3): " << std::setprecision(15) << regular_calc << std::endl;
    std::cout << "MPFR high precision (1/3):     " << std::setprecision(50) << precise_calc << std::endl;

    // Variable precision demonstration
    std::cout << std::endl << "=== Variable Precision Demonstration ===" << std::endl;

    // Create numbers with different precisions
    mpfr_float_var low_prec(1.0 / 3.0, 50);     // 50 bits precision
    mpfr_float_var medium_prec(1.0 / 3.0, 200); // 200 bits precision
    mpfr_float_var high_prec(1.0 / 3.0, 1000);  // 1000 bits precision

    std::cout << "Low precision (50 bits):   " << std::setprecision(20) << low_prec << std::endl;
    std::cout << "Medium precision (200 bits): " << std::setprecision(30) << medium_prec << std::endl;
    std::cout << "High precision (1000 bits):  " << std::setprecision(70) << high_prec << std::endl;

    // Show current default precision
    std::cout << std::endl << "Current default precision: " << mpfr_float_var::default_precision() << " bits" << std::endl;

    return 0;
}
