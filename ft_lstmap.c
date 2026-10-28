#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*add_one(void *content)
{
	int	*result;

	result = malloc(sizeof(int));
	if (!result)
		return (NULL);
	*result = *(int *)content + 1;
	return (result);
}

int	main(void)
{
	t_list	*head;
	t_list	*mapped;
	t_list	*second;
	t_list	*tmp;
	int		a;
	int		b;

	a = 5;
	b = 10;
	head = ft_lstnew(&a);
	second = ft_lstnew(&b);
	if (!head || !second)
	{
		free(head);
		free(second);
		return (1);
	}
	head->next = second;
	mapped = ft_lstmap(head, add_one, free);
	if (!mapped)
	{
		printf("ERROR: ft_lstmap returned NULL\n");
		free(second);
		free(head);
		return (1);
	}
	printf("Original list: ");
	tmp = head;
	while (tmp)
	{
		printf("%d ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("\nNew list: ");
	tmp = mapped;
	while (tmp)
	{
		printf("%d ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	ft_lstclear(&mapped, free);
	free(second);
	free(head);
	return (0);
}


// #include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_list;
// 	t_list	*node;
// 	void	*content;

// 	if (!f || !del)
// 		return (NULL);
// 	new_list = NULL;
// 	while (lst)
// 	{
// 		content = f(lst->content);
// 		node = ft_lstnew(content);
// 		if (!node)
// 		{
// 			del(content);
// 			ft_lstclear(&new_list, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&new_list, node);
// 		lst = lst->next;
// 	}
// 	return (new_list);
// }
