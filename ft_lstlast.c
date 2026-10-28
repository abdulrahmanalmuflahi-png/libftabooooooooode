#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

#include <stdio.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;


	a = ft_lstnew("hello");
	b = ft_lstnew("ddddd");		
	 c = ft_lstnew("uu");

	if (!a || !b )
		return (1);
	a->next = b;
	 b->next = c;
	
	printf("%p\n", ft_lstlast(a)->content);
		
	free(a);
	free(b);
	 free(c);
	return (0);
}
