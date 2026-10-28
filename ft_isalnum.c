/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:50:40 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/13 19:50:41 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_isalnum(int c)
// {
// 	return (ft_isalpha(c) || ft_isdigit(c));
// }

int ft_isalnum(int s)
{
	if (ft_isalpha(s) || ft_isdigit(s))
		return (1);
	else
		return (0);
}

#include <stdio.h>
int main (void)
{
	printf("%d\n", ft_isalnum('A')); // Output: 1
	printf("%d\n", ft_isalnum('5')); // Output: 1
	printf("%d\n", ft_isalnum('!')); // Output: 0
	return 0;
}