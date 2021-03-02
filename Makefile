# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/03/02 14:18:50 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libasm.a
CC = 	nasm #-Wall -Werror -Wextra
RM = 	rm -rf
# FLAGS =	-O2

# **************************************************************************** #

MAKEFLAGS += --silent

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #

SRCSPATH =	.
OBJSPATH =	./objs/
INC =		.

SRCSNAME = ft_strlen.s \

SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))
OBJSNAME = $(SRCSNAME:.c=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))
OBJS = $(OBJSPATH)*.o

# *************************************************************************** #

all:	$(NAME)

$(NAME):
	@make -C $(LBPATH)
	@mkdir $(OBJSPATH) 2> /dev/null || true
	@$(CC) -I$(INC) -c $(SRCS)
	@mv *.o $(OBJSPATH)
	@$(CC) $(OBJS) $(LBNAME) -L$(LBPATH) $(LBINC) -I$(INC) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -C $(LBPATH) -f Makefile clean
	@rmdir $(OBJSPATH) 2> /dev/null || true


fclean: clean
	@$(RM) $(NAME) $(MLXM)
	@make -C $(LBPATH) -f Makefile fclean

re:	fclean all

bonus:	

.PHONY: all, clean, fclean, re, bonus

# **************************************************************************** #
