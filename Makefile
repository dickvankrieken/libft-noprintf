#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kri <dvan-kri@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/27 22:20:58 by dvan-kri      #+#    #+#                  #
#    Updated: 2021/08/01 15:26:43 by dvan-kri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		libftprintf.a

#---------------------- DIRECTORIES ------------------#
HDR_DIR =	includes/
OBJ_DIR =	obj/
PRINTF_DIR =	ft_printf/
LIBFT_DIR = 	libft/
GNL_DIR =	ft_gnl/

#---------------------- SOURCES ----------------------#
SRCS =		ft_printf.c \
		pf_checkfunctions.c \
		pf_checkfunctions_precision.c \
		pf_ultohex.c \
		pf_putfunctions.c \
		pf_putc.c \
		puts/pf_puts.c \
		puts/pf_puts_width.c \
		putd/pf_putd.c \
		putd/pf_putd_minus.c \
		putd/pf_putd_zero.c \
		pf_putp.c \
		putu/pf_putu.c \
		putu/pf_putu_minus.c \
		putu/pf_putu_zero.c \
		putx/pf_putx.c \
		putx/pf_putx_precision.c \
		putx/pf_putx_minus.c \

#---------------------- FILES ------------------------#
FILES =	$(addprefix $(PRINTF_DIR), $(SRCS))

#---------------------- OBJECTS ----------------------#
OBJS =		$(FILES:.c=.o)

#---------------------- FLAGS ------------------------#
C_FLAGS =	-Werror -Wextra -Wall

#---------------------- RULES ------------------------#
all: $(NAME)

test: $(NAME)
	$(CC) -g main.c $<
	./a.out

$(NAME): $(OBJS)
	make bonus -C $(LIBFT_DIR)
	cp libft/libft.a ./$(NAME)
	ar rcs $@ $(OBJS)
	ranlib $@

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	$(CC) -c $(C_FLAGS) -o $@ $<

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all test testwithflags clean fclean re
