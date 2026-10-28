/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 22:24:10 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/28 12:15:06 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	no_del(void *p)
{
	(void)p;
}

#include <stdio.h>
#include <stdlib.h>
char	*make_str(char *text, int len)
{
	char *s;
	int i;

	s = malloc(len + 1);
	i = 0;
	while (i < len )
	{
		s[i] = text[i];
		i++;
	}
	s[i]= '\0';
	return (s);
	
}

int main (void)
{
	t_list *a;
	t_list *b;
	
	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	a->content = make_str("hello", 5);
	b->content = make_str("world", 5);
	a->next = b;	b->next = NULL;
	printf("%s\n", (char *) a->content);
		printf("%s\n", (char *) b->content);
		ft_lstdelone(a, free);
		printf("still %s\n", (char *)b->content);
		ft_lstdelone(b, free);
		return (0);		

	
	
}