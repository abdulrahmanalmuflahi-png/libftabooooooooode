/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:33:09 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/19 02:16:55 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *s)// this is a function that takes a pointer to a null-terminated string (s) as input and returns the length of the string as a size_t value. The function uses a pointer (i) to keep track of the starting position of the string, and it iterates through the string until it reaches the null terminator ('\0'). The length of the string is calculated by subtracting the initial pointer (i) from the final pointer (s), which points to the null terminator. This gives us the number of characters in the string, excluding the null terminator.
{
	const char *i;// what is the benefit of using const char *i is to declare a pointer that points to the same type of data as the input string (const char *). This allows us to keep track of the starting position of the string without modifying the original pointer (s). By using a separate pointer (i), we can safely iterate through the string and calculate its length without altering the original pointer, which is important for maintaining the integrity of the input data.

	i = s;
	while (*s)
		s++;
	return (s - i);// we put  s- i to calculate the length of the string by subtracting the initial pointer i from the final pointer s, which points to the null terminator at the end of the string. This gives us the number of characters in the string, excluding the null terminator whay -i is used is to calculate the length of the string by subtracting the initial pointer i from the final pointer s, which points to the null terminator at the end of the string. This gives us the number of characters in the string, excluding the null terminator. The result is returned as a size_t value, which represents the length of the string in bytes.
}

// #include <stdio.h>
// int main(void)
// {
// 	const char *h = "Hello,World!";
// 	printf("Length of '%s' is: %zu\n", h, ft_strlen(h));// what is meaninh of 
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
