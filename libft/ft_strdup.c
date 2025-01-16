/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:53:33 by asaadeh           #+#    #+#             */
/*   Updated: 2024/08/30 17:07:34 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*ptr;
	char	*src;

	src = (char *)s;
	i = 0;
	j = 0;
	ptr = malloc((ft_strlen(src) + 1) * sizeof(*ptr));
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
/*int	main(void)
{
	printf("%s", ft_strdup("asdsa"));
}*/
