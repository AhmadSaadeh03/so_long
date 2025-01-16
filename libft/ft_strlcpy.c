/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:29:05 by asaadeh           #+#    #+#             */
/*   Updated: 2024/08/27 17:40:59 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*s;
	size_t	a;

	i = 0;
	s = (char *)src;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (s[i] != '\0' && i < (size - 1))
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	a = ft_strlen(s);
	return (a);
}
/*int	main(void)
{
	char s[]="ahmad";
	char d[6];
	printf("%ld", ft_strlcpy(d,s,6));
}*/