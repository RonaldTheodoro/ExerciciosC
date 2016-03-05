#
# Makefile: procedimento de compilação para pr1
#
# Para utilizar:
#	make
#

# Comandos do sistema

CC = cc
RM = rm -f

# Variaveis do procedimento

CFLAGS = -Wall
LIBS = # -lsample

# Nome do projeto

NAME = pr1

# Objetos do projeto

OBJECTS = pr1.o info.o

# Procedimento de compilação
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# Sessão principal, dependente de $(OBJECTS) e $(NAME)
all: $(OBJECTS) $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)

clean:
	$(RM) $(OBJECTS) $(NAME)
