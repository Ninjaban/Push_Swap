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

#include "libft.h"
#include "types.h"
#include "internal.h"

extern t_bool		ft_swap(t_pile *pile, char *print)
{
	int			tmp;

	if (pile->tab_endPoint < 1)
		return (FALSE);
	tmp = pile->tab[0];
	pile->tab[0] = pile->tab[1];
	pile->tab[1] = tmp;
	write(1, print, ft_strlen(print));
	return (TRUE);
}

extern t_bool		ft_swap_all(t_pile *a, t_pile *b, char *print)
{
	ft_swap(a, "");
	ft_swap(b, "");
	write(1, print, ft_strlen(print));
	return (TRUE);
}
