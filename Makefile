CXX = g++ 
CXXFLAGS = -g -Wall -Wextra -Werror -O2 -MMD #-D DEBUG_ON 
OBJECTS = bottlingplant.o nameserver.o student.o truck.o vendingmachinecardeater.o vendingmachine.o vendingmachineovercharger.o watcard.o watcardoffice.o
TEST_DRIVERS = twatcard.o twatcardoffice.o ttruck.o tvendingmachine.o

MAIN_DRIVER = driver.o
DEPENDS = ${OBJECTS:.o=.d} ${TEST_DRIVERS:.o=.d} ${MAIN_DRIVER:.o=.d} 

#TESTS = twatcard twatcardoffice ttruck tvendingmachine tdriver
TESTS = ${TEST_DRIVERS:.o=}
MAIN = soda
EXECS = $(MAIN) $(TESTS)

.PHONY : all clean tests

all : ${EXECS}

tests : ${TESTS}

${MAIN} : driver.o ${OBJECTS} 
	${CXX} ${CXXFLAGS} $^ printer.o -o $@

define func
$1: $1.o ${OBJECTS}
	${CXX} ${CXXFLAGS} $1.o ${OBJECTS} printer.o -o $1
endef

$(foreach EXEC,$(TESTS),$(eval $(call func,$(EXEC))))

#${TWATCARD} : twatcard.o ${OBJECTS} 
#	${CXX} ${CXXFLAGS} $^ printer.o -o $@

#${TWATCARDOFFICE} : twatcardoffice.o ${OBJECTS}
#	${CXX} ${CXXFLAGS} $^ printer.o -o $@

-include ${DEPENDS}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXECS}

