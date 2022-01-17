#include <stdio.h>

int isInBucket[100];
int currentPath[100];
int n;

void dfs(int step) {
	// 边界条件
	if (step>n) {  //路已经走到头了 
		for (int i=1;i<=n;i++) {  
			printf("%d ", currentPath[i]);  //输出选择记录，即一个全排列  
		}
		printf("\n");
		return;  // 非常关键，否则会陷入死循环 
	} 
	// 穷尽每一种可能的选择 
	for (int i=1; i<=n; i++) {
		// 某个节点是否已经被选择的判断，是DFS算法的内在要求，不属于DFS的自设“边界条件” 
		if (!isInBucket[i]) {
			isInBucket[i] = 1;  // 表示数字i已被选择 
			currentPath[step] = i;  // 在选择记录中添加当前选择 
			dfs(step+1);    // 往前走一步 
			isInBucket[i] = 0;  // 尝试完毕，取消对数字i的选择 
		}
	}
	// 返回 
	return;
}

int main() {
	// 输出1,2,...,n这n个数的全排列 
	scanf("%d", &n);
	dfs(1);  // 路要从第 "1" 步开始走 
}
