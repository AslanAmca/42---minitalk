# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 15:19:34 by aaslan            #+#    #+#              #
#    Updated: 2023/01/04 16:14:34 by aaslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	minitalk
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): server client

server: server.c
	$(CC) $(CFLAGS) -o server server.c utilities/*.c

client: client.c
	$(CC) $(CFLAGS) -o client client.c utilities/*.c

bonus: server_bonus.c client_bonus.c
	$(CC) $(CFLAGS) -o server server_bonus.c utilities/*.c
	$(CC) $(CFLAGS) -o client client_bonus.c utilities/*.c

clean:
	rm -f client
	rm -f server

fclean: clean

re: fclean all

.PHONY: all clean fclean re
