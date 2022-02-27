/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:52:26 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/27 00:50:47 by anolivei         ###   ########.fr       */
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

void	free_cli(t_cli *cli)
{
	int	i;

	i = 0;
	while (i < cli->num_lines)
	{
		free(cli->lines[i]);
		i++;
	}
	free(cli->lines);
	free(cli->total_requests);
}
