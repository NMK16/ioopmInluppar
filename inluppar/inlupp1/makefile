# Compiler and options
C_COMPILER     = gcc
C_OPTIONS      = -Wall -pedantic -g
C_LINK_OPTIONS = -lm
CUNIT_LINK     = -lcunit

# Source files
SRC_FILES      = hashtable.c linked_list.c iterator.c
TEST_SRC_FILES = unit_tests.c linked_list_tests.c iterator_tests.c

# Object files (automatically generated for each .c file)
OBJ_FILES       = $(SRC_FILES:.c=.o) $(TEST_SRC_FILES:.c=.o)

# Executable for the main program
myprog: $(SRC_FILES:.c=.o)
	$(C_COMPILER) $(C_LINK_OPTIONS) $^ -o $@ $(CUNIT_LINK)

# Rule for building unit tests
unit_tests: unit_tests.o hashtable.o
	$(C_COMPILER) $(C_OPTIONS) $^ -o $@ $(CUNIT_LINK)

# Rule for testing linked list
linked_list_test: linked_list_tests.o linked_list.o
	$(C_COMPILER) $(C_OPTIONS) $^ -o $@ $(CUNIT_LINK)

# Rule for testing iterator
iterator_tests: iterator_tests.o iterator.o linked_list.o
	$(C_COMPILER) $(C_OPTIONS) $^ -o $@ $(CUNIT_LINK)

# Clean command to remove object files and executables
clean:
	rm -f *.o myprog unit_tests linked_list_test iterator_tests

# Run the tests
run: unit_tests
	./unit_tests

# Memory testing using Valgrind
memtest: unit_tests
	valgrind --leak-check=full ./unit_tests

# Pattern rule for object files
%.o: %.c
	$(C_COMPILER) $(C_OPTIONS) -c $< -o $@
