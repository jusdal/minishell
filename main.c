/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:54:41 by jdaly             #+#    #+#             */
/*   Updated: 2023/08/15 20:41:24 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// lexer analysis
// 1. split and remove whitespace
// 2. create tokens

// prompt loop function
int	main(int argc, char *argv[], char *envp[])
{
	// 1. get username
	// 2. get home directory
	// 3. display prompt string and wait for input

	char *prompt;
	char *out;

	out = NULL;
	prompt = "jdaly@minishell$ ";
	while (1)
	{
		out = readline(prompt);
		usleep(10000);
		printf("out = %s\n", out);
	}


}