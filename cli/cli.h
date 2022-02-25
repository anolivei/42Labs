/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:06:47 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/25 17:21:13 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# define MAX_LINE_LENGTH 40
# define LOG_PATH "../api/api.log"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
** ft_split.c
*/
char	**ft_split(char const *s, char c);
int		count_words(const char *s, char c);
char	*string(const char *s, int init, int end);

/*
** ft_count_lines.c
*/
int		ft_count_lines(void);

#endif
