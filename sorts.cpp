#include <iostream>
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
        outArr[i] = 0;
    }

    outArr[mid] = getArr[0];
    for (int i = 1, j; i < s; i++) {
        tmp = getArr[i];
        j = mid;
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

    cout << endl;
    cout << "ДВУПУТЕВЫЕ ВСТАВКИ";

    cout << endl;
    cout << "Число сравнений: " << comparisons - 1 << endl;
    cout << "Число обменов: " << permutations - 1 << endl;
}

static const int M = 10;
template <class Item>
void quicksort(Item a[], int l, int r)
{
    if (r-1 <= M) return;
    exch(a[(l+r)/2], a[r-1]);
    comexch(a[l], a[r-1]);
    comexch(a[l], a[r]);
    comexch(a[r-1], a[r]);
    int i = partition(a, l+1, r-1);
    quicksort(a,l, i-1);
    quicksort(a, i+1, r);
}

template <class Item>
void hybridsort(Item a[], int l, int r)
{ quicksort(a, l, r); insertion(a, l, r); }

