#include <iostream>
#include <vector>
using namespace std;

void printEdge(vector<vector<int>>& martix,int aX,int aY,int bX,int bY)
{
	int x = aX, y = aY;
	if (aX==bX)
	{
		while (y<=bY)
		{
			cout << martix[aX][y++];
		}
		return;
	}
	if (aY== bY)
	{
		while (x <= bX)
		{
			cout << martix[x++][aY];
		}
		return;
	}
	while (x<bX)
	{
		cout << martix[aY][x++] << endl;
	}
	while (y < bY)
	{
		cout << martix[y++][bX] << endl;
	}
	while (x >aX)
	{
		cout << martix[bY][x--] << endl;
	}
	while (y>aY)
	{
		cout << martix[y--][aX]<<endl;
	}
}

void spiralOrderPrint(vector<vector<int>>& martix)
{
	int aX = 0,aY=0;
	int bX = martix[0].size()-1, bY = martix.size()-1;

	while (aX<=bX&&aY<=bY)
	{
		printEdge(martix, aX++, aY++, bX--, bY--);
	}
}

int main()
{
	vector<vector<int>> martix =
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16},
	};
	spiralOrderPrint(martix);


	cin.get();
	return 0;
}
