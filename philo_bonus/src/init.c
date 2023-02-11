/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:09:29 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/11 10:49:04 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_init_phdata(t_phdata *phdata, int argc, char **argv)
{
	memset(phdata, 0, sizeof(t_phdata));
	phdata->nb_of_philo = ph_parsing_atoi(phdata, argv[1]);
	if (0 == phdata->nb_of_philo)
		ph_exit_error(phdata, "zero philososphe");
	phdata->time_to_die = ph_parsing_atoi(phdata, argv[2]);
	phdata->time_to_eat = ph_parsing_atoi(phdata, argv[3]);
	phdata->time_to_sleep = ph_parsing_atoi(phdata, argv[4]);
	if (6 == argc)
		phdata->must_eat = ph_parsing_atoi(phdata, argv[5]);
	else
		phdata->must_eat = -1;
	phdata->time_to_think = (phdata->time_to_die - \
				(phdata->time_to_eat + phdata->time_to_sleep)) / 2;
	if (phdata->time_to_think < 0)
		phdata->time_to_think = 0;
	phdata->time_start = 0;
	phdata->time_start = ph_clock_timestamp(phdata);
	phdata->ware = ph_semaphore_open(WARE_NAME, phdata->nb_of_philo)
	phdata->table = ph_semaphore_open(TABLE_NAME, 1);
	phdata->speeking = ph_semaphore_open(SPEEKING_NAME, 1);
	ph_init_akademia(phdata);
}

void	ph_init_akademia(t_phdata *phdata)
{
	phdata->akademia = malloc(sizeof(pid_t) * phdata->nb_of_philo);
	if (NULL == phdata->akademia)
		ph_exit_error(phdata, "malloc error");
	memset(phdata->akademia, 0, sizeof(pid_t) * phdata->nb_of_philo);
}

void	ph_init_philo(t_phdata *phdata, t_philo *philo, int i)
{
	philo->number = i + 1;
	philo->must_eat = phdata->must_eat;
	philo->last_meal = ph_clock_timestamp(phdata);
}