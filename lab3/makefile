lab3_A:lab3_A_class.o lab3_A_main.o
	g++ -o lab3_A lab3_A_main.o lab3_A_class.o

lab3_A_class.o:lab3_A_class.cpp lab3_A_headfile.h
	g++ -c lab3_A_class.cpp

lab3_A_main.o:lab3_A_main.cpp lab3_A_headfile.h
	g++ -c lab3_A_main.cpp

clean:
	rm lab3_A_main *.o
