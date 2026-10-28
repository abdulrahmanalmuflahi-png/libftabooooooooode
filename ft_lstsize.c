#include "libft.h"
#include <stdio.h>
unsigned  int 	ft_lstsize(t_list *lst)
{
	unsigned int	n;

	n = 0;
	while (lst != NULL )
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

int main(void)
{
	t_list *head = NULL;
	t_list *first;
	t_list *second;
	t_list *third;

	first = ft_lstnew("Hello");
	second = ft_lstnew("World");
	third = ft_lstnew("People");
	ft_lstadd_front(&head, third);
	ft_lstadd_front(&head, second);
	ft_lstadd_front(&head, first);
	
	t_list *current;
	current = head;
	int len = ft_lstsize(current);
	printf("%s\n",(char *) current->content);
	current = current->next;

	// while (current)
	// {
	// 	printf("%s\n", (char *)current->content);
	// 	current = current->next;
	// }
}
