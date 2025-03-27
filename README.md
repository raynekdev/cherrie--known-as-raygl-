# raygl

raygl is a lightweight and powerful custom graphics api focused on performance and flexibility.it does not use opengl, vulkan, or directx – raygl is built on its own custom rendering engine.

## project goals

- minimal and efficient graphics api
- real-time ray tracing rendering
- fully custom backend (no opengl/vulkan/directx)
- designed for games, visualizations, and scientific tools

## features

- real-time ray tracing engine
- render 2d and 3d scenes
- command-line and optional gui support

## requirements

- programming language: C++
- compiler: gcc / clang / msvc
- supported operating systems: windows and linux

raygl is available as:

- `raygl.dll` for windows (dynamic linking)
- `libraygl.so` for linux (shared object)
- `libraygl.a` for static linking (linux and unix-like systems)

you can link raygl to your project using your preferred method:

### static linking (example)

```bash
g++ main.cpp -L./lib -lraygl -o myapp
