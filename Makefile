# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 11:23:14 by asolano-          #+#    #+#              #
#    Updated: 2022/06/15 09:24:41 by asolano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME		=	push_swap

CC			=	clang

LIB_DIR		=	libft/
LIB			=	libft.a

DIR			=	srcs/
OBJ_DIR		=	obj/
SUB_DIR		=	obj/ps_srcs obj/c_srcs

FLAG		=	-c		\
				-Wall		\
				-Wextra		\
				-Werror

INCLUDE 	=	-I include/	\
			-I $(LIB_DIR)

RM			=	/bin/rm -f

PS_FILES	=	main.c			\
				list.c			\
				list_sort.c 	\
				list_u1.c		\
				check.c			\
				init.c			\
				case.c			\
				algo_short.c	\
				algo_big.c	\
				normalize.c		\
				get.c			\
				push_op.c		\
				swap_op.c		\
				rotate_op.c		\
				

#C_FILES	=	c_srcs/c_main.c

PS_SRCS		=	$(addprefix $(DIR), $(PS_FILES))
# C_SRCS	=	$(addprefix $(DIR), $(C_FILES))
PS_OBJ		=	$(PS_SRCS:$(DIR)%.c=$(OBJ_DIR)%.o)
# C_OBJ		= $(C_SRCS:$(DIR)%.c=$(OBJ_DIR)%.o)

all : $(PS_NAME)
# $(C_NAME)

obj/%.o		:	srcs/%.c
				@mkdir -p $(OBJ_DIR) $(SUB_DIR)
				$(CC) -g $(FLAG) $(INCLUDE) $< -o $@

$(LIB) 		:
				@$(MAKE) bonus -C $(LIB_DIR)
				mv $(LIB_DIR)$(LIB) .

$(PS_NAME)	:	$(PS_OBJ) $(LIB)
				$(CC) -fsanitize=address -o $@ $^

# $(C_NAME)	:	$(C_OBJ) $(LIB)
				# $(CC) -fsanitize=address -o $@ $^

clean		:
				for dir in $(MODULES); do		\
					@$(MAKE) clean -C $$dir;	\
				done
				@/bin/rm -rf $(OBJ_DIR)

fclean		:	clean
				@$(MAKE) fclean -C $(LIB_DIR)
				@$(RM) $(LIB)
				@$(RM) $(PS_NAME)
				# @$(RM) $(C_NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
