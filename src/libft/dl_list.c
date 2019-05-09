#include <stdio.h>
#include "dl_list.h"

t_dl_list				*dl_list_new(void *dat, size_t d_t)
{
	t_dl_list			*head;

	if ((head = malloc(sizeof(t_dl_list))) != NULL)
	{
		if ((head->data = malloc(d_t)) != NULL)
		{
			head->next = NULL;
			head->prev = NULL;
			head->data = ft_memcpy(head->data, dat, d_t);
			head->d_size = d_t;
		}
		else
		{
			free(head);
			head = NULL;
		}
	}
	return (head);
}

void					dl_list_delete(t_dl_list **head)
{
	if (!head)
		return ;
	while (*head != NULL)
		dl_list_poplast(head);
	free(head);
}
/*
void					dl_list_poplast(t_dl_list **head)
{
	*/
	/*
	char				*c;
	*/
	/*
	t_dl_list			*cur;

	if (head && *head)
	{
		cur = *head;
		*/
		/*
		if (cur->d_size == sizeof(char))
		{
			c = (char *)cur->data;
			ft_putchar(*c);
		}
		*/
		/*
		ft_putstr("\ncode: ");
		dl_list_puts(cur);
		ft_putchar('\n');
		ft_putstr(" :-( ");
		*/
		/*
		if (!(cur->next))
		{
			*head = NULL;
			head = NULL;
			return ;
		}
		while (cur && cur->next)
		{
			cur = cur->next;
		}
		if (cur->prev)
			cur->prev->next = NULL;
		if (cur)
		{
			if (cur->data)
			{
				*/
				/*---------------- SEGFAULT -----------------*/
				/*
				free(cur->data);
				*/
				/*---------------- SEGFAULT -----------------*/
				/*
				cur->data = NULL;
			}
			cur->next = NULL;
			cur->prev = NULL;
			free(cur);
			cur = NULL;
		}
	}
	else
		head = NULL;
}
*/

void					dl_list_poplast(t_dl_list **head)
{
	t_dl_list			*cur;

	if (head && (*head))
	{
		cur = *head;
		/*
		if ((*head)->next)
		{
		*/
		if (*head == NULL)
			return ;
		if ((*head)->next == NULL)
		{
			ft_putstr("#");
			if ((*head)->data)
			{
				free((*head)->data);
				(*head)->data = NULL;
			}
			
			printf("%p ", (void*)*head);
			
			if (head && (*head))
				free(*head);
			*head = NULL;
			return ;
		}
			while (cur && cur->next)
			{
				cur = cur->next;
			}
			/*
			if ((*head)->next->prev)
				(*head)->next->prev = NULL;
				*/
			if (cur)
			{
				if (cur->data)
				{
					free(cur->data);
					cur->data = NULL;
				}
				if (cur->prev && cur->prev->next)
					cur->prev->next = NULL;
				/*
				*head = (*head)->next;
				free((*head)->prev);
				*/
			}
		/*
		}
		else if (cur)
		{
			if (cur->data)
				free(cur->data);
			free(cur);
			*head = NULL;
		}
		*/
	}
	else
	{
		head = NULL;
	}
}

void					dl_list_popfirst(t_dl_list **head)
{
	if (head && *head)
	{
		if ((*head)->next)
		{
			if ((*head)->next->prev)
				(*head)->next->prev = NULL;
			if (*head)
			{
				if ((*head)->data)
				{
					free((*head)->data);
					(*head)->data = NULL;
				}
				*head = (*head)->next;
				free((*head)->prev);
			}
		}
		else
		{
			free((*head)->data);
			free(*head);
			*head = NULL;
		}
	}
	else
		head = NULL;
}

t_dl_list				*dl_list_new_node(t_dl_list *prv, void *dat, size_t d_t)
{
	t_dl_list			*node;

	if ((node = malloc(sizeof(t_dl_list))) != NULL)
	{
		if ((node->data = malloc(d_t)) != NULL)
		{
			node->data = ft_memcpy(node->data, dat, d_t);
			node->d_size = d_t;
			node->prev = prv;
			node->next = NULL;
		}
		else
		{
			free(node);
			node = NULL;
		}
	}
	return (node);
}

t_bool					dl_list_pushback(t_dl_list *head, void *dat, size_t d_t)
{
	t_dl_list			*cur;

	cur = head;
	while (head && cur->next)
		cur = cur->next;
	return ((cur->next = dl_list_new_node(cur, dat, d_t)) != NULL);
}

t_bool					dl_list_pushfront(t_dl_list **head, void *dat, size_t d_t)
{
	t_dl_list			*new_head;

	if ((new_head = dl_list_new_node(NULL, dat, d_t)) == NULL)
		return (FAILURE);
	new_head->next = *head;
	(*head)->prev = new_head;
	*head = new_head;
	return (SUCCESS);
}

t_dl_list				*dl_list_dup(t_dl_list *source)
{
	t_dl_list			*dup;

	dup = NULL;
	if (source && (dup = dl_list_new(source->data, source->d_size)))
		source = source->next;
	while (source && dl_list_pushback(dup, source->data, source->d_size))
		source = source->next;
	return (dup);
}

t_dl_list				*dl_list_from_str(char *str)
{
	t_dl_list			*head;
	long				cur;

	head = NULL;
	cur = 1;
	if (str != NULL && (head = dl_list_new(&(str[0]), sizeof(*str))) != NULL)
	{
		while (str[cur] && dl_list_pushback(head, &(str[cur]), sizeof(*str)))
			++cur;
	}
	return (head);
}

void					dl_list_puts(t_dl_list *head)
{
	long				i;
	t_dl_list			*cur;

	i = 0;
	cur = head;
	while (cur != NULL)
	{
		if (cur->d_size == sizeof(char) && cur->data)
			ft_putchar(*((char *)cur->data));
		cur = cur->next;
		++i;
	}
}
