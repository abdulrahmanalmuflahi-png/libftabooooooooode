#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *t;
	const unsigned char *u;
	size_t h;

	t = (const unsigned char *)s1;
	u = (const unsigned char *)s2;
	h = 0;

	while (h < n)
	{
		if (t[h] != u[h])
		return(t[h] - u[h]);
		h++;
	}
	return 0;


}

#include <stdio.h>
int main (void)
{
	printf("%d\n", ft_memcmp("hello", "hetko",5));
	return 0;


}
// {
// 	const unsigned char	*a;
// 	const unsigned char	*b;
// 	size_t				i;

// 	a = (const unsigned char *)s1;
// 	b = (const unsigned char *)s2;
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (a[i] != b[i])
// 			return (a[i] - b[i]);
// 		i++;
// 	}
// 	return (0);
// }
