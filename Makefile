objects := main.o score.o racket.o ball.o
CXXFLAGS := -std=c++11
LDLIBS := -lglut -lGL -lGLU -lglut -lm

main: CC := $(CXX)
main: $(objects)
	$(LINK.o) $^ $(LDLIBS) -o $@

score.o : score.h

racket.o : racket.h

ball.o : ball.h

main.o: main.cpp

.PHONY: 
	clean

clean:
	$(RM) $(objects) main