NAME = pipex

NAME_BONUS = pipex_bonus

CC = @cc

FLAGS = -Wall -Wextra -Werror 

RM = @rm -f

C_FILES = execution.c \
			find_path.c \
			ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_substr.c \
			pipex.c \

M_FILE = main.c \

B_FILE = main_bonus.c \

N_FLAG = -o

#  colors

C_PURPLE = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

all : $(NAME)

$(NAME) : $(C_FILES) $(M_FILE)
	@echo "$(C_GREEN)["pipex" CREATED]$(C_RES)"
	$(CC) $(FLAGS) $(C_FILES) $(M_FILE) $(N_FLAG) $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(C_FILES) $(B_FILE)
	@echo "$(C_L_BLUE)["pipex" BONUS CREATED]$(C_RES)"
	$(CC) $(FLAGS) $(C_FILES) $(B_FILE) $(N_FLAG) $(NAME_BONUS)

clean :
	@echo "$(C_PURPLE)["pipex" REMOVED]$(C_RES)"
	$(RM) $(NAME)

fclean :
	@echo "$(C_PURPLE)["pipex" BONUS REMOVED]$(C_RES)"
	$(RM) $(NAME_BONUS)

re : clean all