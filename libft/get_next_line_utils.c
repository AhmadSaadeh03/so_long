/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:28:52 by asaadeh           #+#    #+#             */
/*   Updated: 2024/12/28 16:05:33 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	g_ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*g_ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*ptr;
	size_t	b;
	size_t	a;
	size_t	j;

	b = 0;
	j = 0;
	i = 0;
	a = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	ptr = malloc(sizeof(char) * (a + 1));
	if (!ptr)
		return (NULL);
	while (s1[j])
		ptr[b++] = s1[j++];
	while (b < a)
	{
		ptr[b] = s2[i];
		i++;
		b++;
	}
	ptr[b] = '\0';
	return (ptr);
}

char	*g_ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (1)
	{
		if (str[i] == (char)c)
			return (str + i);
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
}

char	*g_ft_strdup(const char *s, int i)
{
	int		j;
	char	*ptr;
	char	*src;

	src = (char *)s;
	j = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(src) - i + 1));
	if (!ptr)
		return (NULL);
	while (src[i] != '\0')
	{
		ptr[j] = src[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
