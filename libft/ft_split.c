/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:09:56 by asaadeh           #+#    #+#             */
/*   Updated: 2024/09/03 16:23:46 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(char *s, int c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*s)
	{
		if (*s == c)
			i = 0;
		else if (i == 0)
		{
			count++;
			i = 1;
		}
		s++;
	}
	return (count);
}

static char	**ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**ptr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	count = 0;
	ptr = malloc((sizeof(char *) * (count_w((char *)s, c) + 1)));
	if (!ptr)
		return (NULL);
	while (count < count_w((char *)s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while ((s[i] != c) && s[i])
			i++;
		ptr[count] = ft_substr(s, j, i - j);
		if (!ptr[count])
			return (ft_free(ptr));
		count++;
	}
	ptr[count] = NULL;
	return (ptr);
}
// int	main(void)
// {
// 	char 	**ptr = ft_split("ahm ad saa eh",' ');
// 	int	i;
// 	i = 0;
// 	while (ptr[i])
// 	{
// 		printf("%s\n", ptr[i]);
// 		i++;
// 	}
// }