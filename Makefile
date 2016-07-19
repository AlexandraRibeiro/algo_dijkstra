# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/09 20:04:13 by aribeiro          #+#    #+#              #
#    Updated: 2016/04/22 14:53:10 by aribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

#put here the filenames .c only
SRCS =	main.c \
		lem_atoi.c \
		lem_dijkstra.c \
		lem_dijkstra_free_tabs.c \
		lem_dijkstra_ini_tabs.c \
		lem_dijkstra_tabs.c \
		lem_display_final.c \
		lem_display_final_options.c \
		lem_display_options.c \
		lem_free.c \
		lem_hex.c \
		lem_hex_tab.c \
		lem_list.c \
		lem_read_check.c \
		lem_room.c \
		lem_start_end_ant.c \
		lem_tab.c \
		lem_tools.c \
		lem_tube.c

#the includes directory : ex for libft.h
DIRINC = libft/includes

#the lib filename
LIB	= libft.a

#the lib directory
DIRLIB = libft

#lib to link to, as needed by gcc    -lft   for  libft.a 
LIBFT = -lft

#adapt here your compilation flags
CFLAGS	= -Wall -Wextra -Werror

#adapt here your link flags (normally not needed)
LDFLAGS	= 



# **************************************************************************** #
#                     modify that part only with care                          #
# **************************************************************************** #

#obj application dir, if not present, it will be created ( for .o and .d)
OBJ = obj_$(NAME)
	  	  
#to detect if it is windows OS or not(multi_platform)
ifeq ($(shell echo "_"),"_")
	EXE_F	= $(NAME).exe
else
	EXE_F	= $(NAME)
endif

#variables for colors to highlight the make results
yellow	= \033[33;1m
cyan	= \033[36;1m
vert	= \033[32;1m
normal	= \033[0m

COBJS	= $(SRCS:.c=.o)

OBJ_F	= $(addprefix $(OBJ)/,$(COBJS))

DEP_F	= $(OBJ_F:.o=.d)

 

all: lib build finish

#launch the makefile from the lib directory, for lib creation   
lib: 
	@printf   "\n$(vert)Checking $(LIB)$(normal)\n\n" 
	@(cd $(DIRLIB) && $(MAKE))
	@printf   "\n$(cyan)Lib : $(LIB) ready to use$(normal)\n\n" 

#compile source application and link with the created lib	
build: mk_dir $(EXE_F)

#if obj/dep dir not existing it will be created
mk_dir:
	@test -d $(OBJ) || mkdir $(OBJ)
	
$(EXE_F): $(OBJ_F)
	@printf "\n\n$(vert)Creating $@$(normal)\n\n"
	@printf "using .o files :\n$+\n\nand lib :\n$(vert)$(LIB)$(normal)\n\n"
	@gcc $(LDFLAGS) -o $@ $+ -I $(DIRINC) -L $(DIRLIB) $(LIBFT)
	@printf   "\n$(vert)$@ created!$(normal)\n\n" 		

$(OBJ_F): $(OBJ)/%.o: %.c
	@printf "Compiling : $<\t=> $@\n"
	@gcc -c -MMD -MP $(CFLAGS) -o $@ $< -I $(DIRINC)

-include $(DEP_F)

clean:
	@rm -f $(OBJ_F)
	@rm -f $(DEP_F)
	@(cd $(DIRLIB) && $(MAKE) $@)

fclean: clean
	@rm -f $(EXE_F)
	@(cd $(DIRLIB) && $(MAKE) $@)

re: fclean all

finish:
	@printf "\n$(vert)Make : \t$(EXE_F) terminating!$(normal)\n"

.PHONY: all clean fclean re
