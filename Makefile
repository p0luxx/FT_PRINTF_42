# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 12:02:48 by gorkgall          #+#    #+#              #
#    Updated: 2026/04/22 12:07:50 by gorkgall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ══════════════════════════════════════════════
#  ft_printf — Makefile con target de test rápido
# ══════════════════════════════════════════════

NAME		= libftprintf.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

# ── Fuentes ───────────────────────────────────
SRC		= src/ft_printf.c \
		  utils/ft_put_hex.c \
		  utils/ft_put_unisgned_fd.c

OBJ		= $(SRC:.c=.o)

LIBFT		= libft/libft.a

# ── Reglas principales ────────────────────────
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) -I utils -I libft -c $< -o $@

# ── Test rápido ───────────────────────────────
TEST_FILE	= test_main.c

test: $(NAME)
	$(CC) $(CFLAGS) -I utils -I libft test_main.c -L. -lftprintf -o test_printf
	@./test_printf

# ── Limpieza ──────────────────────────────────
clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME) test_printf $(TEST_FILE)

re: fclean all

.PHONY: all clean fclean re test