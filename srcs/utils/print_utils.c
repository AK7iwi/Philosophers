/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:39:59 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/21 21:49:39 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(1, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	b;

	b = n;
	if (b < 0)
	{
		ft_putchar_fd('-', fd);
		b *= -1;
	}
	if (b <= 9)
		ft_putchar_fd('0' + b, fd);
	else if (b > 9)
	{
		ft_putnbr_fd(b / 10, fd);
		ft_putchar_fd('0' + b % 10, fd);
	}
}

void	ft_print(t_philo *philo)
{
	// to cut
	pthread_mutex_lock(&philo->ptr_data->m_print);
	
	if(philo->ptr_status->dead == 1)
	{
		ft_putnbr_fd(get_current_time() - philo->ptr_data->start, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(philo->id, 1);
		ft_putchar_fd(' ', 1);
		ft_putstr_fd("is dead", 1);
	}
	if(philo->ptr_status->sleep == 1)
	{
		ft_putnbr_fd(get_current_time() - philo->ptr_data->start, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(philo->id, 1);
		ft_putchar_fd(' ', 1);
		ft_putstr_fd("is sleeping", 1);
	}
	if(philo->ptr_status->think == 1)
	{
		ft_putnbr_fd(get_current_time() - philo->ptr_data->start, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(philo->id, 1);
		ft_putchar_fd(' ', 1);
		ft_putstr_fd("is thinking", 1);
		ft_putnbr_fd(philo->ptr_data->test, 1);
	}
	if(philo->ptr_status->fork == 1)
	{
		ft_putnbr_fd(get_current_time() - philo->ptr_data->start, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(philo->id, 1);
		ft_putchar_fd(' ', 1);
		ft_putstr_fd("has taken a fork", 1);
	}
	if(philo->ptr_status->eat == 1)
	{
		ft_putnbr_fd(get_current_time() - philo->ptr_data->start, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(philo->id, 1);
		ft_putchar_fd(' ', 1);
		ft_putstr_fd("is eating", 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(philo->ptr_data->test, 1);
	}
	pthread_mutex_unlock(&philo->ptr_data->m_print);
}