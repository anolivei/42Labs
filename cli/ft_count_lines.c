/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:52:26 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/26 01:27:51 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

int	ft_count_lines(void)
{
	char	line[MAX_LINE_LENGTH];
	int		num_lines;
	FILE	*file;

	num_lines = 0;
	file = fopen(LOG_PATH, "r");
	if (file == NULL)
	{
		perror("open failed");
		exit(1);
	}
	while (fgets(line, MAX_LINE_LENGTH, file))
	{
		if (strlen(line) > 0)
			num_lines++;
	}
	return (num_lines);
}
