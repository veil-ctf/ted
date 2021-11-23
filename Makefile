CFLAGS = -Wall -Wextra -std=c11 -ggdb -lSDL2 -lSDL2main -lSDL2_ttf `pkg-config --cflags sdl2`

ted: main.c
	$(CC) $(CFLAGS) -o ted main.c

clean:
	rm ted
