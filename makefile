
vpath %.c src
vpath %.h include

CC := gcc

CFLAGS := -g -std=c11
CPPFLAGS := -I include
LFLAGS := -lm -lpthread

PROGRAM := pt

all: $(PROGRAM)

$(PROGRAM): build_msg main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(PROGRAM) main.o $(LFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o main.o $<

.PHONY: build_msg
build_msg:
	@printf "#\n# Building $(PROGRAM)\n#\n"

.PHONY: vcs
vcs:
	git status -u

.PHONY: clean
clean:
	rm -rf *.o $(PROGRAM)
