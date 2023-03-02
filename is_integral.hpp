/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:53:23 by ahamdy            #+#    #+#             */
/*   Updated: 2023/03/02 08:26:55 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


namespace ft {

	template<class T> struct remove_cv{
		typedef T type;	
	};
	template<class T> struct remove_cv<const T>
	{
		typedef T type;
	};
		
	template<class T> struct remove_cv<volatile T>
	{
		typedef T type;
	};

	template<class T> struct remove_cv<const volatile T>
	{
		typedef T type;
	};

	template<class> struct is_integral_base {
		static const bool value = 0;
	};
	
	template<> struct is_integral_base<bool>
	{
		static const bool value = 1;
	};
	template<> struct is_integral_base<char>
	{
		static const bool value = 1;
	};
	
	template<> struct is_integral_base<wchar_t>
	{
		static const bool value = 1;
	};
	
	template<> struct is_integral_base<short int>
	{
		static const bool value = 1;
	};
	
	template<> struct is_integral_base<int>
	{
		static const bool value = 1;
	};
	
	template<> struct is_integral_base<long int>
	{
		static const bool value = 1;
	};
	
	template<> struct is_integral_base<long long int>
	{
		static const bool value = 1;
	};
	
	template<> struct is_integral_base<unsigned short int >
	{
		static const bool value = 1;
	};
	
	template<> struct is_integral_base<unsigned int>
	{
		static const bool value = 1;
	};
	
	template<> struct is_integral_base<unsigned long int>
	{
		static const bool value = 1;
	};
	
	template<> struct is_integral_base<unsigned long long int>
	{
		static const bool value = 1;
	};
	
	template<typename T> struct is_integral: is_integral_base<typename ft::remove_cv<T>::type > {};
}