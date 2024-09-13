NAME = libasm.a
SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
# OBJ = ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o ft_read.o ft_strdup.o
OBJ = $(SRC:.s=.o)
NASM = nasm
NASMFLAGS = -f elf64
AR = ar
ARFLAGS = rcs
RM = rm -f
MAIN = main.c
PROGRAM = main

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

# https://www.gnu.org/software/make/manual/html_node/Pattern-Examples.html

# main:
# 	gcc -o $(PROGRAM) $(MAIN) $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
