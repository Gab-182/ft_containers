# include <iostream>
# include <string>
# include <map>
# include <utility>
# include <iterator>
# include <algorithm>
# include <functional>
# include <vector>
/*===============================================================================*/

# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */
# define RESET			"\033[0m"				/* Reset the color */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
/*===============================================================================*/

int main()
{
	std::map<int, std::string> my_map;
	my_map.insert(std::make_pair(1, "A"));
	my_map.insert(std::make_pair(2, "B"));
	my_map.insert(std::make_pair(3, "C"));
	my_map.insert(std::make_pair(4, "D"));
	my_map.insert(std::make_pair(5, "E"));
	my_map.insert(std::make_pair(6, "F"));
	my_map.insert(std::make_pair(7, "G"));
	my_map.insert(std::make_pair(8, "H"));
	my_map.insert(std::make_pair(9, "I"));
	my_map.insert(std::make_pair(10, "J"));
	my_map.insert(std::make_pair(11, "K"));
	my_map.insert(std::make_pair(12, "L"));
	my_map.insert(std::make_pair(13, "M"));
	my_map.insert(std::make_pair(14, "N"));
	my_map.insert(std::make_pair(15, "O"));
	my_map.insert(std::make_pair(16, "P"));
	my_map.insert(std::make_pair(17, "Q"));
	my_map.insert(std::make_pair(18, "R"));
	my_map.insert(std::make_pair(19, "S"));
	my_map.insert(std::make_pair(20, "T"));
	
	std::cout << BOLDGREEN << "\nTesting map range constructor: " << RESET << std::endl;
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
		std::map<int, std::string> my_map4(my_vec.begin(), my_vec.end());
		std::map<int, std::string>::iterator it = my_map4.begin();
		std::map<int, std::string>::iterator ite = my_map4.end();
		while (it != ite) {
			std::cout
					<< BOLDYELLOW << "map Key= " << BOLDWHITE << it->first
					<< BOLDYELLOW << ", map Val= " << BOLDWHITE << it->second
					<< RESET << std::endl;
			++it;
		}
	}
	
	std::cout << BOLDGREEN << "\nTesting map copy constructor: 🧮📐📏" << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string> my_map3(my_map);
		std::map<int, std::string>::iterator it = my_map3.begin();
		std::map<int, std::string>::iterator ite = my_map3.end();
		while (it != ite) {
			std::cout << BOLDYELLOW << "Copied map key   -> [" << BOLDWHITE << it->first << BOLDYELLOW << "]  "
					  << BOLDYELLOW << "Copied map value -> [" << BOLDWHITE << it->second << BOLDYELLOW << "]"
					  << std::endl;
			++it;
		}
	}
	
	std::cout << BOLDGREEN << "\nTesting non const begin() && end(): 🧮📐📏" << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string>::iterator it = my_map.begin();
		std::map<int, std::string>::iterator ite = my_map.end();
		while (it != ite) {
			std::cout << BOLDYELLOW << "map old key   -> [" << BOLDWHITE << it->first << BOLDYELLOW << "] _ ";
			it->first = it->first + 1;
			std::cout << BOLDRED << "map new key   -> [" << BOLDWHITE << it->first << BOLDYELLOW << "]  "
					  << RESET << std::endl;
			it->first = it->first - 1;
			
			++it;
		}
		std::cout << std::endl;
	}
	
	std::cout << BOLDGREEN << "\nTesting const begin() && const end(): " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string>::const_iterator it = my_map.begin();
		std::map<int, std::string>::const_iterator ite = my_map.end();
		std::cout << BOLDRED << "Can't change the key, because the iterator is const" << RESET << std::endl;
//		it->first = it->first + 100;
	}
	
	std::cout << BOLDGREEN << "\nTesting non const rbegin() && rend(): " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string>::reverse_iterator it = my_map.rbegin();
		std::map<int, std::string>::reverse_iterator ite = my_map.rend();
		while (it != ite) {
			std::cout << it->first << " ";
			++it;
		}
		std::cout << std::endl;
	}
	
	std::cout << BOLDGREEN << "\nTesting const rbegin() && const rend(): 🧮📐📏" << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string>::const_reverse_iterator it = my_map.rbegin();
		std::map<int, std::string>::const_reverse_iterator ite = my_map.rend();
		while (it != ite) {
			std::cout << it->first << " ";
			++it;
		}
		std::cout << std::endl;
	}
	
	
	std::cout << BOLDGREEN << "\nTesting range Insert(): " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
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
		
		std::map<int, std::string> my_map4;
		my_map4.insert(vec.begin(), vec.begin() + 5);
		
		std::map<int, std::string>::iterator it = my_map4.begin();
		std::map<int, std::string>::iterator ite = my_map4.end();
		while (it != ite) {
			std::cout
					<< BOLDYELLOW << "Key= " << BOLDWHITE << it->first
					<< BOLDYELLOW << ", Val= " << BOLDWHITE << it->second
					<< RESET << std::endl;
			++it;
		}
	}
	
	std::cout << BOLDGREEN << "\nTesting the erase()" << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::cout << BOLDYELLOW << "Erasing [1]  -> " << BOLDRED << my_map.erase(1)  << RESET << std::endl;
		std::cout << BOLDYELLOW << "Erasing [2]  -> " << BOLDRED << my_map.erase(2)  << RESET << std::endl;
		std::cout << BOLDYELLOW << "Erasing [3]  -> " << BOLDRED << my_map.erase(3)  << RESET << std::endl;
		std::cout << BOLDYELLOW << "Erasing [4]  -> " << BOLDRED << my_map.erase(4)  << RESET << std::endl;
		std::cout << BOLDYELLOW << "Erasing [5]  -> " << BOLDRED << my_map.erase(5)  << RESET << std::endl;
		std::cout << BOLDYELLOW << "Erasing [6]  -> " << BOLDRED << my_map.erase(6)  << RESET << std::endl;
		std::cout << BOLDYELLOW << "Erasing [7]  -> " << BOLDRED << my_map.erase(7)  << RESET << std::endl;
		std::cout << BOLDYELLOW << "Erasing [8]  -> " << BOLDRED << my_map.erase(8)  << RESET << std::endl;
		std::cout << BOLDYELLOW << "Erasing [9]  -> " << BOLDRED << my_map.erase(9)  << RESET << std::endl;
		std::cout << BOLDYELLOW << "Erasing [10] -> " << BOLDRED << my_map.erase(10) << RESET << std::endl;
		std::cout << BOLDYELLOW << "Erasing [55] -> " << BOLDRED << my_map.erase(55) << RESET << std::endl;
	}
	
	std::cout << BOLDGREEN << "\nTesting the swap()" << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string> map1;
		map1.insert(std::make_pair(1, "< A >"));
		map1.insert(std::make_pair(2, "< B >"));
		map1.insert(std::make_pair(3, "< C >"));
		map1.insert(std::make_pair(4, "< D >"));
		
		std::map<int, std::string> map2;
		map2.insert(std::make_pair(10, "[ A ]"));
		map2.insert(std::make_pair(11, "[ B ]"));
		map2.insert(std::make_pair(12, "[ C ]"));
		map2.insert(std::make_pair(13, "[ D ]"));
		map2.insert(std::make_pair(14, "[ E ]"));
		map2.insert(std::make_pair(15, "[ F ]"));
		map2.insert(std::make_pair(16, "[ G ]"));
		map2.insert(std::make_pair(17, "[ H ]"));
		map2.insert(std::make_pair(18, "[ I ]"));
		
		std::cout << BOLDRED << "\n================== [Before swap()] ==================" << RESET << std::endl;
		{
			std::cout << BOLDYELLOW << "------- [Map1] --------" << RESET << std::endl;
			std::map<int, std::string>::iterator it = map1.begin();
			std::map<int, std::string>::iterator ite = map1.end();
			std::cout << "Map1 Size: " << map1.size() << std::endl;
			while (it != ite) {
				std::cout
						<< BOLDYELLOW << "Key= " << BOLDWHITE << it->first
						<< BOLDYELLOW << ", Val= " << BOLDWHITE << it->second
						<< RESET << std::endl;
				++it;
			}
			
			std::cout << BOLDYELLOW << "------- [Map2] --------" << RESET << std::endl;
			std::map<int, std::string>::iterator it2 = map2.begin();
			std::map<int, std::string>::iterator ite2 = map2.end();
			std::cout << "Map2 Size: " << map2.size() << std::endl;
			while (it2 != ite2) {
				std::cout
						<< BOLDYELLOW << "Key= " << BOLDWHITE << it2->first
						<< BOLDYELLOW << ", Val= " << BOLDWHITE << it2->second
						<< RESET << std::endl;
				++it2;
			}
		}
		map1.swap(map2);
		std::cout << BOLDRED << "\n================== [After swap()] ==================" << RESET << std::endl;
		{
			std::cout << BOLDYELLOW << "------- [Map1] --------" << RESET << std::endl;
			std::map<int, std::string>::iterator it = map1.begin();
			std::map<int, std::string>::iterator ite = map1.end();
			std::cout << "Map1 Size: " << map1.size() << std::endl;
			while (it != ite) {
				std::cout
						<< BOLDYELLOW << "Key= " << BOLDWHITE << it->first
						<< BOLDYELLOW << ", Val= " << BOLDWHITE << it->second
						<< RESET << std::endl;
				++it;
			}
			
			std::cout << BOLDYELLOW << "------- [Map2] --------" << RESET << std::endl;
			std::map<int, std::string>::iterator it2 = map2.begin();
			std::map<int, std::string>::iterator ite2 = map2.end();
			std::cout << "Map2 Size: " << map2.size() << std::endl;
			while (it2 != ite2) {
				std::cout
						<< BOLDYELLOW << "Key= " << BOLDWHITE << it2->first
						<< BOLDYELLOW << ", Val= " << BOLDWHITE << it2->second
						<< RESET << std::endl;
				++it2;
			}
		}
	}
	
	std::cout << BOLDGREEN << "\nTesting Operators: 🧮" << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string>::iterator it = my_map.begin();
		std::map<int, std::string>::iterator ite = my_map.end();
		
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
		it = my_map.begin();
		ite = my_map.end();
		while (it != ite) {
			std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
					  << BOLDYELLOW << "Value = " << BOLDWHITE << it->second
					  << RESET << std::endl;
			it++;
		}
	}
	
	std::cout << BOLDGREEN << "\nTesting access operator[]: " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string>::iterator it = my_map.begin();
		std::map<int, std::string>::iterator ite = my_map.end();
		my_map[1]= "AA";
		my_map[20] = "TT";
		my_map[21] = "OUT";
		my_map[22] = "REALLY OUT";
		
		while (it != ite) {
			std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
					  << BOLDYELLOW << "Value = " << BOLDWHITE << it->second
					  << RESET << std::endl;
			it++;
		}
	}
	
	std::cout << BOLDGREEN << "\nTesting access at(): " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		try {
			std::map<int, std::string>::iterator it = my_map.begin();
			std::map<int, std::string>::iterator ite = my_map.end();
			my_map.at(1) = "AAA";
			my_map.at(20) = "TTT";
			my_map.at(21) = "OUT.OUT";
			my_map.at(22) = "REALLY OUT > Really";
			my_map.at(43) = "OUT."; // This will cause an exception, key not found.
			
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
	
	std::cout << BOLDGREEN << "\nTesting find(): " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string>::iterator it = my_map.begin();
		std::map<int, std::string>::iterator ite = my_map.end();
		my_map[1]= "AA";
		my_map[20] = "TT";
		my_map[21] = "OUT";
		my_map[22] = "REALLY OUT";
		
		it = my_map.find(20);

// Here it should return end() iterator.
//		it = my_tree.find(23);
		
		while (it != ite) {
			std::cout << BOLDYELLOW << "Key = " << BOLDWHITE << it->first << ", "
					  << BOLDYELLOW << "Value = " << BOLDWHITE << it->second
					  << RESET << std::endl;
			it++;
		}
	}
	
	std::cout << BOLDGREEN << "\nTesting count(): " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::cout << BOLDYELLOW << "The tree size = " << BOLDRED << my_map.size() << RESET << std::endl;
		std::cout << BOLDWHITE << "count(1) = " << BOLDRED << my_map.count(1) << RESET<< std::endl;
		std::cout << BOLDWHITE << "count(22) = " << BOLDRED << my_map.count(22) << RESET<< std::endl;
		std::cout << BOLDWHITE << "count(23) = " << BOLDRED << my_map.count(23) << RESET<< std::endl;
	}
	
	std::cout << BOLDGREEN << "\nTesting lower_bound(): " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string>::iterator it_lower1 = my_map.lower_bound(3);
		std::map<int, std::string>::iterator it_lower2 = my_map.lower_bound(20);
		std::map<int, std::string>::iterator it_lower3 = my_map.lower_bound(23); // Not in tree, Going to return end().
		
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
	
	std::cout << BOLDGREEN << "\nTesting upper_bound(): " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::map<int, std::string>::iterator it_upper1 = my_map.upper_bound(15);
		std::map<int, std::string>::iterator it_upper2 = my_map.upper_bound(18);
		std::map<int, std::string>::iterator it_upper3 = my_map.upper_bound(20);
		std::map<int, std::string>::iterator it_upper4 = my_map.upper_bound(23); // Not in tree, Going to return end().
		std::map<int, std::string>::iterator it_upper5 = my_map.upper_bound(34); // Not in tree, Going to return end().
		
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
	std::cout << BOLDGREEN << "\nTesting equal_range(): " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator>
				equal_range1 = my_map.equal_range(21);
		
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
	
	std::cout << BOLDGREEN << "\nTesting access clear(): " << RESET << std::endl;
	std::cout << BOLDYELLOW << "=====================================================================" << RESET << std::endl;
	{
		my_map.clear();
		std::cout << BOLDRED << "my_map.size() = " << BOLDWHITE << my_map.size() << RESET << std::endl;
		std::cout << BOLDRED << "my_map.empty() = " << BOLDWHITE << my_map.empty() << RESET << std::endl;
		std::cout << BOLDRED << "map has been cleared\n" << RESET << std::endl;
	}
	
	return 0;
}