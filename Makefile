CXX = g++
CXXFLAGS = -g -Wall -Wextra -Werror -MMD
OBJECTS = vendingmachinecardeater.o vendingmachineovercharger.o watcard.o watcardoffice.o student.o nameserver.o bottlingplant.o truck.o printer.o driver.o printdatastore.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a5.out

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}
