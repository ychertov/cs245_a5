CXX = g++
CXXFLAGS = -g -Wall -Wextra -Werror -MMD
OBJECTS = $(patsubst %.cc,%.o,$(wildcard *.cc))
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a5.out

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ printer.o -o $@

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}
