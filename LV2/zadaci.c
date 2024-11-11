#define _CRT_SECURE_NO_WARNNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DG 0
#define GG 500

typedef struct lista {
	int x;
	struct lista* sljedeci;
}LIST;

void rand_array(int array[], int n);
LIST* pop_listu(int array[], int n);
int sekv_pret_array(int array[], int n, int x);
int sekv_pret_lista(LIST* head, int x);

int main() {


	int n = 1000000;

	int x = 2000;
	int* array = NULL;
	array = (int*)malloc(n * sizeof(int));

	srand((unsigned)time(NULL));

	time_t prvi_time, drugi_time;

	prvi_time = clock();
	rand_array(array, n);
	drugi_time = clock();

	printf("\nFormiranje niza: %d ms\n", drugi_time - prvi_time);

	prvi_time = clock();
	LIST* head = pop_listu(array, n);
	drugi_time = clock();

	printf("Formiranje PP: %d ms\n", drugi_time - prvi_time);

	prvi_time = clock();
	int pron_el = sekv_pret_array(array, n, x);
	drugi_time = clock();

	printf("Pretrazivanje niza: %d ms i element je na %d poziciji \n", (drugi_time - prvi_time), (pron_el + 1));

	prvi_time = clock();
	int pron_elem = sekv_pret_lista(head, x);
	drugi_time = clock();

	printf("Pretrazivanje PP: %d ms i element je na %d poziciji \n", (drugi_time - prvi_time), (pron_elem + 1));

	return 0;
}



void rand_array(int array[], int n) {
	for (int i = 0; i < n; i++) {
		array[i] = DG + (float)rand() / RAND_MAX * (GG - DG);
	}
}



LIST* pop_listu(int array[], int n) {
	LIST* p = NULL;
	LIST* head = NULL;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			head = (LIST*)malloc(sizeof(LIST));
			p = head;
		}
		else {
			p->sljedeci = (LIST*)malloc(sizeof(LIST));
			p = p->sljedeci;
		}
		p->x = array[i];
	}
	p->sljedeci = NULL;
	return head;
}



int sekv_pret_array(int array[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (array[i] == x) {
			return i;
			break;
		}
		if (i == n) {
			return -1;
			break;
		}
	}
}



int sekv_pret_lista(LIST* head, int x) {
	LIST* p = head;
	int br = 0;
	while (p != NULL) {
		if (p->x == x)
		{
			return br;
			break;
		}
		else if (p->x != x) {
			p = p->sljedeci;
			br++;
		}
		else {
			return -1;
			break;
		}
	}
}
//zadatak2
#include <stdio.h>

int main() {
	long long int available_memory_GB = 16;
	int size_of_element_bytes = 8;

	long long int available_memory_bytes = available_memory_GB * 1024 * 1024 * 1024;

	long long int max_elements = available_memory_bytes / size_of_element_bytes;

	printf("Najveci moguci niz elemenata je: %lld\n", max_elements);

	return 0;
}
//zadatak3
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

int main() {
	long long int available_memory_GB = 16;
	int size_of_node_bytes = sizeof(Node);

	long long int available_memory_bytes = available_memory_GB * 1024 * 1024 * 1024;

	long long int max_nodes = available_memory_bytes / size_of_node_bytes;

	printf("Najveci moguci povezani popis elemenata je: %lld\n", max_nodes);

	return 0;
}