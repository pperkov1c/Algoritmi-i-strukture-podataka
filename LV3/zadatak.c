#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int povrh(int n, int m);
void push_stack1(int x);
void push_stack2(int x);
int pop1();
int pop2();
void povrhStog(int a, int b);

int x1 = 0;
int x2 = 0;
int stack1[N];
int stack2[N];
int stackpush1 = 0;
int stackpush2 = 0;

int main() {
	time_t v1, v2, v3, v4;
	int n, m;

	for (int n = 14; n <= 26; n += 2) {
		m = n / 2;
		v1 = clock();
		printf("\nRezultat od n = %d povrh n/2 = %d je: %d ", n, m, povrh(n, m));
		v2 = clock();
		printf("\n\tVrijeme sa standardnom rekurzijom: %d [ms]\n", v2 - v1);
		v3 = clock();
		printf("\n\nRezultat od n = %d povrh n/2 = %d je: ", n, m);
		povrhStog(n, m);
		v4 = clock();
		printf("\n\tVrijeme sa stogom: %d [ms]\n", v4 - v3);

	}

	return 0;
}


int povrh(int n, int m) {
	if (m > n) {
		return 0;
	}
	if (m == 0 || m == n) {
		return 1;
	}
	return povrh(n - 1, m - 1) + povrh(n - 1, m);
}

void push_stack1(int x) {
	if (stackpush1 == N) {
		printf("Stack overflow");
	}
	else {
		stackpush1 = stackpush1 + 1;
		stack1[stackpush1] = x;
	}
}

void push_stack2(int x) {
	if (stackpush2 == N) {
		printf("Stack overflow");
	}
	else {
		stackpush2 = stackpush2 + 1;
		stack2[stackpush2] = x;
	}
}

int pop1() {
	if (stackpush1 == 0) {
		printf("Stack underflow");
	}
	else {
		x1 = stack1[stackpush1];
		stackpush1 = stackpush1 - 1;
		return x1;
	}
}

int pop2() {
	if (stackpush2 == 0)
	{
		printf("Stack Underflow!");
	}
	else {
		x2 = stack2[stackpush2];
		stackpush2 = stackpush2 - 1;
		return x2;
	}
}

void povrhStog(int a, int b) {
	push_stack1(a);
	push_stack2(b);
	int povrh = 0;
	while (stackpush1 != 0) {
		a = pop1();
		b = pop2();
		if (a == b || b == 0) {
			povrh = povrh + 1;
		}
		else {
			push_stack1(a - 1);
			push_stack2(b - 1);
			push_stack1(a - 1);
			push_stack2(b);
		}
	}
	printf("%d", povrh);
}