NAME = so_long
#BONUS =
LIBFT = ./libft/libft.a
MLX42 = ./MLX42/build/libmlx42.a

FILES = so_long.c \
		handle_errors.c \
		free_utils.c \
		error_utils.c \

#BONUS_FILES =

#CBONUS = $(BONUS_FILES:%=%.c)

OFILES = $(FILES:%.c=%.o)
#OBONUS = $(CBONUS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
#FLAGSMLX = -ldl -lglfw -pthread -lm
FLAGSMLX = -L/opt/homebrew/lib -lglfw -lm
LIBFTDIR = libft
MLX42DIR = MLX42

all: $(NAME)

$(LIBFT):
	@echo "Compiling ..."
	@make -C $(LIBFTDIR)
	@echo "Compiled ✅ $(LIBFT)"

$(MLX42):
	@echo "compiling ..."
	@cmake $(MLX42DIR) -B $(MLX42DIR)/build && make -C $(MLX42DIR)/build -j4
#	@make -C $(MLX42DIR)
	@echo "Compiled ✅ $(MLX42)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFTDIR) -I $(MLX42DIR)

$(NAME): $(LIBFT) $(MLX42) $(OFILES)
	$(CC) $(CFLAGS) $(FLAGSMLX) $(OFILES) $(LIBFT) $(MLX42) -o $(NAME)
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
