/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:46:44 by ahamdy            #+#    #+#             */
/*   Updated: 2023/03/02 11:03:05 by ahamdy           ###   ########.fr       */
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
		vector_iterator operator++(int)
    	{
        	vector_iterator &tmp = *this;
			++tmp.current;
        	return tmp;
    	}
		vector_iterator operator++ ()
		{
			return ((current++));
		}
		vector_iterator operator--(int)
    	{
        	vector_iterator &tmp = *this;
			--tmp.current;
        	return (tmp);
    	}
		vector_iterator operator-- ()
		{
			current--;
			return (current);
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
		vector_iterator operator+=(difference_type n) {
          current += n;
          return *this;
        }
		vector_iterator operator-=(difference_type n)
		{
			current -= n;
			return (*this);
		}
		value_type& operator[](difference_type n) const
		{
			return (*(current + n));
		}
	};

	template <typename T> 
	class const_vector_iterator : ft::vector_iterator<T>
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
		const_vector_iterator()
		{}
		const_vector_iterator(pointer copy)
		{
			current = copy;
		}
		const_vector_iterator(const const_vector_iterator& copy)
		{ this->current = copy.current; }
		const_vector_iterator& operator=(const const_vector_iterator& copy)
		{
			this->current = copy.current;
			return (*this);
		}
		bool operator== ( 
			const_vector_iterator& second)
		{
			return (this->current == second.current);
		}
		bool operator != (const const_vector_iterator& second)
		{
			return (this->current != second.current);
		}
		const reference operator *() const
		{
			return (*current);
		}
		const pointer operator ->() const
		{
			return (current);
		}
		void operator = (value_type& t)
		{
			*current = t;
		}
		const_vector_iterator operator++(int)
    	{
        	const_vector_iterator &tmp = *this;
			++tmp.current;
        	return tmp;
    	}
		const_vector_iterator operator++ ()
		{
			return ((current++));
		}
		const_vector_iterator operator--(int)
    	{
        	const_vector_iterator &tmp = *this;
			--tmp.current;
        	return (tmp);
    	}
		const_vector_iterator  operator-- ()
		{
			current--;
			return (current);
		}
		const difference_type operator+ (const const_vector_iterator &n) const
		{
			return (current + n.current);
		}
		const_vector_iterator operator+ (difference_type n) const
		{
			return (current + n);
		}
		const difference_type operator- (const const_vector_iterator &n) const 
		{
			return (current - n.current);
		}
		const_vector_iterator operator- (difference_type n) const 
		{
			return (current - n);
		}
		bool operator>(const const_vector_iterator& other) const
		{
			return (current > other.current);
		}
		bool operator<(const const_vector_iterator& other) const
		{
			return (current < other.current);
		}
		bool operator>=(const const_vector_iterator& other) const
		{
			return (current >= other.current);	
		}
		bool operator<=(const const_vector_iterator& other) const
		{
			return (current <= other.current);	
		}
		const_vector_iterator& operator+=(difference_type n) {
          current += n;
          return *this;
        }
		const_vector_iterator& operator-=(difference_type n)
		{
			current -= n;
			return (*this);
		}
		const value_type& operator[](difference_type n) const
		{
			return (*(current + n));
		}
	};
}
