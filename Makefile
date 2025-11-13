PROG = main.exe 

# detta är h-filer
DEPS= engine.h

SRC = main.cpp engine.cpp
CFLAGS = -g -std=c++17 -Wall -Werror
LIBS = 
CC=g++
OUTPUTDIR=obj

OBJS = $(addprefix $(OUTPUTDIR)/, $(SRC:.cpp=.o))


all: $(OUTPUTDIR) $(PROG)

$(PROG): $(OBJS) 
	$(CC) -o $@ $^ $(CFLAGS)

$(OUTPUTDIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

clean:
	@del /q "$(OUTPUTDIR)" 
	@del /q $(PROG)


.PHONY: prep clean