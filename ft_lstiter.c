/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdulrahmanhussein <abdulrahmanhussein@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:55:54 by abdulrahman       #+#    #+#             */
/*   Updated: 2026/10/28 17:41:54 by abdulrahman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void ft_lstiter(t_list *lst, void(f)(void *))
{
	if (!lst || !f)
	return ;

	while (lst)
	{
		f(lst->content);
		lst = lst->content;
	}
	
	
}

#include <stdio.h>

void	to_upper(void *content)
{
	char	*s;
	int		i;

	s = (char *)content;
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
}

int	main(void)
{
	t_list	*head;
	char	word[] = "hello";

	head = ft_lstnew(word);
	if (!head)
		return (1);
	ft_lstiter(head, to_upper);
	printf("%s\n", word);
	free(head);
	return (0);
}

// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	if (!f)
// 		return ;
// 	while (lst)
// 	{
// 		f(lst->content);
// 		lst = lst->next;
// 	}
// }
