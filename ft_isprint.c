/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:08:16 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/13 20:12:35 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isprint(int s)
{
	if (s >=32 && s <= 126)
		return (1);
	else
		return (0);
}

	#include <stdio.h>
	int main (void)
	{
		printf("%d\n", ft_isprint('A')); // Output: 1
		printf("%d\n", ft_isprint(' ')); // Output: 1
		printf("%d\n", ft_isprint('\n')); // Output: 0
		printf("%d\n", ft_isprint(9990)); // Output: 0
		return 0;
	}
// int	ft_isprint(int c)
// {
// 	return (c >= 32 && c <= 126);
// }
