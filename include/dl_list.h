#ifndef				H_DL_LIST
# define			H_DL_LIST

# include <stdlib.h>
# include "ft_lib.h"

typedef struct			s_dl_list
{
	struct s_dl_list	*next;
	struct s_dl_list	*prev;
	void				*data;
	size_t				d_size;
}						t_dl_list;

t_dl_list			*dl_list_new(void *dat, size_t d_t);
void				dl_list_delete(t_dl_list **head);
void				dl_list_poplast(t_dl_list **head);
void				dl_list_popfirst(t_dl_list **head);
t_dl_list			*dl_list_new_node(t_dl_list *prv, void *dat, size_t d_t);
t_bool				dl_list_pushback(t_dl_list *head, void *dat, size_t d_t);
t_bool				dl_list_pushfront(t_dl_list **head, void *dat, size_t d_t);
t_dl_list			*dl_list_dup(t_dl_list *source);
t_dl_list			*dl_list_from_str(char *str);
void				dl_list_puts(t_dl_list *head);

#endif
