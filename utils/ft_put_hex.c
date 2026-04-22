/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:52:43 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/22 13:27:50 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/ft_printf.h"

size_t	ft_put_hex(unsigned int n, char *base)
{
	size_t	res;

	res = 0;
	if (n >= 16)
		res += ft_put_hex(n / 16, base);
	res += ft_putchar_fd(base[n % 16], 1);
	return (res);
}
