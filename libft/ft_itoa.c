/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:48:19 by asaadeh           #+#    #+#             */
/*   Updated: 2024/09/05 17:20:50 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	i_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*zero(void)
{
	char	*ptr;

	ptr = malloc(2);
	if (!ptr)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	long	a;

	a = n;
	len = i_len(a);
	if (n == 0)
		return (zero());
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	if (a < 0)
	{
		ptr[0] = '-';
		a = -a;
	}
	ptr[len] = '\0';
	len--;
	while (a)
	{
		ptr[len--] = (a % 10) + '0';
		a /= 10;
	}
	return (ptr);
}
// int     main()
// {
//         printf("%s",ft_itoa(1221333));
// }
