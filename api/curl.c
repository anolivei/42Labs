/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:39:34 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/24 16:56:54 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "api.h"

void	ft_curl(char *word)
{
	FILE				*file;
	struct curl_slist	*chunk;
	CURL				*curl;
	CURLcode			res;
	char				*url_api;

	printf("Searching word...\n");
	file = fopen("word.txt", "wb");
	url_api = ft_strjoin("https://api.dictionaryapi.dev/api/v2/entries/en/",
			word);
	curl = curl_easy_init();
	if (curl)
	{
		chunk = NULL;
		curl_easy_setopt(curl, CURLOPT_URL, url_api);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	fclose(file);
	free(url_api);
}
