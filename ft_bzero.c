/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:45:57 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/25 23:11:45 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)//this is a function that takes a pointer to a memory area (s) and a size (n) as input, and sets the first n bytes of the memory area pointed to by s to zero. It is used to initialize a block of memory to zero, effectively "clearing" it.
//the job of *s is to point to the memory area that we want to set to zero, and n is the number of bytes we want to set to zero. The function uses a while loop to iterate through the memory area, setting each byte to zero until it has set n bytes.
//and the job of size_t is to represent the size of the memory area in bytes, and it is an unsigned integer type that can represent the size of any object in bytes. It is used to specify the number of bytes to be set to zero in the memory area.
{
	
	while (n > 0)
	{
		((unsigned char *)s)[n - 1] = 0;// this line casts the pointer s to an unsigned char pointer, allowing us to treat the memory area as an array of bytes. It then accesses the byte at index n - 1 (the last byte in the range we want to set to zero) and sets it to zero. This effectively clears that byte in the memory area.
		//the job of ((unsigned char *)s) is to cast the pointer s to an unsigned char pointer, allowing us to treat the memory area as an array of bytes. This is necessary because we want to set individual bytes to zero, and using an unsigned char pointer allows us to access each byte directly.
		// and the job of [n - 1] is to access the byte at index n - 1 in the memory area, which is the last byte in the range we want to set to zero. By setting this byte to zero, we effectively clear that byte in the memory area.
		//also the job of = 0 is to assign the value zero to the byte at index n - 1 in the memory area, effectively clearing that byte. This is the main operation of the ft_bzero function, as it sets each byte in the specified range to zero.
		n--;
	}
}

// #include "libft.h"
// void	ft_bzero(void *s, size_t n)
// {
// 	ft_memset(s, 0, n);
// }

#include <stdio.h>
int main(void)
{
	 char str[14] = "Hello, World!";
	// printf("Before ft_bzero: %s\n", str);
	ft_bzero(str, 1);
	printf("After ft_bzero: %d %d\n", (unsigned char)str[0],(unsigned char)str[1]);
	// printf("After ft_bzero: %s\n", str);
	return (0);
}

