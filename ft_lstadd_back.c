#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if(!lst || !new)
		return ;

	if(*lst == NULL)
		{
		*lst = new; 
		return ;
	}
	
		t_list *current;
		current = *lst;
		while (current->next != NULL)
		{
			current = current->next;
			


		}

		current->next = new;
		
		
}
// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*head;

// 	head = ft_lstnew("hello");
// 	ft_lstadd_back(&head, ft_lstnew("world"));
// 	printf("First: %s\n", (char *)head->content);
// 	printf("Last: %s\n", (char *)head->next->content);
// 	free(head->next);
// 	free(head);
// 	return (0);
// }
// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*head;

// 	head = NULL;
// 	ft_lstadd_back(&head, ft_lstnew("hello"));
// 	printf("%p\n", head->content);
// 	return (0);
// }























// {
// 	if (!lst || !new)
// 		return ;
// 	if (!*lst)
// 		*lst = new;
// 	else
// 		ft_lstlast(*lst)->next = new;
// }
