# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:57:00 by gle-roux          #+#    #+#              #
#    Updated: 2023/04/18 12:59:16 by gle-roux         ###   ########.fr        #
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
make help		$Y->$Z Display tools available
make norm		$Y->$Z Run Norminette
make pdf 		$Y->$Z Open PDF subject
---------------------------------------------------------------
endef
export HELP

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	= 	-g -Wall -Wextra -Werror 
#CFLAGS	= 	-fsanitize=address

# Remove
RM		=	rm -rf

# Librairies names
NAME		=	fdf

# Dir. and files names
SRCS_DIR	=	./src/
SRCS_LIST	=	clean.c \
				color_scheme.c \
				draw.c \
				hook.c \
				init.c \
				main.c \
				parse_file.c \
				projection.c \
				read_map.c \
				utils.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./obj/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

HEADER_DIR	=	./includes/
HEADER_LIST	=	fdf.h
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

# Evaluator variable
USER		=	$(shell whoami)

#------------------------------------------------------------------------------#
#                                  RULES                                       #
#------------------------------------------------------------------------------#

# Executable creation
all: dir $(NAME)
	@echo $Y"$$BANNER1"$W
	@echo "				$Z...made by $Ygle-roux$Z$W🐭"
	@echo "					$Z...evaluated by $Y$(USER)\n\n$W"

#Create directory for *.o files
dir:
	@mkdir -p $(OBJS_DIR)

# Compilation
$(NAME): $(MLX42) $(LIBFT) $(PRINTF) $(OBJS)
	@echo "\n\n$W----------------------- $Zfdf is $Gdone ✅ $W------------------------"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(PRINTF) $(MLX42) $(OPEN_GL) $(GLFW) -o $(NAME)
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
	@if [ ! -f "lib/MLX42/build/libmlx42.a" ]; then \
		cmake MLX42 -B $(MLX42_DIR) &> /dev/null && make -C $(MLX42_DIR) -j4; \
	fi
	@echo "\n$W---------------------- $Zmlx42 is $Gdone ✅ $W-----------------------\n"
	
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

# Create all files .o (object) from files .c (source code)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@printf "\n $GCompiling : $Z$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove objects
clean:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YCLEANING $W<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$W------------------- $Z$(NAME): $(OBJS_DIR) was $Rdeleted ❌$W-----------------"

# Remove executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(PRINTF)
#	@$(RM) ./lib
	@echo "\n$W-------- $ZAll exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $ZCleaning is $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<\n"

# Remove objects and executables and remake
re: fclean
	@$(MAKE) all

# Display tools available
help:
	@echo "$$HELP"

# Open the subject
pdf:
	@open https://cdn.intra.42.fr/pdf/pdf/80730/fr.subject.pdf

# Open a text generator
text:
	@open https://www.dummytextgenerator.com/#jump

# Open a character generator
test:
	@open https://www.browserling.com/tools/text-repeat
	
# Open a color picker
colors:
	@open https://www.w3schools.com/colors/colors_picker.asp

# Run norminette
norm :
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE $W<<<<<<<<<<<<<<<<<<<<<<<<<<$Z\n"
	@norminette $(SRCS) $(HEADER) $(LIBFT_DIR) $(PRINTF_DIR) $(SRCS_C_DIR) $(SRCS_S_DIR)
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<<"

# Avoids file-target name conflicts
.PHONY: all dir clean fclean re help pdf norm colors