#include "push_swap.h"

void	check_repeating(t_base *base)
{
	int	i;
	int	j;

	i = -1;
	while (++i < base->size_a) // kontrol ettigimiz sayi teker teker.
	{
		j = i;
		while (++j < base->size_a) // gezdigimiz sayilar.
		{
			// ft_printf("base->a[i] = %d, base->a[j] = %d\n", base->a[i], base->a[j]);
			if (base->a[i] == base->a[j])
				print_error("Error\n", 1);
				// print_error("Error: Repeated number found!", 1);
		}
	}
}

int	ft_isspace(char chr)
{
	if ((chr >= 9 && chr <= 13) || chr == ' ')
		return (1);
	return (0);
}

void	check_number(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		while (ft_isspace(arg[i]))
			i++;
		if (arg[i] == '-' || arg[i] == '+')
			i++;
		// ft_printf("check_number: %c\n", arg[i]);
		if (!ft_isdigit(arg[i]))
			print_error("Error\n", 1);
	}
}

int	is_sorted(int *stack_a, int size, int flag)
{
	int	i;

	i = 0;
	while ((flag == 0) && (++i < size))
	{
		if (stack_a[i - 1] > stack_a[i])
			return (0);
	}
	while ((flag == 1) && (++i < size))
	{
		if (stack_a[i - 1] < stack_a[i])
			return (0);
	}
	return (1);
}

void check_sorted(t_base *base)
{
	int i = -1;
	while (++i < base->size_a - 1)
		if (base->a[i] > base->a[i + 1])
			return ;
	// ft_printf("ZATEN SIRALI ASKO\n");
	exit(0);
}
