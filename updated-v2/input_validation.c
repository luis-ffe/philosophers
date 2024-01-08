#include "philo.h"

static int	check_arg_content(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while(str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_validate_args(int argc, char **argv)
{
	static int i;

	if (argc < 5 || argc > 6)
	{
		print_error();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (check_arg_content(argv[i]) == 0)
		{
			print_error();
			return (0);
		}
		i++;
	}
	return (1);
}
