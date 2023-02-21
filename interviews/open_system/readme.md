This example project in sfml show diffenrent geometry figure's types. Also it incude rotation cube(realize with openGl lib).
In include locate sfml service files, in root folder locate .dll files(without them executable file won`t be able to run). In src locate source files .hpp and .h, all .h fiels must be .cpp, but sfml linker cursed at it, and i had to replace .cpp to .h files. In fugures.hpp contains decoraters for classical Geometry shapes and override fucntion  "figureDrawing". Menu_*.hpp files conatins simple menu realization.

As for making this project, we should to run makefile(in my env it was mingw32-make, as for Your env it cab be diffent collectors

If u want just launch this project, open main.exe
