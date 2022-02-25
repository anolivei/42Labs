/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:06:47 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/25 00:34:45 by anolivei         ###   ########.fr       */
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

int		ft_ulfius(void);
int		callback_delete_movie(const struct _u_request *request,
			struct _u_response *response, void *user_data);
int		callback_set_movie(const struct _u_request *request,
			struct _u_response *response, void *user_data);
int		callback_add_movie(const struct _u_request *request,
			struct _u_response *response, void *user_data);
int		callback_get_movie(const struct _u_request *request,
			struct _u_response *response, void *user_data);
int		callback_get_movie_list(const struct _u_request *request,
			struct _u_response *response, void *user_data);
void	ft_log(char *method, char *path, int status);

#endif