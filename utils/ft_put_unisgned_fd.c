/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unisgned_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:48:04 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/22 13:27:57 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/ft_printf.h"

size_t	ft_put_unsigned_fd(unsigned int n, int fd)
{
	char		res;
	size_t		d;

	res = '0';
	d = 0;
	if (n > 9)
		d += ft_put_unsigned_fd(n / 10, fd);
	res = (n % 10) + '0';
	d += ft_putchar_fd(res, fd);
	return (d);
}
