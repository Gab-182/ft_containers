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
	ft::RedBlack<std::string, int> my_tree(std::less<std::string>, std::allocator<ft::pair<std::string, int> >);
	std::cout << BOLDGREEN << "Red Black has been created" << RESET << std::endl;
	std::cout << BOLDGREEN << "Root is: " << my_tree.root() << RESET << std::endl;
	return 0;
}