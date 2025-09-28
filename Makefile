build/ImageEditor: build/main.o build/glad.o build/Application.o build/Texture.o build/Image.o build/TextureRectangle.o build/ShaderProgram.o build/Window.o build/Button.o build/Glyph.o
	g++ build/main.o build/glad.o build/Application.o build/Texture.o build/Image.o build/TextureRectangle.o build/ShaderProgram.o build/Window.o build/Button.o build/Glyph.o -o build/ImageEditor /usr/lib/x86_64-linux-gnu/libglfw.so.3.3

build/main.o: main.cpp
	mkdir -p build
	g++ -I. -Ilib -c main.cpp -o build/main.o

build/Application.o: Application.cpp Application.h
	mkdir -p build
	g++ -I. -Ilib -c Application.cpp -o build/Application.o

build/Texture.o: Texture.cpp Texture.h
	mkdir -p build
	g++ -I. -Ilib -c Texture.cpp -o build/Texture.o

build/Image.o: Image.cpp Image.h
	mkdir -p build
	g++ -I. -Ilib -c Image.cpp -o build/Image.o

build/TextureRectangle.o: TextureRectangle.cpp TextureRectangle.h
	mkdir -p build
	g++ -I. -Ilib -c TextureRectangle.cpp -o build/TextureRectangle.o

build/ShaderProgram.o: ShaderProgram.cpp ShaderProgram.h
	mkdir -p build
	g++ -I. -Ilib -c ShaderProgram.cpp -o build/ShaderProgram.o

build/Window.o: Window.cpp Window.h
	mkdir -p build
	g++ -I. -Ilib -c Window.cpp -o build/Window.o

build/Button.o: Button.cpp Button.h
	mkdir -p build
	g++ -I. -Ilib -c Button.cpp -o build/Button.o

build/Glyph.o: Glyph.cpp Glyph.h
	mkdir -p build
	g++ -I. -Ilib -c Glyph.cpp -o Glyph/Button.o

build/glad.o: lib/glad/glad.c 
	mkdir -p build
	g++ -I. -Ilib -c lib/glad/glad.c -o build/glad.o
clean:
	rm -rf build