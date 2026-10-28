#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
long num;
	char c;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
	ft_putnbr_fd(num / 10, fd);
	c = (num % 10) + '0';
	write(fd, &c, 1);


}


int main (void)
{
	ft_putnbr_fd(-12345,1);
	return (0);
}
	






// #include "libft.h"

// void	ft_putnbr_fd(int n, int fd)
// {
// 	long	nb;
// 	char	c;

// 	nb = n;
// 	if (nb < 0)
// 	{
// 		write(fd, "-", 1);
// 		nb = -nb;
// 	}
// 	if (nb >= 10)
// 		ft_putnbr_fd((int)(nb / 10), fd);
// 	c = '0' + nb % 10;
// 	write(fd, &c, 1);
// }
