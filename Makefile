# Compiler configuration
CC = x86_64-w64-mingw32-gcc
# Note the include path is relative to the root
CFLAGS = -c -Wall -Iincludes

# Output Directory
OUT_DIR = bin

# Targets
all: hello-world.o arg-parse.o

# Compile main BOF
hello-world.o: hello-world.c
	$(CC) $(CFLAGS) hello-world.c -o hello-world.o

# Compile arg-parse from its subdirectory
arg-parse.o: arguments/arg-parse.c
	$(CC) $(CFLAGS) arguments/arg-parse.c -o arguments/arg-parse.o

# Helper to clean everything
clean:
	rm -f *.o arguments/*.o