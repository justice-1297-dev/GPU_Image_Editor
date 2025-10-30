build/ImageEditor: build/main.o build/glad.o build/Application.o build/Texture.o build/Image.o build/TextureRectangle.o build/ShaderProgram.o build/Window.o build/Button.o build/Glyph.o build/Quad.o
	g++ build/main.o build/glad.o build/Application.o build/Texture.o build/Image.o build/TextureRectangle.o build/ShaderProgram.o build/Window.o build/Button.o build/Glyph.o build/Quad.o -o build/ImageEditor /usr/lib/x86_64-linux-gnu/libglfw.so.3.3

build/main.o: src/main.cpp
	mkdir -p build
	g++ -I. -Ilib -c scr/main.cpp -o build/main.o

build/Application.o: src/Application.cpp include/Application.h
	mkdir -p build
	g++ -I. -Ilib -c src/Application.cpp -o build/Application.o

build/Texture.o: src/Texture.cpp include/Texture.h
	mkdir -p build
	g++ -I. -Ilib -c src/Texture.cpp -o build/Texture.o

build/Image.o: src/Image.cpp include/Image.h
	mkdir -p build
	g++ -I. -Ilib -c src/Image.cpp -o build/Image.o

build/TextureRectangle.o: src/TextureRectangle.cpp include/TextureRectangle.h
	mkdir -p build
	g++ -I. -Ilib -c src/TextureRectangle.cpp -o build/TextureRectangle.o

build/ShaderProgram.o: src/ShaderProgram.cpp include/ShaderProgram.h
	mkdir -p build
	g++ -I. -Ilib -c src/ShaderProgram.cpp -o build/ShaderProgram.o

build/Window.o: src/Window.cpp include/Window.h
	mkdir -p build
	g++ -I. -Ilib -c src/Window.cpp -o build/Window.o

build/Button.o: src/Button.cpp include/Button.h
	mkdir -p build
	g++ -I. -Ilib -c src/Button.cpp -o build/Button.o

build/Glyph.o: src/Glyph.cpp include/Glyph.h
	mkdir -p build
	g++ -I. -Ilib -c src/Glyph.cpp -o build/Glyph.o

build/Quad.o: src/Quad.cpp include/Quad.h
	mkdir -p build
	g++ -I. -Ilib -c src/Quad.cpp -o build/Quad.o

build/glad.o: lib/glad/glad.c 
	mkdir -p build
	g++ -I. -Ilib -c lib/glad/glad.c -o build/glad.o
clean:
	rm -rf build