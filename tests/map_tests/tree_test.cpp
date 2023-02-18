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
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair1  = my_tree.insert(ft::make_pair(1, "A"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair2  = my_tree.insert(ft::make_pair(2, "B"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair3  = my_tree.insert(ft::make_pair(3, "C"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair4  = my_tree.insert(ft::make_pair(4, "D"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair5  = my_tree.insert(ft::make_pair(5, "E"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair6  = my_tree.insert(ft::make_pair(6, "F"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair7  = my_tree.insert(ft::make_pair(7, "G"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair8  = my_tree.insert(ft::make_pair(8, "H"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair9  = my_tree.insert(ft::make_pair(9, "I"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair10 = my_tree.insert(ft::make_pair(10, "J"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair11 = my_tree.insert(ft::make_pair(11, "K"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair12 = my_tree.insert(ft::make_pair(12, "L"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair13 = my_tree.insert(ft::make_pair(13, "M"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair14 = my_tree.insert(ft::make_pair(14, "N"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair15 = my_tree.insert(ft::make_pair(15, "O"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair16 = my_tree.insert(ft::make_pair(16, "P"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair17 = my_tree.insert(ft::make_pair(17, "Q"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair18 = my_tree.insert(ft::make_pair(18, "R"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair19 = my_tree.insert(ft::make_pair(19, "S"));
	ft::pair<ft::RedBlack<int, std::string>::iterator, bool> pair20 = my_tree.insert(ft::make_pair(20, "T"));
	
	
	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
	std::cout << BOLDGREEN << "Testing Insert(): 🧮📐📏" << RESET << std::endl;
	{
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair1.first->first  << BOLDYELLOW << ", Val= " << BOLDWHITE << pair1.first->second << ",  Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair2.first->first  << BOLDYELLOW << ", Val= " << BOLDWHITE << pair2.first->second << ",  Inserted? " << pair2.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair3.first->first  << BOLDYELLOW << ", Val= " << BOLDWHITE << pair3.first->second << ",  Inserted? " << pair3.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair4.first->first  << BOLDYELLOW << ", Val= " << BOLDWHITE << pair4.first->second << ",  Inserted? " << pair4.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair5.first->first  << BOLDYELLOW << ", Val= " << BOLDWHITE << pair5.first->second << ",  Inserted? " << pair5.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair6.first->first  << BOLDYELLOW << ", Val= " << BOLDWHITE << pair6.first->second << ",  Inserted? " << pair6.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair7.first->first  << BOLDYELLOW << ", Val= " << BOLDWHITE << pair7.first->second << ",  Inserted? " << pair7.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair8.first->first  << BOLDYELLOW << ", Val= " << BOLDWHITE << pair8.first->second << ",  Inserted? " << pair8.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair9.first->first  << BOLDYELLOW << ", Val= " << BOLDWHITE << pair9.first->second << ",  Inserted? " << pair9.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair10.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair10.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair11.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair11.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair12.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair12.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair13.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair13.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair14.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair14.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair15.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair15.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair16.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair16.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair17.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair17.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair18.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair18.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair19.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair19.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		std::cout << BOLDYELLOW << "Key= " << BOLDWHITE << pair20.first->first << BOLDYELLOW << ", Val= " << BOLDWHITE << pair20.first->second << ", Inserted? " << pair1.second << RESET << std::endl;
		
		std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
		my_tree.erase(10);
		my_tree.erase(10);
		my_tree.erase(1);
		my_tree.erase(9);
		my_tree.erase(20);
		my_tree.erase(11);
		my_tree.erase(12);
		my_tree.erase(13);
		my_tree.erase(14);
		my_tree.erase(15);
		my_tree.erase(16);
		my_tree.erase(17);
		my_tree.erase(18);
		my_tree.erase(19);
		my_tree.erase(2);
		my_tree.erase(3);
		
		
		

		
		
		
		
		
		std::cout << BOLDYELLOW << "The tree size = " << BOLDRED << my_tree.size() << RESET << std::endl;
		my_tree.Inorder(my_tree.get_root());
	}
//	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing Operators: 🧮" << RESET << std::endl;
//	{
//		ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
//		ft::RedBlack<int, std::string>::iterator ite = my_tree.end();
//
//		// Testing (operator++)
//		std::cout << BOLDWHITE << "Testing Operator++" << RESET << std::endl;
//		std::cout << it->first << " " << it->second << std::endl;
//		it++;
//		std::cout << it->first << " " << it->second << std::endl;
//		it++;
//		std::cout << it->first << " " << it->second << std::endl;
//		it++;
//		std::cout << it->first << " " << it->second << std::endl;
//		it++;
//		std::cout << it->first << " " << it->second << std::endl;
//
//		std::cout << BOLDYELLOW << "------------------------------" << RESET << std::endl;
//		// Testing (operator--)
//		std::cout << BOLDWHITE << "Testing Operator--" << RESET << std::endl;
//		it--;
//		std::cout << it->first << " " << it->second << std::endl;
//		it += 5;
//		std::cout << it->first << " " << it->second << std::endl;
//		it -= 5;
//		std::cout << it->first << " " << it->second << std::endl;
//
//		std::cout << BOLDYELLOW << "------------------------------" << RESET << std::endl;
//		std::cout << BOLDWHITE << "Testing Operator+" << RESET << std::endl;
//		// Testing (operator+)
//		it = it + 5;
//		std::cout << it->first << " " << it->second << std::endl;
//
//		std::cout << BOLDYELLOW << "------------------------------" << RESET << std::endl;
//		// Testing (operator-)
//		std::cout << BOLDWHITE << "Testing Operator-" << RESET << std::endl;
//		it = it - 2;
//		std::cout << it->first << " " << it->second << std::endl;
//
//		std::cout << BOLDYELLOW << "------------------------------" << RESET << std::endl;
//		it = my_tree.begin();
//		ite = my_tree.end();
//		while (it != ite) {
//			std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
//					  << BOLDYELLOW << "Value = " << BOLDWHITE << it->second
//					  << RESET << std::endl;
//			it++;
//		}
//	}
//	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing access operator[]: " << RESET << std::endl;
//	{
//		ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
//		ft::RedBlack<int, std::string>::iterator ite = my_tree.end();
//		my_tree[1]= "AA";
//		my_tree[20] = "TT";
//		my_tree[21] = "OUT";
//		my_tree[22] = "REALLY OUT";
//
//		while (it != ite) {
//			std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
//					  << BOLDYELLOW << "Value = " << BOLDWHITE << it->second
//					  << RESET << std::endl;
//			it++;
//		}
//	}
//	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing find(): " << RESET << std::endl;
//	{
//		ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
//		ft::RedBlack<int, std::string>::iterator ite = my_tree.end();
//		my_tree[1]= "AA";
//		my_tree[20] = "TT";
//		my_tree[21] = "OUT";
//		my_tree[22] = "REALLY OUT";
//
//		it = my_tree.find(20);
//
//// Here it should return end() iterator.
////		it = my_tree.find(23);
//
//		while (it != ite) {
//			std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
//					  << BOLDYELLOW << "Value = " << BOLDWHITE << it->second
//					  << RESET << std::endl;
//			it++;
//		}
//	}
//	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing count(): " << RESET << std::endl;
//	{
//		std::cout << BOLDYELLOW << "The tree size = " << BOLDRED << my_tree.size() << RESET << std::endl;
//		std::cout << BOLDWHITE << "count(1) = " << BOLDRED << my_tree.count(1) << RESET<< std::endl;
//		std::cout << BOLDWHITE << "count(22) = " << BOLDRED << my_tree.count(22) << RESET<< std::endl;
//		std::cout << BOLDWHITE << "count(23) = " << BOLDRED << my_tree.count(23) << RESET<< std::endl;
//	}
//	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing lower_bound(): " << RESET << std::endl;
//	{
//		ft::RedBlack<int, std::string>::iterator it_lower1 = my_tree.lower_bound(3);
//		ft::RedBlack<int, std::string>::iterator it_lower2 = my_tree.lower_bound(20);
//		ft::RedBlack<int, std::string>::iterator it_lower3 = my_tree.lower_bound(23); // Not in tree, Going to return end().
//
//		std::cout << BOLDGREEN << "it_lower1 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_lower1->first << ", "
//				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_lower1->second
//				  << RESET << std::endl;
//		std::cout << BOLDGREEN << "it_lower2 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_lower2->first << ", "
//				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_lower2->second
//				  << RESET << std::endl;
//
//		///NOTE:
//		///=====
//		/// If you try to Dereference these iterators, SigFault gonna occur,
//		/// cause you are trying to dereference an end() iterator
//
////		std::cout << BOLDGREEN << "it_lower3 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_lower3->first << ", "
////				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_lower3->second
////				  << RESET << std::endl;
//	}
//	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing upper_bound(): " << RESET << std::endl;
//	{
//		ft::RedBlack<int, std::string>::iterator it_upper1 = my_tree.upper_bound(15);
//		ft::RedBlack<int, std::string>::iterator it_upper2 = my_tree.upper_bound(18);
//		ft::RedBlack<int, std::string>::iterator it_upper3 = my_tree.upper_bound(20);
//		ft::RedBlack<int, std::string>::iterator it_upper4 = my_tree.upper_bound(23); // Not in tree, Going to return end().
//		ft::RedBlack<int, std::string>::iterator it_upper5 = my_tree.upper_bound(34); // Not in tree, Going to return end().
//
//		std::cout << BOLDGREEN << "it_upper1 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_upper1->first << ", "
//				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_upper1->second
//				  << RESET << std::endl;
//		std::cout << BOLDGREEN << "it_upper2 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_upper2->first << ", "
//				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_upper2->second
//				  << RESET << std::endl;
//		std::cout << BOLDGREEN << "it_upper3 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_upper3->first << ", "
//				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_upper3->second
//				  << RESET << std::endl;
//		///NOTE:
//		///=====
//		/// If you try to Dereference these iterators, SigFault gonna occur,
//		/// cause you are trying to dereference an end() iterator
//
////		std::cout << BOLDGREEN << "it_upper4 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_upper4->first << ", "
////				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_upper4->second
////				  << RESET << std::endl;
////		std::cout << BOLDGREEN << "it_upper5 ->" << BOLDYELLOW << "Key = " << BOLDWHITE << it_upper5->first << ", "
////				  << BOLDYELLOW << "Value = " << BOLDWHITE << it_upper5->second
////				  << RESET << std::endl;
//	}
//	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing equal_range(): " << RESET << std::endl;
//	{
//		ft::pair<ft::RedBlack<int, std::string>::iterator, ft::RedBlack<int, std::string>::iterator>
//				equal_range1 = my_tree.equal_range(21);
//
//		std::cout << BOLDYELLOW << "First iterator in the range" << std::endl;
//		std::cout << BOLDYELLOW << "The key= "
//			<< BOLDWHITE << equal_range1.first->first
//			<< ",The value= " << equal_range1.first->second
//			<< std::endl;
//
//		std::cout << BOLDYELLOW << "Second iterator in the range" << std::endl;
//		std::cout << BOLDYELLOW << "The key= "
//				  << BOLDWHITE << equal_range1.first->first
//				  << BOLDYELLOW<< ",The value= "
//				  << BOLDWHITE << equal_range1.first->second
//				  << std::endl;
//	}
//	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing access at(): " << RESET << std::endl;
//	{
//		try {
//			ft::RedBlack<int, std::string>::iterator it = my_tree.begin();
//			ft::RedBlack<int, std::string>::iterator ite = my_tree.end();
//			my_tree.at(1) = "AAA";
//			my_tree.at(20) = "TTT";
//			my_tree.at(21) = "OUT.OUT";
//			my_tree.at(22) = "REALLY OUT > Really";
//			my_tree.at(43) = "OUT."; // This will cause an exception, key not found.
//
//			while (it != ite) {
//				std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
//						  << BOLDYELLOW << "Value = " << BOLDWHITE << it->second
//						  << RESET << std::endl;
//				it++;
//			}
//		} catch (std::exception &e) {
//			std::cout << BOLDRED << e.what() << RESET << std::endl;
//		}
//	}
//	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
//	std::cout << BOLDGREEN << "Testing access clear(): " << RESET << std::endl;
//	{
////		my_tree.clear();
//	}
//	std::cout << BOLDYELLOW << "=============================================" << RESET << std::endl;
//
	return 0;
}