CPP := g++
CPPFLAGS := -std=gnu++11 -pthread

OBJ := obj
BIN := bin
SRC := src

EXEC := Main

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CPP) -o "$(EXEC).out" $(EXEC).cpp $^ -I./$(SRC) $(CPPFLAGS) -L../Box2D/Box2D/Build/make/bin/Debug -lBox2D -I../Box2D/Box2D

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CPP) -o $@ -c $< -I../Box2D/Box2D $(CPPFLAGS)

clean:
	$(RM) "$(EXEC).out"
	$(RM) $(OBJECTS)

force:
	$(MAKE) clean
	$(MAKE) all -j5
