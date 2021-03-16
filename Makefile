# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/03/17 00:18:43 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libasm.a
CC = 	clang -Wall -Werror -Wextra
RM = 	rm -rf
# FLAGS =	-O2
NASM =	nasm
NFLAGS = -f elf64
TESTNAME = libasm_test.out

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

BONUSNAME = ft_list_push_front.s \
			ft_list_size.s

#SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))
#OBJSNAME = $(SRCSNAME:.s=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))
OBJS = $(SRCSNAME:.s=.o)
BONUSOBJS = $(BONUSNAME:.s=.o)

# *************************************************************************** #

%.o:	%.s
	@$(NASM) $(NFLAGS) $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\n$(B)$(MAG)$(BEL)libasm.a\tcompiled !$(D)\n"

clean:
	@$(RM) $(OBJS) $(BONUSOBJS)
	@echo "$(B)Cleared$(D)"

fclean: clean
	@$(RM) $(NAME) $(TESTNAME)

re:	fclean all

bonus: $(OBJS) $(BONUSOBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUSOBJS)
	@echo "\n$(B)$(MAG)$(BEL)bonus\tcompiled !$(D)\n"

test: main.c bonus
	@$(CC) main.c $(NAME) -o $(TESTNAME)
	@echo "\n$(B)$(MAG)$(BEL)$(TESTNAME)\tcompiled !$(D)\n"

.PHONY: all, clean, fclean, re, bonus, test

# **************************************************************************** #
