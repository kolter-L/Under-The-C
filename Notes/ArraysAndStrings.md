
## Strings (char array vs pointer)

We can initialize a string like this:

`char my_name[] = "kolter"`

Or we can do this:

`char* my_name = "kolter"`

The second is a string literal that is immutable. We cannot do something like this:

`my_name[3] = 'x'`

The first one is an array of characters, so we can change individual characters if we want to.

## Stack vs Heap Memory

We can make an array like this:

`char my_name[64]`

This will allocate stack memory. It's size cannot be changed, but it will be automatically cleared at the end of the function.

We can also do this:
 
 `char* my_name = (char*)malloc(sizeof(char)*64)`

 This puts it on the heap. We can reallocate if we want to change the size. But we also have to free the memory manually.

 ### What does this mean?

 Generally, we should use the stack for data that is only used within our function. If we are returning data, we need to use heap so that we don't get a null reference error.