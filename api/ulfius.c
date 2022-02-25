/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulfius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:36:27 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/25 00:46:56 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "api.h"

int	ft_ulfius_endpoint(struct _u_instance *instance, json_t *shared_data)
{
	ulfius_add_endpoint_by_val(instance, "GET", "/api", "/movie/", 1,
		&callback_get_movie_list, shared_data);
	ulfius_add_endpoint_by_val(instance, "GET", "/api", "/movie/:id", 1,
		&callback_get_movie, shared_data);
	ulfius_add_endpoint_by_val(instance, "POST", "/api", "/movie/", 1,
		&callback_add_movie, shared_data);
	ulfius_add_endpoint_by_val(instance, "PUT", "/api", "/movie/:id", 1,
		&callback_set_movie, shared_data);
	ulfius_add_endpoint_by_val(instance, "DELETE", "/api", "/movie/:id", 1,
		&callback_delete_movie, shared_data);
}

int	ft_ulfius(void)
{
	struct _u_instance	instance;
	json_t				*shared_data;

	shared_data = json_array();
	if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK)
	{
		fprintf(stderr, "Error ulfius_init_instance, abort\n");
		return (1);
	}
	ft_ulfius_endpoint(&instance, shared_data);
	if (ulfius_start_framework(&instance) == U_OK)
	{
		printf("Start framework on port %d\n", instance.port);
		getchar();
	}
	else
	{
		fprintf(stderr, "Error starting framework\n");
	}
	printf("End framework\n");
	json_decref(shared_data);
	ulfius_stop_framework(&instance);
	ulfius_clean_instance(&instance);
	return (0);
}
