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

#include <stdio.h>

int			ft_itohex(long int nbr, char *bytes, unsigned int size)
{
	long int		res;
	unsigned int	n;

	if (!size || !bytes)
		return (0);
	n = 0;
	while (n < size)
		bytes[n++] = (nbr >= 0) ? '0' : 'f';
	n = size - 1;
	while (nbr)
	{
		res = (nbr > 0) ? nbr % 16 : 15 + (nbr % 16);
		if (n == size - 1 && nbr < 0)
			res += 1;
		bytes[n] = (res < 10) ? res + '0' : res - 10 + 'a';
		nbr = nbr / 16;
		if (n == 0)
			break ;
		n = n - 1;
	}
	return (size);
}