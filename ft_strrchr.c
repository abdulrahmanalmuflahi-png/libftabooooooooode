#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last);
}
#include <stdio.h>

int main(void)
{
	char str[] = "hello";
	char *res;
	res = ft_strrchr(str, 'e');
	printf("%s\n", res);
	return 0;
}