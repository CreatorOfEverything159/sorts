#include <iostream>
#include "sorts.h"
#include "sorts.cpp"
using namespace std;

// Шаблонные функции
// Двупутевые вставки + быстрая нерекурсивная (разделяющий медиана)
// По неубыванию

// 1) Сортировать до 1М элементов
// 2) Подсчитывать число сравнений и обменов
// 3) Определить время сортировки

int main() {
    const int Size = 100000;
    int arr[Size] ;
//    = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2}

    for (int i = 0; i < Size; ++i) {
        arr[i] = 1+ rand() % 99;
    }

    TwoWayInsert(arr, Size);
    quickSortIterative(arr, Size);

    return 0;
}
