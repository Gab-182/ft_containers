# include <iostream>
# include "../../map/BST.hpp"
/*===============================================================================*/

# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */
# define RESET			"\033[0m"				/* Reset the color */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
/*===============================================================================*/
int main() {
	BST<int> tree;
	
	tree.InsertNode(new Node<int>(1));
	tree.InsertNode(new Node<int>(2));
	tree.InsertNode(new Node<int>(3));
	tree.InsertNode(new Node<int>(4));
	tree.InsertNode(new Node<int>(5));

	tree.PrintTree(tree.RootNode());
	return (0);
}