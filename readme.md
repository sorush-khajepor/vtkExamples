# Particles VTP

Using VTK library, this writes information of a set of particles: position, velocity, density in VTP format.

## Download VTK library

If VTK is not installed on your system, download the latest version. Here, I used version 9.0.3. Then in a terminal:

```
cd /path/to/vtk/source/
mkdir build
cd build
cmake ..
make -j 8
```

## Compile

Before compiling, edit CMakeLists.txt line

```cmake
set(VTK_DIR "path/to/vtk/source/build")
```

To the path of your VTK library build folder. 

