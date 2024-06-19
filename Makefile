COMPILE.C=$(COMPILE.cc)
COMPILE.cc=$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
CXXFLAGS=-g3 -I headers 
CPPFLAGS= -Wall -Wextra -Wpedantic 
CXX= g++
OUTPUT_OPTION = -o $@
#Linking:
LINK.o = $(CC) $(LDFLAGS) $(TARGET_ARCH)
CC= g++

vpath %.cc sources
vpath %.h headers

#rules:

%: %.o 
	$(LINK.o) $(OUTPUT_OPTION) $^
%.o: %.c++
	$(COMPILE.C) $(OUTPUT_OPTION) $<

run: c++
	valgrind --track-origins=yes --leak-check=full ./c++ 


# .PHONY: String.cc String.h

c++: c++.o stock.o

# queue.o: queue.cc
c++.o: c++.cc 
stock.o: stock.cc
# cow.o: cow.cc 
# String.o: String.cc 
# stringBad.o: stringBad.cc 
# myCl: myCl.o 
# myCl.o: myCl.cc 
.INTERMEDIATE: *.o

.PHONY: depend #Now the file will be updated each time it is called.
depend: c++.cc
	g++ -I headers -M $(CPPFLAGS) $^ > $@
	more depend

.PHONY:clean
clean:
	rm -rf *.o c++