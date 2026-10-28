/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:14:37 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/15 11:51:21 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = 0;
	dlen = 0;
	slen = 0;
	while (src[slen])// loop through the source string until the null terminator is reached. This loop will count the number of characters in the source string and we use src[slen] to access each character in the source string, and the loop continues until we reach the null terminator, which indicates the end of the string.
		slen++;// increment slen to move to the next character in the source string. This effectively counts the number of characters in the source string, which will be used later to calculate the total length of the concatenated string.
	while (dlen < size && dst[dlen])//i did deln < size to make sure we don't go beyond the size of the destination buffer, and dst[dlen] to check if we have reached the null terminator of the destination string. This loop will count the number of characters in the destination string up to the specified size.
		dlen++;
	if (dlen == size)// i did dlen == size to check if we have reached the end of the destination buffer without finding a null terminator. If this is the case, it means that the destination string is not properly null-terminated within the specified size, and we return the total length of the source string plus the size of the destination buffer to indicate that no concatenation was performed.
		return (size + slen);// i did return (size + slen) to return the total length of the source string plus the size of the destination buffer, indicating that no concatenation was performed because the destination string was not properly null-terminated within the specified size.
	while (src[i] && dlen + i + 1 < size)//i didi d dlen + i + 1 < size to ensure that we do not exceed the size of the destination buffer while concatenating the source string. The +1 is to leave space for the null terminator at the end of the concatenated string. This loop will copy characters from the source string to the destination string until we reach the end of the source string or until we have filled the destination buffer up to its specified size.
	//idid src[i] to access each character in the source string, and the loop continues until we reach the null terminator of the source string or until we have filled the destination buffer up to its specified size.
	{
		dst[dlen + i] = src[i];// i did dst[dlen + i] = src[i] to copy the character from the source string at index i to the destination string at index dlen + i. This effectively appends the characters from the source string to the end of the destination string, starting from where the destination string currently ends (dlen).
		i++;
	}
	dst[dlen + i] = '\0';// i did dst[dlen + i] = '\0' to add a null terminator at the end of the concatenated string in the destination buffer. This is important to ensure that the destination string is properly null-terminated after the concatenation, allowing it to be treated as a valid C string.
	return (dlen + slen);// i did return (dlen + slen) to return the total length of the concatenated string, which is the sum of the original length of the destination string (dlen) and the length of the source string (slen). This allows the caller to know the total length of the resulting string after concatenation.
}

#include <stdio.h>
int main(void)
{
	char src[50] = "abdulrahman";
	char dst[50] = "hello";
	printf("Before ft_strlcat: %s\n", dst);
	size_t len = ft_strlcat(dst, src, 50);
	printf("After ft_strlcat: %s\n", dst);
	printf("Length of concatenated string: %zu\n", len);
	return (0);
}



// {
// 	size_t	dlen;
// 	size_t	slen;
// 	size_t	i;

// 	dlen = 0;
// 	slen = ft_strlen(src);
// 	while (dlen < size && dst[dlen])
// 		dlen++;
// 	if (dlen == size)
// 		return (size + slen);
// 	i = 0;
// 	while (src[i] && dlen + i + 1 < size)
// 	{
// 		dst[dlen + i] = src[i];
// 		i++;
// 	}
// 	dst[dlen + i] = '\0';
// 	return (dlen + slen);
// }
