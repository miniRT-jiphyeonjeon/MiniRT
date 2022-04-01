SHELL = bash


# ===== Target & FLAGS =====
NAME		:= cjang

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf

INCD		:= -I../include/ -I../lib/libft/include/ -I../lib/mlx_mms
LIB			:= -L../lib/libft -lft -L../lib/mlx_mms -lmlx
MLX_FLAGS	:= -framework OpenGL -framework AppKit

LIBFT		:= ../lib/libft/libft.a
LIBFT_DIR	:= ../lib/libft
MLX_DIR		:= ../lib/mlx_mms


# ===== Packages =====


# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			/$(pkg)/$(file).c\
		)\
	) /main.c
endef


# ===== Sources & Objects =====
SRCS	:= cjang_test.c
OBJS	:= $(SRCS:%.c=%.o)


# ===== Style =====
FG_TEXT		= \033[38;5;85m
FG_DEBUG	= \033[48;5;203m
CL_RESET	= \033[0m
CL_BOLD		= \033[1m
CL_BRESET	= \033[21m


# ===== Rules =====
.PHONY : all clean fclean tclean re rere

all : mlx $(LIBFT) $(NAME)

clean :
	@$(RM) $(OBJS)
	@echo -e "🗑 Remove $(CL_BOLD)$(NAME)'s OBJs$(CL_RESET) ... Done"

fclean : clean
	@$(RM) $(NAME)
	@echo -e "🗑 Remove $(CL_BOLD)$(NAME)$(CL_RESET) ... Done"

re : fclean all

lclean : libft_fclean fclean

tclean : mlx_clean libft_fclean fclean

rere : lclean all

tre : tclean all

$(NAME) : $(OBJS)
	@$(CC) $(LIB) $(MLX_FLAG) $(OBJS) -o $(NAME) -g
	@install_name_tool -change libmlx.dylib ../lib/mlx_mms/libmlx.dylib cjang
	@echo -e "  $(CL_RESET)$(FG_TEXT)Done$(CL_RESET)"

INDEX = 0
%.o : %.c
	$(eval INDEX = $(shell expr $(INDEX) + 1))
	@if [ $(INDEX) = 1 ] ; then \
		echo -en "$(FG_TEXT)Creating $(CL_BOLD)$(NAME) ◼︎︎︎︎︎︎︎︎◼︎︎︎︎︎︎" ; \
	else \
		echo -en "$(FG_TEXT)◼︎︎︎︎︎︎◼︎︎︎︎︎" ; \
	fi
	@$(CC) $(CFLAGS) $(INCD) -c $< -o $@ -g


# ===== Lib Rules =====
mlx :
	@make --no-print-directory -C $(MLX_DIR) all

mlx_clean :
	@make --no-print-directory -C $(MLX_DIR) clean

$(LIBFT) :
	@make --no-print-directory -C $(LIBFT_DIR) all

libft_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean
