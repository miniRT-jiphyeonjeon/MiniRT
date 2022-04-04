SHELL = bash


# ===== Target & FLAGS =====
NAME		:= minirt

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf

SRCS_DIR	:= src
INCD_MANDA	:= -I./include/ -I./lib/libft/include/ -I./lib/mlx_mms
INCD_BONUS	:= -I./include_bonus/ -I./lib/libft/include/ -I./lib/mlx_mms
LIB			:= -L./lib/libft -lft -L./lib/mlx_mms -lmlx
MLX_FLAGS	:= -framework OpenGL -framework AppKit

LIBFT		:= ./lib/libft/libft.a
LIBFT_DIR	:= ./lib/libft
MLX_DIR		:= ./lib/mlx_mms


# ===== Mandatory Packages =====
PKGS_MANDA	:= error event list scene trace parse vector3

errorM		:= error
eventM		:= draw draw_util hook_key_n_exit
listM		:= list_utils
sceneM		:= ambient camera light objects scene
traceM		:= hit_cylinder hit_plane hit_sphere hit phong_illumination phong_light ray util
parseM		:= parse_bool parse_read parse_to_num parse_to_element parse_to_str parse_utils
vector3M	:= vector_operation1 vector_operation2 vector_operation3 vector_set

# ===== Bonus Packages =====
PKGS_BONUS	:= error event list scene trace parse vector3

errorB		:= error
eventB		:= draw draw_util hook_key_n_exit oversampling
listB		:= list_utils
sceneB		:= ambient camera light objects scene
traceB		:= hit_cylinder hit_plane hit_sphere hit phong_illumination phong_light ray util
parseB		:= parse_bool parse_read parse_to_num parse_to_element parse_to_str parse_utils
vector3B	:= vector_operation1 vector_operation2 vector_operation3 vector_set


# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)M),\
			$(SRCS_DIR)/$(pkg)/$(file).c\
		)\
	) $(SRCS_DIR)/main.c
endef

define choose_bonus_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)B),\
			$(SRCS_DIR)_bonus/$(pkg)/$(file)_bonus.c\
		)\
	) $(SRCS_DIR)_bonus/main_bonus.c
endef

# ===== Sources =====
SRCS_M	:= $(call choose_modules, $(PKGS_MANDA))
OBJS_M	:= $(SRCS_M:%.c=%.o)

SRCS_B	:= $(call choose_bonus_modules, $(PKGS_BONUS))
OBJS_B	:= $(SRCS_B:%.c=%.o)


# ===== Bonus Mode =====
ifdef BONUS_MODE
	OBJS	= $(OBJS_B)
	INCD	= $(INCD_BONUS)
else
	OBJS	= $(OBJS_M)
	INCD	= $(INCD_MANDA)
endif


# ===== Style =====
FG_TEXT		= \033[38;5;85m
FG_DEBUG	= \033[48;5;203m
CL_RESET	= \033[0m
CL_BOLD		= \033[1m
CL_BRESET	= \033[21m


# ===== Rules =====
.PHONY : all clean fclean tclean re rere bonus bonus_re

all : mlx $(LIBFT) $(NAME)

bonus :
	@make BONUS_MODE=1 all

bonus_re : fclean bonus

clean :
	@$(RM) $(OBJS_M) $(OBJS_B)
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
ifdef BONUS_MODE
	@rm -rf $(OBJS_M)
else
	@rm -rf $(OBJS_B)
endif
	@$(CC) $(LIB) $(MLX_FLAG) $(OBJS) -o $(NAME) -g
	@install_name_tool -change libmlx.dylib ./lib/mlx_mms/libmlx.dylib minirt
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
