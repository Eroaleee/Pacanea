CC=gcc
CFLAGS=-Wall -Wextra -std=c99

target=pacanea
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

build: $(target)

$(target): $(OBJS)
	$(CC) $(CFLAGS) -o $(target) $(OBJS)
	
clean:
	-rm -f $(OBJS) $(target)