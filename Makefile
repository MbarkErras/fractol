NAME=fractol

SRCS=fractol.c \
	 renderer.c \
	 fractal_iterator.c \
	 render_hooks.c \

OBJS=$(SRCS:.c=.o)

LIBS_DIR=libs
OBJS_DIR=build
SRCS_DIR=srcs
OBJS_PATH=$(addprefix $(OBJS_DIR)/, $(OBJS))
SRCS_PATH=$(addprefix $(SRCS_DIR)/, $(SRCS))
INCLUDES=includes

FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS_PATH) $(INCLUDES)/fractol.h
	make -C $(LIBS_DIR)/centropy
	gcc $(OBJS_PATH) $(LIBS_DIR)/centropy/centropy.a -lmlx -framework openGL -framework AppKit -o $(NAME)

$(OBJS_PATH): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	make -C $(LIBS_DIR)/centropy clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C $(LIBS_DIR)/centropy fclean
	rm -rf $(NAME)

re: fclean all
	make -C $(LIBS_DIR)/centropy re
