# include <iostream>
# include <string>
# include <vector>
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
	my_tree.insert(ft::make_pair(10, "J"));
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

	std::cout << BOLDGREEN << "Testing tree range constructor: 🧮📐📏" << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::vector<std::pair<int, std::string> > my_vec;
		my_vec.push_back(std::make_pair( 1, "Aa"));
		my_vec.push_back(std::make_pair( 2, "Bb"));
		my_vec.push_back(std::make_pair( 3, "Cc"));
		my_vec.push_back(std::make_pair( 4, "Dd"));
		my_vec.push_back(std::make_pair( 5, "Ee"));
		my_vec.push_back(std::make_pair( 6, "Ff"));
		my_vec.push_back(std::make_pair( 7, "Gg"));
		my_vec.push_back(std::make_pair( 8, "Hh"));
		my_vec.push_back(std::make_pair( 9, "Ii"));

		ft::RedBlack<int, std::string> my_tree4(my_vec.begin(), my_vec.end());

		ft::RedBlack<int, std::string>::iterator it = my_tree4.begin();
		ft::RedBlack<int, std::string>::iterator ite = my_tree4.end();
		while (it != ite) {
			std::cout
					<< BOLDYELLOW << "Key= " << BOLDWHITE << it->first
					<< BOLDYELLOW << ", Val= " << BOLDWHITE << it->second
					<< RESET << std::endl;
			++it;
		}
	}
	std::cout << BOLDRED << "Testing tree copy constructor: 🧮📐📏" << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		ft::RedBlack<int, std::string> my_tree3(my_tree);
		ft::RedBlack<int, std::string>::iterator it = my_tree3.begin();
		ft::RedBlack<int, std::string>::iterator ite = my_tree3.end();
		while (it != ite) {
			std::cout << "Copied tree key   -> [" << it->first << "]  "
			<< "Copied tree value -> [" << it->second << "]" << std::endl;
			++it;
		}
	}
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	std::cout << BOLDRED << "Testing RB_iterator: 🧮📐📏" << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing begin() && end(): 🧮📐📏" << RESET << std::endl;
	{
		ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
		ft::RedBlack<int, std::string>::iterator ite = my_tree.end();
		while (it != ite) {
			std::cout << it->first << " ";
			// Here if you tried to change the value of the key, you can.
//			it->first = it->first + 100;
			++it;
		}
		std::cout << std::endl;
	}
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing const begin() && const end(): 🧮📐📏" << RESET << std::endl;
	{
		ft::RedBlack<int, std::string>::const_iterator it = my_tree.begin();
		ft::RedBlack<int, std::string>::const_iterator ite = my_tree.end();

		std::cout << it->first << " ";
		// Here if we try to change the value of the key, we get an error,
		// because the iterator is const.
//		it->first = it->first + 100;
		std::cout << std::endl;
	}

/**
 * @TODO: test reverse rbegin() && rend() and operator++() && operator--().
 */
//	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing rbegin() && rend(): 🧮📐📏" << RESET << std::endl;
//	{
//		ft::RedBlack<int, std::string>::reverse_iterator it = my_tree.rbegin();
//		ft::RedBlack<int, std::string>::reverse_iterator ite = my_tree.rend();
//		while (it != ite) {
//			std::cout << it->first << " ";
//			++it;
//		}
//		std::cout << std::endl;
//	}

//	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing const rbegin() && const rend(): 🧮📐📏" << RESET << std::endl;
//	{
//		ft::RedBlack<int, std::string>::const_reverse_iterator it = my_tree.rbegin();
//		ft::RedBlack<int, std::string>::const_reverse_iterator ite = my_tree.rend();
//		while (it != ite) {
//			std::cout << it->first << " ";
//			++it;
//		}
//		std::cout << std::endl;
//	}

	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	std::cout << BOLDRED << "Testing RedBlack Methods: 🧮📐📏" << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing range Insert(): 🧮📐📏" << RESET << std::endl;
	{
		std::vector<std::pair<int, std::string> > vec;
		vec.push_back(std::make_pair( 1, "A"));
		vec.push_back(std::make_pair( 2, "B"));
		vec.push_back(std::make_pair( 3, "C"));
		vec.push_back(std::make_pair( 4, "D"));
		vec.push_back(std::make_pair( 5, "E"));
		vec.push_back(std::make_pair( 6, "F"));
		vec.push_back(std::make_pair( 7, "G"));
		vec.push_back(std::make_pair( 8, "H"));
		vec.push_back(std::make_pair( 9, "I"));

		ft::RedBlack<int, std::string> my_tree4;
		my_tree4.insert(vec.begin(), vec.begin() + 5);

		ft::RedBlack<int, std::string>::iterator it = my_tree4.begin();
		ft::RedBlack<int, std::string>::iterator ite = my_tree4.end();
		while (it != ite) {
			std::cout
			<< BOLDYELLOW << "Key= " << BOLDWHITE << it->first
			<< BOLDYELLOW << ", Val= " << BOLDWHITE << it->second
			<< RESET << std::endl;
			++it;
		}
	}
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing the erase()" << RESET << std::endl;
	{
		std::cout << "Erasing [1]" << BOLDRED << my_tree.erase(1)  << RESET << std::endl;
		std::cout << "Erasing [2]" << BOLDRED << my_tree.erase(2)  << RESET << std::endl;
		std::cout << "Erasing [3]" << BOLDRED << my_tree.erase(3)  << RESET << std::endl;
		std::cout << "Erasing [4]" << BOLDRED << my_tree.erase(4)  << RESET << std::endl;
		std::cout << "Erasing [5]" << BOLDRED << my_tree.erase(5)  << RESET << std::endl;
		std::cout << "Erasing [6]" << BOLDRED << my_tree.erase(6)  << RESET << std::endl;
		std::cout << "Erasing [7]" << BOLDRED << my_tree.erase(7)  << RESET << std::endl;
		std::cout << "Erasing [8]" << BOLDRED << my_tree.erase(8)  << RESET << std::endl;
		std::cout << "Erasing [9]" << BOLDRED << my_tree.erase(9)  << RESET << std::endl;
		std::cout << "Erasing [10]" << BOLDRED << my_tree.erase(10) << RESET << std::endl;
		std::cout << "Erasing [55]" << BOLDRED << my_tree.erase(55) << RESET << std::endl;
	}
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing the swap()" << RESET << std::endl;
	{
		ft::RedBlack<int, std::string> tree1;
		tree1.insert(ft::make_pair(1, "< A >"));
		tree1.insert(ft::make_pair(2, "< B >"));
		tree1.insert(ft::make_pair(3, "< C >"));
		tree1.insert(ft::make_pair(4, "< D >"));
		tree1.insert(ft::make_pair(5, "< E >"));
		tree1.insert(ft::make_pair(6, "< F >"));
		tree1.insert(ft::make_pair(7, "< G >"));
		tree1.insert(ft::make_pair(8, "< H >"));
		tree1.insert(ft::make_pair(9, "< I >"));
		
		ft::RedBlack<int, std::string> tree2;
		tree2.insert(ft::make_pair(10, "[ A ]"));
		tree2.insert(ft::make_pair(11, "[ B ]"));
		tree2.insert(ft::make_pair(12, "[ C ]"));
		tree2.insert(ft::make_pair(13, "[ D ]"));
		tree2.insert(ft::make_pair(14, "[ E ]"));
		tree2.insert(ft::make_pair(15, "[ F ]"));
		tree2.insert(ft::make_pair(16, "[ G ]"));
		tree2.insert(ft::make_pair(17, "[ H ]"));
		tree2.insert(ft::make_pair(18, "[ I ]"));
		
		std::cout << BOLDRED << "\n================== [Before swap()] ==================" << RESET << std::endl;
		{
			std::cout << BOLDYELLOW << "------- [Tree1] --------" << RESET << std::endl;
			ft::RedBlack<int, std::string>::iterator it = tree1.begin();
			ft::RedBlack<int, std::string>::iterator ite = tree1.end();
			while (it != ite) {
				std::cout
				<< BOLDYELLOW << "Key= " << BOLDWHITE << it->first
				<< BOLDYELLOW << ", Val= " << BOLDWHITE << it->second
				<< RESET << std::endl;
				++it;
			}
			
			std::cout << BOLDYELLOW << "------- [Tree2] --------" << RESET << std::endl;
			ft::RedBlack<int, std::string>::iterator it2 = tree2.begin();
			ft::RedBlack<int, std::string>::iterator ite2 = tree2.end();
			while (it2 != ite2) {
				std::cout
				<< BOLDYELLOW << "Key= " << BOLDWHITE << it2->first
				<< BOLDYELLOW << ", Val= " << BOLDWHITE << it2->second
				<< RESET << std::endl;
				++it2;
			}
		}
		tree1.swap(tree2);
		std::cout << BOLDRED << "\n================== [After swap()] ==================" << RESET << std::endl;
		{
			std::cout << BOLDYELLOW << "------- [Tree1] --------" << RESET << std::endl;
			ft::RedBlack<int, std::string>::iterator it = tree1.begin();
			ft::RedBlack<int, std::string>::iterator ite = tree1.end();
			while (it != ite) {
				std::cout
						<< BOLDYELLOW << "Key= " << BOLDWHITE << it->first
						<< BOLDYELLOW << ", Val= " << BOLDWHITE << it->second
						<< RESET << std::endl;
				++it;
			}
			
			std::cout << BOLDYELLOW << "------- [Tree2] --------" << RESET << std::endl;
			ft::RedBlack<int, std::string>::iterator it2 = tree2.begin();
			ft::RedBlack<int, std::string>::iterator ite2 = tree2.end();
			while (it2 != ite2) {
				std::cout
						<< BOLDYELLOW << "Key= " << BOLDWHITE << it2->first
						<< BOLDYELLOW << ", Val= " << BOLDWHITE << it2->second
						<< RESET << std::endl;
				++it2;
			}
		}
	}
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing Operators: 🧮" << RESET << std::endl;
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
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
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
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing access at(): " << RESET << std::endl;
	{
		try {
			ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
			ft::RedBlack<int, std::string>::iterator ite = my_tree.end();
			my_tree.at(1) = "AAA";
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
	}
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
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
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing count(): " << RESET << std::endl;
	{
		std::cout << BOLDYELLOW << "The tree size = " << BOLDRED << my_tree.size() << RESET << std::endl;
		std::cout << BOLDWHITE << "count(1) = " << BOLDRED << my_tree.count(1) << RESET<< std::endl;
		std::cout << BOLDWHITE << "count(22) = " << BOLDRED << my_tree.count(22) << RESET<< std::endl;
		std::cout << BOLDWHITE << "count(23) = " << BOLDRED << my_tree.count(23) << RESET<< std::endl;
	}
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
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
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
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
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
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
	std::cout << BOLDYELLOW << "—————————————————————————————————————————————" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing access clear(): " << RESET << std::endl;
	{
		my_tree.clear();
		std::cout << BOLDRED << "my_tree.size() = " << BOLDWHITE << my_tree.size() << RESET << std::endl;
		std::cout << BOLDRED << "my_tree.empty() = " << BOLDWHITE << my_tree.empty() << RESET << std::endl;
		std::cout << BOLDRED << "tree has been cleared" << RESET << std::endl;
	}
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;

	return 0;
}