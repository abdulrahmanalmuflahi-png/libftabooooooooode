#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
#include <stdio.h>

int main(void)
{
    char *result;

    // نبحث عن الحرف 'l' في كلمة "hello"
    // نضع النتيجة في متغير ونحوله إلى char * لكي نفهمه
    result = (char *)ft_memchr("hello", 'l', 5);

    // نستخدم %s لطباعة النص ابتداءً من الحرف الذي وجدناه
    printf("%p\n", result);
    
    return (0);
}
// #include <stdio.h>

// int main (void)
// {
// 	printf("%p\n", ft_memchr("hello", 't', 5));
// 	return 0;
// }
