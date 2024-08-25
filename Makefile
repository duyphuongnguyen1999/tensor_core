########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings
CC = gcc
CFLAGS = -std=c11 -Wall -g
LDFLAGS = 

# Makefile settings
APPNAME = C-DSALib	# Core name of the application
LIBNAME = lib$(APPNAME).a	# Static library is 'libC-DSALib.a'
EXT = .c # Source file extension

# Directories
SRCDIR = src				# Directory for the source files
INCDIR = include			# Directory for the header files
OBJDIR = obj				# Directory for the object files
LIBDIR = lib				# Directory for the library files
TESTDIR = tests				# Directory for the test files
EXAMPDIR = examples			# Directory for the example files

# Gather all source, objects, dependency files
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)

# Identify the OS type to adjust commands
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux) 		# Linux OS variables & settings
	MKDIR = mkdir -p
	EXE_EXT =
	RM = rm -rf
else ifeq ($(UNAME_S),Darwin) 	# macOS variables & settings
	MKDIR = mkdir -p
	EXE_EXT =
	RM = rm -rf
else	# Window OS variables & settings
	MKDIR = mkdir
	EXE_EXT = .exe				
	RM = del /Q /F

########################################################################
####################### Targets beginning here #########################
########################################################################

# Default target to build the static library
all: $(LIBDIR)/$(LIBNAME)

# Create static library
$(LIBDIR)/$(LIBNAME): $(OBJ)
	@$(MKDIR) $(LIBDIR)
	ar rcs $@ $(OBJ)		

# Rule for building object files from source files
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	@$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

# Create the dependency files for header inclusion
%.d: $(SRCDIR)/%$(EXT)
	@$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -MM -MT $(@:%.d=$(OBJDIR)/%.o) $< > $@

# Include all .d files (dependency rules)
-include $(DEP)

# Clean up all generated files (multi-OS compatible)
.PHONY: clean
clean:
	$(RM) $(OBJ) $(DEP) $(LIBDIR)/$(LIBNAME) $(TESTDIR)/*$(EXE_EXT) $(EXAMPLEDIR)/*$(EXE_EXT)

# Cleans only all files with the extension .d (multi-OS compatible)
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

########################################################################
##################### Test Compilation and Execution ###################
########################################################################

# Set test files and define their compilation and execution
TESTS = $(wildcard $(TESTDIR)/*$(EXT))
TEST_EXES = $(TESTS:.c=$(EXE_EXT))

# Compile and run all tests
.PHONY: test
test: $(TEST_EXES)
	@for test in $(TEST_EXES); do .$(if $(EXE_EXT),\\,/)$$test; done

# Compile indivisual test file
$(TESTDIR)/%$(EXE_EXT): $(TESTDIR)/%$(EXT) $(LIBDIR)/$(LIBNAME)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $< -L$(LIBDIR) -l$(APPNAME)

########################################################################
################### Example Compilation and Execution ##################
########################################################################

# Set example files and define their compilation and execution
EXAMPLES = $(wildcard $(EXAMPLEDIR)/*$(EXT))
EXAMPLE_EXES = $(EXAMPLES:.c=$(EXE_EXT))

# Compile and run all examples
.PHONY: example
example: $(EXAMPLE_EXES)
	@for example in $(EXAMPLE_EXES); do .$(if $(EXE_EXT),\\,/)$$example; done

# Compile individual example file
$(EXAMPLEDIR)/%$(EXE_EXT): $(EXAMPLEDIR)/%$(EXT) $(LIBDIR)/$(LIBNAME)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $< -L$(LIBDIR) -l$(APPNAME)

########################################################################
##################### Windows Compatibility Notes #####################
########################################################################

# If on Windows, this Makefile assumes that you're using a compatible
# shell environment, such as MinGW or Cygwin, where the `mkdir` and `rm`
# commands will behave as expected. In native Windows Command Prompt,
# use compatible commands as needed.





