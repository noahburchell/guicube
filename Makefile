CC      ?= cc
CFLAGS  ?= -O2 -Wall -Wextra
CFLAGS  += -std=gnu23 $(shell pkg-config --cflags wayland-client)
LDLIBS  += $(shell pkg-config --libs wayland-client)

SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)

guicube: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f -- guicube $(OBJ)

.PHONY: clean
