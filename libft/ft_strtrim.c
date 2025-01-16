/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:04 by asaadeh           #+#    #+#             */
/*   Updated: 2024/09/03 12:27:09 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	*sett;
	int		start;
	int		end;

	s = (char *)s1;
	sett = (char *)set;
	start = 0;
	end = ft_strlen(s1) - 1;
	if (!sett || !s)
		return (NULL);
	while (start <= end && ft_strchr(sett, s[start]))
	{
		start++;
	}
	while (start <= end && ft_strchr(sett, s[end]))
	{
		end--;
	}
	s = ft_substr(s, start, end - start + 1);
	return (s);
}
/*int     main()
{

		printf("%s", ft_strtrim("ahmadah","ah"));
}*/
