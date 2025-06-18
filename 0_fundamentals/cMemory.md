# C Memory
## Variables and Data Types
The C language provides basic data types, like `char`, `int`, `float`, `double`, and `bool`. There also exists modifiers such as `signed`, `unsigned`, `short`, and `long`.  

## Memory Allocation
In C programming, there exists two primary memory areas. These are known as the **stack** and the **heap**.

### Stack
Allocating memory for the stack in a program occurs when dealing with local variables and function calls. This allocation is automatic and is freed when the function ends. The size of memory before the stack is already known before execution.

```
int main() {
    
  // All these variables get memory
  // allocated on stack
  int a;
  int b[10];
  int n = 20;
  int c[n];
}
```

### Heap
Memory in the heap is allocated dynamically during the program's execution. Unlike the stack, this memory is automatically freed and must be manually deallocated. Heap memory can be accessed anywhere in the program instead of its localized function, making heap memory less safe than stack memory. Dynamically allocated memory is referenced with pointers. In C, this type of memory is commonly allocated with `malloc`.  

Keeping a pointer to dynamically allocated memory is important because losing the reference causes a memory leak. The memory has been allocated, but it is not able to be reached.  

Note that a pointer can reference data anywhere (stack and heap), but the location of the pointer itself depends on its declaration:

```
void stackExample() {
    int x = 10;
    int *p = &x;  // p is stored on the stack, points to x on the stack
}
```

```
#include <stdlib.h>

void heapExample() {
    int **p = malloc(sizeof(int*));     // allocate heap space to hold an int pointer
    *p = malloc(sizeof(int));           // allocate heap space to hold an int
    **p = 42;                            // assign value
}
```

Variable `p` is a pointer to pointer that is given memory to store a pointer. Then it is dereferenced once to assign the pointer space to hold an integer. Then it is dereferenced one more time to assign the value. The variable `p` itself is allocated on the stack because its defined in a function but points to heap memory. However, the second pointer was manually allocated memory in the statement `malloc(sizeof(int*));`, so that pointer is stored on the heap. The last statement, `**p = 42;` simply dereferences twice to assign the integer.

## Pointer Arithmetic
There are a few valid operations to perform on pointers in C. These are:  

1. Incrementation/Decrementation of a pointer  
2. Addition/Subtraction of an integer to a pointer  
3. Subtraction of two pointers of the same type  
4. Comparison of pointers  


**Incrementation/Decrementation of a pointer**   
When a pointer is incremented, it is actually incremented by the number equal to the data type the pointer is pointing to. For example, if a pointer points to a data type of 4 bytes, incrementing it will increment the pointer by 4 bytes. The same holds true for decrementation.  

**Addition/Subtraction of an integer to a pointer**  
If a pointer is added to an integer, the integer will first be multiplied by the size of the data type the pointer is pointing to, then added to the pointer. For example, if a pointer to integer is added with 5, the integer 5 will be multipled by the size of the pointer's pointee (in this case an integer, which is commonly 4 bytes) to result in 20. Thus, the pointer will be incremented by 20 bytes. The same holds true for subtraction.

**Subtraction of two pointers of the same type**  
When two pointers of the same type are subtracted from each other, the difference of the addresses are taken and then the increment of the pointers is given. I.e, how many `sizeof(x)`s there are between the two. For example, if pointerOne has address 1000 and pointerTwo has address 1004 and both are integer pointers, the difference between them is 4. Assuming the size of an integer is 4 bytes, this means the increment is 1 (4/4 = 1).

**Comparison of pointers**  
Pointers in C can be compared with all of the comparison operators in C. They can also be compared to `NULL` for error handling.

## Arrays and Strings in Memory

### Arrays
An array in C is a fixed-size collection of a data type stored in contiguous memory. 

```
dataType arrayName[size];
```
In C, the name of an array is also a constant pointer to the first element in the array. When passed to a function, it decays to this pointer. Because of this, passing an array to a function also requires passing its size. However, it is possible to create a pointer that points to an entire array with the following syntax:
```
type(*ptr)[size];
```

Arrays can also be multidimensional with the following syntax:

```
type arrayName[sizeOne][sizeTwo] .. [sizeN];
```

### Strings
In C, there is no `string` data type. Rather, strings can be represented with either a character pointer or a character array.  

**Strings as character arrays**  
```
char str[3] = "AB"
```
These are stored like other arrays in C. Note the extra `char` for the terminating character `\0`.

**Strings as character pointers**  
If a string value is directly assigned to a `char*`, then it is stored in read-only memory. The pointer itself is writable, but the contents of the string cannot be changed.

```
char *str = "AB"
```
Strings can also be stored dynamically on the heap. This allows for the string to be writable.

```
char *str;
int size = 3;
str = (char*)malloc(sizeof(char) * size);
*(str) = 'A'; 
*(str + 1) = 'B';  
*(str + 2) = '\0';
*(str + 1) = 'R'; // valid
```

## Memory Alignment and Padding
Data alignment refers to organizing data in memory at an address that is some multiple of the word size, which increases performance and makes accessing data easier.

Data padding is the act of inserting extra bytes between data structures to maintain the word size alignment of the memory. Consider the following scenario:

![no-padding](https://media.geeksforgeeks.org/wp-content/uploads/DS_Allign.jpg)

The variable `c` here is an integer. However, its data is split between two reads of 4 bytes. Padding can resolve this issue:

![padding](https://media.geeksforgeeks.org/wp-content/uploads/20210902092659/Screenshot20210902092412-300x152.png)

Image credit: GeeksForGeeks

## Undefined Behavior and Dangling Pointers
In C, undefined behavior can occur through multiple means. This can be through division by zero, memory access outside of array bounds, dereferencing a null pointer, etc.  


A dangling pointer refers to a pointer pointing to a location in memory that has been deleted or freed. Dangling pointers can occur in three ways.

**Deallocation of memory**  
Using `free()` on a pointer causes the pointer to become dangling because what it was pointing to is now freed. To remove this, the pointer must be set to `NULL`.

**Functions with local variables**  
If a function contains a local variable and returns a pointer or address to it and is stored outside the function, this will cause a dangling pointer because of the behavior of the stack. 

**Out of scope**  
If a variable changes scope, the pointer pointing to that variable becomes a dangling pointer.

---

See `exercises\` for application of information.

