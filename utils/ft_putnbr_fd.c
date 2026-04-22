/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:22:46 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/20 10:13:59 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/ft_printf.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	char		res;
	long long	nbr;
	size_t		kk;

	res = '0';
	nbr = n;
	kk = 0;
	if (nbr < 0)
	{
		kk += write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		kk += ft_putnbr_fd(nbr / 10, fd);
	res = (nbr % 10) + '0';
	kk += write (fd, &res, 1);
	return (kk);
}

/*
int	main(void)
{
	ft_putnbr_fd(-99888, 1);
	write (1, "\n", 1);
	return (0);
}*/
