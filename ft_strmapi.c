/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 23:13:03 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/25 00:18:02 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*goal;
	unsigned int	go;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	goal = malloc(len + 1);
	if (!goal)
		return (NULL);
	go = 0;
	while (s[go] != '\0')
	{
		goal[go] = f(go, s[go]);
		go++;
	}
	goal[go] = '\0';
	return (goal);
}


#include <stdio.h>
#include <stdlib.h>
char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c == 'a' || c == 'b')
		return ('*');
	
}

int	main(void)
{
	char	*result;

	result = ft_strmapi("aaabbbbbaaa", to_upper);
	if (!result)
		return (1);
	printf("Result: %s\n", result);
	free(result);
	return (0);
}



//  #include "libft.h"

// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
// {
// 	char			*res;
// 	unsigned int	i;

// 	if (!s || !f)
// 		return (NULL);
// 	res = malloc(ft_strlen(s) + 1);
// 	if (!res)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		res[i] = f(i, s[i]);
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }
