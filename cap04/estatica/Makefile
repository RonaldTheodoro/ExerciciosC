#
# Makefile: Procedimento de compilação de slib
#
# Para utilizar:
#	make
#

# Comandos do sistema
CC = cc
RM = rm -f
AR = ar rc
RANLIB = ranlib

# Variaveis do procedimento
CFLAGS = -Wall
LIBS = -L./ -lslib

# Nome do projeto
NAME = app
SLIB = libslib.a

# Objetos do projeto
LIBOBJECT = slib.o
APPOBJECT = app.o

# Procedimento de compilação
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# Sessão principal
all: $(NAME)

$(NAME): $(SLIB) $(APPOBJECT)
	$(CC) $(CFLAGS) -o $(NAME) $(APPOBJECT) $(LIBS)

$(SLIB): $(LIBOBJECT)
	$(AR) $(SLIB) $(LIBOBJECT)
	$(RANLIB) $(SLIB)

clean:
	$(RM) $(NAME) $(SLIB) $(APPOBJECT) $(LIBOBJECT)
