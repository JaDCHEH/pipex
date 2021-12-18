NAME = pipex.a

CC = @cc

AR = @ar -r

FLAGS = -Wall -Wextra -Werror -c 

RM = @rm -f

CFILES = execution.c \
			find_path.c \
			ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_substr.c \
			pipex.c \
			main.c \


EXEC = pipex

N_FLAG = -o

OFILES = execution.o \
			find_path.o \
			ft_split.o \
			ft_strdup.o \
			ft_strjoin.o \
			ft_strlen.o \
			ft_strncmp.o \
			ft_substr.o \
			pipex.o \
			main.o \

all : $(NAME)

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) $(CFILES) 
	$(AR) $(NAME) $(OFILES)	
	$(CC) $(NAME) $(N_FLAG) $(EXEC)

clean :
	$(RM) $(OFILES)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(EXEC)

re : fclean all