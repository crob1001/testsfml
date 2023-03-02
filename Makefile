all: compile link

compile:
	g++ -I src/include -c main.cpp -o out/main.o

link:
	g++ out/main.o -o out/main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system