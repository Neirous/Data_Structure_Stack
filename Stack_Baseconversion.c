#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define OK 1
#define error 0
typedef struct {
	int data[MaxSize];
	int top;
	int base;
}Stack;

int InitStack(Stack* s) {
	s->top = 0;
	s->base = s->top;
	return OK;
}

int Pop(Stack* s, int* x) {
	if (!s) return error;
	*x = s->data[--s->top];
	return OK;
}

int StackEmpty(Stack* s) {
	if (s->top == s->base) return error;
	else return OK;
}
int Push(Stack* s, int x) {
	if (s->top - s->base == MaxSize - 1) return error;
	s->data[s->top] = x;
	s->top++;

}

void conversion(Stack* s)
{
	printf("请输入要转换的数：");
	int n;
	scanf("%d", &n);
	printf("请输入要转换成几进制（2，8，16）");
	int con;
	scanf("%d", &con);
	while (n) {
		Push(s, n % con);
		n /= con;
	}
	while (StackEmpty(s)) {
		int x;
		Pop(s, &x);
		if (x < 10)
		{
			printf("%d", x);
		}
		else
		{
			printf("%c", x - 10 + 'A');
		}

	}
}
int main()
{
	Stack s;
	InitStack(&s);
	conversion(&s);
	return 0;
}
