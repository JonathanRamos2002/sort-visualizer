CC = clang

TARGET = visual-sort
SRC = visual-sort.c

RAYLIB = raylib/src/libraylib.a
INCLUDES = -Iraylib/src

FRAMEWORKS = \
 	-framework OpenGL \
	-framework Cocoa \
	-framework IOKit \
	-framework CoreVideo \
	-framework GLUT

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) $(RAYLIB) $(INCLUDES) $(FRAMEWORKS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

rebuild:
	clean all 
