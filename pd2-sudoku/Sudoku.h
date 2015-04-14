#include <iostream>
class Sudoku
{
		public:
//		Sudoku();
//		Sudoku(const int init_map[]);
		void GiveQuestion();
//		int getElement(int index);
//		bool isCorrect();
		static const int sudokuSize = 12;
//		ReadIn();
//		Slove();

		private:
		bool checkUnity(int arr[]);
		int map[sudokuSize];
};
