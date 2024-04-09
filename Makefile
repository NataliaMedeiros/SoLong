NAME = so_long
#BONUS =
LIBFT = ./libft/libft.a
#MLX42 = ./MLX42/libmlx.dylib

FILES = so_long.c \
		handle_errors.c \

#BONUS_FILES =

#CBONUS = $(BONUS_FILES:%=%.c)

OFILES = $(FILES:%.c=%.o)
#OBONUS = $(CBONUS:%.c=%.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft

all: $(NAME)

$(LIBFT):
	@echo "Compiling ..."
	@make -C $(LIBFTDIR)
	@echo "Compiled ✅ $(LIBFT)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(LIBFTDIR)

$(NAME): $(LIBFT) $(OFILES)
	$(CC) $(FLAGS) $(OFILES) $(LIBFT) -o $(NAME)
	@echo "Compiled push_swap ✅ $^"

#bonus: $(LIBFT) $(OBONUS)
#	$(CC) $(FLAGS) $(OBONUS) $(LIBFT) -o $(BONUS)
#	@echo "Compiled checker ✅ $^"

clean:
	@rm -f $(OFILES)
#	@rm -f $(OBONUS)

fclean: clean
	@cd libft && $(MAKE) fclean
	@rm -f $(NAME)
#	@rm -f $(BONUS)
	@echo "Cleaned all ✅"

re: fclean all

.PHONY: all, clean, fclean, re, bonus
