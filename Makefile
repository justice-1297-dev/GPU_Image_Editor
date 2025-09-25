build/ImageEditor: build/main.o build/glad.o build/Application.o build/Texture.o
	g++ build/main.o build/glad.o build/Application.o build/Texture.o -o build/ImageEditor /usr/lib/x86_64-linux-gnu/libglfw.so.3.3

build/main.o: main.cpp
	mkdir -p build
	g++ -I. -Ilib -c main.cpp -o build/main.o

build/Application.o: Application.cpp Application.h
	mkdir -p build
	g++ -I. -Ilib -c Application.cpp -o build/Application.o

build/Texture.o: Texture.cpp Texture.h
	mkdir -p build
	g++ -I. -Ilib -c Texture.cpp -o build/Texture.o

build/glad.o: lib/glad/glad.c 
	mkdir -p build
	g++ -I. -Ilib -c lib/glad/glad.c -o build/glad.o
clean:
	rm -rf build