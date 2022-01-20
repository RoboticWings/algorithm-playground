#include <iostream>
using namespace std;
int a[51][51];   // ����ϰ����
int book[51][51];  // ����Ѿ��߹���·
int width, height;  // ��ͼ�Ŀ�͸�
int goalX, goalY;   // Ŀ��λ��
int min_step = 999999;  // ��С����
int directions[4][2] = {
	{1,0},  // right
	{0,1},  // down
	{-1,0}, // left
	{0,-1}  // up
};

void dfs(int x, int y, int step) {
	// �߽�����
	//���С���ҵ���С�����Ǿͽ���Ѱ��
	if (x==goalX && y==goalY) {
		if (step + 1 < min_step) {
			min_step = step + 1;
		}
		return;
	}
	// ���ÿһ��ѡ��(��������)
	for (int i = 0; i < 4; i++) {
		int tx = x + directions[i][0];
		int ty = y + directions[i][1];
		// �ж�(tx,ty)�Ƿ��ǺϷ���
		if (tx >= width || ty >= height || tx<0 || ty<0) continue;  //���Խ���߽磬���ѡ�񲻺Ϸ�
		if (book[tx][ty]) continue;  // ���֮ǰ�߹�һ�㣬ȴ������һ�Σ����߳���һ���������·�������Բ���ѡ���߹��ĵ�
		if (a[tx][ty]) continue; // ���ѡ��Ŀ��(tx,ty)�����ϰ�����ѡ�񲻺Ϸ�
		// ����ѡ��
		book[tx][ty] = 1;   // Ҫ�õ���
		dfs(tx,ty,step+1);
		book[tx][ty] = 0;   // ��Ҫ�ܷŵ���!
	}
	// ����
	return;
}

int main() {
	/* �������ݣ� 4 5
	0 0 1 0
	0 0 0 0 
	0 0 1 0 
	0 1 0 0 
	0 0 0 1
	2 3 */
	cout<<"��ͼ��:";
	cin>>width;
	cout<<"��ͼ��:";
	cin>>height;
	cout<<"�������ͼ����:"<<endl;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			cin>>a[i][j];
		}
		cout<<endl;
	}
	cout<<"������С����λ��:";
	cin>>goalX;
	cin>>goalY;
	dfs(0,0,1);
	cout<<"���·����:"<<min_step<<endl;
}
