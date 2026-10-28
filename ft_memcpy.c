#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)

{
	unsigned char		*d; // pointer to the destination memory area, cast to unsigned char for byte-wise copying and  his  job is to point to the memory area where we want to copy the bytes from the source memory area, and we use unsigned char because it can represent all possible byte values (0 to 255) without any sign issues.
	const unsigned char	*s;// pointer to the source memory area, cast to const unsigned char for byte-wise copying and his job is to point to the memory area from which we want to copy the bytes, and we use const unsigned char because we don't want to modify the source memory area during the copying process, and we use unsigned char because it can represent all possible byte values (0 to 255) without any sign issues.
// and we us the *d and *s to dereference the pointers and access the memory areas they point to, allowing us to copy the bytes from the source to the destination amd we put * before d and s to dereference the pointers and access the memory areas they point to, allowing us to copy the bytes from the source to the destination.
	if (!dst && !src)// Here i use the if statement to check if both dst and src are NULL. If they are, the function returns dst (which is NULL) to avoid dereferencing NULL pointers and causing undefined behavior. This is a safety check to ensure that the function doesn't attempt to copy memory from or to a NULL pointer.
	// and i use the && operator to check if both dst and src are NULL. If either of them is not NULL, the function will proceed to copy the memory from src to dst.
	//also i use the ! operator to check if dst and src are NULL. If they are, the function returns dst (which is NULL) to avoid dereferencing NULL pointers and causing undefined behavior. This is a safety check to ensure that the function doesn't attempt to copy memory from or to a NULL pointer.
		return (dst);
	d = (unsigned char *)dst;// cast the destination pointer to unsigned char and assign it to d. This allows us to treat the destination memory area as an array of bytes what is  the job of (unsigned char *)dst is to cast the destination pointer to unsigned char, allowing us to treat the destination memory area as an array of bytes. This is necessary because we want to copy individual bytes from the source to the destination, and using an unsigned char pointer allows us to access each byte directly and we put * before d to dereference the pointer and access the memory area it points to, allowing us to copy the bytes from the source to the destination.
	s = (const unsigned char *)src;
	while (n--)// loop n times, decrementing n each iteration. This loop will copy n bytes from the source to the destination memory area and we use n-- to decrement n after each iteration, ensuring that we copy exactly n bytes from the source to the destination memory area.
		*d++ = *s++;// copy the byte from the source to the destination and increment both pointers. This effectively copies one byte from the source memory area to the destination memory area and we use *d++ to dereference the destination pointer, copy the byte it points to, and then increment the pointer to point to the next byte in the destination memory area. Similarly, we use *s++ to dereference the source pointer, copy the byte it points to, and then increment the pointer to point to the next byte in the source memory area.
	return (dst);
}

// #include <stdio.h>
// int main(void)
// {
// 	char src[50] = "Hello, World!";
// 	char dst[50];

// 	printf("Before ft_memcpy: %s\n", dst);
// 	ft_memcpy(dst, src, 5);
// 	printf("After ft_memcpy: %s\n", dst);
// 	return (0);
// }
// {
// 	unsigned char		*d;
// 	const unsigned char	*s;
// 	size_t				i;

// 	if (!dst && !src)
// 		return (dst);
// 	d = (unsigned char *)dst;
// 	s = (const unsigned char *)src;
// 	i = 0;
// 	while (i < n)
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	return (dst);
// }
