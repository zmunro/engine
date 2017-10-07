PACKAGE := Box2D

LIB := lib

CPP := g++
CPPFLAGS := -std=c++14 -Wall -L./$(LIB)

MAKEFLAGS := --no-print-directory

DEPS := Common Dynamics Collision Rope
DEPLIBS := $(DEPS:%=$(LIB)/lib%.a)

all: $(PACKAGE)

$(PACKAGE): $(DEPS)
	$(foreach dep, $(DEPS), $(MAKE) -C $(dep) $(MAKEFLAGS);)
	$(AR) crfT lib$(PACKAGE).a $(DEPLIBS)

clean:
	$(RM) lib$(PACKAGE).a

cleanall:
	$(MAKE) clean
	$(foreach dep, $(DEPS), $(MAKE) -C $(dep) clean $(MAKEFLAGS);)
