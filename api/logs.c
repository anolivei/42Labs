/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:20:31 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/25 00:07:11 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "api.h"

void	ft_log(char *method, char *path, int status)
{
	time_t		t;
	struct tm	ttm;

	t = time(NULL);
	ttm = *localtime(&t);
	printf("[%02d-%02d-%02d_%02d:%02d:%02d] %s %s %d\n",
		ttm.tm_year + 1900, ttm.tm_mon + 1, ttm.tm_mday,
		ttm.tm_hour, ttm.tm_min, ttm.tm_sec,
		method, path, status);
}
