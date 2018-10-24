#
# This is a Makefile. It's an essential tool for building your program
# in a large project (lots of source files). The Makefile contains a set
# of rules. Each rule says that a certain file (called a target) depends
# on one or more other files (called prerequisites). When building a
# program, make goes through each target and checks if it is older than 
# any of its prerequisites. If it is, that target has to be rebuilt 
# (because the code it depends on has changed). Whenever this happens, 
# a certain command is invoked. This command can either be provided by 
# the rule (called an explicit rule) or omitted (implicit rule). When a
# rule is implicit, a default command is used. We will not go through
# what the default commands look like.
#
# In addition to the rules, the Makefile contains a set of variables
# that contain text strings. The text can be the name of a compiler,
# some compiler options, etc. We will use these text strings to define
# the commands that are used in the rules.
#

# This is what a variable definition looks like.
# CXX is the compiler, CC is the linker (used by implicit rules).
CXX = g++
CC = g++

# Preprocessor options (used by implicit rules). We have no special
# options to pass to the preprocessor, so this can be commented out.
# CPPFLAGS  = 

# Compiler options. You'll always want to set this one.
CXXFLAGS = -pipe -O2 -Wall -W -ansi -pedantic-errors
CXXFLAGS += -Wmissing-braces -Wparentheses -Wold-style-cast -ggdb

# Linker options (used by implicit rules).
LDFLAGS = -ggdb

# If our program depended on external libraries, we would list them here
#LIBS = 

# Here we will put the names of the shape source and object files.
SHAPESRC = shape.cpp triangle.cpp rectangle.cpp square.cpp circle.cpp
SHAPEOBJ = $(SHAPESRC:.cpp=.o)

# The names of the executables
PROGS = newTest

# This is a rule stating that the target "all" depends on whatever is 
# in the variable PROGS. Typing "make all" builds all of the PROGS. 
# It is customary to include this target in any Makefile. As you have 
# deduced by now, not every target has to be the name of a file.
all: $(PROGS)

# The executable defaultTest depends on defaultTest.o as well as all
# the shape object files. The second line is the command that should be
# executed in order to build defaultTest. The variables expand to 
# whatever text strings we put in them earlier. The slightly cryptic 
# symbol $@ expands to the name of the target, and $^ expands to the 
# list of prerequisites. The command therefore expands to something like
#
# g++ -o defaultTest defaultTest.o shape.o triangle.o rectangle.o ...
#
newTest: newTest.o $(SHAPEOBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(CPPFLAGS) $(LIBS)

# This is a rule for cleaning up the file created when building the
# program. Type "make clean" to invoke it. All the .o files are removed.
clean:
	rm -f *.o

# Typing "make realclean" first invokes the "clean" rule, then goes on
# to remove all executables and .d files.
realclean: clean
	rm -f $(PROGS) *.d

#
# This rule takes care of automatically generating your prerequisites.
# That means you don't have to explicitly state that a certain object
# file depends on a certain header file. Make will scan your source
# files, find all the #includes and write the rules for you. Now you can
# include and edit headers without having to worry about dependencies!
# Don't bother understanding the rule - It's taken from the make manual.
#

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

SRC	= $(wildcard *.cpp)
include $(SRC:.cpp=.d)
