CFLAGS   = -g `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lSDL2 aud.o -lSDL2_image -lSDL2_gfx -lSDL2_ttf -lSDL2_mixer -lm
PROG = tet
CXX = gcc 
SDL2 = -L/usr/local/lib/
INC = -L /Users/root1/libs/sdl2/build


OBJS   = init.o input.o graphics.o tetris.o shuffle.o sds.o utility.o main.o 
# top-level rule to create the program.
all: $(PROG) 
     

# compiling other source files.
%.o: src/%.c src/%.h src/defs.h
	$(CXX)  $(CFLAGS) -c $<

# linking the program
$(PROG): $(OBJS)
	$(CXX)  $(INC) $(LDFLAGS)  $(OBJS) -I /Users/root1/libs/sdl2mixer -o $(PROG) 

# cleaning everything that can be automatically recreated with "make"
clean:
	rm $(PROG) *.o
