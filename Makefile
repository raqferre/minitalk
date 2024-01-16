# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raqferre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:36:17 by raqferre          #+#    #+#              #
#    Updated: 2022/12/05 16:03:08 by raqferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		minitalk

CLIENT			=		client

SERVER			=		server


SRC_SERVER		=		server.c 

SRC_CLIENT		=		client.c 

OBJS_SERVER		=		$(SRC_SERVER:.c=.o)

OBJS_CLIENT		=		$(SRC_CLIENT:.c=.o)

LIB				=		make -C ./Libft

CC				=		gcc

CFLAGS			=		-Wall -Werror -Wextra

RM				=		rm -f

$(NAME)			: 		$(SERVER) $(CLIENT)

server			:		$(OBJS_SERVER)
						$(LIB)
						$(CC) $(CFLAGS) $(OBJS_SERVER) Libft/libft.a -o $(SERVER)

client			:		$(OBJS_CLIENT)
						$(LIB)
						$(CC) $(CFLAGS) $(OBJS_CLIENT) Libft/libft.a -o $(CLIENT)

bonus			:	all
		


clean			:
						$(RM) $(OBJS_CLIENT)
						$(RM) $(OBJS_SERVER)

fclean			:		clean
						$(RM) $(CLIENT)
						$(RM) $(SERVER)
						cd ./Libft && make fclean

all				:		$(NAME)

re				:		fclean all

.PHONY			:		clean fclean all re bonus 
