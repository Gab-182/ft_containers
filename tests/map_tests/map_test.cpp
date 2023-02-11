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
	auto pair1 = my_map.insert(std::make_pair(1, "A"));
	auto pair2 = my_map.insert(std::make_pair(2, "B"));
	auto pair3 = my_map.insert(std::make_pair(3, "C"));
	auto pair4 = my_map.insert(std::make_pair(4, "D"));
	auto pair5 = my_map.insert(std::make_pair(5, "E"));
	auto pair6 = my_map.insert(std::make_pair(6, "F"));
	auto pair7 = my_map.insert(std::make_pair(7, "G"));
	auto pair8 = my_map.insert(std::make_pair(8, "H"));
	auto pair9 = my_map.insert(std::make_pair(9, "T"));
	auto pair10 = my_map.insert(std::make_pair(10, "T"));
	auto pair11 = my_map.insert(std::make_pair(11, "T"));
	auto pair12 = my_map.insert(std::make_pair(12, "T"));
	auto pair13 = my_map.insert(std::make_pair(13, "T"));
	auto pair14 = my_map.insert(std::make_pair(14, "T"));
	auto pair15 = my_map.insert(std::make_pair(15, "T"));
	auto pair16 = my_map.insert(std::make_pair(16, "P"));
	auto pair17 = my_map.insert(std::make_pair(17, "Q"));
	auto pair18 = my_map.insert(std::make_pair(18, "R"));
	auto pair19 = my_map.insert(std::make_pair(19, "S"));
	auto pair20 = my_map.insert(std::make_pair(20, "T"));
	
	auto pair21 = my_map.insert(std::make_pair(20, "T"));
	auto pair22 = my_map.insert(std::make_pair(20, "T"));
	auto pair23 = my_map.insert(std::make_pair(20, "T"));
	
	
	
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair1.first->first  << BOLDYELLOW << ",  Val= " << BOLDWHITE << pair1.first->second  << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair2.first->first  << BOLDYELLOW << ",  Val= " << BOLDWHITE << pair2.first->second  << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair3.first->first  << BOLDYELLOW << ",  Val= " << BOLDWHITE << pair3.first->second  << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair4.first->first  << BOLDYELLOW << ",  Val= " << BOLDWHITE << pair4.first->second  << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair5.first->first  << BOLDYELLOW << ",  Val= " << BOLDWHITE << pair5.first->second  << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair6.first->first  << BOLDYELLOW << ",  Val= " << BOLDWHITE << pair6.first->second  << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair7.first->first  << BOLDYELLOW << ",  Val= " << BOLDWHITE << pair7.first->second  << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair8.first->first  << BOLDYELLOW << ",  Val= " << BOLDWHITE << pair8.first->second  << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair9.first->first  << BOLDYELLOW << ",  Val= " << BOLDWHITE << pair9.first->second  << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair10.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair10.first->second << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair11.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair11.first->second << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair12.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair12.first->second << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair13.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair13.first->second << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair14.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair14.first->second << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair15.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair15.first->second << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair16.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair16.first->second << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair17.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair17.first->second << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair18.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair18.first->second << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair19.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair19.first->second << ", " << pair1.second << RESET << std::endl;
	std:: cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair20.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair20.first->second << ", " << pair1.second << RESET << std::endl;
	
	std::cout << std::endl;
	std:: cout << BOLDRED << "Key= " << pair21.first->first << ", Val= " << pair21.first->second << ", " << pair21.second << RESET << std::endl;
	std:: cout << BOLDRED << "Key= " << pair22.first->first << ", Val= " << pair22.first->second << ", " << pair22.second << RESET << std::endl;
	std:: cout << BOLDRED << "Key= " << pair23.first->first << ", Val= " << pair23.first->second << ", " << pair23.second << RESET << std::endl;
	std::cout << std::endl;
	
	std::map<int, std::string>::iterator it = my_map.begin();
	std::map<int, std::string>::iterator ite = my_map.end();
	
	try {
		my_map.at(1) = "AA";
		my_map.at(2) = "AA";
		my_map.at(19) = "AA";
		my_map.at(20) = "AA";
		my_map.at(21) = "AA";
	} catch (std::exception(&e)) {
		std::cout << BOLDRED << e.what() << std::endl;
	}
	
	return 0;
}