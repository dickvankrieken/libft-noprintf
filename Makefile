NAME =		libftprintf.a

#---------------------- DIRECTORIES ------------------#
SRC_DIR =	srcs
HDR_DIR =	includes
OBJ_DIR =	obj
LIBFT_DIR = 	srcs/libft

#---------------------- SOURCES ----------------------#
SRCS =		srcs/ft_printf.c \
		srcs/pf_checkfunctions.c \
		srcs/putfunctions/pf_putfunctions.c \
		srcs/putfunctions/putc/pf_putc.c \
		srcs/putfunctions/puts/pf_puts.c \
		srcs/putfunctions/puts/pf_puts_width.c \
		srcs/putfunctions/puts/pf_puts_minus.c \
		srcs/putfunctions/putd/pf_putd.c \
		srcs/putfunctions/putd/pf_putd_minus.c \
		srcs/putfunctions/putd/pf_putd_zero.c \
		srcs/putfunctions/putp/pf_putp.c \
		srcs/putfunctions/putx/pf_putx.c \
		srcs/pf_ultohex.c \
		srcs/putfunctions/putu/pf_putu.c \
		srcs/putfunctions/putu/pf_putu_minus.c \
		srcs/putfunctions/putu/pf_putu_zero.c \
		srcs/printspecs.c

#---------------------- OBJECTS ----------------------#
OBJS =		$(SRCS:.c=.o)

#---------------------- FLAGS ------------------------#
C_FLAGS =	-Werror -Wextra -Wall

#---------------------- RULES ------------------------#
all: $(NAME)

test: $(NAME)
	$(CC) -g main.c $<
	./a.out

testwithflags:
	$(CC) $(C_FLAGS) -g main.c $(NAME)
	./a.out

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp srcs/libft/libft.a ./$(NAME)
	ar rcs $@ $(OBJS)
	ranlib $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(C_FLAGS) -o $@ $<

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all test testwithflags clean fclean re
