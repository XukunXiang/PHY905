# Commet lines
# Here we define compiler option, libraries and the target
CXX = g++
CXXFLAGS = -Wall -g

PROG = binary

# Here we make the executable file
main: 	${PROG}.o
	${CXX} ${CXXFLAGS} ${PROG}.o -o main

# Whereas here we create the object file
objects = ${PROG}.o
${PROG}.o :	${PROG}.cpp
	${CXX} ${CXXFLAGS} -c ${PROG}.cpp

# Clean
clean:
	rm ${objects}
