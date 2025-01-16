/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:57:28 by asaadeh           #+#    #+#             */
/*   Updated: 2024/09/04 15:06:56 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = ft_strdup((char *)s);
	if (!str)
		return (NULL);
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
// char example(unsigned int index, char c)
// {
//     return (c + index); // Simple transformation: shift character by index
// }
// int main(void) {
//         char str[] = "hello, world!";

//     printf("Modified: %s\n", ft_strmapi(str, example));

//     return (0);
// }