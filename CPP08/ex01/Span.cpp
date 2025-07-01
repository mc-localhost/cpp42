#include "Span.hpp"

Span::Span() : capacity(0) { }

Span::~Span() { }

Span::Span(unsigned int N)
{
	if (N >= v.max_size())
		throw NElementsException();
	capacity = N;
	v.reserve(N);
}

Span::Span(const Span &copy) : capacity(copy.capacity), v(copy.v) { }

Span & Span::operator=(Span assign)
{
	std::swap(capacity, assign.capacity);
	std::swap(v, assign.v);
	return *this;
}

const char * Span::NElementsException::what(void) const noexcept
{
	return "Already has N elements or system max size will be reached";
}

const char * Span::SpanEmptyException::what(void) const noexcept
{
	return "Span has less than 2 elements";
}

void Span::addNumber(const int num)
{
	if (v.size() == capacity || v.size() == v.max_size())
		throw NElementsException();
	v.push_back(num);
}

void Span::addManyNumbers(std::vector<int> to_insert)
{
	if (v.size() + to_insert.size() > capacity || v.size() + to_insert.size() > v.max_size())
		throw NElementsException();
	// v.assign(to_insert.begin(), to_insert.end());
	v.insert(v.end(), to_insert.begin(), to_insert.end());
}

void Span::addRandomNumbers(const unsigned int count)
{
	if (v.size() + count > capacity || v.size() + count > v.max_size())
		throw NElementsException();
	std::srand(time(nullptr));
	for (unsigned int i = 0; i < count; i++)
		v.push_back(std::rand() % 100);
}

long int Span::shortestSpan() const
{
	if (v.size() < 2)
		throw SpanEmptyException();
	std::vector<int> temp = v;
	std::sort(temp.begin(), temp.end());
	std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
	return *(std::min_element(temp.begin(), temp.end()));
}

long int Span::longestSpan() const
{
	if (v.size() < 2)
		throw SpanEmptyException();
	const auto [min, max] = std::minmax_element(begin(v), end(v));
	return *max - *min;
}

void Span::printNumbers() const
{
	for(auto num : v)
		std::cout << num << " ";
	std::cout << std::endl;
}
