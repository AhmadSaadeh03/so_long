/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:20:18 by asaadeh           #+#    #+#             */
/*   Updated: 2024/08/31 10:44:32 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*str;
	size_t	s_len;

	str = (char *)s;
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s_len < start)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (start + len > s_len)
		len = s_len - start;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str + start, len + 1);
	return (ptr);
}
// int     main()
// {
//         char *p = "lorem ipsum dolor sit amet";
//         printf("%s",ft_substr(p, 7, 10));
// }
