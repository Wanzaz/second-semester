
NAME=funkce

DEBUGER=kdbg
CC=gcc
CFLAGS=-std=c99 -pedantic  -Wall  -Wextra -g

OBJFILES=$(NAME).o pomocny-modul.o

%.o : %.c
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

pomocny-modul.o: pomocny-modul.h pomocny-modul.c
$(NAME).o: main.c

$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -lm -o $@

run:
	./$(NAME)

debug: $(NAME)
	$(DEBUGER) $(NAME)

clean:
	rm -f $(NAME) *~ *.bak *.o *.save

edit:
	kate main.c

