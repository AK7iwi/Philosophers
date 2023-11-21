/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:41:14 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/21 21:44:26 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

// # include <stdlib.h>
// # include <fcntl.h>

/* Error code */
# define ERROR_ARG		0x1
# define ERROR_INT		0x2
# define ERROR_INT2		0x4
# define ERROR_INT3		0x8


typedef struct s_error
{
	uint8_t	error_g;
}				t_error;


typedef	struct	s_data
{
	t_error			*error;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_print;
	pthread_mutex_t m_max_eat;
	pthread_mutex_t m_last_meal;
	pthread_mutex_t m_die;
	unsigned long 	start;
	uint8_t			nb_philo;
	uint8_t			died;
	uint16_t		time_to_die;
	uint16_t		time_to_eat;
	uint16_t		time_to_sleep; 
	uint16_t		max_eat;
	pthread_mutex_t	m_test;
	int test;
}				t_data;

typedef struct s_philo
{
	pthread_t		thread;
	uint8_t			id;
	uint16_t		last_meal;
	uint16_t		nb_meal;
	struct s_data	*ptr_data;
	struct s_status	*ptr_status;
}				t_philo;

typedef struct s_status
{
	bool	fork;
	bool	eat;
	bool	sleep;
	bool	think;
	bool	dead;
}				t_status;

/*Free*/

void	ft_free(t_data *data, t_philo *philo);

/*Print Utils*/
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_print(t_philo *philo);

/*Action Utils*/
void			ft_usleep(t_philo *philo, unsigned long time);
unsigned long	get_current_time(void);
int 			is_max_eat(t_philo *philo);
int				is_dead(t_philo *philo);

/*Actions*/
void	ft_died(t_data *data);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_think(t_philo *philo);

/*Init*/
bool	init_thread(t_data *data, t_philo *philo);
bool	init_philo(t_data *data, t_philo **philo, t_status *status);
bool	init_mutex(t_data *data);
void	init_struct(t_data *data, char **argv);

/*Parsing*/
void	parsing_msg_error(t_error *error);
void	ft_check_max_and_neg(char *argv, t_error *error);
int		ft_isdigitc(char c);
void	check_digit(char **argv, t_error *error);
int		parsing(int argc, char **argv, t_error *error);

/*Philosphers utils*/
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);

/*Philospohers*/
void	*ft_routine(void *arg);

#endif
