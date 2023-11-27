# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 16:04:25 by ybahjaou          #+#    #+#              #
#    Updated: 2023/02/24 16:04:32 by ybahjaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files
SERVER		=	ft_server/ft_server.c

CLIENT		=	ft_client/ft_client.c

# Sources and objects
SERVER_SRC	=	./ft_server/ft_server.c \
		./ft_server/my_put.c

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	./ft_client/ft_client.c \
		./ft_client/my_getnbr.c \
		./ft_client/my_put.c \
		./ft_client/my_str_isnum.c

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

SERVER_NAME	=	server

CLIENT_NAME	=	client

NAME		=	server

# ------------------------------ Colors ------------------------------

BOLD_VRT	=	\033[1;32m

BOLD_YELLOW	=	\033[0;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD_VRT)Starting the compilation...$(NO_COLOR)\n"

SERV_READY	=	echo "\n📥 $(BOLD_VRT)Server ready!$(NO_COLOR)\n"

CLI_READY	=	echo "\n📟 $(BOLD_VRT)Client ready!$(NO_COLOR)\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)$(BOLD_VRT)Removed all the \".o\" files$(NO_COLOR) \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)$(BOLD_VRT)Removed the executables$(NO_COLOR) \n"

# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): comp_start ft_server ft_client

comp_start:
	@$(COMP_START)

ft_server: $(SERVER_OBJS)
	@$(GCC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)
	@$(SERV_READY)

ft_client: $(CLIENT_OBJS)
	@$(GCC) $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)
	@$(CLI_READY)

clean:
	@rm -rf $(OBJS) 
	@$(CLEANED)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)  
	@$(FCLEANED)

.c.o:
	@${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all minitalk server client clean fclean re
