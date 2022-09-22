# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abartell <abartell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 15:52:49 by abartell          #+#    #+#              #
#    Updated: 2022/09/22 11:31:00 by abartell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SRCLIENT = client.c
OBJSCLIENT = $(SRCLIENT:.c=.o)

SRCSERVER = server.c
OBJSERVER= $(SRCSERVER:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): server client

server: $(OBJSERVER)
	gcc -o server $(SRCSERVER) $(CFLAGS)

client: $(OBJSCLIENT)
	gcc -o client $(SRCLIENT) $(CFLAGS)

clean:
	rm -f $(OBJSERVER) $(OBJSCLIENT)

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re