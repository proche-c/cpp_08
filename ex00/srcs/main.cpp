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

#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <list>

int main(void)
{
	std::cout << "ARRAY" << std::endl;
	std::array<int, 3>	ar;
	std::array<int, 3>::iterator it;
	ar[0] = 3;
	ar[1] = 5;
	ar[2] = 9;
	try
	{
		it = easyfind<std::array<int, 3> >(ar, 5);
		std::cout << *it << std::endl;
	}
	catch(const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		it = easyfind<std::array<int, 3> >(ar, 6);
		std::cout << *it << std::endl;
	}
	catch(const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "VECTOR" << std::endl;
	std::vector<int>	v;
	std::vector<int>::iterator it2;
	v.push_back(4);
	v.push_back(7);
	v.push_back(12);
	try
	{
		it2 = easyfind<std::vector<int> >(v, 5);
		std::cout << *it << std::endl;
	}
	catch(const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		it2 = easyfind<std::vector<int> >(v, 4);
		std::cout << *it2 << std::endl;
	}
	catch(const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "LIST" << std::endl;
	std::list<int>	l;
	std::list<int>::iterator it3;
	l.push_back(4);
	l.push_back(7);
	l.push_back(12);
	try
	{
		it3 = easyfind<std::list<int> >(l, 5);
		std::cout << *it3 << std::endl;
	}
	catch(const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		it3 = easyfind<std::list<int> >(l, 4);
		std::cout << *it3 << std::endl;
	}
	catch(const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}