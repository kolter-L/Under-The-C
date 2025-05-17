## Creating a new Struct

Structs are kinda like an object. We can predefine our struct like this:

```
typedef struct {
    char* name;
    int id;
    float weight;
} Dog;

```

We can create a new instance of our struct and access its attributes like this:

```
Dog my_dog;
my_dog.name = "jack";
my_dog.id = 0;
my_dog.weight = 3.9;
```

If we are passing our struct into a function, we need to pass it as a pointer. We can dereference and access the attributes with the arrow `->` which is equivalent to doing (*dog).desired_attribute:

```
void print_name(Dog* dog) {
    printf("%s\n", dog->name)
}

int main() {
    Dog my_dog;
    my_dog.name = "jack";
    my_dog.id = 0;
    my_dog.weight = 3.9;

    print_name(&my_dog):

    return 0;
}

```