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

int main(void)
{
	std::cout << "Intanciating a Span..." << std::endl;
	Span	s(8);
	std::cout << "add values..." << std::endl;

	s.addNumber(3);
	s.addNumber(21);
	s.addNumber(2);
	s.addNumber(5);
	s.addNumber(6);
	s.addNumber(4);
	s.addNumber(3);
	s.addNumber(38);
	std::cout << "Checking FullContainerException..." << std::endl;
	s.addNumber(3);
	std::cout << "print vector..." << std::endl;
	std::cout << "s: ";
	s.printSpan();
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
	std::cout << "Checking LessThanTwoNumbersException..." << std::endl;
	Span	s2(2);
	s2.addNumber(3);
	std::cout << "s: ";
	s2.printSpan();
	std::cout << "Shortest span s2: ";
	try
	{
		int	sortest = s2.shortestSpan();
		std::cout << sortest << std::endl;
	}
	catch(const Span::LessThanTwoNumbersException& e)
	{
		std::cout << e.what() << std::endl;;
	}
	std::cout << "Longest span s2: ";
	try
	{
		int	longest = s2.longestSpan();
		std::cout << longest << std::endl;
	}
	catch(const Span::LessThanTwoNumbersException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Checking addManyNumbers with an array..." << std::endl;
	Span	s3(6);
	s3.addNumber(5);
	s3.addNumber(4);
	std::array<int, 2>	ar;
	ar[0] = 3;
	ar[1] = 7;
	try
	{
		s3.addManyNumbers(2, ar);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s3: ";
	s3.printSpan();
	std::cout << "Checking addManyNumbers with an array 2..." << std::endl;
	Span	s4(6);
	s4.addNumber(5);
	s4.addNumber(4);
	int	ar2[] = {3, 7, 9};
	size_t	size = sizeof(ar2) / sizeof(ar2[0]);
	try
	{
		s4.addManyNumbers(2, ar2, size);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s4: ";
	s4.printSpan();
	std::cout << "Checking addManyNumbers with a vector..." << std::endl;
	Span	s5(6);
	s5.addNumber(5);
	s5.addNumber(4);
	std::vector<int>	v;
	v.push_back(3);
	v.push_back(7);
	v.push_back(10);
	try
	{
		s5.addManyNumbers(2, v);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s5: ";
	s5.printSpan();
	std::cout << "Checking addManyNumbers with a deque..." << std::endl;
	Span	s6(6);
	s6.addNumber(5);
	s6.addNumber(4);
	std::deque<int>	dq;
	dq.push_back(3);
	dq.push_back(7);
	dq.push_back(12);
	try
	{
		s6.addManyNumbers(2, dq);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s6: ";
	s6.printSpan();
	std::cout << "s5: ";
	s5.printSpan();
	std::cout << "Checking addManyNumbers with a forward list..." << std::endl;
	Span	s7(6);
	s7.addNumber(5);
	s7.addNumber(4);
	std::forward_list<int>	fl;
	fl.push_front(3);
	fl.push_front(7);
	fl.push_front(13);
	try
	{
		s7.addManyNumbers(2, fl);
	}
	catch(const Span::NotEnoughCapacityException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "s7: ";
	s7.printSpan();
	return 0;
}