#include <iostream>
#include <cstring>

const size_t PARTY_COUNT = 10;
const size_t MAX_NAME_LEN = 64;
/*
Имеется список результатов голосования избирателей за несколько партий, в виде списка названий данных партий. На вход программе в первой строке подается количество избирателей в списке N. В каждой из последующих N строк записано название партии, за которую проголосовал данный избиратель, в виде текстовой строки. Длина строки не превосходит 50 символов, название может содержать буквы, цифры, пробелы и прочие символы.
Пример входных данных:
6
Party one
Party two
Party three
Party three
Party two
Party three
Программа должна вывести список всех партий, встречающихся в исходном списке, в порядке убывания количества голосов, отданных за эту партию. При этом название каждой партии должно быть выведено ровно один раз, вне зависимости от того, сколько голосов было отдано за данную партию. Пример выходных данных для приведенного выше примера входных данных:
Party three  3
Party two    2
Party one    1
При этом следует учитывать, что количество голосов избирателей в исходном списке может быть велико (свыше 1000), а количество различных партий в этом списке не превосходит 10.

*/
void swap(char* str1, char* str2) {
    char *temp = str1;
    str1 = str2;
    str2 = temp;
}
int check_party(char parties[PARTY_COUNT][MAX_NAME_LEN], const char* party) {
    for(int i = 0; i < PARTY_COUNT; i++)
        if(strcmp(parties[i], party) == 0) return i;
    return -1;
}

void sort_parties(char parties[PARTY_COUNT][MAX_NAME_LEN], int votes[PARTY_COUNT]) {
    int max;
    size_t index;
    for(size_t i = 0; i < PARTY_COUNT; i++) {
        max = 0;
        for(size_t j = i + 1; j < PARTY_COUNT; j++) {
            if(votes[j] > max) {
                max = votes[j];
                index = j;
            }
        }
        if(votes[i] < max) {
            int tmp = votes[i];
            votes[i] = votes[index];
            votes[index] = tmp;
            swap(parties[i], parties[index]);
        }
    }
}
void print_parties_with_votes(char parties[PARTY_COUNT][MAX_NAME_LEN], size_t party_size, int votes[PARTY_COUNT]) {
    for(size_t i = 0; i < party_size; i++)
        printf("%s %d\n", parties[i], votes[i]);
}
int main() {
    char parties[PARTY_COUNT][MAX_NAME_LEN] = {0};
    int current_parties_count = 0;
    int votes[PARTY_COUNT] = {0};
    char buff[MAX_NAME_LEN];
    int n, id;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter votes %d times: ", n);
    for(size_t i = 0; i < n; i++) {
        scanf("%s", buff);
        id = check_party(parties, buff);
        if(id == -1) {
            strcpy(parties[current_parties_count], buff);
            votes[current_parties_count]++;
            current_parties_count++;
        } else {
            votes[current_parties_count]++;
        }
    }
    sort_parties(parties, votes);
    print_parties_with_votes(parties, current_parties_count, votes);
    return 0;
}