#
# Specifiy the target
all:	Files
			./Main sample_1.txt 010100
# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Files: FSM.o
	g++ -g FSM.o -o Main

# Specify how the object files should be created from source files
FSM.o: FSM.cpp
	g++ -g -c FSM.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Main
