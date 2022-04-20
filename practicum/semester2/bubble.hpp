//
// Created by Igor on 16.04.2022.
//

#ifndef ALGSORT_BUBBLE_HPP
#define ALGSORT_BUBBLE_HPP

typedef bool (*comparator)(int, int);
void bubble_sort(int* array, int size, comparator func)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(func(array[i], array[j]))
            {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}
#endif //ALGSORT_BUBBLE_HPP
