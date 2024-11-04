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

#include "MutantStack.hpp"

template < typename T , typename U >
MutantStack<T, U>::MutantStack(void):std::stack<T, U>()
{}

template < typename T, typename U >
MutantStack<T, U>::MutantStack(MutantStack const & src):std::stack<T, U>(src)
{}

template < typename T, typename U >
MutantStack<T, U>::~MutantStack(void)
{}

template < typename T, typename U >
MutantStack<T, U> & MutantStack<T, U>::operator=(MutantStack const & src)
{
    if (this != &src)
    {
        this->c = src.c;
    }
    return (*this);
}

template < typename T, typename U >
typename MutantStack<T, U>::iterator	MutantStack<T, U>::begin()
{
    return (std::stack<T>::c.begin());
}

template < typename T, typename U >
typename MutantStack<T, U>::iterator	MutantStack<T, U>::end()
{
    return (std::stack<T>::c.end());
}

template < typename T, typename U >
typename MutantStack<T, U>::const_iterator	MutantStack<T, U>::cbegin() const
{
    return (std::stack<T>::c.begin());
}

template < typename T, typename U >
typename MutantStack<T, U>::const_iterator	MutantStack<T, U>::cend() const
{
    return (std::stack<T>::c.end());
}

template < typename T, typename U >
typename MutantStack<T, U>::reverse_iterator	MutantStack<T, U>::rbegin()
{
    return (std::stack<T>::c.rbegin());
}

template < typename T, typename U >
typename MutantStack<T, U>::reverse_iterator	MutantStack<T, U>::rend()
{
    return (std::stack<T>::c.rend());
}

// template < typename T >
// typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crbegin() const
// {
//     return (std::stack<T>::c.crbegin());
// }

// template < typename T >
// typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crend() const
// {
//     return (std::stack<T>::c.crend());
// }