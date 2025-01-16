CC = cc

CFLAGS = -Wall -Werror -Wextra 

MFLAGS = -Lminilibx-linux -lmlx -lXext -lX11

SLSRCS =  so_long_dir/main.c so_long_dir/initilize.c so_long_dir/put_image.c so_long_dir/move_player.c so_long_dir/error_handling.c \
so_long_dir/free.c so_long_dir/collectable.c so_long_dir/check_images_num.c so_long_dir/flood_fill.c\
so_long_dir/helper.c

SLOBJ = $(SLSRCS:.c=.o)

LIBFT_DIR = libft

LIBFT_A = libft/libft.a

NAME = so_long

all: $(NAME)

$(NAME) : $(SLOBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(SLOBJ) $(MFLAGS) -o $@ -L $(LIBFT_DIR) -lft

$(SLOBJ): %.o : %.c
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o $@
	
$(LIBFT_A) : 
	make -C $(LIBFT_DIR)
clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(SLOBJ)
fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
