/* ----------------------------------------------------------------------------+
                                                                               |
    .------..------..------..------..------..------..------..------..------.   |
    |P.--. ||R.--. ||E.--. ||V.--. ||I.--. ||S.--. ||I.--. ||O.--. ||N.--. |   |
    | :/\: || :(): || (\/) || :(): || (\/) || :/\: || (\/) || :/\: || :(): |   :
    | (__) || ()() || :\/: || ()() || :\/: || :\/: || :\/: || :\/: || ()() |
    | '--'P|| '--'R|| '--'E|| '--'V|| '--'I|| '--'S|| '--'I|| '--'O|| '--'N|
:   `------'`------'`------'`------'`------'`------'`------'`------'`------'
|
|    Created by Jonathan Carra.
|    Copyright (c) 2019 Prévision. All rights reserved.
+---------------------------------------------------------------------------- */

#include <unistd.h>

#include "libft.h"
#include "get_next_line.h"
#include "types.h"
#include "error.h"
#include "internal.h"

static void			ft_init_module(t_module *module)
{
	module->sa = FALSE;
	module->sb = FALSE;
	module->ss = FALSE;
	module->pa = FALSE;
	module->pb = FALSE;
	module->ra = FALSE;
	module->rb = FALSE;
	module->rr = FALSE;
	module->rra = FALSE;
	module->rrb = FALSE;
	module->rrr = FALSE;
	module->print = TRUE;
}

static void			ft_init_read_module(t_module *module, char *line)
{
	if (!ft_strncmp(line, "sa", 2))
		module->sa = !module->sa;
	else if (!ft_strncmp(line, "sb", 2))
		module->sb = !module->sb;
	else if (!ft_strncmp(line, "ss", 2))
		module->ss = !module->ss;
	else if (!ft_strncmp(line, "pa", 2))
		module->pa = !module->pa;
	else if (!ft_strncmp(line, "pb", 2))
		module->pb = !module->pb;
	else if (!ft_strncmp(line, "ra", 2))
		module->ra = !module->ra;
	else if (!ft_strncmp(line, "rb", 2))
		module->rb = !module->rb;
	else if (!ft_strncmp(line, "rr", 2))
		module->rr = !module->rr;
	else if (!ft_strncmp(line, "rra", 3))
		module->rra = !module->rra;
	else if (!ft_strncmp(line, "rrb", 3))
		module->rrb = !module->rrb;
	else if (!ft_strncmp(line, "rrr", 3))
		module->rrr = !module->rrr;
	else
		FT_ERROR("Error\n");
}

static void			ft_init_read(t_module *module)
{
	char			*line;

	while (get_next_line(0, &line))
	{
		ft_init_read_module(module, line);
	}
}

extern t_bool		ft_init(t_stack stack)
{
	t_module		module;

	ft_init_module(&module);
	ft_init_read(&module);
	if (!ft_sort(stack, module))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (TRUE);
}