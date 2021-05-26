NAME =		libftprintf.a

#---------------------- DIRECTORIES ------------------#
SRC_DIR =	srcs
HDR_DIR =	includes
OBJ_DIR =	obj
LIBFT_DIR = 	srcs/libft

#---------------------- SOURCES ----------------------#
SRCS =		srcs/ft_printf.c \
		srcs/pf_checkfunctions.c \
		srcs/pf_ultohex.c \
		srcs/pf_putfunctions.c \
		srcs/pf_putc.c \
		srcs/puts/pf_puts.c \
		srcs/putd/pf_putd.c \
		srcs/putd/pf_putd_minus.c \
		srcs/putd/pf_putd_zero.c \
		srcs/pf_putp.c \
		srcs/putu/pf_putu.c \
		srcs/putu/pf_putu_minus.c \
		srcs/putu/pf_putu_zero.c \
		srcs/putx/pf_putx.c \
		srcs/putx/pf_putx_precision.c \
		srcs/putx/pf_putx_minus.c \
		srcs/printspecs.c
#delete		srcs/printspecs.c before submitting

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
