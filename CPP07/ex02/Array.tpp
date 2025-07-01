// https://isocpp.org/wiki/faq/templates

template <typename T>
const char* Array<T>::OutOfBoundsException::what(void) const noexcept
{
	return "Index is out of bounds";
}

template <typename T>
Array<T>::Array() : m_size(0), arr(nullptr) { }

template <typename T>
Array<T>::Array(unsigned int n) : m_size(n), arr(n > 0 ? new T[n]() : nullptr) { }
// new T[n]() - elements are 0-initialised
// new T[n] - elements are uninitialised

template <typename T>
Array<T>::~Array() { delete[] arr; }

template <typename T>
Array<T>::Array(const Array<T> &copy) : m_size(copy.m_size), arr(copy.m_size > 0 ? new T[copy.m_size]() : nullptr)
{
	for (unsigned int i = 0; i < m_size; i++)
		arr[i] = copy.arr[i];
}
template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &assign)
{
	if (this != &assign)
	{
		delete[] arr;
		m_size = assign.m_size;
		arr = m_size > 0 ? new T[m_size]() : nullptr;
		for (unsigned int i = 0; i < m_size; i++)
			arr[i] = assign.arr[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= m_size)
		throw OutOfBoundsException();
	return arr[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= m_size)
		throw OutOfBoundsException();
	return arr[i];
}

template <typename T>
unsigned int Array<T>::size() const { return m_size; }
