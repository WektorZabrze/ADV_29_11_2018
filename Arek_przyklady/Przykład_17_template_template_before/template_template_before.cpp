#include <iostream>
#include <deque>

/**
 * Przykład 17 - obrazuje jak wygladala sytuacja z szablonowymi parametrami szablonow
 * przez standardem C++17. Poniższy kod kompiluje się, natomiast po zamianie slowa
 * kluczowego class na typename w parametrach szablonu fifo, kompilacja nie powiedzie się
 * Kompilujemy z flagą -std=c++14
 * Uzywamy flagi -pedantic-errors, bo wspolczesne kompilatory potrafia przepuscic to typename,
 * pomimo ze jest niezgodne ze standardem, w ktorym kompilujemy
 */

/// TODO: zmienic class na typename przy pokazywaniu przykladu.

using std::deque;

/// Prosty szablon reprezentujacy adapter na kolejke deque - tworzy kolejke fifo
template <typename T, template 
	<typename StoredType, typename Alloc> class Container = deque> /// problem w tej linii - słowo class
class fifo 
{
public:
	void push(const T& value) {
		m_data.push_back(value);
	}

	void pop() {
		m_data.pop_front();
	}

	auto& front() {
		return m_data.front();
	}

	auto begin() { return m_data.begin(); }
	auto end() {return m_data.end(); }

private:

	Container<T, std::allocator<T>> m_data;

};


int main()
{
	fifo<int> test_fifo;
	for (int i = 0; i < 5; ++i) {
		test_fifo.push(i);
	}

	for (auto& elem : test_fifo) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}