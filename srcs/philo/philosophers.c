/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:00:08 by mfeldman          #+#    #+#             */
/*   Updated: 2023/10/06 01:00:21 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophers(t_data *data)
{
	(void)data;
	printf("oui");
	// init_philo(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_error	error;
	
	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&error, sizeof(t_error));
	data.error = &error;
	parsing(argc, argv, data.error);
	if (!data.error->error_g)
	{
		init_struct_and_argv_value(&data, argv);
		philosophers(&data);
	}
	// free_all(&data);
	return (0);
}
