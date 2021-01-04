#include <iostream>
#include <time.h>
#include "sorts.h"

using namespace std;

template <typename Type>
void TwoWayInsert(Type* getArr, int s) {
    int Size = s * 2 + 1;
    Type* outArr = new Type[Size];  // сортированный массив
    int mid = s;  // середина массива
    int comparisons = 0;  // сравнения
    int permutations = 0;  // перестановки
    int right = mid;  // индекс справа
    int left = mid;  // индекс слева
    Type tmp;

    for (int i = 0; i < Size; ++i) {
        outArr[i] = -1;
    }

    clock_t start = clock();
    outArr[mid] = getArr[0];
    for (int i = 1, j; i < s; i++) {
        tmp = getArr[i];
        j = mid;
        comparisons++;
        if (tmp > outArr[j]) {
            while (tmp > outArr[j] && j < right + 1) {
                j++;
                comparisons++;
            }
            if (j - left <= right - j) {
                for (int k = left; k <= j; ++k) {
                    permutations++;
                    outArr[k-1] = outArr[k];
                }
                left--;
                outArr[j-1] = tmp;
            }
            else {
                for (int k = right; k >= j; --k) {
                    outArr[k+1] = outArr[k];
                    permutations++;
                }
                right++;
                outArr[j] = tmp;
            }
        }
        else {
            while (tmp < outArr[j] && j > left - 1) {
                comparisons++;
                j--;
            }
            if (j - left >= right - j) {
                for (int k = right; k >= j; --k) {
                    outArr[k+1] = outArr[k];
                    permutations++;
                }
                right++;
                outArr[j+1] = tmp;
            }
            else {
                for (int k = left; k <= j; ++k) {
                    outArr[k-1] = outArr[k];
                    permutations++;
                }
                left--;
                outArr[j] = tmp;
            }
        }
    }
    clock_t end = clock();

    cout << endl;
    cout << "ДВУПУТЕВЫЕ ВСТАВКИ";

    cout << endl;
    cout << "Число сравнений: " << comparisons << endl;
    cout << "Число обменов: " << permutations << endl;
    cout << "Время сортировки: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;

    for (int i = left; i < right; ++i) {
        if (outArr[i] > outArr[i+1]) { cout << "Error sort!"; }
    }
}

template <typename Type>
void swap(Type* a, Type* b) {
    Type t = *a;
    *a = *b;
    *b = t;
}

template <typename Type>
void quickSortIterative(Type* arr, int s) {
    int l = 0;
    int h = s - 1;
    Type stack[h - l + 1];
    int comparisons = 0;  // сравнения
    int permutations = 0;  // перестановки

    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    clock_t start = clock();
    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];

//        partition(arr, l, h, comparisons, permutations);
        int x = arr[h];
        int i = (l - 1);

        for (int j = l; j <= h - 1; j++) {
            comparisons++;
            if (arr[j] <= x) {
                permutations++;
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        permutations++;
        swap(&arr[i + 1], &arr[h]);
        int p = i+1;

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
    clock_t end = clock();

    cout << endl;
    cout << "БЫСТРАЯ СОРТИРОВКА";

    cout << endl;
    cout << "Число сравнений: " << comparisons << endl;
    cout << "Число обменов: " << permutations << endl;
    cout << "Время сортировки: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;

    for (int i = 0; i < s-1; ++i) {
        if (arr[i] > arr[i+1]) { cout << "Error sort!"; }
    }
}
