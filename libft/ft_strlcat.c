/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:30:05 by asaadeh           #+#    #+#             */
/*   Updated: 2024/08/28 13:15:05 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;
	size_t	space;
	size_t	j;

	i = 0;
	j = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen((char *)src);
	space = size - ldst - 1;
	if (size <= ldst)
		return (lsrc + size);
	while (dst[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < space)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ldst + lsrc);
}
/*int	main(void)
{
	const char src[] = "abcd";
	char dst[] = "pqrstuvwxyz";
	printf("%ld", ft_strlcat(dst,src,20));
}*/