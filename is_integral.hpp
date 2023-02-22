/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:53:23 by ahamdy            #+#    #+#             */
/*   Updated: 2023/02/19 14:44:04 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<class> struct is_integral_base {
	const bool value = 0;
};

template<> struct is_integral_base<bool>
{
	const bool value = 1;
};
template<> struct is_integral_base<char>
{
	const bool value = 1;
};

template<> struct is_integral_base<wchar_t>
{
	const bool value = 1;
};

template<> struct is_integral_base<short int>
{
	const bool value = 1;
};

template<> struct is_integral_base<int>
{
	const bool value = 1;
};

template<> struct is_integral_base<long int>
{
	const bool value = 1;
};

template<> struct is_integral_base<long long int>
{
	const bool value = 1;
};

template<> struct is_integral_base<long long int>
{
	const bool value = 1;
};

template<> struct is_integral_base<unsigned char>
{
	const bool value = 1;
};

template<> struct is_integral_base<unsigned short int >
{
	const bool value = 1;
};

template<> struct is_integral_base<unsigned int>
{
	const bool value = 1;
};

template<> struct is_integral_base<unsigned long int>
{
	const bool value = 1;
};

template<> struct is_integral_base<unsigned long int>
{
	const bool value = 1;
};

template<> struct is_integral_base<unsigned long long int>
{
	const bool value = 1;
};


template<typename T> struct is_integral: is_integral_base<std::remove_cv_t<T>> {};