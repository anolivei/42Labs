/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:42:31 by anolivei          #+#    #+#             */
/*   Updated: 2022/02/24 12:44:28 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** test.c
** Small Hello World! example
** to compile with gcc, run the following command
** gcc -o test test.c -lulfius
*/
#include <stdio.h>
#include <ulfius.h>

#define PORT 8080

/**
* Callback function for the web application on /helloworld url call
*/
int	callback_hello_world(const struct _u_request *request,
	struct _u_response *response, void *user_data)
{
	ulfius_set_string_body_response(response, 200, "Hello World!");
	return (U_CALLBACK_CONTINUE);
}

/*
** main function
*/
int	main(void)
{
	struct _u_instance	instance;

	if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK)
	{
		fprintf(stderr, "Error ulfius_init_instance, abort\n");
		return (1);
	}
	ulfius_add_endpoint_by_val(&instance, "GET", "/helloworld", NULL, 0,
		&callback_hello_world, NULL);
	if (ulfius_start_framework(&instance) == U_OK)
	{
		printf("Start framework on port %d\n", instance.port);
		getchar();
	}
	else
	{
		fprintf(stderr, "Error starting framework\n");
	}
	printf("End framework\n");
	ulfius_stop_framework(&instance);
	ulfius_clean_instance(&instance);
	return (0);
}
