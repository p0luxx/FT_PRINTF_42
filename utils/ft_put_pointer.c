/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:12:17 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/22 17:47:56 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/ft_printf.h"

static size_t	ft_put_hex_ptr(uintptr_t n, char *base)
{
	size_t	res;

	res = 0;
	if (n >= 16)
		res += ft_put_hex_ptr(n / 16, base);
	res += ft_putchar_fd(base[n % 16], 1);
	return (res);
}

size_t	ft_put_pointer(void *p)
{
	uintptr_t	ptr;
	size_t		res;

	if (!p)
		return("nil")
	ptr = (uintptr_t)p;
	res = 0;
	res += ft_putstr_fd("0x", 1);
	res += ft_put_hex_ptr(ptr, "0123456789abcdef");
	return (res);
}
