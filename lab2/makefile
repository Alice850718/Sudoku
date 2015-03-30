lab2_main:lab2_class.o lab2_main.o
	g++ -o lab2_main  lab2_main.o lab2_class.o

lab2_class.o:lab2_class.cpp lab2_headfile.h
	g++ -c lab2_class.cpp

lab2_main.o:lab2_main.cpp lab2_headfile.h
	g++ -c lab2_main.cpp

clean:
	rm lab2_main *.o
