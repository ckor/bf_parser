#ifndef					H_FT_LIB
# define				H_FT_LIB

# include <unistd.h>

# define				SUCCESS				false
# define				FAILURE				true

typedef enum
{
	false,
	true
}						t_bool;

void					ft_putchar(char c);
void					ft_putstr(char *str);
void					ft_puterr(char *str);
void					ft_putnbr(int nbr);
void					*ft_memcpy(void *m1, const void *m2, size_t size);

#endif
