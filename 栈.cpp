#include <stdio.h>

struct Stack {
	int data[100];
	int tail = 0;  // 注意，栈的有效范围是[0,tail)，所以tail所指的位置不在栈中 
};

struct Stack s;

// 入栈（后进） 
void push(struct Stack* s, int val) {
	// 添加元素 
	s->data[s->tail] = val; 
	// tail 向前进一位，让新添加的元素成为栈的一部分 
	s->tail ++;
}

// 出栈（后出） 
void pop(struct Stack* s) {
	// 让栈的最后一个元素不再是队列的一部分，即弹出最后一个元素 
	s->tail --;  
}

// 获得最后一个元素
int get(struct Stack* s) {
	return s->data[s->tail-1];  // tail 端是开区间，所以要-1 
} 

// 从前到后打印栈 
void print(struct Stack* s) {
	for (int i = 0; i<s->tail; i++) {
		printf("%d ", s->data[i]);
	}
	printf("\n");
}

int main() {
	// 判断括号是否正确闭合
	char str[999];
	scanf("%s",str);
	int i = 0;
	while (str[i]!='\0') {
		char c = str[i];
		switch (c) {
			case '{':
				push(&s, 1);
				break;
			case '}':
				if (get(&s) == 1) pop(&s);
				break;
			case '[':
				push(&s, 2);
				break;
			case ']':
				if (get(&s) == 2) pop(&s);
				break;
			case '(':
				push(&s, 3);
				break;
			case ')':
				if (get(&s) == 3) pop(&s);
				break;
		}
		print(&s);
		i++;
	}
	if (s.tail > 0) {
		printf("括号未正确闭合");
	} else {
		printf("括号正确闭合");
	}
}
