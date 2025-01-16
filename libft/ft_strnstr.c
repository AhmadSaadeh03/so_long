/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:24:13 by asaadeh           #+#    #+#             */
/*   Updated: 2024/08/29 16:36:55 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;

	b = (char *)big;
	l = (char *)little;
	if (!(*little))
	{
		return ((char *)(b));
	}
	while (*b && len > 0)
	{
		if (len < ft_strlen(little))
			return (NULL);
		if (ft_strncmp(b, l, ft_strlen(little)) == 0)
			return ((char *)b);
		len--;
		b++;
	}
	return (NULL);
}
/*int	main(void)
{
	char	big[] = "abcd eye ngg";
		char	little[] = "eye";

	printf("%s",ft_strnstr(big,little, 9));
}*/
