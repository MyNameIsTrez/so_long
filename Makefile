# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/17 18:04:48 by sbos          #+#    #+#                  #
#    Updated: 2022/07/06 16:44:14 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := so_long

CC := cc

OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror
# CFLAGS += -O3 # -O1 adds tail recursion detection

################################################################################

GLFW_FRAMEWORKS :=\
	-framework Cocoa\
	-framework OpenGL\
	-framework IOKit

GLFW := -lglfw3 $(GLFW_FRAMEWORKS)

MLX42_PATH := ./submodules/MLX42
MLX42_LIB_PATH := $(MLX42_PATH)/libmlx42.a
MLX42 := -L$(MLX42_PATH) -lmlx42

LIBFT_PATH := ./submodules/libft
LIBFT_LIB_PATH := $(LIBFT_PATH)/libft.a
LIBFT := -L$(LIBFT_PATH) -lft

FT_PRINTF_PATH := ./submodules/ft_printf
FT_PRINTF_LIB_PATH := $(FT_PRINTF_PATH)/libftprintf.a
FT_PRINTF := -L$(FT_PRINTF_PATH) -lftprintf

LIBS := $(GLFW) $(MLX42) $(LIBFT) $(FT_PRINTF)

################################################################################

SOURCES :=\
	src/0_main.c\
	src/1_parse_argv.c\
	src/2_load_texture.c\
	src/3_instantiate_tile_kinds.c\
	src/4_instantiate_tile_grid.c\
	src/5_instantiate_entities.c\
	src/6_instantiate_players.c\
	src/a_utils.c\
	src/cleanup.c

################################################################################

SOURCES +=\
	src/error/sl_any_error.c\
	src/error/sl_get_error_ptr.c\
	src/error/sl_get_error.c\
	src/error/sl_print_all_errors.c\
	src/error/sl_print_error.c\
	src/error/sl_set_error.c

################################################################################

SOURCES +=\
	src/iterators/char_grid_height.c\
	src/iterators/char_grid_width.c\
	src/iterators/char_grid.c\
	src/iterators/frame_count.c

################################################################################

BONUS_SOURCES :=

ifdef ADD_BONUS
SOURCES += $(BONUS_SOURCES)
endif

################################################################################

FCLEANED_FILES := $(NAME)

ifdef DEBUG
LIBS +=
HEADERS +=
CFLAGS += -g3 -Wconversion
FCLEANED_FILES +=
endif

ifdef SAN
CFLAGS += -fsanitize=address
endif

################################################################################

OBJECT_PATHS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

################################################################################

# Only cleans when MAKE_DATA changes.
DATA_FILE := .make_data
MAKE_DATA := $(CFLAGS) $(SOURCES)
ifneq ($(shell echo "$(MAKE_DATA)"), $(shell cat "$(DATA_FILE)" 2> /dev/null))
PRE_RULES := clean
endif

################################################################################

INCLUDES := $(sort $(addprefix -I, $(MLX42_PATH)/include $(LIBFT_PATH) $(FT_PRINTF_PATH)/src))

################################################################################

all: $(PRE_RULES) $(MLX42_LIB_PATH) $(LIBFT_LIB_PATH) $(FT_PRINTF_LIB_PATH) $(NAME)

################################################################################

$(MLX42_LIB_PATH):
	$(MAKE) -C $(MLX42_PATH)

$(LIBFT_LIB_PATH):
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF_LIB_PATH):
	$(MAKE) -C $(FT_PRINTF_PATH)

################################################################################

$(NAME): $(OBJECT_PATHS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECT_PATHS) -o $(NAME)
	@echo "$(MAKE_DATA)" > $(DATA_FILE)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

################################################################################

clean:
	rm -rf $(OBJ_DIR)/

fclean: clean
	rm -f $(FCLEANED_FILES)
	$(MAKE) -C $(MLX42_PATH) fclean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

bonus:
	@$(MAKE) ADD_BONUS=1 all

################################################################################

.PHONY: all clean fclean re bonus

################################################################################
