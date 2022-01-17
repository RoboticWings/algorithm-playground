#include <stdio.h>

int main() {
	int arr[100] = {0};
	for(int i = 0;i<10;i++) {
		int n;
		scanf("%d",&n);
		arr[n] ++;
	}
	for(int i= 0; i<100;i++) {
		for (int j=0;j<arr[i];j++) {
			printf("%d ", i);
		}
	}
}
