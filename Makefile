OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Coleccion.o Album.o Fotografia.o Fecha.o
	g++ -o program.exe *.o 

Coleccion.o: Coleccion.cc Coleccion.hh Album.hh
	g++ -c Coleccion.cc 

Album.o: Album.cc Album.hh Fotografia.hh 
	g++ -c Album.cc  

Fotografia.o: Fotografia.cc Fotografia.hh Fecha.hh
	g++ -c Fotografia.cc 

Fehca.o:Fecha.cc Fehca.hh
	g++ -c Fecha.cc

prog.o: program.cc Coleccion.hh Album.hh Fotografia.hh
	g++ -c program.cc 

practica.tar: Coleccion.cc Coleccion.hh Album.hh Album.cc Fotografia.hh Fotografia.cc Fecha.hh Fecha.cc program.cc Makefile
	tar -cvf practica.tar Coleccion.cc Coleccion.hh Album.hh Album.cc Fotografia.hh Fotografia.cc Fecha.hh Fecha.cc program.cc Makefile

clean:
	rm -f *.o
	rm -f *.exe
