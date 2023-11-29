/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:19:07 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/29 00:56:16 by mfeldman         ###   ########.fr       */
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
		ft_putstr_fd("-Negativ int or null", 1);
	if (error->error_g & ERROR_INT3)
		ft_putstr_fd("-Wrong number of philosophers", 1);
}

void	ft_check_max_and_neg(char *argv, t_error *error, uint8_t i)
{
	int	res;

	res = ft_atoi(argv);
	if (res <= 0)
		error->error_g |= ERROR_INT2;
	if (res > 200 && i == 1)
		error->error_g |= ERROR_INT3;
}

bool	ft_isdigitc(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
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
			if (ft_isdigitc(argv[i][j]) == 1)
				error->error_g |= ERROR_INT;
			j++;
		}
		ft_check_max_and_neg(argv[i], error, i);
		i++;
	}
}

bool	parsing(int argc, char **argv, t_error *error)
{
	if (argc != 5 && argc != 6)
		error->error_g |= ERROR_ARG;
	check_digit(argv, error);
	if (error->error_g)
		return (parsing_msg_error(error), 1);
	return (0);
}
