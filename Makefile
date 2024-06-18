OBJS_PS = $(SRCS_PS:.c=.o)
SRCS_PS = $(addprefix $(SRC_DIR), \
	core/main.c core/calc_a.c core/calc_b.c core/sort_three.c core/turk_algo.c core/move_sort.c \
	operations/push.c operations/swap.c operations/rotate.c operations/r_rotate.c \
	utils/init.c utils/utils.c utils/utils2.c utils/error.c \
)

SRC_DIR	= ./sources/
INC_DIR	= ./includes/
CC = gcc
MF = Makefile

NAME = push_swap
LIBFT_PATH = ./libft/libft.a
PS_HEADER_FILE = $(INC_DIR)/push_swap.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MF) $(LIBFT_PATH) $(OBJS_PS)
	@$(CC) $(CFLAGS) $(OBJS_PS) $(LIBFT_PATH) -o $(NAME)
	@echo  ""
	@printf "\033[1;32m%s\033[0m\n" "[push_swap] Compiled successfully."
	@cat push_swap_splash.txt

%.o: %.c $(PS_HEADER_FILE) $(MF)
	@printf "\033[1;32m|\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIBFT_PATH): .libft

.libft:
	@make -s -C ./libft

clean:
	@make -s clean -C ./libft
	@rm -f $(OBJS_PS)
	@printf "\033[1;31m%s\033[0m\n" "[push_swap] Object files cleaned."

fclean: clean
	@make -s fclean -C ./libft
	@rm -f $(NAME)
	@printf "\033[1;31m%s\033[0m\n" "[push_swap] Cleaned successfully."

re: fclean all

.PHONY: all clean fclean re