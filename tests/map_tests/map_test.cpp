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
	my_map.insert(std::make_pair(11, "K"));
	my_map.insert(std::make_pair(12, "L"));
	my_map.insert(std::make_pair(13, "M"));
	my_map.insert(std::make_pair(14, "N"));
	my_map.insert(std::make_pair(15, "O"));
	my_map.insert(std::make_pair(16, "P"));
	my_map.insert(std::make_pair(17, "Q"));
	my_map.insert(std::make_pair(18, "R"));
	my_map.insert(std::make_pair(19, "S"));
	my_map.insert(std::make_pair(20, "T"));
	
	my_map[1] = "AA";
	my_map[21] = "asd";
	my_map[22] = "asdasd";
	
	std::map<int, std::string>::iterator it = my_map.begin();
	std::map<int, std::string>::iterator ite = my_map.end();
	
	ite = my_map.find(23);
	while (it != ite) {
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
	return 0;
}