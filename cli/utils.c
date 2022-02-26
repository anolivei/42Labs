/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:52:26 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/26 14:46:21 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

int	count_lines(void)
{
	char	line[MAX_LINE_LENGTH];
	int		num_lines;
	FILE	*file;

	num_lines = 0;
	file = open_file();
	while (fgets(line, MAX_LINE_LENGTH, file))
	{
		if (strlen(line) > 0)
			num_lines++;
	}
	return (num_lines);
}

FILE	*open_file(void)
{
	FILE	*file;

	file = fopen(LOG_PATH, "r");
	if (file == NULL)
	{
		perror("open failed");
		exit(1);
	}
	return (file);
}

void	free_array(void **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_cli(void **lines, void **total_requests, int num_lines)
{
	int	i;

	i = 0;
	while (i < num_lines)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	free(total_requests);
}
