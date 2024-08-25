########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings
CC = gcc
CXXFLAGS = -std=c11 -Wall -g
LDFLAGS = 

# Makefile settings
APPNAME = C-DSALib.a
EXT = .c

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
LIBDIR = lib
TESTDIR = tests
EXAMPDIR = examples
MKDIR = mkdir -p

# Find all source files, objects, and test files
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
TESTS = $(wildcard $(TESTDIR)/*$(EXT))
EXAMPLES = $(wildcard $(EXAMPDIR)/*$(EXT))

# Create dependency files 
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)

# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)

# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(LIBDIR)/$(APPNAME)

# Create static library
$(LIBDIR)/$(APPNAME): $(OBJ)
	@$(MKDIR) $(LIBDIR)
	ar rcs $@ $(OBJ)		

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	@$(MKDIR) $(OBJDIR)
	$(CC) $(CXXFLAGS) -I$(INCDIR) -o $@ -c $<

# Includes all .h files
-include $(DEP)

# Creates the dependecy rules
%.d: $(SRCDIR)/%$(EXT)
	@$(CC) $(CXXFLAGS) -I$(INCDIR) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@


########################################################################
####################### Test and Example Targets #######################
########################################################################

############## Compiling tests files rulefor Unix-base OS ##############
# Compile and run all tests
.PHONY: test
test: $(TESTS:.c=.out)
	@for test in $(TESTS:.c=.out); do ./$$test; done

# Compile indivisual test file
$(TESTDIR)/%.out: $(TESTDIR)/%$(EXT) $(LIBDIR)/lib$(APPNAME)
	$(CC) $(CXXFLAGS) -I$(INCDIR) -o $@ $< -L$(LIBDIR) -l$(APPNAME:lib%.a=%)

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)


