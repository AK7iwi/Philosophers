/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:00:08 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/29 00:34:54 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_check(t_data *data, t_philo *philo)
{
	uint8_t	i;
	
	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if(ft_death(data, philo, i))
				return ;	
			if (max_eat(philo))
				return ;
			i++;
		}
	}
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo*)arg;
	
	if (philo->ptr_data->nb_philo % 2)
	{
		if (philo->id == philo->ptr_data->nb_philo)
			think(philo, (philo->ptr_data->time_to_eat) * 2);
		else if (philo->id % 2)
			think(philo, philo->ptr_data->time_to_eat);
	}
	else
		if(philo->id % 2)
			think(philo, philo->ptr_data->time_to_eat);
	while(!(is_dead(philo)) && !(is_max_eat(philo)))
	{
		if(eat(philo))
			return (NULL);
		if(!(is_dead(philo)) && !(is_max_eat(philo)))
			ft_sleep(philo);
		if(!(is_dead(philo)) && !(is_max_eat(philo)))
			think(philo, 1000);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philo;
	t_error		error;

	ft_bzero(&data, sizeof(t_data));
	philo = NULL;
	ft_bzero(&error, sizeof(t_error));
	data.error = &error;
	parsing(argc, argv, data.error);
	if(data.error->error_g)
		return (0);
	init_struct(&data,argv);
	if(init_mutex(&data))
		return (ft_free(&data, philo), 0);
	if(init_philo(&data, &philo))
		return (ft_free(&data, philo), 0);
	if(init_thread(&data, philo))
		return (ft_free(&data, philo), 0);
	return (ft_free(&data, philo), 0);
}
