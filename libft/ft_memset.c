/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:46:05 by asaadeh           #+#    #+#             */
/*   Updated: 2024/08/26 18:22:09 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)s;
	while (n > 0)
	{
		*b = c;
		b++;
		n--;
	}
	return (s);
}
// int	main(void)
// {
// 	char s[] = "ahmad";
// 	int	c = 'x';
// 	size_t n = 3;
// 	printf("%s",(char  *)ft_memset(s, c, n));
// }
