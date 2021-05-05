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
	srcs/putfunctions/putx/pf_putx.c \
	srcs/pf_ultohex.c \
	srcs/printspecs.c

	# srcs/putfunctions/putu/pf_putu.c \
	# srcs/putfunctions/putu/pf_putu_minus.c \
	# srcs/putfunctions/putu/pf_putu_zero.c \

C_FLAGS = -Werror -Wextra -Wall

OBJ_FILES = ft_printf.o

HEADER_FILES = includes/ft_printf.h

all: $(NAME)

test:
	$(CC) $(C_FLAGS) -g main.c $(SRCS) libft/libft.a
	./a.out

%.o: %.c $(HEADER_FILES)
	$(CC) $(C_FLAGS) -o $@ $^

$(NAME):
	ar

clean:

fclean:

re:

.PHONY:
