##
## Gertrude v.1
##
## This Makefile was generated using Gertrude
##
## (Gertrude is an open-source Makefile creation tool)
##

SRC	=	$(wildcard *.c)	\
		$(wildcard src/*.c)	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

EXEC	=	ai

CFLAGS	+=	-Wall -g3

all:	build	clean

build:	${OBJ}	gertrude
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

clean:
	rm -f vgcore.* $(OBJ) *.gch

fclean:	clean
	rm -f $(EXEC)

re:	fclean	all

gertrude:
	@echo -e "\n\n\033[3mGertrude-CLI - Makefile creation tool\033[0m\n"

.PHONY:	all	build	clean	fclean	re
