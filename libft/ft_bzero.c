/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:22:57 by asaadeh           #+#    #+#             */
/*   Updated: 2024/08/26 19:12:01 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	char	*b;

	b = (char *)s;
	while (n > 0)
	{
		*b = '\0';
		b++;
		n--;
	}
}
/*int	main(void)
{
	char s[] = "ahmadwww";
	printf("%s\n",s);
	ft_bzero(s,2);
	write(1,s,8);
}*/
