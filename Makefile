CC=gcc
RM=rm
CFLAGS :=-c -Wall -Isrc
LDFLAGS :=

SRCS := $(wildcard tests/*.c)
PRGS := $(patsubst %.c,%,$(SRCS))
BINS := $(patsubst %,%,$(PRGS))
OBJS := $(patsubst %,%.o,$(PRGS))
OBJ = $(patsubst %,%.o,$@)
BIN = $(patsubst %,%,$@)

all : $(BINS) test clean

$(BINS): $(OBJS)
	@$(CC) $(OBJ) $(LDFLAGS) -o $(BIN)

test:
	@tests/run_tests.sh

clean:
	@$(RM) $(BINS) $(OBJS)
