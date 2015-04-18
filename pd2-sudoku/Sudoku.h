#include <iostream>
#include <vector>
using namespace std;

class Sudoku
{
		public:
		void GiveQuestion();		//出題目
		void ReadIn();		//讀取的數獨
		void Solve();		//解數獨

		private:
		int i, j, m, n;		//幫助跑迴圈
		int Read[ 12 ];		//讀進來的題目
		void init();		//設定值(幫助計算)
		int sp, sp1;
		int getBlank(int sp);		//取得空白位置座標
		int check(int sp);		//檢查行列格有沒有相同數字
		int check1(int sp, int start, int *add);
		int push(int sp);
		int pop();
		int startH[ 12 ];
		int startV[ 12 ];
		int startB[ 12 ];
		int addH[ 12 ];
		int addV[ 12 ];
		int addB[ 12 ];
		int same;
		int temp[ 144 ];
		int tempsp;
};
