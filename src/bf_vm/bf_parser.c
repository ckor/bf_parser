#include "bf_vm.h"

t_bf_vm				*bf_vm_new(char *code)
{
	t_bf_vm			*ret;

	if ((ret = malloc(sizeof(t_bf_vm)))!= NULL)
	{
		if ((code && (ret->code = dl_list_from_str(code)) == NULL) ||
		(!code && (ret->code = dl_list_new(NULL, sizeof(char))) == NULL))
		{
			free(ret);
			ret = NULL;
		}
		else if ((ret->memory = dl_list_new(NULL, sizeof(char))) == NULL)
		{
			dl_list_delete(&(ret->code));
			free(ret);
			ret = NULL;
		}
		else
		{
			ret->c_cur = 0;
			ret->m_cur = 0;
		}
	}
	return (ret);
}

void				bf_vm_delete(t_bf_vm *vm)
{
	dl_list_delete(&(vm->code));
	vm->code = NULL;
	dl_list_delete(&(vm->memory));
	vm->memory = NULL;
	free(vm);
}

t_bf_vm				*bf_vm_dup(t_bf_vm *source)
{
	t_bf_vm			*dup;

	dup = NULL;
	if (!source || (dup = bf_vm_new(NULL)) == NULL)
		return (dup);
	if ((dup->memory = dl_list_dup(source->memory)) != NULL)
	{
		if ((dup->code = dl_list_dup(source->code)) != NULL)
		{
			dup->c_cur = source->c_cur;
			dup->m_cur = source->m_cur;
		}
		else
			dl_list_delete(&(dup->memory));
	}
	else
	{
		free(dup);
		dup = NULL;
	}
	return (dup);
}

t_bool				bf_vm_run(void)
{
	return (true);
}

int					main(int ac, char **av)
{
	t_bf_vm			*vm;
	t_dl_list		*code;

	if (ac > 1)
	{
		/*
		code = dl_list_from_str(av[1]);
		dup = dl_list_dup(code);
		dl_list_popfirst(&dup);
		dl_list_poplast(dup);
		dl_list_puts(dup);
		dl_list_delete(&code);
		dl_list_delete(&dup);
		*/

		if ((vm = bf_vm_new(av[1])) == NULL)
			return (FAILURE);
		if ((code = dl_list_dup(vm->code)) == NULL)
			return (FAILURE);
		dl_list_puts(code);
		ft_putchar('\n');
		bf_vm_delete(vm);
		dl_list_puts(code);
		ft_putchar('\n');
		dl_list_delete(&code);
	}
	ft_putchar('\n');
	return (SUCCESS);
}
