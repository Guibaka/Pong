objects := main.o
CXXFLAGS := -std=c++11
LDLIBS := -lglut -lGL -lGLU -lglut -lm

main: CC := $(CXX)
main: $(objects)
	$(LINK.o) $^ $(LDLIBS) -o $@

main.o: main.cpp

.PHONY: 
	clean

clean:
	$(RM) $(objects) main