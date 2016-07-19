# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 15:10:33 by aribeiro          #+#    #+#              #
#    Updated: 2016/04/14 14:49:32 by aribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

FLAGS = -Wall -Wextra -Werror

INC	= includes

SRC	= srcs


# **************************************************************************** #
#      			add here the new file sources                          #
# **************************************************************************** #

SRCS	=	ft_atoi.c ft_bzero.c ft_itoa.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_iscntrl.c \
	ft_isblank.c ft_isdigit.c ft_isprint.c \
	ft_free.c ft_countwords_secure.c \
	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memdel.c \
	ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar.c ft_putchar_fd.c  ft_putstr.c ft_putstr_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
	ft_strdup.c ft_strlen.c ft_strncat.c ft_strncmp.c \
	ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c \
	ft_strlcat.c ft_strnew.c ft_strdel.c ft_strsplit.c \
	ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	ft_tolower.c ft_toupper.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	ft_lstiter.c ft_lstmap.c ft_lstdupall.c \
	get_next_line.c \
	ft_printf.c ft_printf_char.c ft_printf_define.c ft_printf_display.c \
	ft_printf_errors.c ft_printf_int.c ft_printf_int_uint_bis.c \
	ft_printf_len_nbc.c ft_printf_oint.c ft_printf_search_parse.c \
	ft_printf_str.c ft_printf_str_null.c ft_printf_tools.c \
	ft_printf_uint.c ft_printf_wide.c ft_printf_xint.c \
	ft_longlongtoa_base.c ft_set_reset_bit.c \
	ft_memalloc_exit.c ft_strnew_exit.c


# **************************************************************************** #
#      			Nothing to change under                                #
# **************************************************************************** #

OBJ	= obj_dep

#variables for colors to highlight the make results
yellow	= \033[33;1m
vert	= \033[32;1m
normal	= \033[0m

COBJS = $(SRCS:.c=.o)

OBJ_F	= $(addprefix $(OBJ)/,$(COBJS))

DEP_F	= $(OBJ_F:.o=.d) 

all: mk_dir $(NAME) finish
		
mk_dir:
	@test -d $(OBJ) || mkdir $(OBJ)
	
clean:
	@rm -rf $(OBJ_F) $(DEP_F)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

finish:
	@printf "\n$(vert)Make : \tterminating with : $(NAME)!$(normal)\n\n"

$(NAME): $(OBJ_F)
	@printf "\n\n$(vert)Creating $@$(normal)\n\n"
	@printf "using :\n  $+\n\n"
	@ar rc $(NAME) $(OBJ_F)
	@ranlib $(NAME)
	@printf "\n$(vert)Lib : $(NAME) successfully created!$(normal)\n"

$(OBJ_F): $(OBJ)/%.o: $(SRC)/%.c
	@printf "Compiling : $<\t=> $@\n"
	@gcc -c -MMD -MP $(CFLAGS) -o $@ $< -I $(INC)

-include $(DEP_F)

.PHONY: all clean fclean re

