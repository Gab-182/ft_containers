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

//template<class Key,
//		class T,
//		class Compare = std::less<Key>,
//		class Allocator = std::allocator<ft::pair<const Key, T> > >
int main()
{
	// Create a tree with a custom compare function and a custom allocator
	ft::RedBlack<std::string, int> *my_tree = new ft::RedBlack<std::string, int>(std::less<std::string>(), std::allocator<ft::pair<const std::string, int> >());
	
	std::cout << BOLDGREEN << my_tree->size() << RESET << std::endl;
	std::cout << BOLDGREEN << "Red Black has been created" << RESET << std::endl;
	std::cout << BOLDGREEN << "Is empty -> " << my_tree->empty() << RESET << std::endl;
	
	my_tree->insert(ft::make_pair("Hello", 1));
	my_tree->insert(ft::make_pair("World", 2));
	my_tree->insert(ft::make_pair("!", 3));
	my_tree->insert(ft::make_pair("This", 4));
	my_tree->insert(ft::make_pair("is", 5));
	my_tree->insert(ft::make_pair("a", 6));
	my_tree->insert(ft::make_pair("Red", 7));
	my_tree->insert(ft::make_pair("Black", 8));
	my_tree->insert(ft::make_pair("Tree", 9));
	my_tree->insert(ft::make_pair("!", 10));
	my_tree->insert(ft::make_pair("!", 11));
	my_tree->insert(ft::make_pair("!", 12));
	
	std::cout << BOLDGREEN << "Is empty -> " << my_tree->empty() << RESET << std::endl;
	std::cout << BOLDGREEN << my_tree->size() << RESET << std::endl;
	
	my_tree->clear();
	
	std::cout << BOLDGREEN << "Is empty -> " << my_tree->empty() << RESET << std::endl;
	std::cout << BOLDGREEN << my_tree->size() << RESET << std::endl;
	return 0;
}