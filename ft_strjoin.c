#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = malloc(l1 + l2 + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, l1);
	ft_memcpy(res + l1, s2, l2 + 1);
	return (res);
}


#include <stdio.h>
#include <stdlib.h>
int main (void)
{
	char *r;

	r = ft_strjoin("Hello ", "world");
	printf("[%s]\n", r);
	free (r);
	return 0;
}
