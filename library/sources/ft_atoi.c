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

int		ft_atoi(char *str)
{
	int	nbr;
	int	n;
	int	neg;

	neg = 1;
	n = 0;
	nbr = 0;
	while (str[n] == '\t' || str[n] == '\v' || str[n] == '\f' ||
			str[n] == '\r' || str[n] == '\n' || str[n] == ' ')
		n = n + 1;
	if (str[n] == '-')
	{
		neg = -1;
		n = n + 1;
	}
	else if (str[n] == '+')
		n = n + 1;
	while (str[n] != '\0' && (str[n] >= '0' && str[n] <= '9'))
	{
		nbr = nbr * 10 + (str[n] - '0');
		n = n + 1;
	}
	nbr = nbr * neg;
	return (nbr);
}