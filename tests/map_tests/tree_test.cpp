# include <iostream>
# include <string>
# include "../../utils/RedBlack/RedBlack.hpp"
/*===============================================================================*/

# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */
# define RESET			"\033[0m"				/* Reset the color */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
/*===============================================================================*/

int main()
{
	// Create a tree with a custom compare function and a custom allocator
	ft::RedBlack<int, std::string> my_tree;
	
	/**———————————————————————————————————[Test]—————————————————————————————————————*/
	std::cout << BOLDGREEN << "Before insert" << RESET << std::endl;
	std::cout << BOLDYELLOW << "----------------------------------------" << RESET << std::endl;
	
	std::cout << BOLDWHITE << my_tree.size() << RESET << std::endl;
	std::cout << BOLDWHITE << "Is empty -> " << my_tree.empty() << RESET << std::endl;
	
	my_tree.insert(ft::make_pair(1, "A"));
	my_tree.insert(ft::make_pair(2, "B"));
	my_tree.insert(ft::make_pair(3, "C"));
	my_tree.insert(ft::make_pair(4, "D"));
	my_tree.insert(ft::make_pair(5, "E"));
	my_tree.insert(ft::make_pair(6, "F"));
	my_tree.insert(ft::make_pair(7, "G"));
	my_tree.insert(ft::make_pair(8, "H"));
	my_tree.insert(ft::make_pair(9, "I"));
	my_tree.insert(ft::make_pair(10, "G"));
	my_tree.insert(ft::make_pair(11, "K"));
	my_tree.insert(ft::make_pair(12, "L"));
	my_tree.insert(ft::make_pair(13, "M"));
	my_tree.insert(ft::make_pair(14, "N"));
	my_tree.insert(ft::make_pair(15, "O"));
	my_tree.insert(ft::make_pair(16, "P"));
	my_tree.insert(ft::make_pair(17, "Q"));
	my_tree.insert(ft::make_pair(18, "R"));
	my_tree.insert(ft::make_pair(19, "S"));
	my_tree.insert(ft::make_pair(20, "T"));
	
	ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
	ft::RedBlack<int, std::string>::iterator ite = my_tree.end();
	
	// Printing all the tree from the smallest key to the largest key
	while (it != ite) {
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
	
	std::cout << BOLDGREEN << "After insert" << RESET << std::endl;
	std::cout << BOLDYELLOW << "----------------------------------------" << RESET << std::endl;
	
	std::cout << BOLDWHITE << my_tree.size() << RESET << std::endl;
	std::cout << BOLDWHITE << "Is empty -> " << my_tree.empty() << RESET << std::endl;
	
	return 0;
}