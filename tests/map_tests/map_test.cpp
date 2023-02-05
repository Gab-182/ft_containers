# include <map>
# include <iostream>
# include <string>
# include <iterator>

int main() {
	std::map<int, std::string> my_map;
	my_map.insert(std::make_pair(10, "A"));
	my_map.insert(std::make_pair(9, "B"));
	my_map.insert(std::make_pair(8, "C"));
	my_map.insert(std::make_pair(7, "D"));
	my_map.insert(std::make_pair(6, "E"));
	my_map.insert(std::make_pair(5, "F"));
	my_map.insert(std::make_pair(4, "G"));
	my_map.insert(std::make_pair(3, "H"));
	my_map.insert(std::make_pair(2, "I"));
	my_map.insert(std::make_pair(1, "G"));
	
	std::map<int, std::string>::iterator it = my_map.begin();
	std::map<int, std::string>::iterator ite = my_map.end();
	
	while (it != ite) {
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
	return 0;
}