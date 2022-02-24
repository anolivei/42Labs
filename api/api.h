/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:06:47 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/24 16:59:04 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_H
# define API_H

# define _GNU_SOURCE
# define PORT 8080

# include <stdio.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <curl/curl.h>
# include <ulfius.h>

int		ft_ulfius(void);
int		callback_hello_world(const struct _u_request *request,
			struct _u_response *response, void *user_data);
char	*ft_strjoin(char *s1, char *s2);
void	ft_curl(char *word);

#endif