
vpath %.cpp src
vpath %.h include

CC := clang++

CFLAGS := -fcolor-diagnostics -I include -fcxx-exceptions -fdeclspec \
-fdebug-info-for-profiling -fdebug-macro -fdouble-square-bracket-attributes \
-fseh-exceptions -gdwarf-5 -g -pipe -pthread  -save-stats -std=c++17 -x c++ \
-gcodeview -gmodules -fdebug-info-for-profiling -faligned-allocation

LIBRARIES := -lpthread -lm
LINKEROPTS := -Xlinker --print-map -Xlinker --trace

LFLAGS := $(LIBRARIES)

SRCS := Bool.cpp Error.cpp main.cpp
OBJS := Bool.o Error.o main.o
#OBJS := $(patsubst(%.cpp, %.o, $(SRCS))

PROGRAM := PosixTest

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.cpp 
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf *.o $(PROGRAM)
