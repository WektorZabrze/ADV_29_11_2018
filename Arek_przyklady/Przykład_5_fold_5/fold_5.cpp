/**
 * Fold expressions - przykład 5
 * Przykład obrazuje działanie operatora przecinka w fold 
 * expressions - konkretnie kolejność wykonania się funkcji.
 */

#include <iostream>

class LoudPrint 
{
public:
	LoudPrint (int value) : m_value(value) {}

	void LoudFun() {
		std::cout << "Wywoluje dla " << m_value << std::endl;
	}

private:
	int m_value;
};

template <typename ... Args>
void fold_test (Args&& ... args) {
	( void(args.LoudFun() ), ... , LoudPrint(0).LoudFun() );
}

int main() {

	LoudPrint a(1);
	LoudPrint b(2);
	LoudPrint c(3);

	fold_test(a, b, c);

	std::cout << std::endl;

	(void (a.LoudFun()),
	(void (b.LoudFun()),
	(void (c.LoudFun()), void(LoudPrint(0).LoudFun()))
	));
}