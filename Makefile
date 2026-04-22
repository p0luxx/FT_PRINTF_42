# ══════════════════════════════════════════════
#  ft_printf Makefile
# ══════════════════════════════════════════════

NAME		= libftprintf.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

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
	$(AR) $(NAME) $(OBJ)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) -I utils -I libft -c $< -o $@

# ── Limpieza ──────────────────────────────────
clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re