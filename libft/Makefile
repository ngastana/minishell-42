# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 12:26:10 by ngastana          #+#    #+#              #
#    Updated: 2023/09/29 16:25:51 by ngastana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*NAME= libft.a
#CC = gcc 
#CF = -Wall -Werror -Wextra
#RM = rm -rf
#SRC = ft_strlen.c \
#AR = ar
#				#ft_strlcat.c 
#ARFLAGS= rcs
#SRC_DIR = src/
#SRCS = $(SRC_DIR) $(SRC)
#OBJS = $(SRCS:%.c = %.o)

#.SILENT:
#all = $(NAME)

#%.o :$(SRC_DIR)%.c
#	$(CC) $(CFLAGS) -c $< -o $@

#$(NAME):    $(OBJS)
#			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

#clean:
#			@$(RM) $(OBJS) $(NAME)

#fclean:		clean
#			@$(RM) $(NAME)

#re:			fclean all
#.PHONY:		all clean fclean re

#NAME = libft.a

#SRCS =  $(shell find "." -name "*.c")
			
#OBJS        = ${SRCS:.c=.o}
#BONUSES		= ${shell find "." -name "*_bonus.c"}
#BONUS_OBJS  = ${BONUSES:.c=.o}
#CC      = gcc
#RM      = rm -rf
#CFLAGS      = -Wall -Wextra -Werror
#AR      = ar csr

#.c.o :
#		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#all : ${NAME}

#bonus: ${BONUSES} ${BONUS_OBJS}
#	${AR} -r ${NAME} $?

#$(NAME) : ${OBJS}
#		@${AR} libft.a ${OBJS} ${BONUS_OBJS}

#clean :
#		@${RM} ${OBJS} ${BONUS_OBJS}

#fclean : clean
#		@${RM} ${NAME}

#re : fclean all

#.PHONY: all clean fclean re .c.o

NAME = libft.a

CFLAGS = -c -Wall -Wextra -Werror

SRCS = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_tolower.c ft_toupper.c \
ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_calloc.c \
ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_split.c ft_atoi.c ft_itoa.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS=ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c \
ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)

$(OBJS_BONUS): $(SRCS_BONUS)
	gcc $(CFLAGS) $(SRCS_BONUS)

.PHONY: all clean fclean re bonus
