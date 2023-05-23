CC=gcc
CFLAGS=-Iinclude -I./include
LDFLAGS=-L./lib
DEPS = player.h http_client.h useful.h
OBJ = src/player.o src/http_client.o src/main.o src/useful.o
LIBS=./lib/libcurl.lib

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

riotapi: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LIBS)

.PHONY: run
run: riotapi
	./riotapi
