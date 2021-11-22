CFLAGS = -Wall -Wextra -std=c11 -ggdb -lSDL2 -lSDL2main `pkg-config --cflags sdl2`

ted: main.c
	$(CC) $(CFLAGS) -o ted main.c

clean:
	rm ted
