CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD
OBJECTS=main.o Shuttle.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=dmf

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
