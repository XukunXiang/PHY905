# Commet lines
# Here we define compiler option, libraries and the target
CXX = g++
CXXFLAGS = -Wall -O3

PROG = gaussian

# Here we make the executable file
main: 	${PROG}.o mysecond.o
	${CXX} -o main ${CXXFLAG} ${PROG}.o mysecond.o

# Whereas here we create the object file
objects = ${PROG}.o mysecond.o

${PROG}.o :	${PROG}.cpp
	${CXX} ${CXXFLAGS} -c ${PROG}.cpp

mysecond.o:
	$(CXX) -c -O2 mysecond.c

# Clean
clean:
	rm ${objects}

realclean:
	rm main 
