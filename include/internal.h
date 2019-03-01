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

#ifndef INTERNAL_H
# define INTERNAL_H

typedef struct		s_pile
{
	int				*tab;
	int				tab_endPoint;
}					t_pile;

typedef struct		s_stack
{
	t_pile			a;
	t_pile			b;
	t_uint			size;
}					t_stack;

typedef struct		s_module
{
	/* ** Swap */
	t_bool			sa;
	t_bool			sb;
	t_bool			ss;

	/* ** Push */
	t_bool			pa;
	t_bool			pb;

	/* ** Rotate */
	t_bool			ra;
	t_bool			rb;
	t_bool			rr;

	/* ** Reverse Rotate */
	t_bool			rra;
	t_bool			rrb;
	t_bool			rrr;

	/* ** Print */
	t_bool			print;
}					t_module;

extern t_bool		ft_init(t_stack stack);
extern t_bool		ft_sort(t_stack stack, t_module module);

/* ** Swap */
extern t_bool		ft_swap(t_pile *pile, char *print);
extern t_bool		ft_swap_all(t_pile *a, t_pile *b, char *print);

/* ** Push */
extern t_bool		ft_push(t_pile *pile1, t_pile *pile2, char *print);

/* ** Rotate */
extern t_bool		ft_rotate(t_pile *pile, char *print);
extern t_bool		ft_rotate_all(t_pile *a, t_pile *b, char *print);

/* ** Reverse Rotate*/
extern t_bool		ft_reverse_rotate(t_pile *pile, char *print);
extern t_bool		ft_reverse_rotate_all(t_pile *a, t_pile *b, char *print);

#endif
