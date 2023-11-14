/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:19:07 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/11 17:37:03 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parsing_msg_error(t_error *error)
{
	ft_putstr_fd("Error", 1);
	if (error->error_g & ERROR_ARG)
		ft_putstr_fd("-Incorrect number of arguments", 1);
	if (error->error_g & ERROR_INT)
		ft_putstr_fd("-One or more arguments are not int", 1);
	if (error->error_g & ERROR_INT2)
		ft_putstr_fd("-Negativ int ", 1);
	if (error->error_g & ERROR_INT3)
		ft_putstr_fd("-Wrong number of philosophers", 1);
}

void	ft_check_max_and_neg(char *argv, t_error *error) 
{
	uint8_t		i;
	long		res;
	uint8_t		pos;

	i = 0;
	res = 0;
	pos = 1;
	if (argv[i] == '-')
	{
		error->error_g |= ERROR_INT2;
		return ;
	}
	while (argv[i])
	{
		res = res * 10 + (argv[i] - 48);
		i++;
	}
	res = res * pos;
	if (res > 200 || res < 0)
		error->error_g |= ERROR_INT3;
}

int	ft_isdigitc(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	check_digit(char **argv, t_error *error)
{
	uint8_t	i;
	uint8_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '+' || argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigitc(argv[i][j]) == 0)
				error->error_g |= ERROR_INT;
			j++;
		}
		ft_check_max_and_neg(argv[i], error);
		i++;
	}
}

int	parsing(int argc, char **argv, t_error *error)
{
	if (argc != 5 && argc != 6)
		error->error_g |= ERROR_ARG;
	check_digit(argv, error);
	if (error->error_g)
		return(parsing_msg_error(error), 1);
	return(0);
}
