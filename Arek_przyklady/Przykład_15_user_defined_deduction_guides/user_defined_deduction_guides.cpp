/**
 * Prosty przykład na tworzenie własnych deduction guides.
 */

#include <iostream>
#include <algorithm>

template <typename T>
class PseudoVector
{
public:

	PseudoVector() {
		m_data = nullptr;
		m_size = 0;
	} 

	template <typename ... Args>
	PseudoVector(Args&& ... newElems) : m_size(0), m_data(nullptr) {
		( push_back(newElems), ... );
	}

	void push_back(const T& elem) {
		T* temp = new T [m_size + 1];
		temp[m_size] = elem;
		for (int i = 0; i < m_size; ++i) { temp[i] = m_data[i]; }
		if (m_data) 
			delete [] m_data;
		m_data = temp;
		++m_size;
	}

	void print() const {
		for (int i = 0; i < m_size; ++i) 
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	~PseudoVector() {
		delete [] m_data;
	}

private:
	unsigned m_size;
	T* m_data;
};

/// co sie stanie jak zakomentujemy?
template <typename ... Args>
PseudoVector (Args ... args) -> PseudoVector<std::common_type_t<Args...>>;



int main()
{
	PseudoVector test1 (1, 2, 3, 4, 5, 6);
	test1.print();

	return 0;
}