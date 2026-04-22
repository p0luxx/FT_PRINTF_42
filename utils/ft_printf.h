/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:15:43 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/22 12:45:21 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/libft.h"

int		ft_printf(char const *s, ...);
size_t	ft_put_unsigned_fd(unsigned int n, int fd);
size_t	ft_put_hex(unsigned int n, char *base);

# endif