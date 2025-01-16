/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:38:59 by asaadeh           #+#    #+#             */
/*   Updated: 2024/08/29 14:28:44 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
/*int	main(void)
{

	printf("%p",ft_strchr("ahmatd", 'z'));
}*/