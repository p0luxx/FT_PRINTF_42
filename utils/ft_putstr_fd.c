/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:16:40 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/11 17:34:14 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/ft_printf.h"

static	char	*ft_return_null(void)
{
	return ("null");
}
size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	res;

	res = 0;
	if (!s)
	{
		ft_return_null();
		return (0);
	}
	res += write (fd, s, ft_strlen(s));
	return (res);
}
