# include <stdio.h>
# include <stdlib.h>

typedef struct {
    char* name;
    int id;
    float weight;
} Dog;

void print_name(Dog* dog) {
    printf("%s\n", dog->name);
}

int main() {
Dog my_dog;
my_dog.name = "jack";
my_dog.id = 0;
my_dog.weight = 3.9;

print_name(&my_dog);

return 0;
}