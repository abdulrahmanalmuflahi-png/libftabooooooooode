/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 18:54:23 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/18 14:05:11 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// int	ft_isdigit(int c)
// {
// 	return (c >= '0' && c <= '9');
// }
#include "libft.h"

int ft_isdigit (int s)
{
	if (s >= '0' && s <= '9')
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d\n", ft_isdigit('5')); // Output: 1
// 	printf("%d\n", ft_isdigit('a')); // Output: 0
// 	printf("%d\n", ft_isdigit('o')); // Output: 1
// 	return 0;
// }