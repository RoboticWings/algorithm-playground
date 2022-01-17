#include <stdio.h>

int arr[100];
int n = 10;
void quicksort(int head, int tail) {
	if (head > tail) return;
	int base = arr[head];
	int i=head,j=tail;
	// �������� ʵ�ִ�С���� => �ұߵ�j���Ȼ�׼��С�ģ���ߵ�i���Ȼ�׼�����
	while (i!=j) {
		for (j = tail; j >= head; j--) {
			// �ڱ�j�����Ȼ�׼��С��,��ͣ��
			if (arr[j]<base || i==j) {
				//printf("%d < %d",arr[j],base);
				break;
			} 
		}
		for (i = head; i<= tail; i++) {
			// �ڱ�i�����Ȼ�׼����ģ���ͣ��
			if (arr[i]>base || i==j) {
				//printf("%d > %d",arr[i],base);
				break;
			}
		}
		if (i<j) {  // i��jû����������i��j���ڵ�λ�õ������� 
			int m = arr[j];
			arr[j] = arr[i];
			arr[i] = m;
		}
	}
	// i��j����ˣ��Ͱ�i��j���ڵ�λ�����׼������
	arr[head] = arr[i];
	arr[i] = base;
	// ������Ϻ��ڱ�i��j�Ĺ�ͬλ�ó�Ϊ�����еķָ���
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
