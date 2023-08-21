/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:54:41 by jdaly             #+#    #+#             */
/*   Updated: 2023/08/21 21:09:40 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// lexer analysis
// 1. split and remove whitespace
	/* count words */

int	ft_count_words(char *str)
{
    int	wordcount = 0;
    int	start = 0;
    int	i = 0;
    int	flag_sq = 0;
    int	flag_dq = 0;
    int	flag_rd = 0;

    while (str[i])
    {
        // not skipping many spaces

        if (str[i] == 39 && !flag_dq) // single
        {
            if (!flag_sq)
            {
                flag_sq = 1;
                start = i;
            }
            else
            {
                //str_copy(str, start, i)
                // printf("SQ END ++ \n");

                wordcount++;
                flag_sq = 0;
                start = -1;
            }

        }

        if (str[i] == 34 && !flag_sq) // double
        {
            if (!flag_dq)
            {
                flag_dq = 1;
                start = i;
            }
            else
            {
                // printf("DQ END ++ \n");
                wordcount++;
                flag_dq = 0;
                start = -1;
            }

        }

        if (str[i] && !flag_sq && !flag_dq && str[i] != 34 && str[i] != 39)
        {
            // if not space start reading
            if (!flag_rd && str[i] != ' ')
            {
                // printf("last word start\n");
                flag_rd = 1;
                start = i;
            }
            // reach the end of word - if next one is space or quotes or EOL
            if (flag_rd && (str[i+1] == ' ' || str[i+1] == 34 || str[i+1] == 39 || !str[i+1]))
            {
                // printf("last word end\n");
                wordcount++;
                flag_rd = 0;
            }
        }

        i++;
    }
    if (flag_dq || flag_sq)
        return (-1);
    return (wordcount);
}

char	**ft_create_array(char *str, int wordcount)
{
    char **array;
    int	start = 0;
    int	i = 0;
	int	j = 0;
    int	flag_sq = 0;
    int	flag_dq = 0;
    int	flag_rd = 0;

	array = malloc(sizeof(char *) * (wordcount + 1));
	if (!array)
		return (NULL);
    while (str[i])
    {
        if (str[i] == 39 && !flag_dq) // single
        {
            if (!flag_sq)
            {
                flag_sq = 1;
                start = i;
            }
            else
            {
                array[j++] = strndup(&str[start], i - start + 1);
                flag_sq = 0;
                start = -1;
            }

        }

        if (str[i] == 34 && !flag_sq) // double
        {
            if (!flag_dq)
            {
                flag_dq = 1;
                start = i;
            }
            else
            {
                array[j++] = strndup(&str[start], i - start + 1);
                flag_dq = 0;
                start = -1;
            }

        }

        if (str[i] && !flag_sq && !flag_dq && str[i] != 34 && str[i] != 39)
        {
            // if not space start reading
            if (!flag_rd && str[i] != ' ')
            {
                // printf("last word start\n");
                flag_rd = 1;
                start = i;
            }
            // reach the end of word - if next one is space or quotes or EOL
            if (flag_rd && (str[i+1] == ' ' || str[i+1] == 34 || str[i+1] == 39 || !str[i+1]))
            {
                // printf("last word end\n");
                array[j++] = strndup(&str[start], i - start + 1);
                flag_rd = 0;
            }
        }

        i++;
    }
    return (array);
}

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("array[%d] = %s\n", i, array[i]);
		i++;
	}
}


// 2. create tokens

// prompt loop function
int	main(int argc, char *argv[], char *envp[])
{
	// 1. get username
	// 2. get home directory
	// 3. display prompt string and wait for input

	char	*prompt;
	char	*out;
	char	**array;
	int		wordcount;
	char	space = ' ';

	out = NULL;
	prompt = "jdaly@minishell$ ";
	while (1)
	{
		out = readline(prompt);
		wordcount = ft_count_words(out);
		printf("wordcount = %d\n", wordcount);
		array = ft_create_array(out, wordcount);
		print_array(array);
	}

	


}