/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char* Span::FullContainerException::what() const throw()
{
	return "Fail to add number, Span object is full";
}

const char* Span::LessThanTwoNumbersException::what() const throw()
{
	return "Impossible to find Span, the container has less than two numbers";
}

const char* Span::NotEnoughCapacityException::what() const throw()
{
	return "Data size exceed Span capacity";
}

Span::Span(void):_n(0)
{
	return ;
}

Span::Span(unsigned int N):_n(N)
{
	return ;
}

Span::Span(Span const & src):_n(src._n), _v(src._v)
{
	*this = src;
}

Span::~Span(void)
{
	return ;
}

Span & Span::operator=(Span const & src)
{
	if (this != &src)
	{
		this->_n = src._n;
		this->_v = src._v;
	}
	return (*this);
}

void	Span::addNumber(int const value)
{
	try
	{
		if (this->_v.size() == this->_n)
			throw Span::FullContainerException();
		this->_v.push_back(value);
	}
	catch(const Span::FullContainerException& e)
	{
		std::cout << e.what() << std::endl;
	}

}

int	Span::shortestSpan()
{
	std::vector<int>	sorted_v = this->_v;
	std::sort(sorted_v.begin(), sorted_v.end());
	if (this->_v.size() < 2)
		throw Span::LessThanTwoNumbersException();
	int	distance = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted_v.size() - 1; ++i)
	{
		if (std::abs(sorted_v[i] - sorted_v[i + 1]) < distance)
			distance = std::abs(sorted_v[i] - sorted_v[i + 1]);
	}
	return (distance);
}

int	Span::longestSpan()
{
	if (this->_v.size() < 2)
		throw Span::LessThanTwoNumbersException();
	int	max_int = *std::max_element(this->_v.begin(), this->_v. end());
	int	min_int = *std::min_element(this->_v.begin(), this->_v. end());
	int	distance = std::abs(max_int - min_int);
	return (distance);
}

void	Span::printSpan(void)
{
	for (size_t i = 0; i < this->_v.size(); ++i)
		std::cout << "[" << this->_v[i] << "] ";
	std::cout << std::endl;
}
