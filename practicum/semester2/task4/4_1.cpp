#include <iostream>
/*Написать программу, выполняющую следующие действия:
   -  ввод данных с клавиатуры / из текстового файла в массив из 10 элементов типа Student;
   -  выдать  список  студентов,  которым должна быть назначена стипендия (получены оценки 4 или 5);
   -  если таких студентов нет, вывести соответствующее сообщение.
*/
const size_t STUDENT_SIZE = 4;
const size_t BUFF_SIZE = 256;
struct Student {
    int id;
    char name[32];
    char i1;
    char i2;
    int grade[4];
};

void read_from_console(Student* students, size_t size) {
    for(size_t i = 0; i < STUDENT_SIZE; i++) {
        printf("Enter student info (id name i1 i2 grade1 grade2 grade3 grade4): ");
        scanf("%d %s %c %c %d %d %d %d",
              &students[i].id, students[i].name, &students[i].i1, &students[i].i2,
              &students[i].grade[0], &students[i].grade[1],
              &students[i].grade[2], &students[i].grade[3]);
    }
}

int read_from_file(Student* students, size_t size, const char* filename) {
    FILE* file = fopen(filename, "r");
    if(file == NULL) return -1;
    for(size_t i = 0; !feof(file) && i != STUDENT_SIZE; i++) {
        fscanf(file, "%d %s %c %c %d %d %d %d",
               &students[i].id, students[i].name, &students[i].i1, &students[i].i2,
               &students[i].grade[0], &students[i].grade[1],
               &students[i].grade[2], &students[i].grade[3]);
    }

    return 0;
}
void print_students_with_grant(Student* students, size_t size) {
    bool withGrant;
    size_t count = 0;
    printf("Students with grants:\n");
    for(size_t i = 0; i < size; i++) {
        withGrant =  true;
        for(size_t j = 0; j < 4; j++) {
            if(students[i].grade[j] < 4)  {
                withGrant = false;
                break;
            }
        }
        if(withGrant) {
            count++;
            printf("%s %c. %c.\n", students[i].name, students[i].i1, students[i].i1);
        }
    }
    if(count == 0)
        printf("No students");
}
int main() {
    Student students[STUDENT_SIZE] = {0};
    int n;
    bool isNotWrited = true;
    while(isNotWrited) {
        printf("1 - file, 2 - console: ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                char filename[BUFF_SIZE];
                printf("Enter file name: ");
                scanf("%s", filename);
                read_from_file(students, STUDENT_SIZE, filename);
                isNotWrited = false;
                break;
            case 2:
                read_from_console(students, STUDENT_SIZE);
                isNotWrited = false;
                break;
            default:
                printf("Not right number. Retry\n");
        }
    }
    print_students_with_grant(students, STUDENT_SIZE);
    return 0;
}