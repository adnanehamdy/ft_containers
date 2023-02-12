/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:40:32 by ahamdy            #+#    #+#             */
/*   Updated: 2023/02/09 15:35:46 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<memory>

namespace ft {
	template<class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&>>
	struct iterator {
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
	typedef Category iterator_category;
	};
}
