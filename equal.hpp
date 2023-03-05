/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:40:23 by ahamdy            #+#    #+#             */
/*   Updated: 2023/03/05 14:31:17 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// template <class InputIterator1, class InputIterator2>
//   bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
// {
// 	std::cout << "pardonaa\n";
// 	std::cout << first2[0] << std::endl;
// 	std::cout << "pardonaa\n";
// 	std::cout << last1[0] << std::endl;
//   while (first1!=last1) {
//     if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
//       return false;
//     ++first1; ++first2;
//   }
//   return true;
// }

// template <class InputIterator1, class InputIterator2, class BinaryPredicate>  
// 	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
// {
//   while (first1!=last1) {
//     if (!(pred(*first1, *first2)))   // or: if (!pred(*first1,*first2)), for version 2
//       return false;
//     ++first1; ++first2;
//   }
//   return true;
// }	