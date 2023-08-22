/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:26:42 by jdaly             #+#    #+#             */
/*   Updated: 2023/08/22 21:39:42 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t    ft_strlen(const char *a)
{
    int    i;

    i = 0;
    while (a[i])
        i++;
    return (i);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t  src_size;
    size_t  i;

    src_size = ft_strlen(src);
    i = 0;
    if (dstsize != 0)
    {
        while (src[i] && i < dstsize - 1)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (src_size);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char            *new;

    if (!s)
        return (0);
    if (ft_strlen(s) < start)
        len = 0;
    if (ft_strlen(s + start) < len)
        len = ft_strlen(s + start);
    new = (char *)malloc(len + 1);
    if (!new)
        return (0);
    ft_strlcpy(new, s + start, len + 1);
    return (new);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	if (i > dstsize || dstsize == 0)
		return (dstsize + ft_strlen(src));
	j = 0;
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len + 1);
	ft_strlcat(str, s2, len + 1);
	return (str);
}

int ft_strcmp(const char *str1, const char *str2)
{
unsigned int i;

i = 0;
while (str1[i] || str2[i])
{
    if (str1[i] != str2[i])
    {
        return ((unsigned char)str1[i] - (unsigned char)str2[i]);
    }
    i++;
}
return (0);
}

void expand_vars(char *str)
{
    int	start = 0;
    int	i = 0;
    int j = 0;
    char *bgn;
    char *strcpy;
    char *varname;

    // printf("i = %d\n", i);


    while (str[i]) //double
    {
        if (str[0] == 39)
        {
            // exit
        }

        if (str[i] == '$' && str[i+1] != ' ' && str[i+1])
        {
            // str[i] = '#';
            i++;
            j = 0;
            bgn = ft_substr(str, 0, i - 1);
            printf("bgn = %s\n", bgn);
            while(str[i] != '$' && str[i] != ' ' && str[i])
            {
                j++;
                i++;
            }
        }
        //save variable name
        //join beginning of string and variable value and 
        //printf("j is %d\n", j);
        if (j > 0)
        { 
            ft_strlcpy(varname, &str[i - j], j + 1);
            printf("varname = %s\n", varname);
            strcpy = ft_strjoin(bgn, "variablevalue");
            printf("strcpy = %s\n", strcpy);
            str = ft_strjoin(strcpy, &str[i + j]);
            printf("str = %s\n", str);
        }   
        j = 0;
        i++;
    }
}

int main(void)
{

    char    *str = "hello $var1 the $end";
    // char    *str = "$var1 string";
    // char    *str = "$var1 string";

    expand_vars(str);
}
