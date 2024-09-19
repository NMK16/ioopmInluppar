# Compiler and options
C_COMPILER     = gcc
C_OPTIONS      = -Wall -pedantic -g
C_LINK_OPTIONS = -lm
CUNIT_LINK     = -lcunit

# Object files (automatically generated for each .c file)
%.o: %.c
	$(C_COMPILER) $(C_OPTIONS) $^ -c

# Executable for the main program
myprog: unit_tests.o hashtable.o
	$(C_COMPILER) $(C_LINK_OPTIONS) $^ -o $@ $(CUNIT_LINK)

# Executable for testing
test_hash_table: unit_tests.o hashtable.o
	$(C_COMPILER) $(C_LINK_OPTIONS) $? -o $@ $(CUNIT_LINK)

# Clean command to remove object files and executables
clean:
	rm -f *.o myprog test_hash_table

# Run the tests
run: test_hash_table
	./test_hash_table

# Memory testing using Valgrind
memtest: test_hash_table
	valgrind --leak-check=full ./test_hash_table
