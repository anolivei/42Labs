/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:06:47 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/25 11:06:25 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_H
# define API_H

# define PORT 8080

# include <stdio.h>
# include <jansson.h>
# include <ulfius.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>

/*
** callback.c
*/
int		callback_get_movie_list(const struct _u_request *request,
			struct _u_response *response, void *user_data);
int		callback_get_movie(const struct _u_request *request,
			struct _u_response *response, void *user_data);
int		callback_post_movie(const struct _u_request *request,
			struct _u_response *response, void *user_data);
int		callback_put_movie(const struct _u_request *request,
			struct _u_response *response, void *user_data);
int		callback_delete_movie(const struct _u_request *request,
			struct _u_response *response, void *user_data);

/*
** log.c
*/
void	ft_log(char *method, char *path, int status);

/*
** ulfius.c
*/
int		ft_ulfius(void);
int		ft_ulfius_endpoint(struct _u_instance *instance, json_t *shared_data);

#endif