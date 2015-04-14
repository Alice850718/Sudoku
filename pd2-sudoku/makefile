test: Sudoku.o give_question.o
	g++ -o test give_question.cpp Sudoku.o

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

give_question.o:give_question.cpp Sudoku.h
	g++ -c give_question.cpp

clean:
	rm Sudoku *.o
