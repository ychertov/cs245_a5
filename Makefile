CXX = g++ 
CXXFLAGS = -g -Wall -Wextra -Werror -MMD
OBJECTS = bottlingplant.o nameserver.o student.o truck.o vendingmachinecardeater.o vendingmachine.o vendingmachineovercharger.o watcard.o watcardoffice.o
TEST_DRIVERS = twatcard.o

MAIN_DRIVER = driver.o
DEPENDS = ${OBJECTS:.o=.d} ${TEST_DRIVERS:.o=.d} ${MAIN_DRIVER:.o=.d} 

TWATCARD = twatcard
MAIN = soda

EXECS = ${MAIN} ${TWATCARD}
.PHONY : all clean tests

all : ${EXECS}

${MAIN} : driver.o ${OBJECTS} 
	${CXX} ${CXXFLAGS} $^ printer.o -o $@

${TWATCARD} : watcard_driver.o ${OBJECTS} 
	${CXX} ${CXXFLAGS} $^ printer.o -o $@

${EXEC_MAIN} : ${PROJ_OBJECTS}
	${CXX} ${CXXFLAGS} $^ printer.o -o $@


-include ${DEPENDS}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXECS}

