#include <stdio.h>

int isInBucket[100];
int currentPath[100];
int n;

void dfs(int step) {
	// �߽�����
	if (step>n) {  //·�Ѿ��ߵ�ͷ�� 
		for (int i=1;i<=n;i++) {  
			printf("%d ", currentPath[i]);  //���ѡ���¼����һ��ȫ����  
		}
		printf("\n");
		return;  // �ǳ��ؼ��������������ѭ�� 
	} 
	// �ÿһ�ֿ��ܵ�ѡ�� 
	for (int i=1; i<=n; i++) {
		// ĳ���ڵ��Ƿ��Ѿ���ѡ����жϣ���DFS�㷨������Ҫ�󣬲�����DFS�����衰�߽������� 
		if (!isInBucket[i]) {
			isInBucket[i] = 1;  // ��ʾ����i�ѱ�ѡ�� 
			currentPath[step] = i;  // ��ѡ���¼����ӵ�ǰѡ�� 
			dfs(step+1);    // ��ǰ��һ�� 
			isInBucket[i] = 0;  // ������ϣ�ȡ��������i��ѡ�� 
		}
	}
	// ���� 
	return;
}

int main() {
	// ���1,2,...,n��n������ȫ���� 
	scanf("%d", &n);
	dfs(1);  // ·Ҫ�ӵ� "1" ����ʼ�� 
}
