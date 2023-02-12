/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:46:44 by ahamdy            #+#    #+#             */
/*   Updated: 2023/02/12 12:56:09 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
// #include "vector.hpp"
#include "iterator_traits.hpp"

namespace ft
{
	template <typename T>
	class vector_iterator
	{
		public :
		typedef typename iterator_traits<T>::difference_type difference_type;
		typedef typename iterator_traits<T>::value_type value_type;
		typedef typename iterator_traits<T>::pointer pointer;
		typedef typename iterator_traits<T>::reference reference;
		typedef typename iterator_traits<T>::iterator_category iterator_category;
		protected :
		pointer current;
		public :
		vector_iterator()
		{}
		vector_iterator(pointer copy)
		{
			current = copy;
		}
		vector_iterator(const vector_iterator& copy)
		{ this->current = copy.current; }
		vector_iterator& operator=(const vector_iterator& copy)
		{
			this->current = copy.current;
			return (*this);
		}
		bool operator== ( 
			const vector_iterator& second)
		{
			return (this->current == second.current);
		}
		bool operator != (const vector_iterator& second)
		{
			return (this->current != second.current);
		}
		reference operator *() const
		{
			return (*current);
		}
		pointer operator ->() const
		{
			return (current);
		}
		void operator = (value_type& t)
		{
			*current = t;
		}
		value_type& operator++(int)
    	{
        	vector_iterator &tmp = *this;
			++tmp.current;
        	return *tmp;
    	}
		value_type& operator++ ()
		{
			return (*(current++));
		}
		value_type& operator--(int)
    	{
        	vector_iterator &tmp = *this;
			--tmp.current;
        	return (*tmp);
    	}
		value_type& operator-- ()
		{
			current--;
			return (*this);
		}
		difference_type operator+ (const vector_iterator &n) const
		{
			return (current + n.current);
		}
		vector_iterator operator+ (difference_type n) const
		{
			return (current + n);
		}
		difference_type operator- (const vector_iterator &n) const 
		{
			return (current - n.current);
		}
		vector_iterator operator- (difference_type n) const 
		{
			return (current - n);
		}
		bool operator>(const vector_iterator& other) const
		{
			return (current > other.current);
		}
		bool operator<(const vector_iterator& other) const
		{
			return (current < other.current);
		}
		bool operator>=(const vector_iterator& other) const
		{
			return (current >= other.current);	
		}
		bool operator<=(const vector_iterator& other) const
		{
			return (current <= other.current);	
		}
		vector_iterator& operator+=(difference_type n) {
          current += n;
          return *this;
        }
		vector_iterator& operator-=(difference_type n)
		{
			current -= n;
			return (*this);
		}
		value_type& operator[](difference_type n) const
		{
			return (*(current + n));
		}
	};
}
