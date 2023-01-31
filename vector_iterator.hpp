/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:46:44 by ahamdy            #+#    #+#             */
/*   Updated: 2023/01/30 18:53:19 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include<vector.hpp>
#include "iterator_traits.hpp"

template <typename value_type>
class vector_iterator
{
	value_type *_array;

	typedef iterator_traits<value_type>::difference_type differnce_type;
	typedef iterator_traits<value_type>::value_type value_type;
	typedef iterator_traits<value_type>::pointer pointer;
	typedef iterator_traits<value_type>::reference reference;
	typedef iterator_traits<value_type>::iterator_category iterator_category;

	vector_iterator()
	{}

	vector_iterator(vector_iterator& copy)
	{
		copy._array = this->_array;
	}

	vector_iterator& operator=(vector_iterator& copy)
	{
		copy._array = this->_array;
		return (*this);
	}

	
};
