/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_and_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:45:22 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/23 11:21:55 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	get_start_time(t_vault *data)
{
	gettimeofday(&data->start_time, NULL);
	data->start_time_ms = (data->start_time.tv_sec * 1000)
		+ (data->start_time.tv_usec / 1000);
}

long int	get_actual_time(t_vault *data)
{
	gettimeofday(&data->current_time, NULL);
	return ((data->current_time.tv_sec * 1000)
		+ (data->current_time.tv_usec / 1000));
}

bool	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->death == TRUE)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (false);
}

bool	check_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->food_mutex);
	if (philo->data->nbr_philo_full == philo->data->nbr_philo)
	{
		pthread_mutex_unlock(&philo->data->food_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->food_mutex);
	return (false);
}
