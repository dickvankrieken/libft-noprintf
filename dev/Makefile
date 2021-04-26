NAME = libftprintf.a

SRCS = srcs/ft_printf.c \
	srcs/pf_checkfunctions.c \
	srcs/putfunctions/pf_putfunctions.c \
	srcs/putfunctions/puts/pf_puts.c \
	srcs/putfunctions/puts/pf_puts_width.c \
	srcs/putfunctions/putd/pf_putd.c \
	srcs/putfunctions/putd/pf_putd_minus.c \
	srcs/putfunctions/putd/pf_putd_zero.c \
	srcs/putfunctions/putp/pf_putp.c \
	srcs/putfunctions/putp/pf_ultohex.c \
	srcs/printspecs.c

C_FLAGS = -Werror -Wextra -Wall

OBJ_FILES = ft_printf.o

HEADER_FILES = includes/ft_printf.h

all: $(NAME)

test:
	$(CC) -g main.c $(SRCS) libft/libft.a
	./a.out

%.o: %.c $(HEADER_FILES)
	$(CC) $(C_FLAGS) -o $@ $^

$(NAME):
	ar

clean:

fclean:

re:

.PHONY:
