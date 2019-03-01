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

#ifndef ERROR_H
# define ERROR_H

#include "libft.h"

# ifndef	DEBUG_MODE
#  define	DEBUG_MODE		TRUE
#  define	WARNING_MODE	TRUE
#  define	ERROR_MODE		TRUE
# endif

#define FT_DEBUG(in_context)		do { if (ERROR_MODE) write(2, in_context, ft_strlen(in_context)); } while (0)
#define FT_WARNING(in_context)		do { if (ERROR_MODE) write(2, in_context, ft_strlen(in_context)); } while (0)
#define FT_ERROR(in_context)		do { if (ERROR_MODE) write(2, in_context, ft_strlen(in_context)); } while (0)

#endif
