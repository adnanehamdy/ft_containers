/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:31:59 by ahamdy            #+#    #+#             */
/*   Updated: 2023/02/24 15:33:03 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
	template<bool Condition, typename T = void>
	struct enable_if
	{
	};
	
	template<typename T>
	struct enable_if<true, T>
	{
	    typedef T type;
	};
}