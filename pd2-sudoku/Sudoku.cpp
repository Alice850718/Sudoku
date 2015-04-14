#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Sudoku.h"
using namespace std;

/*
Sudoku::Sudoku()
{
		for(int i = 0; i < sudokuSize; ++ i)
		{
				for(int j = 0; j < sudokuSize; ++ j)
				{
						map[ i ][ j ] = 0;
				}
		}
}


Sudoku::Sudoku(const int init_map[])
{
		for(int i = 0; i < sudokuSize; ++ i)
		{
				for(int j = 0; j < sudokuSize; ++ j)
				{
						map[ i ][ j ] = init_map[ i ][ j ];
				}
		}
}
*/
void Sudoku::GiveQuestion()
{
/*		for(int i = 0; i < sudokuSize; ++ i)
		{
				for(int j = 0; j < sudokuSize; ++ j)
				{
						map[ i ][ j ] = set_map[ i ][ j ];
				}
		}
*/
		//預設數獨
		int i, j;		//幫助跑迴圈
		int o = -1;
		int num[ 9 ];		//儲存隨機亂數
		srand((unsigned)time(NULL));		//設定亂數種子
		for(i = 0; i < 9; i ++)		//產生1~9的數字
		{
				num[ i ] = (rand()%9)+1;
				for(j = 0; j < i; j ++)
				{
						if(num[ i ] == num[ j ])
						{
								i --;
								break;
						}
				}
		}
		int a = num[ 0 ];
		int b = num[ 1 ];
		int c = num[ 2 ];
		int d = num[ 3 ];
		int e = num[ 4 ];
		int f = num[ 5 ];
		int g = num[ 6 ];
		int h = num[ 7 ];
		int k = num[ 8 ];
		//預設數獨
		int Question_arr[ 12 ][ 12 ] = { {e,c,k,o,o,o,a,d,g,f,k,c},
								     	 {f,a,g,o,o,o,b,e,h,d,g,a},
								    	 {d,b,h,o,o,o,c,f,k,e,h,b},
							 	    	 {a,h,d,k,c,f,o,o,o,g,b,f},
								    	 {b,k,e,g,a,d,o,o,o,h,c,e},
								    	 {c,g,f,h,b,e,o,o,o,k,a,d},
								    	 {o,o,o,e,g,b,d,k,c,a,f,h},
								    	 {o,o,o,f,h,c,e,g,a,b,d,k},
								    	 {o,o,o,d,k,a,f,h,b,c,e,g},
								    	 {g,e,c,a,d,k,h,b,f,o,o,o},
								    	 {h,f,a,b,e,g,k,c,d,o,o,o},
							        	 {k,d,b,c,f,h,g,a,e,o,o,o} };
		int r[ 4 ];
		for(i = 0; i < 4; i ++)		//產生亂數(幫助變換)
		{
				r[ i ] = (rand()%4)*3;
				for(j = 0; j < i; j ++)
				{
						if(r[ i ] == r[ j ])
						{
								i --;
								break;
						}
				}
		}
		int r1 = r[ 0 ];
		int r2 = r[ 1 ];
		int r3 = r[ 2 ];
		int r4 = r[ 3 ];		//為0,3,6,9之不重複亂數
		int temp_arr[ 12 ][ 12 ] = { 0 };
		for(i = 0; i < 3; i ++)		//每大列隨機排列
		{
				for(j = 0; j < 12; j ++)
				{
						temp_arr[ i ][ j ] = Question_arr[ i+r1 ][ j ];
						if(temp_arr[ i ][ num[ i ] ] != -1)
						{
								temp_arr[ i ][ num[ i ] ] = 0;
						}
						else
						{
								temp_arr[ i ][ num[ i+1 ] ] = 0;
						}
						temp_arr[ i+3 ][ j ] = Question_arr[ i+r2 ][ j ];
						temp_arr[ i+6 ][ j ] = Question_arr[ i+r3 ][ j ];
						temp_arr[ i+9 ][ j ] = Question_arr[ i+r4 ][ j ];
				}
		}
		for(i = 0; i < 3; i ++)		//每大行隨機排列
		{
				for(j = 0; j < 12; j ++)
				{
						Question_arr[ j ][ i ] = temp_arr[ j ][ i+r2 ];
						Question_arr[ j ][ i+3 ] = temp_arr[ j ][ i+r3 ];
						Question_arr[ j ][ i+6 ] = temp_arr[ j ][ i+r4 ];
						Question_arr[ j ][ i+9 ] = temp_arr[ j ][ i+r1 ];
				}
		}

/*		int ax = 0;		//ax,bx,cx,dx和-1的前面座標位置有關
		int bx = 1;
		int cx = 2;
		int dx = 3;
		int ay = r[ ax ];		//ay,by,cy,dy和-1的後面座標位置有關
		int by = r[ bx ];
		int cy = r[ cx ];
		int dy = r[ dx ];
*/
		for(i = 0; i < 3; i ++)		//產生不重複隨機亂數(輔助排列)
		{
				r[ i ] = rand()%3;
				for(j = 0; j < i; j ++)
				{
						if(r[ i ] == r[ j ])
						{
								i --;
								break;
						}
				}
		}
/*		int x = r[ 0 ];		//x,y,z為0~2不重複亂數(輔助排列)
		int y = r[ 1 ];
		int z = r[ 2 ];

		Question_arr[ ax*3 ][ dy ] = 1;
		Question_arr[ ax*3 + 1 ][ by ] = 1;
		Question_arr[ ax*3 + 2 ][ cy ] = 1;
		Question_arr[ cx*3 ][ by + 1 ] = 1;
		Question_arr[ dx*3 ][ by + 2 ] = 1;


		//把-1放入12x12數獨裡
		for(i = ax*3; i < (ax+1)*3; i ++)
		{
				for(j = ay; j < ay+3; j ++)
				{
						Question_arr[ i ][ j ] = -1;
				}
		}
		for(i = bx*3; i < (bx+1)*3; i ++)
		{
				for(j = by; j < by+3; j ++)
				{
						Question_arr[ i ][ j ] = -1;
				}
		}
		for(i = cx*3; i < (cx+1)*3; i ++)
		{
				for(j = cy; j < cy+3; j ++)
				{
						Question_arr[ i ][ j ] = -1;
				}
		}

		for(i = dx*3; i < (dx+1)*3; i ++)
		{
				for(j = dy; j < dy+3; j ++)
				{
						Question_arr[ i ][ j ] = -1;
				}
		}
*/
		//把題目印出來
		for(i = 0; i < 12; i ++)
		{
				for(j = 0; j < 12; j++)
						{
								if(Question_arr[ i ][ j ] != 0)
								{
										cout << setw(3) << Question_arr[ i ][ j ];
								}
								else
								{
										cout << setw(3) << " ";
								}
						}
						cout << endl;
		}

}
/*
int Sudoku::getElement(int index)
{
		return map[index];
}

bool Sudoku::checkUnity(int arr[])
{
		int arr_unity[ 9 ];		//counters
		for(int i = 0; i < 9; ++ i)
		{
				arr_unity[ i ] = 0;		//initialize
		}
		for(int i = 0; i < 9; ++ i)
		{
				++ arr_unity[ arr[ i ] - 1 ];		//all element
		}
		for(int i = 0; i < 9; ++ i)
		{
				if(arr_unity[ i ] != 1)		//all element
				{
						return false;		//must be 1
				}
		}
		return true;
}

bool Sudoku::isCorrect()
{
		bool check_result;
		int check_arr[ 9 ];
		int location;
		for(int i = 0; i < 81; i += 9 )		//check rows
		{
				for(int j = 0; j < 9; ++ j)
				{
						check_arr[ j ] = map[ i + j ];
				}
				check_result = checkUnity(check_arr);
				if(check_result == false)
				{
						return false;
				}
		}
		for(int i = 0; i < 9; ++ i)		//check columns
		{
				for(int j = 0; j < 9; ++ j)
				{
						check_arr[ j ] = map[ i + 9*j ];
				}
				check_result = checkUnity(check_arr);
				if(check_result == false)
				{
						return false;
				}
		}
		for(int i = 0; i < 9; ++ i)		//check cells
		{
				for(int j = 0; j < 9; ++ j)
				{
						location = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3);
						check_arr[ j ] = map[location];
				}
				check_result = checkUnity(check_arr);
				if(check_result == false)
				{
						return false;
				}
		}
		return true;
}
*/
