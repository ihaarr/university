#include <iostream>

int** get_matrix(int rows, int columns) {
    int** matrix = new int*[rows];
    for(int i = 0; i < columns; i++) {
        matrix[i] = new int[columns];
    }

    return matrix;
}

void delete_matrix(int** matrix, int rows) {
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void fill_matrix(int** matrix, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int** matrix, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

bool is_vector_non_decreasing(int* vector, int size) {
    bool flag = true;
    for(int i = 1; i < size; i++) {
        if(vector[i - 1] > vector[i]) {
            flag = false;
            break;
        }
    }

    return flag;
}

int find_max(int** valid_vectors, const int size, const int vec_size) {
    int max = INT_MIN;
    for(int i = 0; i < size; i++) {
       for(int j = 0; j < vec_size; j++) {
           if(valid_vectors[i][j] > max) {
               max = valid_vectors[i][j];
           }
       }
    }

    return max;
}

int digits_count(int number) {
    int count = 0;
    while(number > 0) {
        count++;
        number /= 10;
    }

    return count;
}

void a(int** matrix, int rows, int columns) {
    int** valid_vectors = new int*[rows];
    int count = 0;
    for(int i = 0; i < columns; i++) {
        if(is_vector_non_decreasing(matrix[i], columns)) {
            valid_vectors[count] = matrix[i];
            count++;
        }
    }

    if(count == 0) {
        printf("В массиве нет неубывающих строк\n");
    } else {
        if(digits_count(find_max(valid_vectors, count, columns)) % 2 == 1) {
            print_matrix(matrix, rows, columns);
        } 
    }

    delete[] valid_vectors;
}


int main() {
    int n, m, k, l;
    n = m = k = l = 3;
    int** m1 = get_matrix(n, m);
    int** m2 = get_matrix(k, l);
    fill_matrix(m1, n, m);
    fill_matrix(m2, k, l);
    a(m1, n, m);
    a(m2, k, l);
    return 0;
}