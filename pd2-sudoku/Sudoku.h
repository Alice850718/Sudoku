#include <iostream>
#include <vector>
using namespace std;

class Sudoku
{
		public:
		void GiveQuestion();		//出題目
		void ReadIn();		//讀取的數獨
		int Solve();		//解數獨
		int Read[ 144 ];		//讀進來的題目
		int Read1[ 144 ];
		void init();		//設定值(幫助計算)
		int temp[ 144 ];
		int tempsp;
		int sp, sp1;
		int same;

		private:
		int i, j, m, n;		//幫助跑迴圈
		int check(int sp);		//檢查行列格有沒有相同數字
		int check1(int sp, int start, int *add);
		int check2(int sp);		//檢查行列格有沒有相同數字
		int check3(int sp, int start, int *add);
		int getBlank(int sp);		//取得空白位置座標
		int getBlank1(int sp);
		int pop();
		int push(int sp);
		int startH[ 144 ];
		int startV[ 144 ];
		int startB[ 144 ];
		int addH[ 12 ];
		int addV[ 12 ];
		int addB[ 12 ];
};
