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
	std::cout << BOLDGREEN << "Testing lower_bound(): " << RESET << std::endl;
	{
		ft::RedBlack<int, std::string>::iterator it_lower1 = my_tree.lower_bound(3);
		ft::RedBlack<int, std::string>::iterator it_lower2 = my_tree.lower_bound(20);
		ft::RedBlack<int, std::string>::iterator it_lower3 = my_tree.lower_bound(23); // Not in tree, Going to return end().

		std::cout << BOLDGREEN << "it_lower1 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_lower1->first << ", "
				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_lower1->second
				  << RESET << std::endl;
		std::cout << BOLDGREEN << "it_lower2 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_lower2->first << ", "
				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_lower2->second
				  << RESET << std::endl;
		
		///NOTE:
		///=====
		/// If you try to Dereference these iterators, SigFault gonna occur,
		/// cause you are trying to dereference an end() iterator

//		std::cout << BOLDGREEN << "it_lower3 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_lower3->first << ", "
//				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_lower3->second
//				  << RESET << std::endl;
	}
	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing upper_bound(): " << RESET << std::endl;
	{
		ft::RedBlack<int, std::string>::iterator it_upper1 = my_tree.upper_bound(15);
		ft::RedBlack<int, std::string>::iterator it_upper2 = my_tree.upper_bound(18);
		ft::RedBlack<int, std::string>::iterator it_upper3 = my_tree.upper_bound(20);
		ft::RedBlack<int, std::string>::iterator it_upper4 = my_tree.upper_bound(23); // Not in tree, Going to return end().
		ft::RedBlack<int, std::string>::iterator it_upper5 = my_tree.upper_bound(34); // Not in tree, Going to return end().
		
		std::cout << BOLDGREEN << "it_upper1 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_upper1->first << ", "
				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_upper1->second
				  << RESET << std::endl;
		std::cout << BOLDGREEN << "it_upper2 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_upper2->first << ", "
				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_upper2->second
				  << RESET << std::endl;
		std::cout << BOLDGREEN << "it_upper3 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_upper3->first << ", "
				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_upper3->second
				  << RESET << std::endl;
		///NOTE:
		///=====
		/// If you try to Dereference these iterators, SigFault gonna occur,
		/// cause you are trying to dereference an end() iterator
		
//		std::cout << BOLDGREEN << "it_upper4 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_upper4->first << ", "
//				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_upper4->second
//				  << RESET << std::endl;
//		std::cout << BOLDGREEN << "it_upper5 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_upper5->first << ", "
//				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_upper5->second
//				  << RESET << std::endl;
	}
	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing equal_range(): " << RESET << std::endl;
	{
		ft::pair<ft::RedBlack<int, std::string>::iterator, ft::RedBlack<int, std::string>::iterator>
				equal_range1 = my_tree.equal_range(21);

		std::cout << BOLDYELLOW << "First iterator in the range" << std::endl;
		std::cout << BOLDYELLOW << "The key= "
			<< BOLDWHITE << equal_range1.first->first
			<< ",The value= " << equal_range1.first->second
			<< std::endl;
		
		std::cout << BOLDYELLOW << "Second iterator in the range" << std::endl;
		std::cout << BOLDYELLOW << "The key= "
				  << BOLDWHITE << equal_range1.first->first
				  << BOLDYELLOW<< ",The value= "
				  << BOLDWHITE << equal_range1.first->second
				  << std::endl;
	}
	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing access at(): " << RESET << std::endl;
	try {
		ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
		ft::RedBlack<int, std::string>::iterator ite = my_tree.end();
		my_tree.at(1)= "AAA";
		my_tree.at(20) = "TTT";
		my_tree.at(21) = "OUT.OUT";
		my_tree.at(22) = "REALLY OUT > Really";
		my_tree.at(43) = "OUT."; // This will cause an exception, key not found.
		
		while (it != ite) {
			std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
						<< BOLDYELLOW << "Value = " << BOLDWHITE << it->second
						<< RESET << std::endl;
			it++;
		}
	} catch (std::exception &e) {
		std::cout << BOLDRED << e.what() << RESET << std::endl;
	}
	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
	return 0;
}