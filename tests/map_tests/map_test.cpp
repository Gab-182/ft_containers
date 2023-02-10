# include <map>
# include <iostream>
# include <string>
# include <iterator>
/*===============================================================================*/

# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */
# define RESET			"\033[0m"				/* Reset the color */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
/*===============================================================================*/

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
	
	std::map<int, std::string>::iterator it = my_map.begin();
	std::map<int, std::string>::iterator ite = my_map.end();
	
	return 0;
}