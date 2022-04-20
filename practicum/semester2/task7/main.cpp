#pragma warning(disable: 4996);
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

const int BUFF_SIZE = 256;
typedef struct
{
    int shelf_life, price, count;
    char name[BUFF_SIZE];
    char producer[BUFF_SIZE];
    char name_of_department[BUFF_SIZE];
    char date[BUFF_SIZE];
} product;
typedef struct {
    int year;
    int month;
    int day;
} date;

void parse_date(const char*, date*);
bool is_exceeded(struct tm*, struct tm*, int);
bool write_to_end(FILE*, product*);
bool write_to_begin(FILE*, product*);
bool write_to_center(FILE*, product*);
void print_product(product*);
void print_products(product**, size_t);
void print_exceeded_product(product*);
void sort_by_departement(product**, size_t);
void sort_product_alphabetically(product**, size_t);
size_t get_count_of_products(FILE*);
size_t get_count_of_department(product**, size_t, const char*);
product* read_product(FILE*);
product** read_all_products(FILE*);
int find_index_product_by_department(product**, size_t, const char*);
int productcmp(const void*, const void*);
int a(const char*);
int b(const char*);

int main()
{
//    product pr;
//    FILE* file = fopen("test.bin", "a+b");
//    strcpy(pr.name, "MOKA");
//    strcpy(pr.producer, "VRKA");
//    strcpy(pr.name_of_department, "AAA");
//    strcpy(pr.date,"26-01-2021");
//    pr.count = 111;
//    pr.price = 10;
//    pr.shelf_life = 13;
//    write_to_begin(file, &pr);
    a("test.bin");
    b("test.bin");
    return 0;
}
bool is_exceeded(struct tm* product, struct tm* now, int shelf_life)
{
    struct tm shelf = {0};
    shelf.tm_mday = shelf_life;
    double a = difftime(mktime(product), mktime(now)) / 3600 / 24;
    if(a < 0) return false;
    if(a > shelf_life) return true;
    return false;
}
void parse_date(const char* str, date* r_date)
{
    char buf[8];
    int len = strlen(str);
    if(len != 10) return;
    buf[0] = str[0];
    buf[1] = str[1];
    buf[2] = '\0';
    r_date->day = atoi(buf);
    buf[0] = str[3];
    buf[1] = str[4];
    buf[2] = '\0';
    r_date->month = atoi(buf);
    buf[0] = str[6];
    buf[1] = str[7];
    buf[2] = str[8];
    buf[3] = str[9];
    buf[4] = '\0';
    r_date->year = atoi(buf);
}
size_t get_count_of_products(FILE* file)
{
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file) / sizeof(product);
    rewind(file);
    return size;
}
size_t get_count_of_department(product** products, size_t size, const char* name_of_deparment)
{
    size_t count = 0;
    for(int i = 0; i < size; i++)
    {
        if(strcmp(products[i]->name_of_department, name_of_deparment) == 0) count++;
    }
    return count;
}
bool write_to_end(FILE* file, product* prod)
{
    if (file == NULL) return false;
    fseek(file, 0, SEEK_END);
    int s = fwrite(prod, sizeof(product), 1, file);
    fclose(file);
    return s;
}
bool write_to_begin(FILE* file, product* prod)
{
    FILE* new_file = fopen("testcpy.bin", "w+b");
    if(!new_file) return false;
    size_t size = get_count_of_products(file);
    fwrite(prod, sizeof(product), 1, new_file);
    for(int i = 0; i < size; i++)
    {
        product* pr = read_product(file);
        fwrite(pr, sizeof(product), 1, new_file);
        delete pr;
    }
    fclose(file);
    file = new_file;
    fclose(new_file);
    return rename("testcpy.bin", "test.bin");
}
bool write_to_center(FILE* file, product* prod)
{
    FILE* new_file = fopen("testcpy.bin", "w+b");
    if(!new_file) return false;
    size_t size = get_count_of_products(file) + 1;
    size_t index = size / 2;
    for(int i = 0; i < size; i++)
    {
        if(i == index)
            fwrite(prod, sizeof(product), 1, new_file);
        else
        {
            product* pr = read_product(file);
            fwrite(pr, sizeof(product), 1, new_file);
            delete pr;
        }
    }
    fclose(file);
    file = new_file;
    fclose(new_file);
    return rename("testcpy.bin", "test.bin");
}
product* read_product(FILE* file)
{
    product* pr = new product;
    fread(pr, sizeof(product), 1, file);
    return pr;
}
product** read_all_products(FILE* file)
{
    if(file == NULL) return NULL;
    size_t count_of_records = get_count_of_products(file);
    rewind(file);
    product** products = new product*[count_of_records];
    for(int i = 0; i < count_of_records; i++)
        products[i] = read_product(file);
    return products;
}
int find_index_product_by_department(product** products, size_t size, const char* name)
{
    for(int i = 0; i < size; i++)
        if(strcmp(products[i]->name_of_department, name) == 0) return i;
}
void sort_by_departement(product** products, size_t size)
{
    if(size < 2) return;
    for(int i = 0; i < size; i++)
    {
        product* not_right_department = NULL;
        int index;
        for(int j = i + 1; j < size; j++)
        {
            if(strcmp(products[j]->name_of_department, products[i]->name_of_department) != 0)
            {
                not_right_department = products[j];
                index = j;
                for(; j < size; j++)
                {
                    if(strcmp(products[j]->name_of_department, products[i]->name_of_department) == 0)
                    {
                        products[index] = products[j];
                        products[j] = not_right_department;
                        not_right_department = NULL;
                        break;
                    }
                }
            }
            else
            {
                if(not_right_department != NULL)
                {
                    products[index] = products[j];
                    products[j] = not_right_department;
                    not_right_department = NULL;
                }
            }
        }
    }
}
void sort_product_alphabetically(product** products, size_t size)
{
    qsort(products, size, sizeof(product*), productcmp);
}
int productcmp(const void* s1, const void* s2)
{
    product* _s1 = *(product**)s1;
    product* _s2 = *(product**)s2;
    return strcmp(_s1->name, _s2->name);
}
void print_product(product* pr)
{
    printf("%s | ", pr->name);
    printf("%s | ", pr->producer);
    printf("%d | ", pr->count);
    printf("%s | ", pr->name_of_department);
    printf("%s | ", pr->date);
    printf("%d | ", pr->shelf_life);
    printf("%d\n", pr->price);
}
void print_exceeded_product(product* pr)
{
    printf("%s | ", pr->name);
    printf("%s | ", pr->name_of_department);
    printf("%s | ", pr->date);
    printf("%d | ", pr->shelf_life);
    printf("%d\n", pr->price);
}
void print_products(product** products, size_t size)
{
    for(int i = 0; i < size; i++)
        print_product(products[i]);
}
int a(const char* file_name)
{
    FILE* file = fopen(file_name, "a+b");
    if(file == NULL) return 1;
    product** products  = read_all_products(file);
    size_t size = get_count_of_products(file);
    sort_by_departement(products, size);
    for(int i = 0; i < size; i++)
    {
        size_t count = get_count_of_department(products, size, products[i]->name_of_department);
        size_t index = find_index_product_by_department(products, size, products[i]->name_of_department);
        sort_product_alphabetically(products + index, count);
    }
    print_products(products, size);
}
int b(const char* filename)
{
    char dat[11];
    FILE* file = fopen(filename, "a+b");
    if(file == NULL) return 1;
    printf("Enter a date: ");
    scanf("%s", dat);
    date d1, d2;
    dat[10] = '\0';
    parse_date(dat, &d2);
    struct tm t1 = {0};
    struct tm t2 = {0};
    t1.tm_year = d2.year;
    t1.tm_mon = d2.month;
    t1.tm_mday = d2.day;
    product** products  = read_all_products(file);
    size_t size = get_count_of_products(file);
    for(int i = 0; i < size; i++)
    {
        parse_date(products[i]->date, &d1);
        t2.tm_mday = d1.day;
        t2.tm_year = d1.year;
        t2.tm_mon = d1.month;
        if(is_exceeded(&t1, &t2, products[0]->shelf_life)) print_exceeded_product(products[i]);
    }
    return 0;
}