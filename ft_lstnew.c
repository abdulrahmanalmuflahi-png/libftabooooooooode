/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:40:08 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/27 17:37:01 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *new;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);

		new->content = content;
		new->next = NULL;
		return (new);
		
}

// #include <stdio.h>

// int main (void)
// {
// 	t_list *nod;
// 	nod = ft_lstnew("abood");
// 	printf("%p\n",nod->content);
// 	free(nod);
// 	return 0;
// }