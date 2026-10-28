/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:22:55 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/22 23:18:02 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int count_len(long n)
{
	int count;
	
	count = 0;
	if (n == 0)
	return 1;
	
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
	
}

char *ft_itoa(int n)
{
	char *str;
	long num;
	int i;
	
	num = n;
	str = malloc(count_len(num) +1);
	if(!str)
	return (NULL);

	i = count_len(num) -1;
	str[count_len(num)] = '\0';
	if(num < 0)
	{
		str[0] = '-';
		num = -num;
		
	}
	if (num == 0)
		str[0] = '0';
		
		while (num > 0)
		{
			str[i] = (num % 10) + '0';
			num = num /10;
			i--;
		}
		return (str);
		
}

#include <stdio.h>
int main (void)
{
	char *result;

result = ft_itoa(123);
	printf("%s\n", result);
	free(result);
	return 0;
}






// #include "libft.h"

// static int	num_len(long n)
// {
// 	int	len;

// 	len = (n <= 0);
// 	while (n)
// 	{
// 		len++;
// 		n /= 10;
// 	}
// 	return (len);
// }

// char	*ft_itoa(int n)
// {
// 	long	nb;
// 	int		len;
// 	char	*s;

// 	nb = n;
// 	len = num_len(nb);
// 	s = malloc(len + 1);
// 	if (!s)
// 		return (NULL);
// 	s[len] = '\0';
// 	if (nb == 0)
// 		s[0] = '0';
// 	if (nb < 0)
// 	{
// 		s[0] = '-';
// 		nb = -nb;
// 	}
// 	while (nb)
// 	{
// 		s[--len] = '0' + nb % 10;
// 		nb /= 10;
// 	}
// 	return (s);
// }
