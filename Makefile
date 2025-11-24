# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: laveerka <laveerka@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/11/14 05:52:06 by laveerka      #+#    #+#                  #
#    Updated: 2025/11/24 11:05:21 by laveerka      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_char_string.c ft_itoa_atoi.c ft_number.c ft_pointer_hex.c \
	ft_printf_utils.c ft_printf.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_char_string_bonus.c ft_itoa_atoi_bonus.c ft_number_bonus.c \
	ft_pointer_hex_bonus.c ft_printf_bonus.c ft_printf_utils_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re