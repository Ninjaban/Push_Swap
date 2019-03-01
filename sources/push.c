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

static void			ft_push_move_down(t_pile *pile)
{
	int				n;

	n = pile->tab_endPoint + 1;
	while (n > 0)
	{
		pile->tab[n] = pile->tab[n - 1];
		n = n - 1;
	}
	pile->tab[n] = 0;
	pile->tab_endPoint++;
}

static void			ft_push_move_up(t_pile *pile)
{
	int				n;

	n = 0;
	while (n < pile->tab_endPoint)
	{
		pile->tab[n] = pile->tab[n + 1];
		n = n + 1;
	}
	pile->tab[n] = 0;
	pile->tab_endPoint--;
}

extern t_bool		ft_push(t_pile *pile1, t_pile *pile2, char *print)
{
	if (pile2->tab_endPoint < 0)
		return (FALSE);
	ft_push_move_down(pile1);
	pile1->tab[0] = pile2->tab[0];
	ft_push_move_up(pile2);
	write(1, print, ft_strlen(print));
	return (TRUE);
}