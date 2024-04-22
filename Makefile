NAME = so_long
BONUS = so_long_bonus
LIBFT = ./libft/libft.a
MLX42 = ./MLX42/build/libmlx42.a

FILES = so_long.c \
		handle_errors.c \
		free_utils.c \
		error_utils.c \
		textures.c \
		textures_character.c \
		images.c \
		movements.c \
		game_checker.c \
		initialize_game_data.c \
		check_path.c \
		utils.c \

BONUS_FILES = bonus/so_long_bonus.c \
			bonus/handle_errors_bonus.c \
			bonus/free_utils_bonus.c \
			bonus/error_utils_bonus.c \
			bonus/textures_bonus.c \
			bonus/textures_character_bonus.c \
			bonus/images_bonus.c \
			bonus/movements_bonus.c \
			bonus/game_checker_bonus.c \
			bonus/initialize_game_data_bonus.c \
			bonus/check_path_bonus.c \
			bonus/print_on_screen_bonus.c \
			bonus/utils_bonus.c \

OFILES = $(FILES:%.c=%.o)
OBONUS = $(BONUS_FILES:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
FLAGSMLX = -ldl -lglfw -pthread -lm
#FLAGSMLX = -L/opt/homebrew/lib -lglfw -lm
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
	@echo "Compiled ✅ $(MLX42)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFTDIR) -I $(MLX42DIR)

%.o: bonus/%.c 
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFTDIR) -I $(MLX42DIR)

$(NAME): $(LIBFT) $(MLX42) $(OFILES)
	$(CC) $(CFLAGS) $(FLAGSMLX) $(OFILES) $(LIBFT) $(MLX42) -o $(NAME)
	@echo "Compiled so_long ✅ $^"


bonus: $(LIBFT) $(MLX42) $(OBONUS)
	$(CC) $(CFLAGS) $(FLAGSMLX) $(OBONUS) $(LIBFT) $(MLX42) -o $(BONUS)
	@echo "Compiled so_long_bonus ✅ $^"

clean:
	@rm -f $(OFILES)

clean_bonus:
	@rm -f $(OBONUS)

fclean: clean clean_bonus
	@cd libft && $(MAKE) fclean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@echo "Cleaned all ✅"

re: fclean all

.PHONY: all, clean, fclean, re, clean_bonus, bonus
