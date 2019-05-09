#include "ft_lib.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char *str)
{
	long			len;

	len = 0;
	while (str[len])
		++len;
	write(1, str, len);
}

void				ft_puterr(char *str)
{
	long			len;

	len = 0;
	while (str[len])
		++len;
	write(2, str, len);
}

void				ft_putnbr(int nbr)
{
	unsigned int	n;

	n = (nbr < 0)? ((unsigned int)-nbr) : ((unsigned int)nbr);
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar('0' + (n % 10));
}
