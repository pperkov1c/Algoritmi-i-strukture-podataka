#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popuni_polje(float V[], int n, float dg, float gg);
int sekv_pret(float V[], int n, float x);
void swap(float* a, float* b);
void heapify(float V[], int n, int i);
void sort(float V[], int n);
int bin_pret(float V[], int n, float x);

int main() {
	int n = 10000;
	float* polje;

	polje = (float*)malloc(n * sizeof(float));
	if (polje == NULL) {
		return 1;
	}

	popuni_polje(polje, n, 0, 100);

	time_t time1, time2;

	time1 = clock();
	sekv_pret(polje, n, 105);
	time2 = clock();
	printf("\nTime za sekvencijalno pretrazivanje: %dms\n", time2 - time1);

	time1 = clock();
	sort(polje, n);
	time2 = clock();
	printf("\nTime za heap sort: %dms\n", time2 - time1);

	time1 = clock();
	bin_pret(polje, n, 105);
	time2 = clock();
	printf("\nTime za binarno pretrazivanje: %dms\n", time2 - time1);

	free(polje);
	polje = NULL;

	return 0;
}

void popuni_polje(float V[], int n, float dg, float gg) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++) {
		V[i] = dg + (float)rand() / RAND_MAX * (gg - dg + 1);
	}
}


int sekv_pret(float V[], int n, float x) {
	int i = 0;

	for (i = 0; i < n; i++) {
		if (V[i] == x) {
			return i;
		}

	}
	return -1;
}

void swap(float* a, float* b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(float V[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && V[l] > V[largest])
		largest = l;

	if (r < n && V[r] > V[largest])
		largest = r;

	if (largest != i) {
		swap(&V[i], &V[largest]);
		heapify(V, n, largest);
	}
}

void sort(float V[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(V, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(&V[0], &V[i]);
		heapify(V, i, 0);
	}
}

int bin_pret(float V[], int n, float x) {
	int dg = 0;
	int gg = n - 1;
	int s = -1;

	while (dg <= gg) {
		s = (dg + gg) / 2;

		if (V[s] == x) {
			return s;
		}
		else if (V[s] > x) {
			gg = s - 1;
		}
		else {
			dg = s + 1;
		}
	}
	return -1;
}