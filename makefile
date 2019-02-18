
vpath %.cpp src
vpath %.h include

CC := clang++

CFLAGS := -fcolor-diagnostics -I include -fcxx-exceptions -fdeclspec \
-fdebug-info-for-profiling -fdebug-macro -fdouble-square-bracket-attributes \
-fseh-exceptions -gdwarf-5 -g -pipe -pthread  -save-stats -std=c++17 -x c++ \
-gcodeview -gmodules -fdebug-info-for-profiling -faligned-allocation

LIBRARIES := -lpthread -lm

LFLAGS := $(LIBRARIES) -Xlinker --print-map -Xlinker --trace

PROGRAM := PosixTest

all: $(PROGRAM)

$(PROGRAM): main.o
	$(CC) -o $@ $^ $(LFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf *.o $(PROGRAM)
