/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:56:09 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/14 20:14:09 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(t_philo *philo)
{
	philo->sleep = 1;
}

void	ft_eat(t_philo *philo)
{
	philo->l_fork = 1;
	philo->eat = 1;
	philo->last_meal = get_current_time(); 
	philo->nb_meal++;
}

void	ft_think(t_philo *philo)
{
	philo->think = 1;
}
