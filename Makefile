NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_printf_utils.c \
	   ft_printf_utils_two.c \
	   ft_tools.c


OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = .PHONY: all clean fclean re
