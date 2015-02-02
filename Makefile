#
# Simple generic Makefile for parse-url
#

#-----------------------------------------------------------------------
# EDIT HERE
#-----------------------------------------------------------------------
RM		= /bin/rm -f
CC		= gcc
DEFS		= -O3 -Wall -fmessage-length=0
PROGNAME	= parseurl
INCLUDES	= 
LIBS		= 
#-----------------------------------------------------------------------

DEFINES 	= $(INCLUDES) $(DEFS)
CFLAGS  	= $(DEFINES)

SRC		= $(shell find ./src -type f -name "*.c")
HEADERS		= $(shell find ./src -type f -name "*.h")
OBJS		= $(SRC:.c=.o)

DATE 		= $(shell date +%Y-%d-%m)

.c.o:
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	$(CC) $(CFLAGS) -c $*.c -o $*.o
	@echo 'Finished building: $<'
	@echo ' '
	
all: $(PROGNAME)

$(PROGNAME) : $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	$(CC) $(LIBS) $(OBJS) -o $(PROGNAME)
	@echo 'Finished building target: $@'
	@echo ' '
	
.PHONY: clean tar
clean:
	$(RM) $(PROGNAME) $(OBJS)
	@echo ' '
	
tar:
	tar cvjf $(PROGNAME)_src_$(DATE).tar.bz2 $(SRC) $(HEADERS) Makefile
	@echo ' '
