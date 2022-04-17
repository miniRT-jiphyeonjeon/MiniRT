# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 21:20:28 by cjang             #+#    #+#              #
#    Updated: 2022/04/17 21:20:29 by cjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash


# ===== Target & FLAGS =====
NAME		:= libft.a

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar rc
RM			:= rm -rf

SRCS_DIR	:= src
INCD		:= -I./include/


# ===== Packages =====
PKGS		:= math memory string write ascii read

asciiV		:= ft_atof ft_atoi ft_isdigit ft_isspace
mathV		:= ft_clamp ft_fmod_abs
memoryV		:= ft_bzero ft_calloc ft_memset
readV		:= get_next_line
stringV		:= ft_split ft_strcmp ft_strdup ft_strjoin ft_strlcpy ft_strlen ft_strncmp ft_strsep
writeV		:= ft_putstr_fd ft_write ft_writes


# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(SRCS_DIR)/$(pkg)/$(file).c\
		)\
	)
endef


# ===== Sources & Objects & Include =====
SRCS	:= $(call choose_modules, $(PKGS))
OBJS	:= $(SRCS:%.c=%.o)


# ===== Style =====
FG_TEXT		= \033[38;5;85m
FG_DEBUG	= \033[48;5;203m
CL_RESET	= \033[0m
CL_BOLD		= \033[1m
CL_BRESET	= \033[21m


# ===== Rules =====
.PHONY : all clean fclean tclean re rere

all : $(NAME)

clean :
	@$(RM) $(OBJS)
	@echo -e "🗑 Remove $(CL_BOLD)$(NAME)'s OBJs$(CL_RESET) ... Done"

fclean : clean
	@$(RM) $(NAME)
	@echo -e "🗑 Remove $(CL_BOLD)$(NAME)$(CL_RESET) ... Done"

re : fclean all

$(NAME) : $(OBJS)
	@echo -e "  $(CL_RESET)$(FG_TEXT)Done$(CL_RESET)"
	@$(AR) $@ $^

INDEX = 0
%.o : %.c
	$(eval INDEX = $(shell expr $(INDEX) + 1))
	@if [ $(INDEX) = 1 ] ; then \
		echo -en "$(FG_TEXT)Creating $(CL_BOLD)$(NAME) ◼︎︎︎︎︎︎︎︎◼︎◼︎︎︎︎︎︎︎︎◼︎" ; \
	else \
		echo -en "$(FG_TEXT)◼︎︎︎︎︎︎︎︎◼︎◼︎︎︎︎︎︎︎︎◼" ; \
	fi
	@$(CC) $(CFLAGS) $(INCD) -c $< -o $@ -g
