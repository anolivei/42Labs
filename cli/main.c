/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:46:51 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/26 01:19:58 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	free_array(void **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	print_logs(int *total_requests, char **lines)
{
	int		i;
	char	**ret;
	char	status_code[4];

	printf("-------------------------------------------------------------\n");
	printf("|  Total Requests  |  Method  |  Path  |  HTTP Status Code  |\n");
	printf("-------------------------------------------------------------\n");
	i = 0;
	while (total_requests[i] != 0)
	{
		if (strcmp(lines[i], "0") != 0)
		{
			ret = ft_split(lines[i], ' ');
			memcpy(status_code, ret[2], 3);
			status_code[3] = '\0';
			printf("| %16d | %8s | %6s | %18s |\n",
				total_requests[i], ret[0], ret[1], status_code);
			free_array((void *)ret);
		}
		i++;
	}
	printf("-------------------------------------------------------------\n");
}

int	main(void)
{
	char	line[MAX_LINE_LENGTH];
	char	**lines;
	int		num_lines;
	int		i;
	int		j;
	int		*total_requests;
	FILE	*file;

	num_lines = ft_count_lines();
	lines = (char **)malloc((num_lines + 1) * sizeof(char *));
	total_requests = malloc((num_lines + 1) * sizeof(int));
	i = 0;
	while (i < num_lines)
	{
		total_requests[i] = 0;
		i++;
	}
	file = fopen(LOG_PATH, "r");
	if (file == NULL)
	{
		perror("open failed");
		exit(1);
	}
	i = 0;
	while (fgets(line, MAX_LINE_LENGTH, file))
	{
		lines[i] = strdup(&line[21]);
		i++;
	}
	i = 0;
	while (i < num_lines - 1)
	{
		while (lines[i] == NULL)
			i++;
		total_requests[i] = 1;
		j = i + 1;
		while (j < num_lines)
		{
			if (lines[j] != NULL && strcmp(lines[i], lines[j]) == 0)
			{
				free(lines[j]);
				lines[j] = strdup("0");
				total_requests[i]++;
			}
			j++;
		}
		i++;
	}
	print_logs(total_requests, lines);
	i = 0;
	while (i < num_lines)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	free(total_requests);
	return (0);
}
