/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:54:41 by jdaly             #+#    #+#             */
/*   Updated: 2023/08/17 20:09:45 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// lexer analysis
// 1. split and remove whitespace
	/* count words */

int	ft_wordcount(char *str)
{
	int	wordcount = 0;
	int	start = 0;
	int	i = 0;
	int	flag_sq = 0;
	int flag_dq = 0;

	while (str[i])
	{
		while(str[i] && (str[i] == ' ' && str[i+1] == ' '))
		{
			i++;
			if (!flag_sq && !flag_dq)
				start = i;
		}

		if (str[i] == '\'')
		{
			if (!flag_sq)
			{
				flag_sq = 1;
				start = i;
			}
			else
			{
				//str_copy(str, start, i)
				wordcount++;
				flag_sq = 0;
				start = -1;
			}
		}

		if (str[i] == '"')
		{
			if (!flag_dq)
			{
				flag_dq = 1;
				start = i;
			}
			else
			{
				//str_copy(str, start, i)
				wordcount++;
				flag_dq = 0;
				start = -1;
			}
		}

    	if (str[i] == ' ' && !flag_sq && !flag_dq)
   	 	{
        	if (start != -1)
        	{
           		//str_copy(str, start, i-1);
				wordcount++;
            	start = i;
        	}
    	}
    	i++;
	}
	return (wordcount);
}
// static int ft_count_words(const char *s, char *c)
// {
//     int q_single; /*single quote flag*/
//     int q_double; /*double quote flag*/
//     int nwords;  /*number of words*/
// 	int	i;

// 	q_single = 0;
// 	q_double = 0;
// 	nwords = 0;
// 	i = 0;
//     while (s[i] != '\0')
//     {
//         if (!ft_strchr(c, s[i]))
//         {
//             nwords++;

//             while ((!ft_strchr(c, s[i]) || q_single) && s[i] != '\0')
//             {
//                 if (!q_double && (s[i] == '\"' || s[i] == '\''))
//                     q_double = s[i];
//                 q_single = (q_single + (s[i] == q_double)) % 2;
//                 q_double *= q_single != 0;
//                 i++;
//             }

//             if (q_single)
//                 return (-1);
//         }
//         else
//             i++;
//     }

//     return (nwords);
// }


// 2. create tokens

// prompt loop function
int	main(int argc, char *argv[], char *envp[])
{
	// 1. get username
	// 2. get home directory
	// 3. display prompt string and wait for input

	char	*prompt;
	char	*out;
	int		wordcount;
	char	space = ' ';

	out = NULL;
	prompt = "jdaly@minishell$ ";
	while (1)
	{
		out = readline(prompt);
		wordcount = ft_wordcount(out);
		printf("wordcount = %d\n", wordcount);
	}

	


}