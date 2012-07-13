CXX = g++
CXXFLAGS = -g -Wall -Wextra -WError -MMD
OBJECTS = vendingmachinecardeater.o vendingmachineovercharger.o watcard.o watcardoffice.o student.o nameserver.o bottlingplant.o truck.o printer.o driver.o printdatastore.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a5.out

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}
