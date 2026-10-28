#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if (!s || !f)
	return ;
	i = 0;

	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	

}

#include <stdio.h>
#include <stdlib.h>
void _traying(unsigned int i, char *c)
{
	(void)i;
	if (*c == 'a' || *c == 'b')
		*c = '*';
	
}

int	main(void)
{
	char s[50] = "bananana";

		ft_striteri(s, _traying);

	printf("%s\n",s);
	
	
}



// #include "libft.h"

// void	ft_striteri(char *s, void (*f)(unsigned int, char *))
// {
// 	unsigned int	i;

// 	if (!s || !f)
// 		return ;
// 	i = 0;
// 	while (s[i])
// 	{
// 		f(i, &s[i]);
// 		i++;
// 	}
// }
