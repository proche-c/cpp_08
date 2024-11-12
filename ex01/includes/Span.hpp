/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <algorithm>
// #include <forward_list>

class Span
{
	public:
		class 	FullContainerException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class 	LessThanTwoNumbersException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class 	NotEnoughCapacityException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Span(void);
		Span(unsigned int N);
		Span(Span const & src);
		~Span(void);

		Span & operator=(Span const & src);

		void	addNumber(int const value);
		int	shortestSpan();
		int	longestSpan();
		void			printSpan(void);
		template < typename T >
		void	addManyNumbers(size_t position, T & data)
		{
			if (data.size() > this->_n - position)
				throw Span::NotEnoughCapacityException();
			this->_v.insert(this->_v.begin() + position, data.begin(), data.end());
		}

		void	addManyNumbers(size_t position, int  *data, size_t size)
		{
			if (size > this->_n - position)
				throw Span::NotEnoughCapacityException();
			this->_v.insert(this->_v.begin() + position, data, data + size);
		}

		// void	addManyNumbers(size_t position, std::forward_list<int> data)
		// {
		// 	size_t	size = std::distance(data.begin(), data.end());
		// 	if (size > this->_n - position)
		// 		throw Span::NotEnoughCapacityException();
		// 	this->_v.insert(this->_v.begin() + position, data.begin(), data.end());
		// }

	private:
		unsigned int		_n;
		std::vector<int>	_v;

};

std::ostream & operator<<(std::ostream & o, Span const & s);

#endif
