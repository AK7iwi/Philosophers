/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:29:16 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/10 22:06:20 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(t_philo *data)
{
	long long	start_time;
	// a modif 
	start_time = ft_get_time();
	while (((ft_get_time() - start_time) * 1000) < data->time_to_sleep
		&& !is_die(data) && !is_max_eat(data))
		usleep(50);
}

long	get_current_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000;
	time += tv.tv_usec / 1000;
	return (time);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(1, "\n", 1);
}

int	ft_atoi(const char *nptr)
{
	size_t		i;
	long long	j;
	int			cont;

	i = 0;
	j = 0;
	cont = 1;
	while (nptr[i] == ' ' || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			cont *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (j * cont > 2147483647)
			return (-1);
		else if (j * cont < -2147483648)
			return (0);
		j = j * 10 + nptr[i] - '0';
		i++;
	}
	return (j * cont);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
}
