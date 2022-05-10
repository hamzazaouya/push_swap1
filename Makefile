NAME = push_swap
BONUS = checker
HEADER = push_swap.h

SOURCES = push_swap.c stacks.c \
		rules1.c rules2.c rules3.c push_bta.c push_atb.c ft_aid_fun.c \
		check.c prepare_stack_a.c rules4.c
SOURCES_B = checker.c ../srcs/stacks.c ../srcs/check.c

BONUS_PATH = bonus
SRC_PATH = srcs
OBJ_PATH  = objs
OBJ_PATH_B = objs_b
LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a

CC = cc

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

OBJS_B = $(addprefix $(OBJ_PATH)/,$(SOURCES_B:.c=.o))


all : $(OBJ_PATH) $(NAME)

$(LIB):
	@cd $(LIB_PATH) && make && make clean


$(NAME) : $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c includes/$(HEADER)
	@$(CC) -c -o $@ $<

$(OBJ_PATH):
	@mkdir objs

bonus: $(BONUS)

$(BONUS): $(OBJS_B) $(LIB) $(OBJ_PATH_B)
	$(CC) $(OBJS_B) $(LIB) -o $(BONUS)

$(OBJ_PATH_B)/%.o: $(BONUS_PATH)/%.c includes/$(HEADER)
	@$(CC) -c -o $@ $<

$(OBJ_PATH_B):
	@mkdir objs_b

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	@cd $(LIB_PATH) && make fclean
	rm -fr $(OBJ_PATH)
	rm -fr $(OBJ_PATH_B)
re : fclean all