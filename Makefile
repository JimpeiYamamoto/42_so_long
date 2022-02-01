# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 14:13:30 by yjimpei           #+#    #+#              #
#    Updated: 2022/01/30 06:14:49 by yjimpei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./lib/libft
MLX_DIR = ./minilibx-linux
CC = gcc
#CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I ${MLX_DIR} -I ${INCLUDES} -I ${LIBFT_DIR}

# Mandatory
NAME = so_long
SRCS_DIR = ./srcs/
SRCS_NAME = main.c \
			get_next_line.c \
			get_next_line_utils.c \
			input_map_utils.c \
			ft_exit.c \
			init_data.c \
			put_console.c \
			key_hook_utils.c
SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAME}}
OBJS = ${SRCS:.c=.o}
INCLUDES = ./includes
CFLAGS = -Wall -Wextra -Werror -I ${MLX_DIR} -I ${INCLUDES} -I ${LIBFT_DIR}
#FLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I ${MLX_DIR} -I ${INCLUDES} -I ${LIBFT_DIR}
# bonus
NAME_BONUS = so_long_bonus
SRCS_DIR_BONUS = ./srcs_bonus/
SRCS_NAME_BONUS =	main_bonus.c \
					ft_exit_bonus.c \
					get_next_line_bonus.c \
					get_next_line_utils_bonus.c \
					init_data_bonus.c \
					input_map_bonus.c \
					input_map_utils_bonus.c \
					loop_bonus.c \
					key_hook_bonus.c \
					enemy_setting_bonus.c \
					put_info_bonus.c \
					xpm_to_data_bonus.c \
					xpm_to_data2_bonus.c

SRCS_BONUS = ${addprefix ${SRCS_DIR_BONUS}, ${SRCS_NAME_BONUS}}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
CFLAGS_BONUS = -Wall -Wextra -Werror -I ${MLX_DIR} -I ${INCLUDES} -I ${LIBFT_DIR}
#CFLAGS_BONUS = -Wall -Wextra -Werror -g -fsanitize=address -I ${MLX_DIR} -I ${INCLUDES} -I ${LIBFT_DIR}


all: 		${NAME}

${NAME}:	${MLX_DIR} ${OBJS} ${INCLUDES} ${LIBFT_DIR}
	@${MAKE} -C ${MLX_DIR}
	@${MAKE} -C ${LIBFT_DIR}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${MLX_DIR} -lmlx -lXext -lX11 -L ${LIBFT_DIR} -lft

bonus:	${MLX_DIR} ${OBJS_BONUS} ${INCLUDES} ${LIBFT_DIR}
	@${MAKE} -C ${MLX_DIR}
	@${MAKE} -C ${LIBFT_DIR}
	${CC} ${CFLAGS_BONUS} -o ${NAME_BONUS} ${OBJS_BONUS} -L ${MLX_DIR} -lmlx -lXext -lX11 -L ${LIBFT_DIR} -lft

${MLX_DIR}:
	git clone https://github.com/42Paris/minilibx-linux.git ${MLX_DIR}

clean:
	${MAKE} -C ${LIBFT_DIR} clean
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
	${MAKE} -C ${LIBFT_DIR} fclean
	${RM} -r ${NAME} ${MLX_DIR} ${NAME_BONUS}

re: fclean all

leak: ${NAME}
	valgrind --leak-check=full ./$(NAME) map/validate_map/stage0.ber

leak_bonus: bonus ${NAME_BONUS}
	valgrind --leak-check=full ./$(NAME_BONUS) map/validate_map/stage0.ber

.PHONY: all clean fclean re leak leak_bonus