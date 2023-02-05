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
	
//	my_tree.insert(ft::make_pair(1, "Hello"));
//	my_tree.insert(ft::make_pair(2, "World"));
//
	std::cout << BOLDGREEN << "After insert" << RESET << std::endl;
	std::cout << BOLDYELLOW << "----------------------------------------" << RESET << std::endl;
	
	std::cout << BOLDWHITE << "Is empty -> " << my_tree.empty() << RESET << std::endl;
	std::cout << BOLDWHITE << my_tree.size() << RESET << std::endl;
	
//	my_tree.clear();
	
	std::cout << BOLDGREEN << "After clear" << RESET << std::endl;
	std::cout << BOLDYELLOW << "----------------------------------------" << RESET << std::endl;
	
	std::cout << BOLDWHITE << "Is empty -> " << my_tree.empty() << RESET << std::endl;
	std::cout << BOLDWHITE << my_tree.size() << RESET << std::endl;
	return 0;
}