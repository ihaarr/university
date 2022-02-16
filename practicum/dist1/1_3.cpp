#include <iostream>

const int n = 3;
const int m = 2;

int **get_matrix()
{
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }

    return matrix;
}

void free_matrix(int **matrix)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void fill_matrix(int **matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void fill_matrix(int **matrix, int **m2)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = m2[i][j];
        }
    }
}

int get_trace(int **matrix)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
    }

    return sum;
}

int **mult_matrix(int **m1, int **m2)
{
    int **matrix = get_matrix();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
            for (int k = 0; k < n; k++)
                matrix[i][j] += m1[i][k] * m2[k][j];
        }
    }

    return matrix;
}

void print_matrix(int **matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int *get_vector(int **matrix, const int m)
{
    int *vector = new int[m];
    int **mat = matrix;
    for (int i = 0; i < m; i++)
    {
        mat = mult_matrix(mat, matrix);
        vector[i] = get_trace(mat);
    }

    free_matrix(mat);
    return vector;
}

void print_vector(int *vec, const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", vec[i]);
    }

    printf("\n");
}

int main()
{
    int **ma = get_matrix();
    fill_matrix(ma);
    print_vector(get_vector(ma, m), m);
}