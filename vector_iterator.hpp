/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:46:44 by ahamdy            #+#    #+#             */
/*   Updated: 2023/03/04 09:56:51 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
			++current;
        	return tmp;
    	}
		vector_iterator& operator++ ()
		{
			current += 1;
			return (*this);
		}
		vector_iterator operator--(int)
    	{
        	vector_iterator &tmp = *this;
			--current;
        	return (tmp);
    	}
		vector_iterator& operator-- ()
		{
			current -= 1;
			return (*this);
		}
		vector_iterator operator+ (difference_type n) const
		{
			return (vector_iterator(current + n));	
		}
		vector_iterator operator- (difference_type n) const 
		{
			return (vector_iterator(current - n));
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
		template <typename value>
		friend bool operator != (const vector_iterator<value>& first, const vector_iterator<value>& second);
		template <typename value>
		friend typename vector_iterator<value>::difference_type operator- (const vector_iterator<value>& first, const vector_iterator<value> &n); //const;
		template <typename value>
		friend typename vector_iterator<value>::difference_type operator+ (const vector_iterator<value>& first, const vector_iterator<value> &n); //const;
		template <typename value>
		friend bool operator== (const vector_iterator<value>& first, const vector_iterator<value>& second);
		template <typename value>
		friend bool operator>(const vector_iterator<value>& first ,const vector_iterator<value>& other); //const;
		template <typename value>
		friend bool operator<(const vector_iterator<value>& first ,const vector_iterator<value>& other); //const;
		template <typename value>
		friend bool operator>=(const vector_iterator<value>& first ,const vector_iterator<value>& other); //const;
		template <typename value>
		friend bool operator<=(const vector_iterator<value>& first ,const vector_iterator<value>& other); //const;
	};
		template <typename value>
		bool operator== (const vector_iterator<value>& first ,const vector_iterator<value>& second)
		{
			return (first.current == second.current);
		}
		template <typename value>	
		bool operator != (const vector_iterator<value>& first ,const vector_iterator<value>& second)
		{
			return (first.current != second.current);
		}
		template <typename value>
		typename vector_iterator<value>::difference_type operator+ (const vector_iterator<value>& first, const vector_iterator<value> &n) //const 
		{
			return (first.current - n.current);
		}
		template <typename value>
		typename vector_iterator<value>::difference_type operator- (const vector_iterator<value>& first, const vector_iterator<value> &n) //const
		{
			return (first.current - n.current);
		}
		template <typename value>
		bool operator>(const vector_iterator<value>& first ,const vector_iterator<value>& other) //const
		{
			return (first.current > other.current);
		}
		template <typename value>
		bool operator<(const vector_iterator<value>& first, const vector_iterator<value>& other) //const
		{
			return (first.current < other.current);
		}
		template <typename value>
		bool operator>=(const vector_iterator<value>& first, const vector_iterator<value>& other) //const
		{
			return (first.current >= other.current);	
		}
		template <typename value>
		bool operator<=(const vector_iterator<value>& first, const vector_iterator<value>& other) //const
		{
			return (first.current <= other.current);	
		}
		
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
			++current;
        	return tmp;
    	}
		const_vector_iterator& operator++ ()
		{
			current += 1;
			return (*this);
		}
		const_vector_iterator operator--(int)
    	{
        	const_vector_iterator &tmp = *this;
			--current;
        	return (tmp);
    	}
		const_vector_iterator&  operator-- ()
		{
			current--;
			return (*this);
		}
		const_vector_iterator operator+ (difference_type n) const
		{
			return (const_vector_iterator(current + n));
		}
		const_vector_iterator operator- (difference_type n) const 
		{
			return (const_vector_iterator(current - n));
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
		template <typename value>
		friend bool operator != (const const_vector_iterator<value>& first, const const_vector_iterator<value>& second);
		template <typename value>
		friend difference_type operator- (const const_vector_iterator<value>& first, const const_vector_iterator<value> &n); //const;
		template <typename value>
		friend difference_type operator+ (const const_vector_iterator<value>& first, const const_vector_iterator<value> &n); //const;
		template <typename value>
		friend bool operator == (const const_vector_iterator<value>& first, const const_vector_iterator<value>& second);
		template <typename value>
		friend bool operator > (const const_vector_iterator<value>& first, const const_vector_iterator<value>& second); //const;
		template <typename value>
		friend bool operator < (const const_vector_iterator<value>& first, const const_vector_iterator<value>& second); //const;
		template <typename value>
		friend bool operator >= (const const_vector_iterator<value>& first, const const_vector_iterator<value>& second); //const;
		template <typename value>
		friend bool operator <= (const const_vector_iterator<value>& first, const const_vector_iterator<value>& second); //const;
	};
		template <typename value>
		bool operator== (const const_vector_iterator<value>& first,  const const_vector_iterator<value>& second)
		{
			return (first.current == second.current);
		}
		template <typename value>
		bool operator != (const const_vector_iterator<value>& first, const const_vector_iterator<value>& second)
		{
			return (first.current != second.current);
		}
		template <typename value>
		typename const_vector_iterator<value>::difference_type operator- (const const_vector_iterator<value>& first, const const_vector_iterator<value> &n) //const 
		{
			return (first.current - n.current);
		}
		template <typename value>
		typename const_vector_iterator<value>::difference_type operator+ (const const_vector_iterator<value>& first, const const_vector_iterator<value> &n) //const
		{
			return (first.current + n.current);
		}
		template <typename value>
		bool operator>(const const_vector_iterator<value>& first ,const const_vector_iterator<value>& other)// const
		{
			return (first.current > other.current);
		}
		template <typename value>
		bool operator<(const const_vector_iterator<value>& first, const const_vector_iterator<value>& other) //const
		{
			return (first.current < other.current);
		}
		template <typename value>
		bool operator>=(const const_vector_iterator<value>& first, const const_vector_iterator<value>& other) //const
		{
			return (first.current >= other.current);	
		}
		template <typename value>
		bool operator<=(const const_vector_iterator<value>& first, const const_vector_iterator<value>& other) //const
		{
			return (first.current <= other.current);	
		}
}
