# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 05:28:16 by bmarek            #+#    #+#              #
#    Updated: 2024/03/22 08:21:21 by bmarek           ###   ########.fr        #
#                                                                              #void	return_error(void)
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(MINLIBX) -Imlx -O3

PFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o

MINLIBX = minilibx-linux

SRCS = ft_fractol.c \
		ft_atod.c \
		ft_draw_fractols.c \
		ft_error_handling.c \
		ft_error_msg.c \
		ft_fractal_calculation.c \
		ft_fractol_utils.c \
		ft_init_fractal_environment.c \
		ft_keycode.c \

OBJS = $(SRCS:.c=.o)

title: all

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MINLIBX)
	cp $(MINLIBX)/libmlx_Linux.a .
	$(CC) $(OBJS) libmlx_Linux.a $(PFLAGS) $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^ 
	
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f libmlx_Linux.a
	make -C $(MINLIBX) clean

re : fclean all title

.PHONY: all clean fclean re title

COLOR_GREEN=\033[32m
COLOR_YELLOW=\033[33m
COLOR_MAGENTA=\033[35m
COLOR_RED=\033[31m
COLOR_BLUE=\033[34m
COLOR_CYAN=\033[36m
BOLD=\033[1m
COLOR_END=\033[0m

title:
	@clear
	@echo " "
	@echo " "
	@echo "$(COLOR_GREEN)$(BOLD)#######   ########         ####          ######   ############  ######     ##"
	@echo "##       ##      ##      ##    ##       ##    ##       ##      ##    ##    ##"
	@echo "##       ##       ##    ##      ##     ##      ##      ##     ##      ##   ##"
	@echo "##       ##     ##     ##        ##   ##               ##    ##        ##  ##"
	@echo "#######  #######      ##          ##  ##               ##    ##        ##  ##"
	@echo "##       ##     ##    ##############  ##               ##    ##        ##  ##"
	@echo "##       ##      ##   ##          ##   ##      ##      ##     ##      ##   ##"
	@echo "##       ##       ##  ##          ##    ##    ##       ##      ##    ##    ##"
	@echo "##       ##        ## ##          ##     ######        ##       ######     ########"
	@echo "$(COLOR_YELLOW)"
	@echo "		     You are able to see two fractols: "
	@echo "		      Fractol Julia: ./fractol julia "
	@echo "		  Fractol Mandelbrot: ./fractol mandelbrot "
	@echo "$(COLOR_MAGENTA) "
	@echo "			Different Julia sets examples:"
	@echo "$(COLOR_CYAN)"
	@echo "			      -0.079       0.15"
	@echo "			      -0.162       1.04"
	@echo "			       0,300       -0.1"
	@echo "			      -1.476       0.00"
	@echo "			      -0.120       0,77"
	@echo "			       0,280       0,008"
	@echo "$(COLOR_MAGENTA)"