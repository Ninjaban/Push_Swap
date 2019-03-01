#  ----------------------------------------------------------------------------+
#                                                                              |
#   .------..------..------..------..------..------..------..------..------.   |
#   |P.--. ||R.--. ||E.--. ||V.--. ||I.--. ||S.--. ||I.--. ||O.--. ||N.--. |   |
#   | :/\: || :(): || (\/) || :(): || (\/) || :/\: || (\/) || :/\: || :(): |   |
#   | (__) || ()() || :\/: || ()() || :\/: || :\/: || :\/: || :\/: || ()() |   |
#   | '--'P|| '--'R|| '--'E|| '--'V|| '--'I|| '--'S|| '--'I|| '--'O|| '--'N|   |
#   `------'`------'`------'`------'`------'`------'`------'`------'`------'   |
#                                                                              |
#    Created by Jonathan Carra.                                                |
#    Copyright (c) 2019 Prévision. All rights reserved.                        |
#  ----------------------------------------------------------------------------+

NAME_SWAP	=	push_swap
NAME_CHECK	=	checker

LIB			=	libft.a

SRC_SWAP	=	main.c \
				sort.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c \
				push_swap.c
SRC_CHECK	=	main.c \
   				sort.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c \
				checker.c

DIRSRC		=	sources/
DIRINC		=	include/
DIRLIB		=	library/
DIROBJ		=	objects/

LIBS		=	$(LIB:%=$(DIRLIB)%)

OBJS_SWAP	=	$(addprefix $(DIROBJ), $(SRC_SWAP:.c=.o))
OBJS_CHECK	=	$(addprefix $(DIROBJ), $(SRC_CHECK:.c=.o))

CFLAGS		=	-Wall -Wextra -Werror -I./$(DIRINC) -I./$(DIRLIB)$(DIRINC) -g3
LFLAGS		=

CC			=	gcc
RM			=	rm -rf
ECHO		=	printf
MAKE		=	make -sC

CLEAN		=	"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         "
LEN			=	$$(/bin/echo -n $(NAME) | wc -c)
DELTA		=	$$(echo "$$(tput cols)-32-$(LEN)"|bc)
NB			=	$(words $(SRC))
INDEX		=	0
SHELL		=	/bin/bash

all				:	$(DIROBJ) $(NAME_SWAP) $(NAME_CHECK)

$(NAME_SWAP)	:	data_swap $(OBJS_SWAP)
	@$(eval OBJ_LEN=$(shell echo "$(NAME)" | wc -c))
	@$(eval CLEAN_LEN=$(shell echo "$$(tput cols)-6-$(OBJ_LEN)"|bc))
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_SWAP) $(LIBS) $(LFLAGS)
	@$(ECHO) "\r\033[38;5;040m✓ MAKE $(NAME)%.*s\033[0m\033[0m\n" $(CLEAN_LEN) $(CLEAN)
data_swap		:
	@$(eval LEN=$(shell echo $$(/bin/echo -n $(NAME_SWAP) | wc -c)))
	@$(eval DELTA=$(shell echo $$(echo "$$(tput cols)-32-$(LEN)"|bc)))
	@$(eval NB=$(shell echo $(words $(SRC_SWAP))))
	@$(eval INDEX=0)
	@$(eval NAME=$(shell echo $(NAME_SWAP)))


$(NAME_CHECK)		:	data_check $(OBJS_CHECK)
	@$(eval OBJ_LEN=$(shell echo "$(NAME_CHECK)" | wc -c))
	@$(eval CLEAN_LEN=$(shell echo "$$(tput cols)-6-$(OBJ_LEN)"|bc))
	@$(CC) $(CFLAGS) -o $(NAME_CHECK) $(OBJS_CHECK) $(LIBS) $(LFLAGS)
	@$(ECHO) "\r\033[38;5;040m✓ MAKE $(NAME_CHECK)%.*s\033[0m\033[0m\n" $(CLEAN_LEN) $(CLEAN)
data_check		:
	@$(eval LEN=$(shell echo $$(/bin/echo -n $(NAME_CHECK) | wc -c)))
	@$(eval DELTA=$(shell echo $$(echo "$$(tput cols)-32-$(LEN)"|bc)))
	@$(eval NB=$(shell echo $(words $(SRC_CHECK))))
	@$(eval INDEX=0)
	@$(eval NAME=$(shell echo $(NAME_CHECK)))


$(DIROBJ)%.o	:	$(DIRSRC)%.c | $(DIROBJ)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB) - 1))))
	@$(eval COLOR=$(shell list=(20 21 26 27 32 33 38 39 44 45 50 51); index=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$index]}"))
	@$(ECHO) "\r\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[0m" $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@$(eval OBJ_LEN=$(shell echo "$$(echo "$@" | sed 's/^.*\///')" | wc -c))
	@$(eval CLEAN_LEN=$(shell echo "$$(tput cols)-1-$(OBJ_LEN)"|bc))
	@$(ECHO) "\r\033[38;5;%dm✓ %s\033[0m\033[0m%.*s\n\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[0m"  $(COLOR) "$(shell echo "$@" | sed 's/^.*\///')"  $(CLEAN_LEN) $(CLEAN) $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))


$(DIROBJ)		:
	@$(MAKE) $(DIRLIB)
	@mkdir -p $(DIROBJ)

clean			:
	@$(MAKE) $(DIRLIB) clean
	@if [ -e $(DIROBJ) ];											\
	then															\
		$(RM) $(DIROBJ);											\
		$(ECHO) "\033[38;5;202m✗ Objects\033[0m\033[0m\n";			\
	fi;

fclean			:	clean
	@$(MAKE) $(DIRLIB) fclean
	@if [ -e $(NAME_SWAP) ];										\
	then															\
		$(RM) $(NAME_SWAP);											\
		$(ECHO) "\033[38;5;196m✗ $(NAME_SWAP)\033[0m\033[0m\n";		\
	fi;
	@if [ -e $(NAME_CHECK) ];										\
	then															\
		$(RM) $(NAME_CHECK);										\
		$(ECHO) "\033[38;5;196m✗ $(NAME_CHECK)\033[0m\033[0m\n";	\
	fi;

re				:	fclean all

.PHONY			:	all fclean clean re data_swap data_check
