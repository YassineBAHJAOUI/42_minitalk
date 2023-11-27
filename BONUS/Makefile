# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 18:54:43 by ybahjaou          #+#    #+#              #
#    Updated: 2023/02/25 13:45:04 by ybahjaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files
SERVER		=	ft_server_bonus/ft_server_bonus.c

CLIENT		=	ft_client_bonus/ft_client_bonus.c

# Sources and objects
SERVER_SRC	=	./ft_server_bonus/ft_server_bonus.c \
		./ft_server_bonus/my_put.c

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	./ft_client_bonus/ft_client_bonus.c \
		./ft_client_bonus/my_getnbr.c \
		./ft_client_bonus/my_put.c \
		./ft_client_bonus/my_str_isnum.c\
		./ft_client_bonus/get_next_line.c\
		./ft_client_bonus/get_next_line_utils.c

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

SERVER_NAME	=	server_bonus

CLIENT_NAME	=	client_bonus

NAME		=	server_bonus

# ------------------------------ Colors ------------------------------

BOLD_VRT	=	\033[1;32m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD_VRT)Starting the compilation...$(NO_COLOR)\n"

SERV_READY	=	echo "\n📥 $(BOLD_VRT)Server ready!$(NO_COLOR)\n"

CLI_READY	=	echo "\n📟 $(BOLD_VRT)Client ready!$(NO_COLOR)\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)$(BOLD_VRT)Removed all the \".o\" files$(NO_COLOR) \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)$(BOLD_VRT)Removed the executables$(NO_COLOR) \n"

# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): comp_start ft_server_bonus ft_client_bonus

comp_start:
	@$(COMP_START)

ft_server_bonus: $(SERVER_OBJS)
	@$(GCC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)
	@$(SERV_READY)

ft_client_bonus: $(CLIENT_OBJS)
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
