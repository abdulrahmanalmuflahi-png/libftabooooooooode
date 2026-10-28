

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;

	while (s[i] != '\0')
{
	write(fd, &s[i], 1);
	i++;
}

}

int main (void)
{
	ft_putstr_fd("aboode", 1);
	return 0;
}


// #include "libft.h"

// void	ft_putstr_fd(char *s, int fd)
// {
// 	if (!s)
// 		return ;
// 	write(fd, s, ft_strlen(s));
// }
