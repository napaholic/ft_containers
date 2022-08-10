/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:18:27 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/12 14:50:22 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	error_handler(char *err)
{
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
