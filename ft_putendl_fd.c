#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}


int main(void)
{
	ft_putendl_fd("heelo",1);
		ft_putendl_fd("heelo",1);
			ft_putendl_fd("heelo",1);


}

// #include "libft.h"

// void	ft_putendl_fd(char *s, int fd)
// {
// 	if (!s)
// 		return ;
// 	ft_putstr_fd(s, fd);
// 	write(fd, "\n", 1);
// }
