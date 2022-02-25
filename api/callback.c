/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:40:20 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/25 10:55:00 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "api.h"

int	callback_get_movie_list(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	ft_log("GET", "/", 200);
	ulfius_set_json_body_response(response, 200, (json_t *)user_data);
	return (U_CALLBACK_CONTINUE);
}

int	callback_get_movie(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	json_t	*j_movie;
	size_t	index;
	int		found;

	found = 0;
	json_array_foreach((json_t *)user_data, index, j_movie)
	{
		if (0 == o_strcmp(u_map_get(request->map_url, "id"),
			json_string_value(json_object_get(j_movie, "ID"))))
		{
			ulfius_set_json_body_response(response, 200, j_movie);
			found = 1;
			ft_log("GET", "/:id", 200);
		}
	}
	if (!found)
	{
		response->status = 404;
		ft_log("GET", "/:id", 404);
	}
	return (U_CALLBACK_CONTINUE);
}

int	callback_post_movie(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	ft_log("POST", "/", 200);
	json_t *j_movie = ulfius_get_json_body_request(request, NULL);
	json_array_append((json_t *)user_data, j_movie);
	json_decref(j_movie);
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
	j_body = ulfius_get_json_body_request(request, NULL);
	json_array_foreach((json_t *)user_data, index, j_movie)
	{
		if (0 == o_strcmp(u_map_get(request->map_url, "id"),
			json_string_value(json_object_get(j_movie, "ID"))))
		{
			json_array_set((json_t *)user_data, index, j_body);
			found = 1;
			ft_log("PUT", "/:id", 200);
		}
	}
	if (!found)
	{
		response->status = 404;
		ft_log("PUT", "/:id", 404);
	}
	json_decref(j_body);
	return (U_CALLBACK_CONTINUE);
}

int callback_delete_movie(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	json_t	*j_movie;
	size_t	index;
	int		found;

	found = 0;
	json_array_foreach((json_t *)user_data, index, j_movie)
	{
		if (0 == o_strcmp(u_map_get(request->map_url, "id"),
			json_string_value(json_object_get(j_movie, "ID"))))
		{
			json_array_remove((json_t *)user_data, index);
			found = 1;
			ft_log("DELETE", "/:id", 200);
		}
	}
	if (!found)
	{
		response->status = 404;
		ft_log("DELETE", "/:id", 404);
	}
	return (U_CALLBACK_CONTINUE);
}
