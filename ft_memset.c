/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:29:52 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/20 22:58:29 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//this s is as link  betwwen us and the system manager to allocate the memory and fill it with the value of c for len bytes
void	*ft_memset(void *b, int c, size_t len)// *b is the pointer to the memory area to be filled and (the address we will start at), c is the value to be set and the request paint, and len is the number of bytes to be set
// and we use len as size_t because it is an unsigned integer type that can represent the size of any object in bytes, and it is used to specify the number of bytes to be set in the memory area.
{
	unsigned char	*p;// pointer to the memory area and we use it to uderstand the memory area as an array of bytes, and we use unsigned char because it can represent all possible byte values (0 to 255) without any sign issues.
	size_t			i;// variable to keep track of the current index in the memory area.

	p = (unsigned char *)b;// cast the input pointer b to an unsigned char pointer and assign it to p. This allows us to treat the memory area as an array of bytes.
	i = 0;// initialize the index i to 0, which will be used to iterate through the memory area.
	while (i < len)// this is a loop that continues until i is less than len, meaning we will fill len bytes of memory.
	{
		p[i] = (unsigned char)c;// set the byte at index i of the memory area pointed to by p to the value of c, cast to an unsigned char. This effectively fills the memory with the specified value.
		i++;//why p[i]//array indxing= //is used instead of *p++ is because we want to access the memory area as an array of bytes, and// p[i] allows us to access the i-th byte directly. Using *p++ would increment the pointer p itself, which is not what we want in this case. We want to keep p pointing to the start of the memory area while we fill it with the value of c for len bytes.
	}
	return (b);// return the original pointer b, which points to the start of the memory area that was filled. This allows the caller to use the modified memory area.
}

// #include <stdio.h>
// int main(void)
// {
// 	char str[50] = "Hello, World!";
// 	printf("Before ft_memset: %s\n", str);
// 	ft_memset(str, 'A', 9);
// 	printf("After ft_memset: %s\n", str);
// 	return (0);
// }
