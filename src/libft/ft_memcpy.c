#include "ft_lib.h"

void			*ft_memcpy(void *m1, const void *m2, size_t size)
{
	char		*mi_1;
	const char	*mi_2;

	if (!m2)
		return ((void*) 0);
	mi_1 = (char *)m1;
	mi_2 = (const char *)m2;
	while (size > 0)
	{
		*mi_1 = *mi_2;
		--size;
		++mi_1;
		++mi_2;
	}
	return (m1);
}
