/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:00:08 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/26 17:43:59 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophers(t_data *data)
{
	init_philo(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	init_struct_and_argv_value(&data, argv);
	parsing(argc, argv, data.error);
	if (!data.error->error_g)
		philosophers(&data);
	// free_all(&data);
	return (0);
}
