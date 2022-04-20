//
// Created by Igor on 16.04.2022.
//

#ifndef ALGSORT_QUICK_HPP
#define ALGSORT_QUICK_HPP
void quicksort(int* array, int n)
{
    int i = 0;
    int j = n - 1;
    int mid = array[n / 2];
    do {
        while(array[i] < mid)
            i++;

        while(array[j] > mid)
            j--;

        if (i <= j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if(j > 0)
        quicksort(array, j + 1);
    if (i < n)
        quicksort(&array[i], n - i);
}
#endif //ALGSORT_QUICK_HPP
