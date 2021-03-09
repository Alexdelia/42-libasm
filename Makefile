# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/03/09 14:07:53 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libasm.a
CC = 	clang -Wall -Werror -Wextra
RM = 	rm -rf
# FLAGS =	-O2
NASM =	nasm
NFLAGS = -f elf64

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
		   ft_strcmp.s \
		   ft_strcpy.s \
		   ft_strdup.s \
		   ft_write.s \
		   ft_read.s

SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))
OBJSNAME = $(SRCSNAME:.s=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))
OBJS = $(OBJSPATH)*.o

# *************************************************************************** #

all:	$(NAME)

$(NAME):
	@mkdir $(OBJSPATH) 2> /dev/null || true
	@$(NASM) $(NFLAGS) -o $(SRCS)
	@mv *.o $(OBJSPATH)
	@$(CC) $(OBJS) $(LBNAME) -L$(LBPATH) $(LBINC) -I$(INC) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@rmdir $(OBJSPATH) 2> /dev/null || true

fclean: clean
	@$(RM) $(NAME) $(MLXM)

re:	fclean all

bonus:

test:

.PHONY: all, clean, fclean, re, bonus, test

# **************************************************************************** #
