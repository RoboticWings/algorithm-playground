#include <iostream>
using namespace std;
int a[51][51];   // 标记障碍物的
int book[51][51];  // 标记已经走过的路
int width, height;  // 地图的宽和高
int goalX, goalY;   // 目标位置
int min_step = 999999;  // 最小步数
int directions[4][2] = {
	{1,0},  // right
	{0,1},  // down
	{-1,0}, // left
	{0,-1}  // up
};

void dfs(int x, int y, int step) {
	// 边界条件
	//如果小哼找到了小哈，那就结束寻找
	if (x==goalX && y==goalY) {
		if (step + 1 < min_step) {
			min_step = step + 1;
		}
		return;
	}
	// 穷举每一种选择(右下左上)
	for (int i = 0; i < 4; i++) {
		int tx = x + directions[i][0];
		int ty = y + directions[i][1];
		// 判断(tx,ty)是否是合法的
		if (tx >= width || ty >= height || tx<0 || ty<0) continue;  //如果越出边界，则该选择不合法
		if (book[tx][ty]) continue;  // 如果之前走过一点，却还再走一次，那走出的一定不是最短路径。所以不能选择走过的点
		if (a[tx][ty]) continue; // 如果选择目标(tx,ty)上是障碍物，则该选择不合法
		// 进行选择
		book[tx][ty] = 1;   // 要拿得起
		dfs(tx,ty,step+1);
		book[tx][ty] = 0;   // 还要能放得下!
	}
	// 返回
	return;
}

int main() {
	/* 样例数据： 4 5
	0 0 1 0
	0 0 0 0 
	0 0 1 0 
	0 1 0 0 
	0 0 0 1
	2 3 */
	cout<<"地图宽:";
	cin>>width;
	cout<<"地图高:";
	cin>>height;
	cout<<"请输入地图数据:"<<endl;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			cin>>a[i][j];
		}
		cout<<endl;
	}
	cout<<"请输入小哈的位置:";
	cin>>goalX;
	cin>>goalY;
	dfs(0,0,1);
	cout<<"最短路径是:"<<min_step<<endl;
}
