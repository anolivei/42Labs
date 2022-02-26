/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulfius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:36:27 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/26 16:36:25 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "api.h"

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
		fprintf(stderr, "Error starting framework\n");
	printf("End framework\n");
	json_decref(shared_data);
	ulfius_stop_framework(&instance);
	ulfius_clean_instance(&instance);
	return (0);
}

void	ft_ulfius_endpoint(struct _u_instance *instance, json_t *shared_data)
{
	ulfius_set_default_endpoint(instance,
		&callback_dfault, shared_data);
	ulfius_add_endpoint_by_val(instance, "GET", "/", "", 1,
		&callback_get_movie_list, shared_data);
	ulfius_add_endpoint_by_val(instance, "GET", "/", "/:id", 1,
		&callback_get_movie, shared_data);
	ulfius_add_endpoint_by_val(instance, "POST", "/", "", 1,
		&callback_post_movie, shared_data);
	ulfius_add_endpoint_by_val(instance, "PUT", "/", "/:id", 1,
		&callback_put_movie, shared_data);
	ulfius_add_endpoint_by_val(instance, "DELETE", "/", "/:id", 1,
		&callback_delete_movie, shared_data);
}

int	callback_dfault(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	(void)user_data;
	ft_log(request->http_verb, request->http_url, response->status);
	return (U_CALLBACK_CONTINUE);
}
