/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 08:51:29 by ahamdy            #+#    #+#             */
/*   Updated: 2023/03/02 11:35:37 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (typename ft::enable_if<!(ft::is_integral<InputIterator1>::value), InputIterator2>::type first1, InputIterator1 last1,
                                typename ft::enable_if<!(ft::is_integral<InputIterator2>::value) ,InputIterator2>::type first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
    if (first2==last2 || *first2<*first1) return false;
    else if (*first1<*first2) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);
}


template <class InputIterator1, class InputIterator2, class Compare>
  bool lexicographical_compare (typename ft::enable_if<!(ft::is_integral<InputIterator1>::value) , InputIterator1>::type  first1, InputIterator1 last1,
                                typename ft::enable_if<!(ft::is_integral<InputIterator2>::value) ,InputIterator2>::type  first2, InputIterator2 last2, Compare comp)
{
  while (first1!=last1)
  {
    if (first2==last2 || comp(first2, first1)) return false;
    else if (*first1<*first2) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);	
}