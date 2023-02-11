/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:55:18 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/10 13:50:47 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/ft_printf.h"
# include <signal.h>

typedef struct s_bitvalue {
	int	bit_counter;
	int	value;
}			t_bitvalue;

int	ft_atoi(const char *str);

#endif