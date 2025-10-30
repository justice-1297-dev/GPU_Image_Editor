![GPU Image Editor](GPUImage.png)

# GPU Image Editor

Personal playground for experimenting with a GPU-accelerated 2D image editor.  
The project grew out of a class assignment, but this repo is maintained as a standalone
portfolio piece with a cross-platform setup guide.

## Features

- Rendering pipeline split into reusable classes (`Application`, `Window`, `Image`, `Texture`, `TextureRectangle`, `ShaderProgram`, `Button`, `Glyph`, `Quad`).
- Glad + OpenGL shader pipeline for drawing textured quads.
- Buttons backed by textures (reset button included) and room for custom image filters.
- Sample assets (`img_small.jpeg`, `img_large.jpeg`, `grayscale.png`, `reset.png`) for quick experiments.

## Project Layout

- `*.cpp / *.h` – Core engine code.
- `lib/glad` – Vendor copy of glad.
- `lib/stb_image.h` / `stb_image_write.h` – Image IO helpers.
- `src/shaders` – GLSL shaders.
- `build/` – Compiled objects and binaries (ignored in Git except for local builds).

## File Structure

```
.
├── Application.cpp/.h        # Main application controller
├── Button.cpp/.h             # UI button logic and rendering
├── Glyph.cpp/.h              # Text glyph rendering support
├── Image.cpp/.h              # CPU-side image loading/manipulation
├── Quad.cpp/.h               # Screen-aligned quad geometry
├── ShaderProgram.cpp/.h      # GLSL program compilation/usage
├── Texture.cpp/.h            # OpenGL texture wrapper
├── TextureRectangle.cpp/.h   # Rectangle texture helper
├── Window.cpp/.h             # GLFW window lifecycle management
├── lib/
│   ├── glad/                 # Glad loader source
│   └── stb_image*.h          # stb image IO headers
├── src/
│   └── shaders/              # GLSL shader sources
├── build/                    # Local build artifacts
├── img_*.jpeg, grayscale.png # Sample assets
└── README.md                 # Project documentation
```

## Requirements

### Shared Dependencies

- C++11-capable compiler (`g++`, `clang++`, or MSVC 2019+).
- OpenGL loader (glad is already vendored).
- OpenGL 3.3+ runtime on the host machine.
- GLFW 3.x development files.
- CMake 3.3+ (optional; only needed for the CMake workflow).

### Linux

```bash
sudo apt install build-essential libglfw3-dev
```

The default `Makefile` links against `/usr/lib/x86_64-linux-gnu/libglfw.so.3.3`.  
If your distro keeps the library elsewhere, adjust the link line or use `pkg-config --libs glfw3`.

### macOS

```bash
brew install glfw
```

Update the link command in `Makefile` to use platform frameworks:

```
g++ ... -framework OpenGL -lglfw
```

You may also want to add `-std=c++11` (or higher) if your compiler defaults differ.

### Windows

Pick one of the following setups:

1. **Visual Studio**  
   - Install the “Desktop Development with C++” workload.  
   - Build GLFW from source or use a prebuilt binary.  
   - Link against `opengl32.lib` and `glfw3.lib`, and place `glfw3.dll` next to the executable.

2. **MSYS2 / MinGW-w64**  
   ```bash
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-glfw
   ```
   - Adjust the `Makefile` link line to `-lopengl32 -lglfw3 -lgdi32` (path depends on your installation).

## Build and Run

### Using the Makefile (default)

```bash
make
./build/ImageEditor
```

Run the binary from the repository root so the shaders and textures load correctly via relative paths.

### Using CMake (optional)

Update `CMakeLists.txt` so all engine `.cpp` files are listed:

```cmake
add_executable(ImageEditor
    main.cpp
    Application.cpp
    Button.cpp
    Glyph.cpp
    Image.cpp
    Quad.cpp
    ShaderProgram.cpp
    Texture.cpp
    TextureRectangle.cpp
    Window.cpp
    lib/glad/glad.c)
```

Then:

```bash
cmake -S . -B build
cmake --build build
./build/ImageEditor
```

## Notes

- Shaders are in `src/shaders`; tweak or add new ones to experiment with effects.
- The reset button reloads the base image. New buttons can hook into the same event flow.
- If you extend the project, update this README and the build system so others can follow along.
