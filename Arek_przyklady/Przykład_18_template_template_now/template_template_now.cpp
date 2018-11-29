#include <iostream>
#include <deque>

/**
 * Przykład 18 - obrazuje jak wyglada sytuacja z szablonowymi parametrami szablonow
 * teraz - standard C++17. 
 */


using std::deque;

/// Prosty szablon reprezentujacy adapter na kolejke deque - tworzy kolejke fifo
template <typename T, template 
	<typename StoredType, typename Alloc> typename Container = deque> /// teraz pozbywamy sie problemu
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