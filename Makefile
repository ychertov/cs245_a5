CXX = g++ 
CXXFLAGS = -g -Wall -Wextra -Werror -MMD
OBJECTS = bottlingplant.o nameserver.o student.o truck.o vendingmachinecardeater.o vendingmachine.o vendingmachineovercharger.o watcard.o watcardoffice.o
TEST_DRIVERS = twatcard.o twatcardoffice.o

MAIN_DRIVER = driver.o
DEPENDS = ${OBJECTS:.o=.d} ${TEST_DRIVERS:.o=.d} ${MAIN_DRIVER:.o=.d} 

TWATCARDOFFICE = twatcardoffice
TWATCARD = twatcard
MAIN = soda


TEST_EXECS = ${TWATCARD} ${TWATCARDOFFICE}
EXECS = ${MAIN} ${TEST_EXECS}
.PHONY : all clean tests

all : ${EXECS}

tests : ${TEST_EXECS}

${MAIN} : driver.o ${OBJECTS} 
	${CXX} ${CXXFLAGS} $^ printer.o -o $@

${TWATCARD} : twatcard.o ${OBJECTS} 
	${CXX} ${CXXFLAGS} $^ printer.o -o $@

${TWATCARDOFFICE} : twatcardoffice.o ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ printer.o -o $@

-include ${DEPENDS}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXECS}

