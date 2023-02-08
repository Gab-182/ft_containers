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
	
	/**—————————————————————————[Test Red Black tree]————————————————————————————*/
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
	std::cout << BOLDYELLOW << "The tree size = " << BOLDRED << my_tree.size() << RESET << std::endl;
	
	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing Operators: 🧮📐📏" << RESET << std::endl;
	{
		ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
		ft::RedBlack<int, std::string>::iterator ite = my_tree.end();

		// Testing (operator++)
		std::cout << BOLDWHITE << "Testing Operator++" << RESET << std::endl;
		std::cout << it->first << " " << it->second << std::endl;
		it++;
		std::cout << it->first << " " << it->second << std::endl;
		it++;
		std::cout << it->first << " " << it->second << std::endl;
		it++;
		std::cout << it->first << " " << it->second << std::endl;
		it++;
		std::cout << it->first << " " << it->second << std::endl;

		std::cout << BOLDYELLOW << "------------------------------" << RESET << std::endl;
		// Testing (operator--)
		std::cout << BOLDWHITE << "Testing Operator--" << RESET << std::endl;
		it--;
		std::cout << it->first << " " << it->second << std::endl;
		it += 5;
		std::cout << it->first << " " << it->second << std::endl;
		it -= 5;
		std::cout << it->first << " " << it->second << std::endl;

		std::cout << BOLDYELLOW << "------------------------------" << RESET << std::endl;
		std::cout << BOLDWHITE << "Testing Operator+" << RESET << std::endl;
		// Testing (operator+)
		it = it + 5;
		std::cout << it->first << " " << it->second << std::endl;

		std::cout << BOLDYELLOW << "------------------------------" << RESET << std::endl;
		// Testing (operator-)
		std::cout << BOLDWHITE << "Testing Operator-" << RESET << std::endl;
		it = it - 2;
		std::cout << it->first << " " << it->second << std::endl;

		std::cout << BOLDYELLOW << "------------------------------" << RESET << std::endl;
		it = my_tree.begin();
		ite = my_tree.end();
		while (it != ite) {
			std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
					  << BOLDYELLOW << "Value = " << BOLDWHITE << it->second
					  << RESET << std::endl;
			it++;
		}
	}
	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing access operator[]: " << RESET << std::endl;
	{
		ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
		ft::RedBlack<int, std::string>::iterator ite = my_tree.end();
		my_tree[1]= "AA";
		my_tree[20] = "TT";
		my_tree[21] = "OUT";
		my_tree[22] = "REALLY OUT";
	
		while (it != ite) {
			std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
					  << BOLDYELLOW << "Value = " << BOLDWHITE << it->second
					  << RESET << std::endl;
			it++;
		}
	}
	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing find(): " << RESET << std::endl;
	{
		ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
		ft::RedBlack<int, std::string>::iterator ite = my_tree.end();
		my_tree[1]= "AA";
		my_tree[20] = "TT";
		my_tree[21] = "OUT";
		my_tree[22] = "REALLY OUT";
		
		it = my_tree.find(20);
		
// Here it should return end() iterator.
//		it = my_tree.find(23);
		
		while (it != ite) {
			std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
					  << BOLDYELLOW << "Value = " << BOLDWHITE << it->second
					  << RESET << std::endl;
			it++;
		}
	}
	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing count(): " << RESET << std::endl;
	{
		std::cout << BOLDYELLOW << "The tree size = " << BOLDRED << my_tree.size() << RESET << std::endl;
		std::cout << BOLDWHITE << "count(1) = " << BOLDRED << my_tree.count(1) << RESET<< std::endl;
		std::cout << BOLDWHITE << "count(22) = " << BOLDRED << my_tree.count(22) << RESET<< std::endl;
		std::cout << BOLDWHITE << "count(23) = " << BOLDRED << my_tree.count(23) << RESET<< std::endl;
	}
	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;

	
	return 0;
}