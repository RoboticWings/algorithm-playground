#include <stdio.h>

struct Queue {
	int data[100];
	int head = 0;
	int tail = 0;  // ע�⣬���е���Ч��Χ��[head,tail)������tail��ָ��λ�ò��ڶ����� 
};

struct Queue q1, q2;

void push(struct Queue *q, int val) {
	// �������
	q->data[q->tail] = val;
	// tail��ǰ��һλ��������ӵ�Ԫ�س�Ϊ���е�һ���� 
	q->tail ++;
}

void pop(struct Queue *q) {
	// �ö��еĵ�һ��Ԫ�ز����Ƕ��е�һ���֣�������Ԫ�� 
	q->head ++;
}

void print(struct Queue *q) {
	for (int i = q->head; i < q->tail; i++) {
		printf("%d ", q->data[i]);
	}
	printf("\n");
}

int main() {
	for (int i = 0; i < 9; i++) {
		int m;
		scanf("%d", &m);
		push(&q1, m);
	}
	// ������Ů��QQ��~
	while (q1.head < q1.tail) {
		// ����ɾ������ 
		int deleted = q1.data[q1.head];
		pop(&q1);
		push(&q2, deleted);
		// �������ֵĽ���
		int shifted = q1.data[q1.head];
		pop(&q1);
		push(&q1, shifted); 
	} 
	print(&q2);
}
