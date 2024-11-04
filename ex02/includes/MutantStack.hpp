/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>
#include <deque>

template < typename T, typename U = std::deque<T> >
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const & src);
		~MutantStack(void);

		MutantStack & operator=(MutantStack const & src);

		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator	begin();
		iterator	end();
		const_iterator	cbegin() const;
		const_iterator	cend() const;
		reverse_iterator	rbegin();
		reverse_iterator	rend();

};

#include "MutantStack.tpp"

#endif
