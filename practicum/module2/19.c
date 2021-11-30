#include <stdio.h>

const int n = 2;
const int m = 2;

//Найти количество строк и столбцов, в которых элементы попарно различны
int main() {
    int columnCount, rowCount;

    int arr[n][m];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            printf("Enter a el with indexes i = %d j = %d: ", i + 1, j + 1);
            scanf("%d",&arr[i][j]);
        }
    } 
    columnCount = rowCount = 0;
    int find = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(find != 0)
                break;
            for(int k = 0; k < n; ++k) {
                if((j != k && arr[i][j] == arr[i][k])) {
                    printf("ij = %d; ik = %d\n", arr[i][j],  arr[i][k]);
                    ++rowCount;
                    find = 1;
                    break;
                }
            }
        }
    } 


    find = 0;
    for(int j = 0; j < m; ++j) {
        for(int i = 0; i < n; ++i) {
            if(find != 0) 
                break;
            for(int k = 0; k < m; ++k) {
            printf("a[%d][%d] = %d\n", j, k, arr[j][k]);
                if(j != k && arr[i][j] == arr[j][k]) {
                    ++columnCount;
                    find = 1;
                    break;
                }
            }
        }
    }

    if(columnCount == 0 && rowCount == 0)
        printf("There is no column or row");
    else if(columnCount != 0 && rowCount == 0)
        printf("column = %d", columnCount);
    else if(rowCount != 0 && columnCount == 0)
        printf("row = %d", rowCount);
    else
        printf("column = %d; row = %d", columnCount, rowCount);
    return 0; 
}