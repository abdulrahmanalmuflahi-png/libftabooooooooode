/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:50:13 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/15 19:14:09 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isascii(int s)
{
	if (s >= 0 && s <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_isascii(65));
// 	printf("%d\n", ft_isascii(127));
// 	printf("%d\n", ft_isascii(-1));
// 	return 0;
// }

// int	ft_isascii(int c)
// {
// 	return (c >= 0 && c <= 127);
// }
