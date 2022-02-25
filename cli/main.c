/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:46:51 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/25 17:22:47 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	print_logs(int *total_requests, char **lines)
{
	int	i;

	printf("-------------------------------------------------------------\n");
	printf("|  Total Requests  |  Method  |  Path  |  HTTP Status Code  |\n");
	printf("-------------------------------------------------------------\n");
	i = 0;
	while (total_requests[i] !=0 )
	{
		if (strcmp(lines[i],"0") != 0 )
			printf("| %-16d | %s", total_requests[i], lines[i]);
		i++;
	}
	printf("-------------------------------------------------------------\n");
}

int	main(void)
{

	char	line[MAX_LINE_LENGTH] = {0};
	char	**lines;
	int		num_lines;
	int		i;
	int		j;
	int		*total_requests;
	FILE	*file;

	num_lines = ft_count_lines();
	lines = (char**)malloc(num_lines * sizeof(char*) + 1);
	total_requests = malloc(num_lines * sizeof(int) + 1);
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
	while (i < num_lines)
	{
		
		while (lines[i] == NULL)
			i++;
		total_requests[i] = 1;
		j = i + 1;
		while(j <= num_lines)
		{
			if( lines[j] != NULL && strcmp(lines[i],lines[j]) == 0)
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
	free(lines);
	free(total_requests);
	return (0);
}
