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
PKGS		:= memory string write

memoryV		:= ft_bzero ft_calloc ft_memset
stringV		:= ft_strlen
writeV		:= ft_write ft_writes


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