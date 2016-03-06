#
# Makefile: Procedimento de compilação de slib
#
# Para utilizar:
#	make
#

# Comandos do sistema
CC = cc
RM = rm -f

# Variaveis do procedimento
CFLAGS = -Wall
LIBS = -L./ -lslib

# Nome do projeto
NAME = app
SLIB = libslib.so

# Objetos do projeto
LIBOBJECTS = slib.o
APPOBJECTS = app.o

# Procedimento de compilação
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# Sessão principal
all: $(NAME)

$(NAME): $(SLIB) $(APPOBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(APPOBJECTS) $(LIBS)

$(SLIB): $(LIBOBJECTS)
	$(CC) $(CFLAGS) -shared -Wl, -soname -Wl, $(SLIB) -o $(SLIB) $(LIBOBJECTS)

clean:
	$(RM) $(NAME) $(SLIB) $(APPOBJECTS) $(LIBOBJECTS)
