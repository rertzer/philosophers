/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:35:20 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/11 12:10:15 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_exit_kill_all(t_phdata *phdata, pid_t pid)
{
	int	i;

	i = -1;
	while (++i < phdata->nb_of_philo)
	{
		if (phdata->akademia[i] == pid)
			continue ;
		if (-1 == kill(phdata->akademia[i], TERM))
			ph_exit_error(phdata "kill error");
	}
}

void	ph_exit_error(t_phdata *phdata, char *msg)
{
	int	i;
	if (msg)
		ph_utils_errormsg(phdata, msg);
	free(phdata->akademia);
	if (-1 != sem_close(phdata->ware))
		sem_unlink(WARE_NAME);
	if (-1 != sem_close(phdata->table))
		sem_unlink(TABLE_NAME);
	if (-1 != sem_close(phdata->speeking))
		sem_unlink(SPEEKING_NAME);
}