/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <array>
#include <deque>
#include <list>

void	basicTest(Span & s)
{
	std::cout << "**BASIC TESTS**" << std::endl;
	std::cout << "Intanciating a Span and adding values..." << std::endl;
	s.addNumber(3);
	s.addNumber(21);
	s.addNumber(2);
	s.addNumber(5);
	s.addNumber(6);
	s.addNumber(4);
	s.addNumber(3);
	s.addNumber(38);
	std::cout << "s: ";
	s.printSpan();
	std::cout << "Checking copy constructor..." << std::endl;
	Span	s2(s);
	std::cout << "s2: ";
	s2.printSpan();
	std::cout << "Checking operator =..." << std::endl;
	Span	s3;
	s3 = s;
	std::cout << "s3: ";
	s3.printSpan();
	std::cout << "checking shortest Span..." << std::endl;
	std::cout << "Shortest span s: ";
	try
	{
		int	sortest = s.shortestSpan();
		std::cout << sortest << std::endl;
	}
	catch(const Span::LessThanTwoNumbersException& e)
	{
		std::cout << e.what() << std::endl;;
	}
	std::cout << "checking longest Span..." << std::endl;
	std::cout << "Longest span s: ";
	try
	{
		int	longest = s.longestSpan();
		std::cout << longest << std::endl;
	}
	catch(const Span::LessThanTwoNumbersException& e)
	{
		std::cout << e.what() << std::endl;;
	}
}

void	testFullContainerException(Span &s)
{
	std::cout << "**Checking FullContainerException...**" << std::endl;
	s.addNumber(3);
	std::cout << "print vector..." << std::endl;
	std::cout << "s: ";
	s.printSpan();
}

void	testLessThanTwoNumbersException(void)
{
	std::cout << "**Checking LessThanTwoNumbersException...**" << std::endl;
	Span	s(2);
	s.addNumber(3);
	std::cout << "s: ";
	s.printSpan();
	std::cout << "Shortest span s: ";
	try
	{
		int	sortest = s.shortestSpan();
		std::cout << sortest << std::endl;
	}
	catch(const Span::LessThanTwoNumbersException& e)
	{
		std::cout << e.what() << std::endl;;
	}
	std::cout << "Longest span s: ";
	try
	{
		int	longest = s.longestSpan();
		std::cout << longest << std::endl;
	}
	catch(const Span::LessThanTwoNumbersException& e)
	{
		std::cout << e.what() << std::endl;
	}	
}

void	testArray(void)
{
	std::cout << "**Checking addManyNumbers with an array...**" << std::endl;
	Span	s(6);
	s.addNumber(5);
	s.addNumber(4);
	std::array<int, 3>	ar;
	ar[0] = 3;
	ar[1] = 7;
	ar[2] = 8;
	try
	{
		s.addManyNumbers(2, ar);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
	std::cout << "Trying to add more elements than s capacity:" << std::endl;
	std::array<int, 2>	ar2;
	ar2[0] = 21;
	ar2[0] = 42;
	try
	{
		s.addManyNumbers(5, ar2);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
}

void	testArray2(void)
{
	std::cout << "**Checking addManyNumbers with an array 2...**" << std::endl;
	Span	s(6);
	s.addNumber(5);
	s.addNumber(4);
	int	ar[] = {3, 7, 9};
	size_t	size = sizeof(ar) / sizeof(ar[0]);
	try
	{
		s.addManyNumbers(2, ar, size);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
	std::cout << "Trying to add more elements than s capacity:" << std::endl;
	std::array<int, 2>	ar2;
	ar2[0] = 21;
	ar2[0] = 42;
	try
	{
		s.addManyNumbers(5, ar2);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
}

void	testVector(void)
{
	std::cout << "**Checking addManyNumbers with a vector...**" << std::endl;
	Span	s(6);
	s.addNumber(5);
	s.addNumber(4);
	std::vector<int>	v;
	v.push_back(3);
	v.push_back(7);
	v.push_back(10);
	try
	{
		s.addManyNumbers(2, v);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
	std::cout << "Trying to add more elements than s capacity:" << std::endl;
	std::vector<int>	v2;
	v2.push_back(21);
	v2.push_back(42);
	try
	{
		s.addManyNumbers(5, v2);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
}

void	testDeque(void)
{
	std::cout << "**Checking addManyNumbers with a deque...**" << std::endl;
	Span	s(6);
	s.addNumber(5);
	s.addNumber(4);
	std::deque<int>	dq;
	dq.push_back(3);
	dq.push_back(7);
	dq.push_back(11);
	try
	{
		s.addManyNumbers(2, dq);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
	std::cout << "Trying to add more elements than s capacity:" << std::endl;
	std::deque<int>	dq2;
	dq2.push_back(21);
	dq2.push_back(42);
	try
	{
		s.addManyNumbers(5, dq2);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
}

void	testForwardList(void)
{
	std::cout << "**Checking addManyNumbers with a forward list...**" << std::endl;
	Span	s(6);
	s.addNumber(5);
	s.addNumber(4);
	std::forward_list<int>	fl;
	int	ar[] = {3, 7, 12};
	fl.assign(ar, ar + 3);
	try
	{
		s.addManyNumbers(2, fl);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
	std::cout << "Trying to add more elements than s capacity:" << std::endl;
	std::forward_list<int>	fl2;
	int	ar2[] = {21, 42};
	fl2.assign(ar2, ar2 + 2);
	try
	{
		s.addManyNumbers(5, fl2);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();	
}

void	testList(void)
{
	std::cout << "**Checking addManyNumbers with a list...**" << std::endl;
	Span	s(6);
	s.addNumber(5);
	s.addNumber(4);
	std::list<int>	l;
	int	ar[] = {3, 7, 13};
	l.assign(ar, ar + 3);
	try
	{
		s.addManyNumbers(2, l);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
	std::cout << "Trying to add more elements than s capacity:" << std::endl;
	std::list<int>	l2;
	int	ar2[] = {21, 42};
	l2.assign(ar2, ar2 + 2);
	try
	{
		s.addManyNumbers(5, l2);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s: ";
	s.printSpan();
}

int main(void)
{
	Span	s(8);
	basicTest(s);
	std::cout << std::endl;
	testFullContainerException(s);
	std::cout << std::endl;
	testLessThanTwoNumbersException();
	std::cout << std::endl;
	testArray();
	std::cout << std::endl;
	testArray2();
	std::cout << std::endl;
	testVector();
	std::cout << std::endl;
	testDeque();
	std::cout << std::endl;
	testForwardList();
	std::cout << std::endl;
	testList();
	return 0;
}