#include <stdio.h>

int arr[100];
int n = 10;
void quicksort(int head, int tail) {
	if (head > tail) return;
	int base = arr[head];
	int i=head,j=tail;
	// 快速排序 实现从小到大 => 右边的j侦测比基准数小的，左边的i侦测比基准数大的
	while (i!=j) {
		for (j = tail; j >= head; j--) {
			// 哨兵j遇到比基准数小的,就停下
			if (arr[j]<base || i==j) {
				//printf("%d < %d",arr[j],base);
				break;
			} 
		}
		for (i = head; i<= tail; i++) {
			// 哨兵i遇到比基准数大的，就停下
			if (arr[i]>base || i==j) {
				//printf("%d > %d",arr[i],base);
				break;
			}
		}
		if (i<j) {  // i和j没有相遇，让i和j所在的位置的数交换 
			int m = arr[j];
			arr[j] = arr[i];
			arr[i] = m;
		}
	}
	// i与j相等了，就把i和j所在的位置与基准数调换
	arr[head] = arr[i];
	arr[i] = base;
	// 调换完毕后，哨兵i和j的共同位置成为了序列的分隔点
	quicksort(head, i - 1);
	quicksort(i + 1, tail); 
}

int main() {
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quicksort(0, n-1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

// 2 3 6 2 5 3 4 1 6 7
