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

static int	ft_check(const char s, const char *c)
{
	int		n;

	n = 0;
	while (c[n] && c[n] != s)
		n = n + 1;
	return ((c[n]) ? 1 : 0);
}

int			ft_strlchr(const char *s, const char *c)
{
	int		n;

	n = 0;
	if (!s || !c)
		return (-1);
	while (s[n] && ft_check(s[n], c) == 0)
		n = n + 1;
	if (ft_check(s[n], c) == 1)
		return (n);
	return (-1);
}
