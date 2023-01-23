# ft_containers

#### The designer of STL chose a wonderful yet simple common approach - "The separation of data and operation".
- The data is held and managed by the Container classes.
- The operations over the containers are defined and managed by the configurable algorithms.



In this project I'm re-implementation some of the standard C++ containers with the specific usage.

### re-implementation of:

  **std::vector** -> [ft::vector](./vector/vector.hpp)

  **std::map** -> [ft::map](./map/map.hpp)

  **std::stack** -> [ft::stack](./stack/stack.hpp)

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
-----------------------------------------
Useful Notes: **[Notes](./resources/Notes.txt)**

-----------------------------------------