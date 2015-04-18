#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include "Sudoku.h"
using namespace std;

void Sudoku::GiveQuestion()
{
		int i, j, m, n = 0;		//幫助跑迴圈
		int o = -1;
		int num[ 9 ];		//儲存隨機亂數
		int set[ 9 ] = { 0 };		//計算歸零幾個
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
		//將亂數值輸入數獨
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
		int Question_arr[ 12 ][ 12 ] = { {e,c,k,o,o,o,a,d,g,f,h,b},
								     	 {f,a,g,o,o,o,b,e,h,d,k,c},
								    	 {d,b,h,o,o,o,c,f,k,e,g,a},
							 	    	 {a,h,d,k,c,f,o,o,o,g,b,e},
								    	 {b,k,e,g,a,d,o,o,o,h,c,f},
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
		//為0,3,6,9之不重複亂數
		int r1 = r[ 0 ];
		int r2 = r[ 1 ];
		int r3 = r[ 2 ];
		int r4 = r[ 3 ];
		int temp_arr[ 12 ][ 12 ] = { 0 };		//暫存數獨(幫助變換)
		for(i = 0; i < 3; i ++)
		{
				for(j = 0; j < 12; j ++)		//每大列隨機排列
				{
						temp_arr[ i ][ j ] = Question_arr[ i+r1 ][ j ];
				 		temp_arr[ i+3 ][ j ] = Question_arr[ i+r2 ][ j ];
						temp_arr[ i+6 ][ j ] = Question_arr[ i+r3 ][ j ];
						temp_arr[ i+9 ][ j ] = Question_arr[ i+r4 ][ j ];
				}
		}
		
		m = 0;

		for(i = 0; i < 3; i ++)
		{
				for(j = 0; j < 12; j ++)		//每大行隨機排列
				{
						Question_arr[ j ][ i ] = temp_arr[ j ][ i+r2 ];
						Question_arr[ j ][ i+3 ] = temp_arr[ j ][ i+r3 ];
						Question_arr[ j ][ i+6 ] = temp_arr[ j ][ i+r4 ];
						Question_arr[ j ][ i+9 ] = temp_arr[ j ][ i+r1 ];
				}
		}

		
		int seti[ 12 ] = { 0 };
		int setj[ 12 ] = { 0 };

		for(i = 0; i < 12; i ++)
		{
				for(j = 0; j < 12; j ++)
				{
						for(m = 1; m < 10; m ++)
						{
								if(Question_arr[ i ][ j ] == m && set[ m ] < m && seti[ i ] < 2 && setj[ j ] < 2)
								{
										Question_arr[ i ][ j ] = 0;
										set[ m ] ++;
										seti[ i ] ++;
										setj[ j ] ++;
								}
						}
				}
		}

		Question_arr[ 5 ][ 9 ] = 0;
		//把題目印出來
		for(i = 0; i < 12; i ++)
		{
				for(j = 0; j < 12; j++)
						{
								cout << setw(3) << Question_arr[ i ][ j ];
						}
						cout << endl;
		}
}


void Sudoku::ReadIn()
{
		for(i = 0; i < 144; i ++)
		{
				cin >> Read[ i ];
		}
}

int Sudoku::Solve()
{
		init();			//設定參數
		tempsp = 0;
		sp = getBlank( -1 );		//取得空白位置
		do
		{
				Read[ sp ] ++;		//將此位置數字+1慢慢測試
				if(Read[ sp ] > 9)		//若此位置數字超過9則回溯
				{
						Read[ sp ] = 0;
						sp = pop();
				}
				else
				{
						if(check( sp ) == 0)		//若同行列格皆無相同數字
						{
								push( sp );			//記錄此次空格位置
								sp = getBlank( sp );//取得下次空格位置
						}
				}
		}
		while( sp >= 0 && sp < 144);		//直到每一格執行完
		
		for(i = 0; i < 144; i ++)		//判斷是否為無解
		{
				if(Read[ i ] == 0 )
				{
						cout << 0 << endl;
						return 0;		//若無解則結束程式
				}
		}
		for(i = 0; i < 144; i ++)		//印出答案
		{
				cout << setw(3) << Read[ i ];
				if( (i+1)%12 == 0 )
				{
						cout << endl;
				}
		}
}

void Sudoku::init()		//設定初值
{
		for(i = 0; i < 144; i ++)
		{
				startH[ i ] = (i/12)*12;							//列位置起點座標
				startV[ i ] = i%12;									//行位置起點座標
				startB[ i ] = ((i/12)/3)*36 + ((i%12)/3)*3;			//格位置起點座標
		}
		for(i = 0; i < 12; i ++)
		{
				addH[ i ] = i;					//列位置座標增加值
				addV[ i ] = 12*i;				//行位置座標增加值
				addB[ i ] = (i/3)*12 + (i%3);	//格位置座標增加值
		}
		for(i = 9; i < 12; i ++)
		{
				addB[ i ] = 0;
		}
}
int Sudoku::getBlank(int sp)		//取得空白位置座標
{
		do
		{
				sp ++;
		}
		while( sp < 144 && Read[ sp ] != 0);
		return( sp );
}

int Sudoku::check(int sp)		//檢查行列格是否有相同的數字
{
		same = 0;
		if(!same)
		{
				same = check1(sp, startH[ sp ], addH);		//檢查同列是否有相同數字
		}
		if(!same)
		{
				same = check1(sp, startV[ sp ], addV);		//檢查同行是否有相同數字
		}
		if(!same)
		{
				same = check1(sp, startB[ sp ], addB);		//檢查同格是否有相同數字
		}
		return( same );
}

int Sudoku::check1(int sp, int start, int *add)		//檢查指定的行列格有沒有相同的數字
{
		same = 0;
		for(i = 0; i < 12; i ++)
		{

				sp1 = start + add[ i ];
				if(sp != sp1 && Read[ sp ] == Read[ sp1 ] && Read[ sp ] != 0 )		//檢查指定的行列格是否有相同數字
				{
						same ++;
				}
		}
		return( same );
}

int Sudoku::push(int sp)		//紀錄此次空格位置
{
		temp[ tempsp ++] = sp;
}

int Sudoku::pop()		//取出上次空格位置
{
		if( tempsp <= 0)
		{
				return( -1 );
		}
		else
		{
				return( temp[ -- tempsp ]);
		}
}
