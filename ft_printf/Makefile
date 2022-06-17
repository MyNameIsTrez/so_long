# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: trez <trez@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/10 13:54:36 by trez          #+#    #+#                  #
#    Updated: 2022/06/17 14:41:00 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := libftprintf.a
LIBFT_PATH := libft/libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

SOURCES :=\
	src/0_ft_printf.c\
	src/get_type_strings/pft_get_char.c\
	src/get_type_strings/pft_get_decimal.c\
	src/get_type_strings/pft_get_hex_lower.c\
	src/get_type_strings/pft_get_hex_upper.c\
	src/get_type_strings/pft_get_percent.c\
	src/get_type_strings/pft_get_pointer.c\
	src/get_type_strings/pft_get_string.c\
	src/get_type_strings/pft_get_unsigned.c\
	src/1_pft_initialize_options.c\
	src/2_pft_parse_format.c\
	src/3_pft_fix_priorities.c\
	src/4_pft_parse_argument.c\
	src/5_pft_fill_parts.c\
	src/pft_utils.c

HEADERS :=\
	libft/libft.h\
	libft/helper_headers/boolean_operators.h\
	libft/helper_headers/shared_system_headers.h\
	libft/helper_headers/success.h\
	libft/helper_headers/whitespace.h\
	src/ft_printf.h\
	src/get_type_strings/pft_get_type_strings.h

CLEANED_FILES := obj
FCLEANED_FILES := $(NAME)

SRC_DIR := src
OBJ_DIR := obj

LIBFT_DIR := libft

################################################################################

ifdef DEBUG
CFLAGS += -DSTATIC=
CFLAGS += -g3 -Wconversion
CFLAGS += -Wno-nullability-completeness # Needed for intercepting stdlib.h
# CFLAGS += -fsanitize=address # Not compatible with "leaks" program.
FCLEANED_FILES += tester
endif

################################################################################

OBJECT_PATHS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))

################################################################################

all: $(NAME)

$(NAME): $(LIBFT_PATH) $(OBJECT_PATHS)
	cp $(LIBFT_PATH) $(NAME)
	ar rs $(NAME) $(OBJECT_PATHS)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_PATH):
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: all

################################################################################

bonus: all

clean:
	rm -rf $(CLEANED_FILES)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(FCLEANED_FILES)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: bonus clean fclean re

################################################################################
