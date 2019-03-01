#include "types.h"
#include "error.h"
#include "internal.h"

static t_bool		ft_is_numbers(const int ac, char **av)
{
	t_uint			n;

	if (ac > 1)
	{
		if (!ft_is_numbers(ac - 1, av))
		{
			FT_WARNING("ft_is_numbers() failed\n");
			return (FALSE);
		}
	}
	n = 0;
	while (av[ac][n])
	{
		if (av[ac][n] < '0' || av[ac][n] > '9')
		{
			FT_ERROR("Error\n");
			return (FALSE);
		}
		n = n + 1;
	}
	return (TRUE);
}

static void			ft_parsing_atoi(const int ac, char **av, int **out_tab)
{
	int				n;

	n = ac - 1;
	while (n > 0)
	{
		(*out_tab)[n - 1] = ft_atoi(av[n]);
		n = n - 1;
	}
}

static t_bool		ft_eq_numbers(const int *tab, const t_uint tab_size,
									t_uint i)
{
	t_uint			n;

	if (i < tab_size)
	{
		if (!ft_eq_numbers(tab, tab_size, i + 1))
		{
			FT_WARNING("ft_eq_numbers() failed\n");
			return (FALSE);
		}
	}
	n = 0;
	while (n < tab_size)
	{
		if (n != i && tab[n] == tab[i])
		{
			FT_ERROR("Error\n");
			return (FALSE);
		}
		n = n + 1;
	}
	return (TRUE);
}

static t_bool		ft_parsing(const int ac, char **av)
{
	t_stack			stack;

	if (!ft_is_numbers(ac - 1, av))
	{
		FT_WARNING("ft_is_numbers() failed\n");
		return (FALSE);
	}

	stack.size = (t_uint)ac - 1;
	stack.a.tab_endPoint = stack.size - 1;
	if ((stack.a.tab = malloc(sizeof (int) * stack.size)) == NULL)
	{
		FT_ERROR("Error\n");
		return (FALSE);
	}
	stack.b.tab_endPoint = -1;
	if ((stack.b.tab = malloc(sizeof (int) * stack.size)) == NULL)
	{
		FT_ERROR("Error\n");
		return (FALSE);
	}

	ft_parsing_atoi(ac, av, &stack.a.tab);

	if (!ft_eq_numbers(stack.a.tab, stack.size, 0))
	{
		FT_WARNING("ft_eq_numbers() failed\n");
		return (FALSE);
	}

	if (!ft_init(stack))
	{
		FT_WARNING("ft_init() failed\n");
		return (FALSE);
	}

	free(stack.a.tab);
	free(stack.b.tab);
	return (TRUE);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		FT_ERROR("Error\n");
		return (1);
	}

	if (!ft_parsing(ac, av))
	{
		FT_WARNING("ft_parsing() failed\n");
		return (1);
	}

	return (0);
}