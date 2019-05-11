comp = c++ -std=c++1z
incs = -I./Resources/include
objs = Window.o Object.o glad.o Shader.o VertexShader.o FragmentShader.o ShaderProgram.o stb_image.o Texture.o
libs = -lglfw3 -ldl -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread

main: Source/Main.cpp $(objs)
	$(comp) -o main Source/Main.cpp $(incs) $(objs) $(libs)

Window.o: Source/Window.cpp Header/Window.hpp
	$(comp) -c Source/Window.cpp $(incs)
Object.o: Source/Object.cpp Header/Object.hpp Header/Model.hpp Header/TexModel.hpp
	$(comp) -c Source/Object.cpp $(incs)
Shader.o: Header/Shader.hpp Source/Shader.cpp
	$(comp) -c Source/Shader.cpp $(incs)
VertexShader.o: Header/VertexShader.hpp Source/VertexShader.cpp
	$(comp) -c Source/VertexShader.cpp $(incs)
FragmentShader.o: Header/FragmentShader.hpp Source/FragmentShader.cpp
	$(comp) -c Source/FragmentShader.cpp $(incs)
ShaderProgram.o: Header/ShaderProgram.hpp Source/ShaderProgram.cpp
	$(comp) -c Source/ShaderProgram.cpp $(incs)
Texture.o: Header/Texture.hpp Source/Texture.cpp
	$(comp) -c Source/Texture.cpp $(incs)


stb_image.o: Source/stb_image.cpp Header/stb_image.h
	$(comp) -c Source/stb_image.cpp

glad.o: Resources/glad.c
	gcc -c Resources/glad.c $(incs)


