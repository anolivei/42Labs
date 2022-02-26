/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:46:51 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/26 14:44:28 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

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

void	calculate_resume(t_cli *cli)
{
	int	i;
	int	j;

	i = 0;
	while (i < cli->num_lines - 1)
	{
		while (cli->lines[i] == NULL)
			i++;
		cli->total_requests[i] = 1;
		j = i + 1;
		while (j < cli->num_lines)
		{
			if (cli->lines[j] != NULL
				&& strcmp(cli->lines[i], cli->lines[j]) == 0)
			{
				free(cli->lines[j]);
				cli->lines[j] = strdup("0");
				cli->total_requests[i]++;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_cli	cli;
	FILE	*file;
	char	line[MAX_LINE_LENGTH];
	int		i;

	cli.num_lines = count_lines();
	cli.lines = (char **)malloc((cli.num_lines + 1) * sizeof(char *));
	cli.total_requests = malloc((cli.num_lines + 1) * sizeof(int));
	i = 0;
	while (i < cli.num_lines)
	{
		cli.total_requests[i] = 0;
		i++;
	}
	file = open_file();
	i = 0;
	while (fgets(line, MAX_LINE_LENGTH, file))
	{
		cli.lines[i] = strdup(&line[21]);
		i++;
	}
	calculate_resume(&cli);
	print_logs(cli.total_requests, cli.lines);
	free_cli((void *)cli.lines, (void *)cli.total_requests, cli.num_lines);
	return (0);
}
