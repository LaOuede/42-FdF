# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:57:00 by gle-roux          #+#    #+#              #
#    Updated: 2023/10/29 11:38:05 by gwenolalero      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                          BANNER & COLOR SETTINGS                             #
#------------------------------------------------------------------------------#

#Banner
define BANNER1
                   
$G       _____ $Y_$G _       _        _____         
$G      |  ___$Y(_)$G |   __| | ___  |  ___|__ _ __ 
$G      | |_  | | |  / _` |/ $Y_$G \ | |_ / $Y_$G \ '__|
$C      |  _| | | | | (_| |  __/ |  _|  __/ |   
$C      |_|   |_|_|  \__,_|\___| |_|  \___|_|   
$C                                         
endef
export BANNER1

# Colors settings
R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)

# Print settings
ERASE_LINE	=	\033[2K\r

#------------------------------------------------------------------------------#
#                                   TOOLS                                      #
#------------------------------------------------------------------------------#
define HELP
$Z---------------------------------------------------------------
$YTools available$Z
make bres 		$Y->$Z Open Bresenham algo informations
make color 		$Y->$Z Open color picker
make dda 		$Y->$Z Open DDA algo informations
make help		$Y->$Z Display tools available
make iso 		$Y->$Z Open isometric projection informations
make norm		$Y->$Z Run Norminette
make pdf 		$Y->$Z Open PDF subject
make rot 		$Y->$Z Open rotation informations
---------------------------------------------------------------
endef
export HELP

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC			=	gcc
CFLAGS		= 	-g -Wall -Wextra -Werror 
#CFLAGS		= 	-fsanitize=address

# Remove
RM			=	rm -rf

# Librairies names
NAME		=	fdf
NAME_B		=	fdf_bonus

# Dir. and files names
SRCS_DIR	=	./src/
SRCS_LIST	=	clean.c \
				color_scheme.c \
				draw.c \
				hook.c \
				init.c \
				main.c \
				projection.c \
				read_map.c \
				utils.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./obj/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

# Dir. and files names - BONUS
SRCS_DIR_B	=	./src_bonus/
SRCS_LIST_B	=	clean_bonus.c \
				colors_bonus.c \
				color_scheme_bonus.c \
				draw_bonus.c \
				hook_1_bonus.c \
				hook_2_bonus.c \
				init_bonus.c \
				main_bonus.c \
				modifications_bonus.c \
				projection_bonus.c \
				read_map_bonus.c \
				rotation_bonus.c \
				utils_bonus.c
SRCS_B		=	$(addprefix $(SRCS_DIR_B), $(SRCS_LIST_B))

OBJS_LIST_B	=	$(patsubst %.c, %.o, $(SRCS_LIST_B))
OBJS_B		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST_B))

# Headers
HEADER_DIR	=	./includes/
HEADER_LIST	=	fdf.h \
				fdf_bonus.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LIST))

# Libft variables
LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a

# Printf variables
PRINTF_DIR	=	./ft_printf/
PRINTF		=	$(PRINTF_DIR)printf.a

# MLX42 variables
MLX42_DIR	=	./lib/MLX42/build/
MLX42		=	$(MLX42_DIR)libmlx42.a
OPEN_GL		=	-framework Cocoa -framework OpenGL -framework IOKit
GLFW		=	-lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"
#GLFW		=	-lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib"

# Evaluator variable
USER		=	$(shell whoami)

#------------------------------------------------------------------------------#
#                                  RULES                                       #
#------------------------------------------------------------------------------#

# Executable creation
all: dir $(NAME)
	@echo $Y"$$BANNER1"$W
	@echo "				$Z...made by $Ygle-roux$Z🐭"
	@echo "					$Z...evaluated by $Y$(USER)\n\n$W"

#Create directory for *.o files
dir:
	@mkdir -p $(OBJS_DIR)

# Compilation
$(NAME): $(MLX42) $(LIBFT) $(PRINTF) $(OBJS)
	@echo "$(ERASE_LINE)$W\n------------------------ $Zfdf is $Gdone ✅ $W-----------------------"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(PRINTF) $(MLX42) $(OPEN_GL) $(GLFW) -o $(NAME)
	@echo "\n-------------- $ZIf help is needed, type $Ymake help $W--------------"
	@echo "\n>>>>>>>>>>>>>>>>>>>>> $YFILdeFER $Gis ready ✅$W <<<<<<<<<<<<<<<<<<<<"

$(NAME_B): $(MLX42) $(LIBFT) $(PRINTF) $(OBJS_B)
	@echo "$(ERASE_LINE)$W\n-------------------- $Zfdf_bonus is $Gdone ✅ $W---------------------"
	@$(CC) $(CFLAGS) $(SRCS_B) $(LIBFT) $(PRINTF) $(MLX42) $(OPEN_GL) $(GLFW) -o $(NAME_B)
	@echo "\n-------------- $ZIf help is needed, type $Ymake help $W--------------"
	@echo "\n>>>>>>>>>>>>>>>>>>>>> $YFILdeFER $Gis ready ✅$W <<<<<<<<<<<<<<<<<<<<"

$(MLX42):
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>> $YCONFIGURATION $W<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "****************** $GChecking for $YBREW $Gupdate$W *******************\n"
	@brew update
	@if brew search cmake &> /dev/null; then \
		echo "\n***************** $YCMAKE $Gis already installed$W ******************\n"; \
	else \
		echo "\n**************** $RInstalling $ZCMAKE please wait$W *****************\n"; \
		brew install cmake > /dev/null; \
	fi
	@if brew list glfw &> /dev/null; then \
		echo "****************** $YGLFW $Gis already installed$W ******************\n"; \
	else \
		echo "***************** $RInstalling $ZGLFW please wait$W *****************\n"; \
		brew install glfw &> /dev/null; \
	fi
	@echo "$W------------------------- $Zlibmlx42.a $W--------------------------\n"
	@if [ ! -f "./lib/MLX42/build/libmlx42.a" ]; then \
		cmake MLX42 -B $(MLX42_DIR) &> /dev/null && make -C $(MLX42_DIR) -j4; \
	fi
	@echo "\n$W----------------------- $Zmlx42 is $Gdone ✅ $W----------------------\n"
	
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

# Create all files .o (object) from files .c (source code)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@printf "$(ERASE_LINE) $GCompiling : $Z$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Create all files .o (object) from files .c (source code)
$(OBJS_DIR)%.o: $(SRCS_DIR_B)%.c $(HEADER)
	@printf "$(ERASE_LINE) $GCompiling : $Z$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove objects
clean:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YCLEANING $W<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$W------------------- $Z$(NAME) : $(OBJS_DIR) was $Rdeleted ❌$W----------------"

# Remove executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(PRINTF)
	@$(RM) ./lib
	@$(RM) $(NAME_B)
	@echo "\n$W-------- $ZAll exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $ZCleaning is $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<\n"

# Remove objects and executables and remake
re: fclean
	@$(MAKE) all

# Create Bonus files
bonus: dir $(NAME_B)
	@echo $Y"$$BANNER1"$W
	@echo "	$Y-> BONUS! <-$W		$Z...made by $Ygle-roux$W🐭"
	@echo "					$Z...evaluated by $Y$(USER)\n\n$W"

# Display tools available
help:
	@echo "$$HELP"

# Open a color picker
color:
	@open https://www.w3schools.com/colors/colors_picker.asp

# Open isometric projection informations
iso:
	@open https://en.wikipedia.org/wiki/Isometric_projection

# Open rotation informations
rot:
	@open https://fr.wikipedia.org/wiki/Rotation_vectorielle

# Open Bresenham algo informations
bres:
	@open https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

# Open DDA algo informations
dda:
	@open https://www.thecrazyprogrammer.com/2017/01/dda-line-drawing-algorithm-c-c.html

# Run norminette
norm :
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE $W<<<<<<<<<<<<<<<<<<<<<<<<<<$Z\n"
	@norminette $(SRCS) $(HEADER) $(LIBFT_DIR) $(PRINTF_DIR) $(SRCS_B)
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<<"

# Avoids file-target name conflicts
.PHONY: all dir clean fclean re bonus help color iso rot bres dda norm
