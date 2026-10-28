#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
	i++;
	}

	if (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
		{
			sign = -1;

		}
		i++;

		

	}
	while (str[i] >=  '0' && str[i] <= '9')
	{
			
		result = (result * 10) + (str[i] - '0');
		i++;
	}	
	return (result * sign);

	

	
}

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char *s = "++42";
	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
}

// #include "libft.h"

// int	ft_atoi(const char *str)
// {
// 	int		sign;
// 	long	res;

// 	sign = 1;
// 	res = 0;
// 	while (*str == ' ' || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			sign = -1;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		res = res * 10 + (*str - '0');
// 		str++;
// 	}
// 	return ((int)(res * sign));
// }
