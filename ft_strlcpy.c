/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 20:43:19 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/15 10:45:14 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlcpy(char *dst, const char *src, size_t size)

{
	size_t	j;// variable to keep track of the current index in the source string.
	size_t		i;// variable to keep track of the current index in the destination string.
	j = 0;// initialize the index j to 0, which will be used to iterate through the source string.
	while (src[j])// loop through the source string until the null terminator is reached. This loop will count the number of characters in the source string and we use src[j] to access each character in the source string, and the loop continues until we reach the null terminator, which indicates the end of the string.
		j++;// increment j to move to the next character in the source string. This effectively counts the number of characters in the source string, which will be returned as the length of the source string at the end of the function.
	if (size == 0)// check if the size of the destination buffer is zero. If it is, the function returns the length of the source string without copying any characters. This is a safety check to prevent writing to a null pointer or an empty buffer.
		return (j);
	i = 0;// initialize the index i to 0, which will be used to iterate through the destination string.
	while (src[i] && i < size -1)
	{
		dst[i] = src[i];// copy the character from the source string to the destination string at the current index i. This effectively copies the characters from the source string to the destination string, up to size - 1 characters to leave space for the null terminator.
		i++;// increment i to move to the next character in the destination string. This ensures that we copy the correct number of characters from the source string to the destination string.
	}
	dst[i] = '\0';// add a null terminator at the end of the destination string to ensure it is properly terminated. This is important for string handling functions that rely on null-terminated strings.
	return (j);// return the length of the source string, which was calculated earlier. This allows
	
}

#include <stdio.h>
int main(void)
{
	char src[30] = "abrood";
	char dest[30] = "herllo";
	printf("Before ft_strlcpy: %s\n", dest);
	size_t len = ft_strlcpy(dest, src, 10);
	printf("After ft_strlcpy: %s\n", dest);
	printf("Length of copied string: %zu\n", len);
}



// #include "libft.h"

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;

// 	if (size == 0)
// 		return (ft_strlen(src));
// 	i = 0;
// 	while (src[i] && i < size - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (ft_strlen(src));
// }
