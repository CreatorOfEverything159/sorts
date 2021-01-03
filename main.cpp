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
    const int Size = 15;
    int arr[Size] = {5, 8, 21, 7, 3, 5, 17, 4, 9, 12, 8, 7, 11, 8, 12};

    cout << "Изначальный массив: ";
    for (int i = 0; i < Size; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;

    TwoWayInsert(arr, Size);

    return 0;
}
