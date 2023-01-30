<h1> <p align="center"> FT_Containers </p> </h1>



<img src="UnderConstruction.jpg">

<p align="center">
  <img src="https://user-images.githubusercontent.com/83855149/214600672-3ff0531b-8237-419e-9dd2-b9ed87a3dffc.png" />
</p>

## ➤ Description

#### The designer of STL chose a wonderful yet simple common approach - "The separation of data and operation".
- The data is held and managed by the Container classes.
- The operations over the containers are defined and managed by the configurable algorithms.



In this project I'm re-implementation some of the standard C++ containers with the specific usage, such as vector, map, and stack, under the namespace "ft" instead of "std".

## ➤ Usage

To use these container classes in your project, simply include the appropriate header file and use the "ft" namespace. For example:

```c++
#include "vector.h"

int main() {
    ft::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i : v) {
        std::cout << i << std::endl;
    }
}
```

### re-implementation of:

  **➤ std::vector** -> [ft::vector](./vector/vector.hpp):

    ➤➤ It is implemented using a dynamic array, which is a contiguous block of memory that can be accessed using pointers.
    The vector class is a dynamic array that can grow and shrink in size.

  **➤ std::map** -> [ft::map](./map/map.hpp) : 

    ➤➤ The best type of tree data structure to implement a map container in C++ would be a self-balancing binary search tree (BST), such as a [Red-Black tree] or [AVL tree].
    These trees provide O(log n) time for search, insertion, and deletion operations, and have a well-balanced structure that ensures O(log n) time for most operations, even in the worst case scenario.

  **➤ std::stack** -> [ft::stack](./stack/stack.hpp) : 

    ➤➤ The stack is implemented by using a LIFO (last-in first-out) data structure. 
    Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.

Resources that helped me in this project:
-----------------------------------------

- [ft_container testers](https://morioh.com/p/06e8c5450e41).
- [allocator Class](https://learn.microsoft.com/en-us/cpp/standard-library/allocator-class?view=msvc-170).
- [vector](https://cplusplus.com/reference/vector/vector/).
- [ptrdiff_t](https://en.cppreference.com/w/cpp/types/ptrdiff_t).
- [allocator construct](https://cplusplus.com/reference/memory/allocator/construct/).
- [C++ vector max_size()](https://stackoverflow.com/questions/3813124/c-vector-max-size#:~:text=max_size()%20is%20the%20theoretical,or%202%5E29%20double%20values.).
- [size vs capacity of a vector](https://stackoverflow.com/questions/6296945/size-vs-capacity-of-a-vector).
- [Intro to Iterator traits](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits).
- [The difference between the (allocator.destruct) and (allocator.deallocate) in allocator class](https://stackoverflow.com/questions/26667026/difference-between-destroy-destructor-deallocate-in-stdallocator)
- [overloading with the usage of enable_if](https://akrzemi1.wordpress.com/examples/overloading-enable_if/)
- [how to use enable_if with overloads](https://stackoverflow.com/questions/38908260/how-to-use-enable-if-with-overloads)
-----------------------------------------
Useful Notes: **[Notes](./resources/Notes.txt)**

-----------------------------------------
