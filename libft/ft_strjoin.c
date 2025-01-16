/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:06:13 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 16:54:17 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
// int	main(void)
// {
// 	char	* s1 = "aahmad";
// 	char	*s2 = "saadeh";
// 	printf("%s",ft_strjoin(s1,s2));
// }
