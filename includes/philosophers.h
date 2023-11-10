/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:41:14 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/10 16:29:37 by mfeldman         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		thread;
	bool			sleep;
	bool			eat;
	bool			think;
	bool			fork;
	bool			dead;
	uint16_t		last_meal;
	uint16_t		nb_meal;
	uint8_t			id;
}				t_philo;

typedef	struct	s_data
{
	t_error			*error;
	t_philo			*philo;
	pthread_mutex_t *fork;
	uint8_t			nb_philo;
	long 			start;
	uint16_t		time_to_die;
	uint16_t		time_to_eat;
	uint16_t		time_to_sleep; 
	uint16_t		max_eat;
	uint32_t			test;
}				t_data;

/*Free*/
void	ft_destroy(t_data *data);

/*Utils*/
void	ft_putstr_fd(char *s, int fd);
long	get_current_time(void);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);

/*Actions*/
void	ft_sleep(t_data *data);
void	ft_eat(t_data *data);
int 	is_max_eat(t_data *data);
int		is_dead(t_data *data);


/*Philospohers*/
void	*ft_routine(void *arg);
void	philosophers(t_data *data, char **argv);

/*Init*/
int		init_thread(t_data *data);
int		init_philo(t_data *data);
int		init_mutex(t_data *data);
void	init_struct_and_argv_value(t_data *data, char **argv);

/*Parsing*/
void	parsing_msg_error(t_error *error);
void	ft_check_max_and_neg(char *argv, t_error *error);
int		ft_isdigitc(char c);
void	check_digit(char **argv, t_error *error);
int		parsing(int argc, char **argv, t_error *error);

#endif
