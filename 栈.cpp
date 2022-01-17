#include <stdio.h>

struct Stack {
	int data[100];
	int tail = 0;  // ע�⣬ջ����Ч��Χ��[0,tail)������tail��ָ��λ�ò���ջ�� 
};

struct Stack s;

// ��ջ������� 
void push(struct Stack* s, int val) {
	// ���Ԫ�� 
	s->data[s->tail] = val; 
	// tail ��ǰ��һλ��������ӵ�Ԫ�س�Ϊջ��һ���� 
	s->tail ++;
}

// ��ջ������� 
void pop(struct Stack* s) {
	// ��ջ�����һ��Ԫ�ز����Ƕ��е�һ���֣����������һ��Ԫ�� 
	s->tail --;  
}

// ������һ��Ԫ��
int get(struct Stack* s) {
	return s->data[s->tail-1];  // tail ���ǿ����䣬����Ҫ-1 
} 

// ��ǰ�����ӡջ 
void print(struct Stack* s) {
	for (int i = 0; i<s->tail; i++) {
		printf("%d ", s->data[i]);
	}
	printf("\n");
}

int main() {
	// �ж������Ƿ���ȷ�պ�
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
		printf("����δ��ȷ�պ�");
	} else {
		printf("������ȷ�պ�");
	}
}
