NAME = libftprintf.a



# DIRECTORIES #
SRC_DIR =				srcs
HDR_DIR =				includes
OBJ_DIR =				obj
LIBFT_DIR = 			libft

#---------------------- SOURCES ----------------------#

SOURCES =	 			ft_printf.c \
						pf_checkfunctions.c \
						putfunctions/pf_putfunctions.c \
						putfunctions/puts/pf_puts.c \
						putfunctions/puts/pf_puts_width.c \
						putfunctions/putd/pf_putd.c \
						putfunctions/putd/pf_putd_minus.c \
						putfunctions/putd/pf_putd_zero.c \
						putfunctions/putp/pf_putp.c \
						putfunctions/putx/pf_putx.c \
						pf_ultohex.c \
						putfunctions/putu/pf_putu.c \
						putfunctions/putu/pf_putu_minus.c \
						putfunctions/putu/pf_putu_zero.c \
						printspecs.c



LIBFT_FILES = 			$(LIBFT_DIR)/ft_memset.c \
						$(LIBFT_DIR)/ft_bzero.c \
						$(LIBFT_DIR)/ft_memcpy.c \
						$(LIBFT_DIR)/ft_memccpy.c \
						$(LIBFT_DIR)/ft_memmove.c \
						$(LIBFT_DIR)/ft_memchr.c \
						$(LIBFT_DIR)/ft_memcmp.c \
						$(LIBFT_DIR)/ft_strlen.c \
						$(LIBFT_DIR)/ft_strlcpy.c \
						$(LIBFT_DIR)/ft_strlcat.c \
						$(LIBFT_DIR)/ft_tolower.c \
						$(LIBFT_DIR)/ft_toupper.c \
						$(LIBFT_DIR)/ft_isalnum.c \
						$(LIBFT_DIR)/ft_isalpha.c \
						$(LIBFT_DIR)/ft_isascii.c \
						$(LIBFT_DIR)/ft_isdigit.c \
						$(LIBFT_DIR)/ft_isprint.c \
						$(LIBFT_DIR)/ft_strchr.c \
						$(LIBFT_DIR)/ft_strncmp.c \
						$(LIBFT_DIR)/ft_strrchr.c \
						$(LIBFT_DIR)/ft_strnstr.c \
						$(LIBFT_DIR)/ft_atoi.c \
						$(LIBFT_DIR)/ft_calloc.c \
						$(LIBFT_DIR)/ft_strdup.c \
						$(LIBFT_DIR)/ft_substr.c \
						$(LIBFT_DIR)/ft_strjoin.c \
						$(LIBFT_DIR)/ft_strtrim.c \
						$(LIBFT_DIR)/ft_split.c \
						$(LIBFT_DIR)/ft_itoa.c \
						$(LIBFT_DIR)/ft_strmapi.c \
						$(LIBFT_DIR)/ft_putchar_fd.c \
						$(LIBFT_DIR)/ft_uintcountchars.c \
						$(LIBFT_DIR)/ft_putstr_fd.c \
						$(LIBFT_DIR)/ft_putendl_fd.c \
						$(LIBFT_DIR)/ft_putnbr_fd.c \
						$(LIBFT_DIR)/ft_intcountchars.c \
						$(LIBFT_DIR)/ft_putuint_fd.c \
						$(LIBFT_DIR)/ft_lstnew.c \
						$(LIBFT_DIR)/ft_lstadd_front.c \
						$(LIBFT_DIR)/ft_lstsize.c \
						$(LIBFT_DIR)/ft_lstlast.c \
						$(LIBFT_DIR)/ft_lstadd_back.c \
						$(LIBFT_DIR)/ft_lstdelone.c \
						$(LIBFT_DIR)/ft_lstclear.c \
						$(LIBFT_DIR)/ft_lstiter.c \
						$(LIBFT_DIR)/ft_lstmap.c

#---------------------- OBJECTS ----------------------#
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))


#---------------------- FLAGS ----------------------#
C_FLAGS 	= 	-Werror -Wextra -Wall
CC 			= 	gcc

HEADER_FILES = includes


#---------------------- RECIPES ----------------------#
all: $(NAME)

test:
	$(CC) -g main.c $(SOURCE_FILES) libft/libft.a
	./a.out

testwithflags:
	$(CC) $(C_FLAGS) -g main.c $(SRCS) libft/libft.a
	./a.out

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp libft/libft.a ./$(NAME)
	ar rcs $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(C_FLAGS) -I includes/libft.h $< -o $@

clean:
	rm -rf $(SOURCES:.c=.o)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all test testwithflags clean fclean re
