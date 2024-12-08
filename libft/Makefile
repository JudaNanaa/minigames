# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madamou <madamou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 16:07:55 by madamou           #+#    #+#              #
#    Updated: 2024/12/08 19:10:51 by madamou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
PURPLE			=	\033[0;35m
END= 	$(shell tput -Txterm sgr0)

CC = cc
C_FLAGS = -Wall -Wextra -Werror -g3 -pg

OBJS_DIR = .objets/

FT_PRINTF = $(addprefix ft_printf/, flags.c format.c ft_itoa_base.c ft_printf.c \
				ft_atoi_base.c precision.c field_minimum_width.c \
				ft_itoa_pointer.c buffer_functions.c parse_and_apply_format.c format_bis.c)

SRCS = 	count_char.c free_split.c ft_atoi.c ft_bzero.c \
		ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
		ft_lstsize_bonus.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c \
		ft_putstr_fd.c ft_putstr.c ft_re_strdup.c ft_re_strjoin.c ft_realloc.c ft_split_utils.c \
		ft_split.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen_2d.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strncpy.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
		ft_strstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line_bonus.c \
		get_next_line_utils_bonus.c join2d.c read_file.c sort_str2d.c \
		str_join_2d.c str2d_join.c strdup2d.c  add_string_char_2d.c $(FT_PRINTF)

SRCS := $(SRCS:%=./%)

OBJS = $(SRCS:./%.c=$(OBJS_DIR)/%.o)

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c \
              ft_lstadd_back_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
              ft_lstclear_bonus.c ft_lstdelone_bonus.c

SRCS_BONUS := $(SRCS_BONUS:%=./%)

OBJS_BONUS = $(SRCS_BONUS:./%.c=$(OBJS_DIR)/%.o)

DIR_DUP = mkdir -p $(@D)

G				= $(GREEN)
X 				= $(END)
BAR_SIZE		= 50

TOTAL_FILES		:= $(words $(SRCS))
COMPILED_FILES	:= 0

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo
	@echo "✅$(GREEN)Libft archived>_$(END)✅"
$(OBJS_DIR)/%.o : %.c
	@$(DIR_DUP)
	@$(CC) $(C_FLAGS) -c $< -o $@
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))
	@echo -n ""
	@for i in `seq 1 $(shell echo "$$(($(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
		echo -n "$(G)▰$(X)" ; \
	done
	@for i in `seq 1 $(shell echo "$$(($(BAR_SIZE)-$(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
		echo -n "▱" ; \
	done
	@echo -n " [$(shell echo "scale=2; $(COMPILED_FILES)/$(TOTAL_FILES) * 100" | bc)%] "
# @echo -n ""
# @printf "%d/%d" $(COMPILED_FILES) $(TOTAL_FILES)
# @echo -n " "
# @printf "%s" $(notdir $<)
	@printf "\e[0K\r"

bonus: all $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)

%.o : %.c
	$(CC) $(C_FLAGS) -c -include ./libft.h $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
                                                                             
fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus
