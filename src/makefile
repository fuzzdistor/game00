#makefile
#sfml project makefile

#directory var
IDIR = ../include
ODIR = obj
LDIR = ../lib

#compiler flags
CC=g++
CFLAGS=-I$(IDIR)

#libraries var
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#header dependencies
_DEPS = Game.hpp #ResourceHolder.hpp Aircraft.hpp Entity.hpp SceneNode.hpp SpriteNode.hpp World.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#object dependencies
_OBJ = Main.o Game.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#make command
$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Game: $(OBJ)
	$(CC) -o "../Bin/$@" $^ $(CFLAGS) $(LIBS)

#exe rule
exe:
	./../Bin/Game

#clean rule
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 