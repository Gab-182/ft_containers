# Map (RedBlack tree) iterator:

---------------------------------

#### The iterator is a simple class that allows to iterate over the tree in order of the keys.

#### Example:

```c++
# include <map>
# include <iostream>
# include <string>
# include <iterator>

int main() {
	std::map<int, std::string> my_map;
	my_map.insert(std::make_pair(1, "A"));
	my_map.insert(std::make_pair(2, "B"));
	my_map.insert(std::make_pair(3, "C"));
	my_map.insert(std::make_pair(4, "D"));
	my_map.insert(std::make_pair(5, "E"));
	my_map.insert(std::make_pair(6, "F"));
	my_map.insert(std::make_pair(7, "G"));
	my_map.insert(std::make_pair(8, "H"));
	my_map.insert(std::make_pair(9, "I"));
	my_map.insert(std::make_pair(10, "G"));
	
	std::map<int, std::string>::iterator it = my_map.begin();
	std::map<int, std::string>::iterator ite = my_map.end();
	
	while (it != ite) {
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
	return 0;
}
```

#### Output:

```bash 
1 A
2 B
3 C
4 D
5 E
6 F
7 G
8 H
9 I
10 G
```
#### The Red Black tree will take the following form:

![Red black tree](Desktop/Containers/ft_container_D/iterator/RedBlack_iterator/Red-Black-Tree-Visualization.png "Iterator")

---------------------------------
So from the output we can understand that:
- The iterator will point to the paired data (key, value) of the tree.
    - iterator -> first = key
    - iterator -> second = value
- **begin()** will point to the element that hold the smallest key.
- **end()** will point to the element that hold the largest key.
- The iterator will iterate over the tree in order of the keys, and sice we wrote the operator ++, it will iterate in ascending order, from the smallest key to the largest key.
- **operator++** will return the next element in the tree, that is the next element in order of the keys.

----------------------------------------