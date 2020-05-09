all:
	g++ main.cpp -o build.exe -DSFML_STATIC -I D:\liby\SFML\include -L D:\liby\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg
	