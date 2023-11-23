#include <stdio.h>

struct Person {
    char name[20];
    int age;
    float height;
};

int main() {
    struct Person person;
    printf("ÄãºÃ°¡%d\n", sizeof(person));
    return 0;
}
