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

extern t_bool		ft_rotate(t_pile *pile, char *print)
{
	int				n;
	int				tmp;

	n = 0;
	tmp = pile->tab[n];
	while (n < pile->tab_endPoint)
	{
		pile->tab[n] = pile->tab[n + 1];
		n = n + 1;
	}
	pile->tab[n] = tmp;
	write(1, print, ft_strlen(print));
	return (TRUE);
}

extern t_bool		ft_rotate_all(t_pile *a, t_pile *b, char *print)
{
	ft_rotate(a, "");
	ft_rotate(b, "");
	write(1, print, ft_strlen(print));
	return (TRUE);
}
