#	Compiler options and flags
CC = g++
CFLAGS = -std=c++17 -Wall

#	Directories
SRCDIR = ./cpp
INCDIR = ./headers

#	Definition and declaration files paths
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(wildcard $(INCDIR)/*.h)
MAIN = Main.cpp

#	Executable name
EXEC = Scheduler

#	Targets
all: $(EXEC)

$(EXEC): $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) -o $(EXEC)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f *.o $(EXEC)
