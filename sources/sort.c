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
#include "error.h"
#include "internal.h"

static t_bool		ft_sort_check(t_stack stack, t_bool bCheck)
{
	int				n;

	if (bCheck && stack.b.tab_endPoint >= 0)
		return (FALSE);
	n = 0;
	while (n < stack.a.tab_endPoint)
	{
		if (stack.a.tab[n] > stack.a.tab[n + 1])
			return (FALSE);
		n = n + 1;
	}
	return (TRUE);
}

static t_bool		ft_sort_rotate(t_stack *stack, t_module module)
{
	if (module.rrr && stack->a.tab_endPoint > 1 && stack->b.tab_endPoint > 1 &&
		stack->a.tab[0] > stack->a.tab[stack->a.tab_endPoint] &&
		stack->b.tab[0] < stack->b.tab[stack->b.tab_endPoint])
		return (ft_reverse_rotate_all(&stack->a, &stack->b, (module.print) ? "rrr\n" : ""));
	if (module.rra && stack->a.tab_endPoint > 1 &&
		stack->a.tab[0] > stack->a.tab[stack->a.tab_endPoint])
		return (ft_reverse_rotate(&stack->a, (module.print) ? "rra\n" : ""));
	if (module.rrb && stack->b.tab_endPoint > 1 &&
		stack->b.tab[0] < stack->b.tab[stack->b.tab_endPoint])
		return (ft_reverse_rotate(&stack->b, (module.print) ? "rrb\n" : ""));

	if (module.rr && stack->a.tab_endPoint > 1 && stack->b.tab_endPoint > 1 &&
		stack->a.tab[0] > stack->a.tab[stack->a.tab_endPoint] &&
		stack->b.tab[0] < stack->b.tab[stack->b.tab_endPoint])
		return (ft_rotate_all(&stack->a, &stack->b, (module.print) ? "rr\n" : ""));
	if (module.ra && stack->a.tab_endPoint > 1 &&
		stack->a.tab[0] > stack->a.tab[stack->a.tab_endPoint])
		return (ft_rotate(&stack->a, (module.print) ? "ra\n" : ""));
	if (module.rb && stack->b.tab_endPoint > 1 &&
		stack->b.tab[0] < stack->b.tab[stack->b.tab_endPoint])
		return (ft_rotate(&stack->b, (module.print) ? "rb\n" : ""));

	return (FALSE);
}

static t_bool 		ft_sort_swap(t_stack *stack, t_module module)
{
	if (module.ss && stack->a.tab_endPoint >= 1 && stack->b.tab_endPoint >= 1 &&
		stack->a.tab[0] > stack->a.tab[1] && stack->b.tab[0] < stack->b.tab[1])
		return (ft_swap_all(&stack->a, &stack->b, (module.print) ? "ss\n" : ""));
	if (module.sa && stack->a.tab_endPoint >= 1 &&
		stack->a.tab[0] > stack->a.tab[1])
		return (ft_swap(&stack->a, (module.print) ? "sa\n" : ""));
	if (module.sb && stack->b.tab_endPoint >= 1 &&
		stack->b.tab[0] < stack->b.tab[1])
		return (ft_swap(&stack->b, (module.print) ? "sb\n" : ""));
	return (FALSE);
}

static t_bool		ft_sort_push(t_stack *stack, t_module module)
{
	if (module.pa && module.pb && stack->a.tab_endPoint >= 0 &&
		!ft_sort_check(*stack, FALSE))
		return (ft_push(&stack->b, &stack->a, (module.print) ? "pb\n" : ""));
	if (module.pa && stack->b.tab_endPoint >= 0)
		return (ft_push(&stack->a, &stack->b, (module.print) ? "pa\n" : ""));
	return (FALSE);
}

extern t_bool		ft_sort(t_stack stack, t_module module)
{
	t_bool			doSomething;

	doSomething = TRUE;
	while (doSomething)
	{
		if (!(doSomething = ft_sort_rotate(&stack, module)))
		{
			if (!(doSomething = ft_sort_swap(&stack, module)))
			{
				doSomething = ft_sort_push(&stack, module);
			}
		}
	}

	if (!ft_sort_check(stack, TRUE))
		return (FALSE);
	return (TRUE);
}