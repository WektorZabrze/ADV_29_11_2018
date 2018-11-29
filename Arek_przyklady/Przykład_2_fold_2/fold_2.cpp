/**
 * Fold expressions - przykład 2
 * Przykład ma na celu ukazanie różnicy pomiędzy poszczególnymi 
 * rodzajami fold expressions, jak również pokazać proste 
 * zastosowanie nowej funkcjonalności. 
 */

#include <iostream>
#include <string>

class Complex
{
public:

	Complex (double real = 0.0, double imag = 0.0) : 
		m_real(real), m_imag(imag) {}

	std::string toString() const {
		return std::string ( std::to_string(m_real) + " + " + std::to_string(m_imag) + "i" );
	}

	Complex operator+ (const Complex& rhs) const {
		std::cout << __PRETTY_FUNCTION__ << " " << 
			toString() << " " << rhs.toString() << std::endl;

		return Complex (m_real + rhs.m_real, m_imag + rhs.m_imag);
	}


private:
	double m_real;
	double m_imag;
};

/**
 * Klasyczne variadic templates
 */

template <typename T>
T sumVariadic (const T& value) {
	return value;
}

template <typename T, typename ... Args>
T sumVariadic (const T& value, Args ... args ) {
	return value + sumVariadic(args...);
}


/**
 * Fold expressions
 */

template <typename ... Args>
auto sumComplexRight (Args ... args) {
	return ( args + ... );
}

template <typename ... Args>
auto sumComplexLeft (Args ... args) {
	return ( ... + args );
}

template <typename ... Args>
auto sumComplexRightBinary (Args ... args) {
	return ( args + ... + Complex() );
}

template <typename ... Args>
auto sumComplexLeftBinary (Args ... args) {
	return ( Complex() + ... + args );
}


int main()
{
	std::cout << "Variadic templates" << std::endl;
	auto sum0 = sumVariadic ( Complex(1, 0), Complex(1, 1), Complex (5, 5) );
	std::cout << "Sum = " << sum0.toString() << std::endl;
	std::cout << std::endl;


	std::cout << "Unary right fold" << std::endl;
	auto sum1 = sumComplexRight ( Complex(1, 0), Complex(1, 1), Complex (5, 5) );
	std::cout << "Sum = " << sum1.toString() << std::endl;
	std::cout << std::endl;


	std::cout << "Unary left fold" << std::endl;
	auto sum2 = sumComplexLeft ( Complex(1, 0), Complex(1, 1), Complex (5, 5) );
	std::cout << "Sum = " << sum2.toString() << std::endl;
	std::cout << std::endl;

	/// W tym przykładzie operacje są oczywiście trywialne, bo dodajemy dwie
	/// liczby zespolone - kolejnosc nie ma znaczenia, tak samo jak obecność
	/// elementu neutralnego (0, 0). Czasem jednak będziemy chcieli mieć 
	/// możliwość ustawienia jakiejś wartości startowej. 

	std::cout << "Binary right fold" << std::endl;
	auto sum3 = sumComplexRightBinary ( Complex(1, 0), Complex(1, 1), Complex (5, 5) );
	std::cout << "Sum = " << sum3.toString() << std::endl;
	std::cout << std::endl;


	std::cout << "Binary left fold" << std::endl;
	auto sum4 = sumComplexLeftBinary ( Complex(1, 0), Complex(1, 1), Complex (5, 5) );
	std::cout << "Sum = " << sum4.toString() << std::endl;
	std::cout << std::endl;

	return 0;
}