#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int sortinfo[6][2];

void hello() {
	printf("0. Выход\n");
	printf("1. Создание массива\n");
	printf("2. Линейный поиск\n");
	printf("3. Бинарный поиск\n");
	printf("4. Пузырьковая сортировка\n");
	printf("5. Сортировка выбором\n");
	printf("6. Сортировка вставками\n");
	printf("7. Сортировка подсчётом\n");
	printf("8. Быстрая сортировка\n");
	printf("Ваш выбор: ");

}

void output(int* m, int n) {
	for (int i = 0; i < n; i++) {
		printf("| %d ", m[i]);
	}
	printf("|\n");
}

int* arr(int* m, int* n) {
	int a, b, buff;
	if (m != NULL) {
		free(m);
	}
	printf("Введите размер массива: ");
	scanf_s("%d", n);
	m = (int*)malloc((*n) * sizeof(int));
	if ((*n) > 10) {
		printf("Введите левую границу значений элементов массива: ");
		scanf_s("%d", &a);
		printf("Введите правую границу значений элементов массива: ");
		scanf_s("%d", &b);
		if (a > b) {
			buff = a;
			a = b;
			b = buff;
		}
		for (int i = 0; i < (*n); i++) {
			m[i] = a + rand() % (b - a + 1);
		}
	}
	else {
		printf("Введите элементы массива: ");
		for (int i = 0; i < (*n); i++) {
			scanf_s("%d", &m[i]);
		}
	}
	return m;
}

int* arr2(int* m, int n) {
	int* mass = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		mass[i] = m[i];
	}
	return mass;
}

int* sortarr(int* m, int n) {
	int buff;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (m[j] > m[j + 1]) {
				buff = m[j];
				m[j] = m[j + 1];
				m[j + 1] = buff;
			}
		}
	}
	return m;
}

void linear(int* m, int n) {
	int el, flag = 0, com = 0;
	printf("Введите элемент, который вы хотите найти: ");
	scanf_s("%d", &el);
	for (int i = 0; i < n; i++) {
		com++;
		if (el == m[i]) {
			flag = 1;
			printf("Элемент %d стоит на позиции %d\n", el, i);
			break;
		}
	}
	if (flag == 0) {
		printf("Такого элемента нет в массиве\n");
	}
	printf("Количество проверок: %d\n", com);
}

void binear(int* mass, int n) {
	int first = 0, last = n - 1, mid, el, com = 0, flag = 0;
	printf("Введите элемент, который хотите найти: ");
	scanf_s("%d", &el);
	while (first <= last) {
		mid = (first + last) / 2;
		com++;
		if (mass[mid] == el) {
			flag = 1;
			printf("Элемент %d стоит на позиции %d\n", el, mid);
			break;
		}
		com++;
		if (el > mass[mid]) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}
	if (flag == 0) {
		printf("Такого элемента нет в массиве\n");
	}
	printf("Количество сравнений: %d\n", com);
}

void bubble(int* m, int n) {
	int buff, oper = 0;
	int* arr = arr2(m, n);
	clock_t start = clock();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			oper++;
			if (arr[j] > arr[j + 1]) {
				buff = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buff;
				oper++;
			}
		}
	}
	clock_t end = clock();
	printf("Time: %.6f\n", (float)(end - start) / CLOCKS_PER_SEC);
	output(arr, n);
	printf("Количество операций: %d\n", oper);
	sortinfo[0][0] = oper;
	sortinfo[0][1] = (float)(end - start) / CLOCKS_PER_SEC;
	free(arr);
}

void choise(int* m, int n) {
	int imin, buff, oper = 0;
	int* arr = arr2(m, n);
	clock_t start = clock();
	for (int i = 0; i < n; i++) {
		imin = i;
		for (int j = i; j < n; j++) {
			oper++;
			if (arr[imin] > arr[j]) {
				imin = j;
			}
		}
		buff = arr[imin];
		arr[imin] = arr[i];
		arr[i] = buff;
		oper++;
	}
	clock_t end = clock();
	output(arr, n);
	printf("Time: %.6f\n", (float)(end - start) / CLOCKS_PER_SEC);
	printf("Количество операций: %d\n", oper);
	sortinfo[1][0] = oper;
	sortinfo[1][1] = (float)(end - start) / CLOCKS_PER_SEC;
	free(arr);
}

void insert(int* m, int n) {
	int copy, pos, oper = 0;
	int* arr = arr2(m, n);
	clock_t start = clock();
	for (int i = 1; i < n; i++) {
		pos = i;
		for (int j = i-1; j >= 0; j--) {
			oper++;
			if (arr[i] >= arr[j]) {
				pos = j+1;
				break;
			}
		}
		copy = arr[i];
		for (int j = i - 1; j >= pos; j--) {
			arr[j + 1] = arr[j];
			oper++;
		}
		arr[pos] = copy;
	}
	clock_t end = clock();
	output(arr, n);
	printf("Time: %.6f\n", (float)(end - start) / CLOCKS_PER_SEC);
	printf("Количество опреаций: %d\n", oper);
	sortinfo[2][0] = oper;
	sortinfo[2][1] = (float)(end - start) / CLOCKS_PER_SEC;
	free(arr);
}

void count(int* m, int n) {
	int max = m[0], oper = 0;
	for (int i = 0; i < n; i++) {
		if (max <= m[i]) {
			max = m[i];
		}
	}

	int* count = arr2(m, max + 1);
	int* arr = arr2(m, n);
	clock_t start = clock();
 	for (int i = 0; i < max + 1; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		count[m[i]]++;
	}
	int k = 0;
	for (int i = 0; i <= max; i++) {
		for (int j = 0; j < count[i]; j++) {
			oper++;
			arr[k++] = i;
		}
	}
	clock_t end = clock();
	output(arr, n);
	printf("Time: %.6f\n", (float)(end - start) / CLOCKS_PER_SEC);
	printf("Количество опреаций: %d\n", oper);
	sortinfo[3][0] = oper;
	sortinfo[3][1] = (float)(end - start) / CLOCKS_PER_SEC;
	free(count);
	free(arr);
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int* m = nullptr, n, code, turn, flag = 0, f = 0, *sortm = nullptr;
	do {
		hello();
		turn = scanf_s("%d", &code);
		switch (code) {
			case 0: break;
			case 1: flag = 1;
				m = arr(m, &n);
				sortm = arr2(m, n);
				output(m, n);
				break;

			case 2: if (flag == 0) {
				printf("Сначала заполните массив\n");
				break;
			}
				  linear(m, n); break;

			case 3: 
				if (flag == 0) {
				printf("Сначала заполните массив\n");
				break;
				}
				if (f == 0) {
				  printf("Сначала отсортируйте массив\n");
				  break;
				}
				sortarr(sortm, n);
				binear(sortm, n);
				free(sortm);
				break;

			case 4: if (flag == 0) {
				printf("Сначала заполните массив\n");
				break;
			}
				  bubble(m, n); f++; break;

			case 5: if (flag == 0) {
				printf("Сначала заполните массив\n");
				break;
			}
				  choise(m, n); f++; break;

			case 6: if (flag == 0) {
				printf("Сначала заполните массив\n");
				break;
			}
				  insert(m, n);f++; break;

			case 7: if (flag == 0) {
				printf("Сначала заполните массив\n");
				break;
			}
				  count(m, n); break;
			
			default: if (turn == 0) {
				printf("Ошибка! Можно вводить только числа\n");
				while (getchar() != '\n');
			}
				   break;
		}
	} while (code != 0);

	if (m != NULL) {
		free(m);
	}
	return 0;
}