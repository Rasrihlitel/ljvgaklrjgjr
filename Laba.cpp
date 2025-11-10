#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

double bubb = 0, cho = 0, ins = 0;

void hello() {
	printf("Select an action:\n");
	printf("0. Exit\n");
	printf("1. Filling in the array\n");
	printf("2. Linear element search\n");
	printf("3. Binary element search\n");
	printf("4. Bubble Sort\n");
	printf("5. Choise Sort\n");
	printf("6. Insert Sort\n");
	printf("7. Time comparison\n");
	printf("Your choice: ");
}

void arr(int* m, int n) {
	int a, b, buff;
	if (n <= 10 && n > 0) {
		for (int i = 0; i < n; i++) {
			printf("Input %d number: ", i + 1);
			scanf_s("%d", &m[i]);
		}
		printf("Your array: |");
		for (int i = 0; i < n; i++) {
			printf(" %d |", m[i]);
		}
		printf("\n");
	}
	else {
		printf("Enter the first face of the range: ");
		scanf_s("%d", &a);
		printf("Enter the second face of the range: ");
		scanf_s("%d", &b);
		if (a > b) {
			buff = a;
			a = b;
			b = buff;
		}
		for (int i = 0; i < n; i++) {
			m[i] = a + rand() % (b - a + 1);
		}
		printf("Your array: |");
		for (int i = 0; i < n; i++) {
			printf(" %d |", m[i]);
		}
		printf("\n");
	}
}

void arr2(int* m, int* mass, int n) {
	for (int i = 0; i < n; i++) {
		mass[i] = m[i];
	}
}

void linear(int* m, int n) {
	int num = 0, s = 0, f = 0;
	printf("Enter the item you want to find: ");
	scanf_s("%d", &num);
	for (int i = 0; i < n; i++) {
		s++;
		if (num == m[i]) {
			f = 1;
			printf("Number %d in position %d\n", num, i);
			break;
		}
	}
	if (f == 0) {
		printf("The element is not in the array\n");
	}
	printf("Number of operations: %d\n", s);
}

void binary(int* m, int*mass, int n) {
	int first = 0, last = n - 1, mid = n / 2, el = 0, flag = 0, oper = 0;
	arr2(m, mass, n);
	printf("Enter the item you want to find: ");
	scanf_s("%d", &el);
	while (first <= last) {
		if (mass[mid] == el) {
			flag = 1;
			printf("Number %d in position %d\n", el, mid);
			printf("Operations: %d", oper);
			break;
		}
		if (el < mass[mid]) {
			last = mid - 1;
			oper++;
		}
		else {
			first = mid + 1;
			oper++;
		}
		mid = ((last + first) / 2);
		oper++;
	}
	if (flag == 0) {
		printf("There is no such number\n");
		printf("Operations: %d\n", oper);
	}
}

void bubble(int* m, int* mass, int n) {
	clock_t start, end;
	int buff, oper = 0, srav = 0;
	arr2(m, mass, n);
	start = clock();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (mass[j] > mass[j + 1]) {
				srav++;
				buff = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = buff;
				oper++;
			}
		}
	}
	end = clock();
	bubb = end - start;
	for (int i = 0; i < n; i++) {
		printf("| %d ", mass[i]);
	}
	printf("|\n");
	printf("Operation: %d\n", oper);
	printf("Comparisons: %d\n", srav);
	printf("Time: %lf ms\n", end - start);
}

void choise(int* m, int* mass, int n) {
	int imin, srav = 0, oper = 0, buff;
	clock_t start, end;
	arr2(m, mass, n);
	start = clock();
	for (int i = 0; i < n; i++) {
		imin = i;
		for (int j = i; j < n; j++) {
			if (mass[j] < mass[imin]) {
				imin = j;
				srav++;
			}
		}
		buff = mass[imin];
		mass[imin] = mass[i];
		mass[i] = buff;
		oper++;
	}
	end = clock();
	cho = end - start;
	for (int i = 0; i < n; i++) {
		printf("| %d ", mass[i]);
	}
	printf("|\n");
	printf("Operation: %d\n", oper);
	printf("Comparisons: %d\n", srav);
	printf("Time = %lf ms\n", end - start);
}

void inserts(int* m, int* mass, int n) {
	clock_t start, end;
	int pos, copy, oper = 0, srav = 0;
	arr2(m, mass, n);
	start = clock();
	for (int i = 1; i < n; i++) {
		pos = i;
		for (int j = 0; j < i; j++) {
			if (mass[i] < mass[j]) {
				pos = j;
				srav++;
				break;
			}
		}
		copy = mass[i];
		for (int k = i - 1; k >= pos; k--) {
			mass[k + 1] = mass[k];
			oper++;
		}
		mass[pos] = copy;
	}
	end = clock();
	ins = end - start;
	for (int i = 0; i < n; i++) {
		printf("| %d ", mass[i]);
	}
	printf("|\n");
	printf("Operation: %d\n", oper);
	printf("Comparisons: %d\n", srav);
	printf("Time: %lf ms\n", end - start);
}

void time(double bubb, double cho, double ins) {
	double m[3] = { bubb, cho, ins };
	double min = m[0];
	int n;
	for (int i = 0; i < 3; i++) {
		if (min > m[i]) {
			min = m[i];
			n = i;
		}
	}
	printf("MIN Time have a ");
	switch (n) {
		case 0: printf("bubble sort: %lf", m[n]); break;
		case 1: printf("choise sort: %lf", m[n]); break;
		case 2: printf("insert sort: %lf", m[n]); break;
		default: break;
	}
}

int main() {
	srand(time(0));
	int* m = nullptr, n, flag = 0, code, turn, * mass = nullptr, f = 0;
	do {
		hello();
		turn = scanf_s("%d", &code);
		switch (code) {
		case 0: break;
		case 1: flag = 1;
			printf("Enter the size of the array: ");
			scanf_s("%d", &n);
			m = (int*)malloc(n * sizeof(int));
			arr(m, n);
			mass = (int*)malloc(n * sizeof(int));
			break;

		case 2: if (flag == 0) {
			printf("First fill in the array\n");
			break;
		}
			  linear(m, n); break;

		case 3: if (flag == 0) {
			printf("First fill in the array\n");
			break;
		}
			  if (f == 0) {
				  printf("It is necessary to arrange the array\n");
				  break;
			  }
			  binary(m, mass, n); break;

		case 4: if (flag == 0) {
			printf("First fill in the array\n");
			break;
		}
			  f++;
			  bubble(m, mass, n); break;

		case 5: if (flag == 0) {
			printf("First fill in the array\n");
			break;
		}
			  f++;
			  choise(m, mass, n); break;

		case 6: if (flag == 0) {
			printf("First fill in the array\n");
			break;
		}
			  f++;
			  inserts(m, mass, n); break;

		case 7: if (flag == 0) {
			printf("First fill in the array\n");
			break;
		}
			  if (f < 3) {
				  printf("It is necessary to perform all the sorting\n");
				  break;
			  }
			  time(bubb, cho, ins); break;

		default: if (turn == 0) {
			getchar();
			printf("Error");
			break;
		}
		}
	} while (code != 0);

	free(m);
	free(mass);
	return 0;
}