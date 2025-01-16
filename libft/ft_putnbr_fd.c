/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:10:08 by asaadeh           #+#    #+#             */
/*   Updated: 2024/09/05 17:11:41 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	a;

	a = n;
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a = -a;
	}
	if (a / 10 != 0)
	{
		ft_putnbr_fd(a / 10, fd);
	}
	ft_putchar_fd(a % 10 + '0', fd);
}
/*int	main(void)
{
	ft_putnbr_fd(123,1);
}*/
