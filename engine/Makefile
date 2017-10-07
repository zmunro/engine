CPP := g++
CPPFLAGS := -std=c++14 -pthread

OBJ := obj
BIN := bin
SRC := src

EXEC := HW2

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CPP) -o "$(EXEC).out" $(EXEC).cpp $^ -I./$(SRC) $(CPPFLAGS) -L../Box2D -lBox2D -I..

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CPP) -o $@ -c $< -I.. $(CPPFLAGS)

clean:
	$(RM) "$(EXEC).out"
	$(RM) $(OBJECTS)

force:
	$(MAKE) clean
	$(MAKE) all -j5
