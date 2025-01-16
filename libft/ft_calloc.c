/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:09:08 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/15 16:52:24 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	sum;

	sum = nmemb * size;
	p = malloc(sum);
	if (!p)
		return (NULL);
	else
		ft_bzero(p, sum);
	return (p);
}
/*int     main()
{
		//printf("%p",ft_calloc(6, 3));

		printf("%p",calloc(9, 2));
}*/
