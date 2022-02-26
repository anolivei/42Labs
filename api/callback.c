/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:40:20 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/26 15:36:47 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "api.h"

int	callback_get_movie_list(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	(void)request;
	ulfius_set_json_body_response(response, 200, (json_t *)user_data);
	ft_log("GET", "/", 200);
	return (U_CALLBACK_CONTINUE);
}

int	callback_get_movie(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	json_t	*j_movie;
	size_t	index;
	int		found;

	found = 0;
	index = 0;
	while (index < json_array_size((json_t *)user_data)
		&& (json_array_get((json_t *)user_data, index)))
	{
		j_movie = json_array_get((json_t *)user_data, index);
		if (0 == o_strcmp(u_map_get(request->map_url, "id"),
				json_string_value(json_object_get(j_movie, "id"))))
		{
			ulfius_set_json_body_response(response, 200, j_movie);
			found = 1;
		}
		index++;
	}
	if (!found)
		response->status = 404;
	ft_log("GET", "/:id", response->status);
	return (U_CALLBACK_CONTINUE);
}

int	callback_post_movie(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	json_t	*j_movie;

	(void)response;
	j_movie = ulfius_get_json_body_request(request, NULL);
	json_array_append((json_t *)user_data, j_movie);
	json_decref(j_movie);
	ft_log("POST", "/", 200);
	return (U_CALLBACK_CONTINUE);
}

int	callback_put_movie(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	json_t	*j_movie;
	json_t	*j_body;
	size_t	index;
	int		found;

	found = 0;
	index = 0;
	j_body = ulfius_get_json_body_request(request, NULL);
	while (index < json_array_size((json_t *)user_data)
		&& (json_array_get((json_t *)user_data, index)))
	{
		j_movie = json_array_get((json_t *)user_data, index);
		if (0 == o_strcmp(u_map_get(request->map_url, "id"),
				json_string_value(json_object_get(j_movie, "id"))))
		{
			json_array_set((json_t *)user_data, index, j_body);
			found = 1;
		}
		index++;
	}
	if (!found)
		response->status = 404;
	ft_log("PUT", "/:id", response->status);
	json_decref(j_body);
	return (U_CALLBACK_CONTINUE);
}

int	callback_delete_movie(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	json_t	*j_movie;
	size_t	index;
	int		found;

	found = 0;
	index = 0;
	while (index < json_array_size((json_t *)user_data)
		&& (json_array_get((json_t *)user_data, index)))
	{
		j_movie = json_array_get((json_t *)user_data, index);
		if (0 == o_strcmp(u_map_get(request->map_url, "id"),
				json_string_value(json_object_get(j_movie, "id"))))
		{
			json_array_remove((json_t *)user_data, index);
			found = 1;
		}
		index++;
	}
	if (!found)
		response->status = 404;
	ft_log("DELETE", "/:id", response->status);
	return (U_CALLBACK_CONTINUE);
}
