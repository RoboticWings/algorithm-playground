#include <stdio.h>

char mbti[100];

void dfs(int step) {
	// 边界条件 
	if (step>=4) {
		printf(mbti); 
		printf("\n");
		return;
	}
	// 做出选择
	switch (step) {
		case 0:
			mbti[step] = 'E';
			dfs(step+1);
			mbti[step] = 'I';
			dfs(step+1);
			break;
		case 1:
			mbti[step] = 'S';
			dfs(step+1);
			mbti[step] = 'N';
			dfs(step+1);
			break;
		case 2:
			mbti[step] = 'F';
			dfs(step+1);
			mbti[step] = 'T';
			dfs(step+1);
			break;
		case 3:
			mbti[step] = 'P';
			dfs(step+1);
			mbti[step] = 'J';
			dfs(step+1);
			break;
	}
	return;
}

int main() {
	dfs(0); 
}
