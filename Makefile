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
		  utils/ft_put_unisgned_fd.c \
		  utils/ft_putchar_fd.c \
		  utils/ft_putstr_fd.c \
		  utils/ft_putnbr_fd.c \
		  utils/ft_strlen.c

OBJ		= $(SRC:.c=.o)

# ── Reglas principales ────────────────────────
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I utils -c $< -o $@

# ── Limpieza ──────────────────────────────────
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re