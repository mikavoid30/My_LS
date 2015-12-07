##
## Makefile for colle3 in /home/hounak_e/rendu/Piscine_C_colles-Semaine_03
## 
## Made by Enam HOUNAKE KOUASSI
## Login   <hounak_e@epitech.net>
## 
## Started on  Sat Oct 25 18:11:34 2014 Enam HOUNAKE KOUASSI
## Last update Fri Nov  7 17:18:46 2014 Mickael BOULAT
##

RM	= rm -f

SRCS	= main.c \
	  functions/options.c \
	  functions/options_2.c \
	  functions/directories.c \
	  functions/get_conf.c \
	  functions/xmalloc.c \
	  functions/utils_1.c \
	  functions/utils_2.c \
	  functions/utils_3.c

OBJS	= $(SRCS:.c=.o)

NAME	= my_ls

HNAME	= -I ./include

CFLAGS = -W -Wall $(HNAME)

LIBNAME	= -L ./lib/my -lmy

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS) $(LIBNAME) $(CFLAGS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
