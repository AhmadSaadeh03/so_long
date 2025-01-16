/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:57:49 by asaadeh           #+#    #+#             */
/*   Updated: 2024/09/05 14:58:12 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <ctype.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!(*s))
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
// void to_uppercase(unsigned int , char *c) {
//     *c = *c + 1;
// }
// int main(void) {
//         char str[] = "hello, world!";

//     ft_striteri(str, to_uppercase);

//     printf("Modified: %s\n", str);

//     return (0);
// }