/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 22:20:08 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/21 17:51:16 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)// the job of *s is to move address
	{
		if (*s == (char)c)// we writ e (char)c to cast the integer c to a character type, allowing us to compare it with the characters in the string s. This is necessary because the function is designed to search for a character in a string, and we want to ensure that the comparison is done between two character types. By casting c to char, we can accurately check if the current character in the string matches the target character c.
			return ((char *)s);// and we put * before s to dereference the pointer and access the character it points to, allowing us to compare it with the target character c. If a match is found, we return a pointer to the first occurrence of the character in the string by casting s to (char *)also we put the * in
		// and we use (char *)s to cast the pointer s to a char pointer, allowing us to return a pointer to the first occurrence of the character in the string. This is necessary because the function is designed to return a pointer to a character in a string, and we want to ensure that the return type matches the expected type.
			s++;
	}
	if ((char)c == '\0')// we put (char)c == '\0' to check if the target character c is the null terminator ('\0'). This is necessary because the function is designed to search for a character in a string, and we want to ensure that we can also find the null terminator if it is present in the string. By checking for the null terminator, we can return a pointer to the end of the string if c is equal to '\0'.
		return ((char *)s);// whay we put return ((char *)s); and write it againg we use it again  becuase we dealing with null trmanital
	return (NULL);
}


// #include <stdio.h>

// int main(void)
// {
//     char *text = "libft";
//     char *result;

//     // سنبحث عن الحرف 'b' داخل كلمة "libft"
//     result = ft_strchr(text, 't');

//     if (result != NULL)
//     {
//         // إذا وجدته، اطبع النص بداية من المكان الذي وجدته فيه
//         printf("وجدت الحرف والنتيجة هي: %s\n", result);
//     }
//     else
//     {
//         printf("الحرف غير موجود!\n");
//     }

//     return (0);
// }