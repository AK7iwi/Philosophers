/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:56:09 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/10 14:12:37 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print(t_data *data)
{
	if(data->philo->eat == 1)
		printf("%ld%d%s", get_current_time() - data->start , data->philo->id, "is eating");
	else if(data->philo->sleep == 1)
		printf("%ld%d%s", get_current_time() - data->start , data->philo->id, "is sleeping");
	else if(data->philo->think == 1)
		printf("%ld%d%s", get_current_time() - data->start , data->philo->id, "is thinking");
	else if(data->philo->think == 1)
		printf("%ld%d%s", get_current_time() - data->start , data->philo->id, "has taken a fork");
}

void	ft_sleep(t_data *data)
{
	data->philo->sleep = 1;
}

void	ft_eat(t_data *data)
{
	data->philo->eat = 1;
	data->philo->last_meal = get_current_time(); 
	data->philo->nb_meal++;
	// if(data->philo->nb_meal = data->max_eat)
		
}

int	is_dead(t_data *data)
{
	long time;

	time = get_current_time();
	if(time - data->philo->last_meal > data->time_to_die)
		return(1);
	return(0);
}

int is_max_eat(t_data *data)
{
	if(data->philo->nb_meal )
}
