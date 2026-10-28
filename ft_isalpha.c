/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:12:26 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/15 19:12:47 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)// this is a function that takes an integer c as input and checks if it is an alphabetic character (either uppercase or lowercase). It returns 1 if c is an alphabetic character and 0 otherwise. The function uses the ASCII values of characters to determine if c falls within the ranges of uppercase letters ('A' to 'Z') or lowercase letters ('a' to 'z').
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d\n", ft_isalpha('A')); // Output: 1
// 	printf("%d\n", ft_isalpha('4')); // Output: 0
// 	printf("%d\n", ft_isalpha('1')); // Output: 0	
// }