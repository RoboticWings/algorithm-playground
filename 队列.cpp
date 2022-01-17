#include <stdio.h>

struct Queue {
	int data[100];
	int head = 0;
	int tail = 0;  // 注意，队列的有效范围是[head,tail)，所以tail所指的位置不在队列中 
};

struct Queue q1, q2;

void push(struct Queue *q, int val) {
	// 添加数据
	q->data[q->tail] = val;
	// tail向前进一位，让新添加的元素成为队列的一部分 
	q->tail ++;
}

void pop(struct Queue *q) {
	// 让队列的第一个元素不再是队列的一部分，即弹出元素 
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
	// 计算美女的QQ号~
	while (q1.head < q1.tail) {
		// 处理被删除的数 
		int deleted = q1.data[q1.head];
		pop(&q1);
		push(&q2, deleted);
		// 处理数字的交换
		int shifted = q1.data[q1.head];
		pop(&q1);
		push(&q1, shifted); 
	} 
	print(&q2);
}
