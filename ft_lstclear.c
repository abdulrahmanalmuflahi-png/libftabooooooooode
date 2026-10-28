#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;
	if(!lst || !del)
		return ;

	while (*lst)
	{
		current = *lst;
		*lst = current->next;
		del(current->content);
		free(current);
	}
	*lst = NULL;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*head;
// 	char	*p;

// 	p = malloc(1);
// 	if (!p)
// 		return (1);
// 	*p = 'A';
// 	head = ft_lstnew(p);
// 	if (!head)
// 	{
// 		free(p);
// 		return (1);
// 	}
// 	ft_lstclear(&head, free);
// 	printf("%p\n", (void *)head);
// 	return (0);
// }