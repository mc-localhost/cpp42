template <typename T>
MutantStack<T>::MutantStack() { }

template <typename T>
MutantStack<T>::~MutantStack() { }


template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) { *this = copy; }

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> &assign)
{
	if (this != &assign)
		*this = assign;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return iterator(std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return iterator(std::stack<T>::c.end());
}