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

	
	my_map.insert(std::make_pair(16, "P"));
	my_map.insert(std::make_pair(17, "Q"));
	my_map.insert(std::make_pair(18, "R"));
	my_map.insert(std::make_pair(19, "S"));
	my_map.insert(std::make_pair(20, "T"));
	
	my_map.equal_range(4);
	
//	std::cout << ite->first << " " << ite->second << std::endl;
	
	return 0;
}