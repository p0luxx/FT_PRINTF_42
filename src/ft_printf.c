/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:49:06 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/22 17:41:23 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/ft_printf.h"

size_t	ft_format(char type, va_list arg)
{
	size_t	count;

	count = 0;
	if (type == 'd')
		count += ft_putnbr_fd(va_arg(arg, int), 1);
	else if (type == 'c')
		count += ft_putchar_fd((char)va_arg(arg, int), 1);
	else if (type == 'p')
		count += ft_put_pointer(va_arg(arg, void *));
	else if (type == 's')
		count += ft_putstr_fd(va_arg(arg, char *), 1);
	else if (type == 'u')
		count += ft_put_unsigned_fd(va_arg(arg, unsigned int), 1);
	else if (type == 'x')
		count += ft_put_hex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		count += ft_put_hex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (type == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(char const *s, ...)
{
	va_list		arg;
	size_t		i;
	size_t		res;

	va_start(arg, s);
	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			res += ft_format(s[i + 1], arg);
			i++;
		}
		else
			res += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(arg);
	return (res);
}
