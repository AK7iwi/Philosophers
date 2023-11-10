/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:29:16 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/10 10:55:14 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print(t_data *data)
{
	if(data->philo->eat == 1)
		printf("%ld%d%s", get_current_time() - data->start   , data->philo->id, "is eating");
	else if(data->philo->sleep == 1)
		printf("%ld%d%s", get_current_time() - data->start , data->philo->id, "is sleeping");
	else if(data->philo->think == 1)
		printf("%ld%d%s", get_current_time() - data->start , data->philo->id, "is thinking");
	else if(data->philo->think == 1)
		printf("%ld%d%s", get_current_time() - data->start , data->philo->id, "has taken a fork");
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
