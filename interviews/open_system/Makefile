all: compile link run
compile:
	g++ -c main.cpp -I include  -DSFML_STATIC
link:
	g++ main.o -o main -L lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32

run:
	.\main.exe
