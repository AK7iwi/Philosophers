/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:41:14 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/22 14:22:14 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
// # include <stdlib.h>
// # include <fcntl.h>
// # include <stdbool.h>

/* Error code */
# define ERROR_ARG		0x1
# define ERROR_INT		0x2
# define ERROR_INT2		0x4
// # define ERROR_EMPTY			0x8
// # define ERROR_RECT				0x10
// # define ERROR_WALL				0x20
// # define ERROR_POS				0x40
// # define ERROR_EXIT				0x80
// # define ERROR_COL				0x100
// # define ERROR_CHAR				0x200
// # define ERROR_NO_VALID_PATH	0x400

typedef struct s_error
{
	uint8_t	error_g;
}				t_error;

/*Philospohers*/
void	philosophers(void);

/*Utils*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigitc(char c);
void	ft_bzero(void *s, size_t n);

/*Parsing*/
void	parsing_msg_error(t_error *error);
void	parsing(int argc, char **argv, t_error *error);

#endif
