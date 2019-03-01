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

#include "types.h"
#include "internal.h"

static void			ft_init_module(t_module *module)
{
	module->sa = TRUE;
	module->sb = TRUE;
	module->ss = TRUE;
	module->pa = TRUE;
	module->pb = TRUE;
	module->ra = TRUE;
	module->rb = TRUE;
	module->rr = TRUE;
	module->rra = TRUE;
	module->rrb = TRUE;
	module->rrr = TRUE;
	module->print = TRUE;
}

extern t_bool		ft_init(t_stack stack)
{
	t_module		module;

	ft_init_module(&module);
	if (!ft_sort(stack, module))
		return (FALSE);
	return (TRUE);
}