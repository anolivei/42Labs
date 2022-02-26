/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:06:47 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/26 14:45:47 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# define MAX_LINE_LENGTH 40
# define LOG_PATH "../api/api.log"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_cli
{
	int		num_lines;
	int		*total_requests;
	char	**lines;
}			t_cli;

/*
** ft_split.c
*/
char	**ft_split(char const *s, char c);
int		count_words(const char *s, char c);
char	*string(const char *s, int init, int end);

/*
** utils.c
*/
int		count_lines(void);
FILE	*open_file(void);
void	free_array(void **array);
void	free_cli(void **lines, void **total_requests, int num_lines);

#endif
