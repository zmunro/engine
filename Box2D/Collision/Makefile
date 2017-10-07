COMPONENT := Collision

OBJ := obj
LIB := ../lib
INC := ../..

CPP := g++
CPPFLAGS := -std=c++14 -I$(INC)

SOURCES := $(shell find . -name "*.cpp")
OBJECTS := $(SOURCES:%.cpp=$(OBJ)/%.o)

all: $(COMPONENT)

$(COMPONENT): $(OBJECTS)
	$(AR) crf $(LIB)/lib$(COMPONENT).a $^

$(OBJ)/%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)/*.o
	$(RM) $(OBJ)/Shapes/*.o
	$(RM) $(LIB)/lib$(COMPONENT).a
