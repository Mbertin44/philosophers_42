/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:40:54 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/08 13:23:13 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	error_management(t_vault *data)
{
	if (data->error == 1)
		printf("Wrong parameters\n");
	else if (data->error == 2)
		printf("Wrong amount of philosophers\n");
	if (data->error != 0)
		return (false);
	return (true);
}