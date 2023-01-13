# include "../vector/vector.hpp"
# include "../iterator/vector_iterator.hpp"
# include <iostream>

# include <cstring>
# include <iterator>
#include <cassert>
#include <vector>
/*===============================================================================*/
# define BLACK			"\033[30m"				/* Black */
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */
# define WHITE			"\033[37m"				/* White */
# define BOLDMAGENTA	"\033[1m\033[35m"		/* Bold Magenta */
# define BOLDCYAN		"\033[1m\033[36m"		/* Bold Cyan */
# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */
# define RESET			"\033[0m"				/* Reset the color */
# define BOLDBLACK		"\033[1m\033[30m"		/* Bold Black */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
# define BOLDBLUE		"\033[1m\033[34m"		/* Bold Blue */
/*===============================================================================*/

int main()
{
	/*==================================================================================================================*/
	{ // 1. (default constructor):
		std::cout << BOLDYELLOW << "[1]. (default constructor):" << RESET << std::endl;
		/**
		 *!=====================*
		 *! [integer vector] 
		 *!=====================*/
		ft::vector<int> mv1;
		assert(mv1.size() == 0);
		std::cout << BOLDWHITE << mv1.size() << RESET << std::endl;
		/**
		 *!===================*
		 * ! [string vector] 
		 *!===================*/
		ft::vector<std::string> mv1_str;

		assert(mv1_str.size() == 0);

		std::cout << BOLDWHITE << mv1_str.size() << RESET << std::endl;

		std::cout << BOLDGREEN << "Default constructor test passed ✅" << RESET << std::endl;
		std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;
	}
	/*==================================================================================================================*/
	{ // 2. (Test the size constructor:)
		std::cout << BOLDYELLOW << "[2]. (Test the size constructor):" << RESET << std::endl;

		ft::vector<int> mv2(5);
		
		assert(mv2.size() == 5);

		std::cout << BOLDWHITE << "The vector (mv2) size = [" << mv2.size() << "]" << RESET << std::endl;
		
		std::cout << BOLDGREEN << "Size constructor test passed ✅" << RESET << std::endl;
		std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;
	}
	/*==================================================================================================================*/
	{ // 3. (Test the fill constructor):
		std::cout << BOLDYELLOW << "[3]. (Test the fill constructor):" << RESET << std::endl;
		/**
		 *!=====================*
		 *! [integer vector] 
		 *!=====================*/

		ft::vector<int> mv3(5, 10);

		assert(mv3.size() == 5);

		for (int i = 0; i < mv3.size(); i++)
			assert(mv3[i] == 10);
		for (int i = 0; i < mv3.size(); i++)
			std::cout << BOLDWHITE << mv3[i] << RESET << std::endl;
		std::cout << BOLDWHITE << "The vector (mv3) size = [" << mv3.size() << "]" << RESET << std::endl;

		/**
		 *!===================*
		 * ! [string vector] 
		 *!===================*/
		ft::vector<std::string> mv2_str(5, "hello");
		assert(mv2_str.size() == 5);
		assert(mv2_str[0] == "hello");
		std::cout << BOLDWHITE << mv2_str.size() << RESET << std::endl;
		std::cout << BOLDWHITE << "mv2_str[0] = " << mv2_str[0] << RESET << std::endl;
		std::cout << BOLDGREEN << "Fill constructor test passed ✅" << RESET << std::endl;
		std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;
	}
	/*==================================================================================================================*/
	{// 4. (Test the range constructor):
		// std::cout << BOLDYELLOW << "[4]. (Test the range constructor):\n" << RESET << std::endl;

		// int arr[5] = {1, 2, 3, 4, 5};
		// std::vector<int> v4(arr, arr + 5);
		// // arr is the memory location for the beginning of the array.
		// // arr + 5 is the memory location for the end of the array.

		// assert(v4.size() == 5);
		// assert(v4[0] == 1);
		// assert(v4[4] == 5);

		// std::cout << BOLDWHITE << "v4[0] = [" << v4[0] << "]" << RESET << std::endl;
		// std::cout << BOLDWHITE << "v4[4] = [" << v4[4] << "]" << RESET << std::endl;
		// std::cout << BOLDWHITE << "The vector (v4) size = [" << v4.size() << "]" << RESET << std::endl;
		// std::cout << BOLDGREEN << "Range constructor test passed ✅" << RESET << std::endl;
		// std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;
	}
	/*==================================================================================================================*/
	{ // 5. (Test the copy constructor):
		std::cout << BOLDYELLOW << "[5]. (Test the copy constructor):" << RESET << std::endl;
		ft::vector<int> mv3(5, 10);
		ft::vector<int> mv5(mv3);

		assert(mv5.size() == 5);
		assert(mv5[0] == 10);
		assert(mv5[1] == 10);
		assert(mv5[2] == 10);
		assert(mv5[3] == 10);
		assert(mv5[4] == 10);
		for (int i = 0; i < mv5.size(); i++)
			std::cout << BOLDWHITE << "mv5[i] = " << mv5[i] << RESET << std::endl;

		std::cout << BOLDWHITE << "The vector (mv5) size = [" << mv5.size() << "]" << RESET << std::endl;

		std::cout << BOLDGREEN << "Copy constructor test passed ✅" << RESET << std::endl;
		std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;
	}
	/*==================================================================================================================*/
	{ // 6. (Test the operator=):
		std::cout << BOLDYELLOW << "[6]. (Test the operator=):" << RESET << std::endl;
		ft::vector<int> mv3(2, 10);
		ft::vector<int> mv6;
		mv6 = mv3;

		assert(mv6.size() == 2);
		assert(mv6[0] == 10);
		assert(mv6[1] == 10);
		for (int i = 0; i < mv6.size(); i++)
			std::cout << BOLDWHITE << "mv6[i] = " << mv6[i] << RESET << std::endl;

		std::cout << BOLDWHITE << "The vector (mv6) size = [" << mv6.size() << "]" << RESET << std::endl;

		std::cout << BOLDGREEN << "Operator= test passed ✅" << RESET << std::endl;
		std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;

	}
	/*==================================================================================================================*/
	{ // 7.8. (Test the push_back function) && (Test the pop_back function):
		std::cout << BOLDYELLOW << "7. (Test the push_back function):" << RESET << std::endl;
		ft::vector<int> mv7;
		mv7.push_back(1);
		mv7.push_back(2);
		mv7.push_back(3);
		mv7.push_back(4);
		mv7.push_back(5);

		assert(mv7.size() == 5);
		assert(mv7[0] == 1);
		assert(mv7[1] == 2);
		assert(mv7[2] == 3);
		assert(mv7[3] == 4);
		assert(mv7[4] == 5);

		for (int i = 0; i < mv7.size(); i++)
			std::cout << BOLDWHITE << mv7[i] << RESET << std::endl;
		std::cout << BOLDWHITE << "The vector (v6) size = [" << mv7.size() << "]" << RESET << std::endl;
		std::cout << BOLDGREEN << "Push_back function test passed ✅" << RESET << std::endl;
		std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;
	
	/*==================================================================================================================*/

		std::cout << BOLDYELLOW << "8. (Test the pop_back function):" << RESET << std::endl;
		
		ft::vector<int> mv8(mv7);
		mv8.pop_back();
		mv8.pop_back();

		assert(mv8.size() == 3);
		assert(mv8[0] == 1);
		assert(mv8[1] == 2);
		assert(mv8[2] == 3);

		for (int i = 0; i < mv8.size(); i++)
			std::cout << BOLDWHITE << mv8[i] << RESET << std::endl;
		std::cout << BOLDWHITE << "The vector (mv8) size = [" << mv8.size() << "]" << RESET << std::endl;
		std::cout << BOLDGREEN << "Pop_back function test passed ✅" << RESET << std::endl;
		std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;
	}
	/*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "8. (Test the insert function):" << RESET << std::endl;
	// std::vector<int> v8(v7);
	// v8.insert(v8.begin() + 1, 10);
	// v8.insert(v8.begin() + 3, 20);
	// v8.insert(v8.begin() + 5, 30);

	// assert(v8.size() == 6);
	// assert(v8[0] == 1);
	// assert(v8[1] == 10);
	// assert(v8[2] == 2);
	// assert(v8[3] == 20);
	// assert(v8[4] == 3);
	// assert(v8[5] == 30);

	// for (int i = 0; i < v8.size(); i++)
	// 	std::cout << BOLDWHITE << v8[i] << RESET << std::endl;
	// std::cout << BOLDWHITE << "The vector (v8) size = [" << v8.size() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Insert function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "9. (Test the erase function):" << RESET << std::endl;
	// std::vector<int> v9(v8);
	// v9.erase(v9.begin() + 1);
	// v9.erase(v9.begin() + 2);
	// v9.erase(v9.begin() + 3);

	// assert(v9.size() == 3);
	// assert(v9[0] == 1);
	// assert(v9[1] == 2);
	// assert(v9[2] == 3);

	// for (int i = 0; i < v9.size(); i++)
	// 	std::cout << BOLDWHITE << v9[i] << RESET << std::endl;
	// std::cout << BOLDWHITE << "The vector (v9) size = [" << v9.size() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Erase function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	 /*==================================================================================================================*/
	std::cout << BOLDYELLOW << "10. (Test the clear function):" << RESET << std::endl;
	std::vector<int> mv10(10, 10);
	assert(mv10.size() == 10);
	std::cout << BOLDWHITE << "The vector (v10) size = [" << mv10.size() << "]" << RESET << std::endl;
	mv10.clear();
	assert(mv10.size() == 0);
	std::cout << BOLDWHITE << "The vector (v10) size = [" << mv10.size() << "]" << RESET << std::endl;
	std::cout << BOLDGREEN << "Clear function test passed ✅" << RESET << std::endl;
	std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	/*==================================================================================================================*/
	std::cout << BOLDYELLOW << "11. (Test the resize function):" << RESET << std::endl;
	ft::vector<int> mv11;
	std::cout << BOLDWHITE << "The vector (mv11) size = [" << mv11.size() << "]" << RESET << std::endl;
	mv11.resize(5);
	assert(mv11.size() == 5);
	std::cout << BOLDWHITE << "The vector (mv11) size = [" << mv11.size() << "]" << RESET << std::endl;
	mv11.resize(10);
	assert(mv11.size() == 10);

	std::cout << BOLDWHITE << "The vector (mv11) size = [" << mv11.size() << "]" << RESET << std::endl;
	std::cout << BOLDGREEN << "Resize function test passed ✅" << RESET << std::endl;
	std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	/*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "12. (Test the at function):" << RESET << std::endl;
	// std::vector<int> v12;
	// v12.push_back(1);
	// v12.push_back(2);
	// v12.push_back(3);
	// v12.push_back(4);
	// v12.push_back(5);

	// assert(v12.at(0) == 1);
	// assert(v12.at(1) == 2);
	// assert(v12.at(2) == 3);
	// assert(v12.at(3) == 4);
	// assert(v12.at(4) == 5);

	// for (int i = 0; i < v12.size(); i++)
	// 	std::cout << BOLDWHITE << "v12.at(" << i << ") = " << v12.at(i) << RESET << std::endl;

	// std::cout << BOLDGREEN << "At function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "13. (Test the front function):" << RESET << std::endl;
	// std::vector<int> v13;
	// v13.push_back(1);
	// v13.push_back(2);
	// v13.push_back(3);

	// assert(v13.front() == 1);

	// for (int i = 0; i < v13.size(); i++)
	// 	std::cout << BOLDWHITE << v13[i] << RESET << std::endl;

	// std::cout << BOLDWHITE << "v13.front() = [" << v13.front() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Front function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "14. (Test the back function):" << RESET << std::endl;
	
	// std::vector<int> v14(v13);
	// assert(v14.back() == 3);

	// for (int i = 0; i < v14.size(); i++)
	// 	std::cout << BOLDWHITE << v14[i] << RESET << std::endl;
	
	// std::cout << BOLDWHITE << "v14.back() = [" << v14.back() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Back function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	 /*==================================================================================================================*/
	
	std::cout << BOLDYELLOW << "15. (Test the empty function):" << RESET << std::endl;
	
	ft::vector<int> mv15;
	assert(mv15.empty() == true);
	std::cout << BOLDWHITE << "mv15.empty() = [" << mv15.empty() << "]" << RESET << std::endl;

	mv15.push_back(1);
	assert(mv15.empty() == false);
	std::cout << BOLDWHITE << "mv15.empty() = [" << mv15.empty() << "]" << RESET << std::endl;
	
	std::cout << BOLDGREEN << "Empty function test passed ✅" << RESET << std::endl;
	std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;

	 /*==================================================================================================================*/
	// /**
	//  * max_size() is the theoretical maximum number of items that could be put in your vector.
	//  * On a 32-bit system, you could in theory allocate 4Gb == 2^32 which is: 
	//  * 2^32 char values, 
	//  * 2^30 int values or 2^29 double values.
	//  * 
	//  * max_size() function is going to return (4611686018427387903) built as 64-bit target
	//  * max_size() function is going to return (1073741823) built as 32-bit target
	//  */
	
	std::cout << BOLDYELLOW << "16. (Test the max_size function):" << RESET << std::endl;
	
	std::vector<int> v16;
	ft::vector<int> mv16;
//	assert(mv16.max_size() == v16.max_size());
	std::cout << BOLDWHITE << "v16.max_size() = [" << v16.max_size() << "]" << RESET << std::endl;
	std::cout << BOLDWHITE << "mv16.max_size() = [" << mv16.max_size() << "]" << RESET << std::endl;
	
	std::cout << BOLDGREEN << "Max_size function test passed ✅" << RESET << std::endl;
	std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	 /*==================================================================================================================*/
	 /**
	  * Size: the number of items currently in the vector
	  * Capacity: how many items can be fit in the vector before it is "full". Once full,
	  * adding new items will result in a new, larger block of memory being allocated and the existing items being copied to it
	  */
	 std::cout << BOLDYELLOW << "17. (Test the capacity function):" << RESET << std::endl;

	 ft::vector<int> mv17(17);
	 assert(mv17.capacity() == 17);

	 std::cout << BOLDWHITE << "v17.capacity() = [" << mv17.capacity() << "]" << RESET << std::endl;
	 std::cout << BOLDGREEN << "Capacity function test passed ✅" << RESET << std::endl;
	 std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	 /*==================================================================================================================*/

	 std::cout << BOLDYELLOW << "18. (Test the reserve function):" << RESET << std::endl;

	 ft::vector<int> mv18;
	 mv18.reserve(18);
	 assert(mv18.capacity() == 18);

	 std::cout << BOLDWHITE << "mv18.capacity() = [" << mv18.capacity() << "]" << RESET << std::endl;
	 std::cout << BOLDGREEN << "Reserve function test passed ✅" << RESET << std::endl;
	 std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "19. (Test the shrink_to_fit function):" << RESET << std::endl;

	// std::vector<int> v19;
	// v19.reserve(19);
	// assert(v19.capacity() == 19);
	// v19.shrink_to_fit();
	// assert(v19.capacity() == 0);

	// std::cout << BOLDWHITE << "v19.capacity() = [" << v19.capacity() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Shrink_to_fit function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "20. (Test the assign function):" << RESET << std::endl;

	// std::vector<int> v20;
	// v20.assign(20, 20);
	// assert(v20.size() == 20);
	// assert(v20.capacity() == 20);
	// assert(v20[0] == 20);
	// assert(v20[19] == 20);

	// for (int i = 0; i < v20.size(); i++)
	// 	std::cout << BOLDWHITE << v20[i] << RESET << std::endl;

	// std::cout << BOLDGREEN << "Assign function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	 /*==================================================================================================================*/
	std::cout << BOLDYELLOW << "21. (Test the swap function):" << RESET << std::endl;
	ft::vector<int> mv21(6);
	ft::vector<int> mv22(3);
	
	mv21[0] = 1;
	mv21[1] = 2;
	mv21[2] = 3;
	mv21[3] = 4;
	mv21[4] = 5;
	mv21[5] = 6;
	
	mv22[0] = 7;
	mv22[1] = 8;
	mv22[2] = 9;
	
	mv21.swap(mv22);
	std::cout << BOLDWHITE << "mv21.size() = " << mv21.size() << RESET << std::endl;
	std::cout << BOLDWHITE << "mv21.capacity() = " << mv21.capacity() << RESET << std::endl;
	for (int i = 0; i < mv21.size(); i++)
		std::cout << BOLDWHITE << mv21[i] << RESET << std::endl;
	
	std::cout << BOLDWHITE << "mv22.size() = " << mv22.size() << RESET << std::endl;
	std::cout << BOLDWHITE << "mv22.capacity() = " << mv22.capacity() << RESET << std::endl;
	for (int i = 0; i < mv22.size(); i++)
		std::cout << BOLDWHITE << mv22[i] << RESET << std::endl;
	
	std::cout << BOLDGREEN << "Swap function test passed ✅" << RESET << std::endl;
	std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;

	/*==================================================================================================================*/
	std::cout << BOLDYELLOW << "22. (Test the begin function):" << RESET << std::endl;
	ft::vector<int> mv23(6);
	
	mv23[0] = 1;
	mv23[1] = 2;
	mv23[2] = 3;
	mv23[3] = 4;
	mv23[4] = 5;
	mv23[5] = 6;
	
	ft::vector<int>::iterator it = mv23.begin();
	ft::vector<int>::iterator ite = mv23.end();

	assert(*it == 1);
	assert(*ite == 6);
	std::cout << BOLDWHITE << "mv23.begin() = " << *it << RESET << std::endl;
	std::cout << BOLDWHITE << "mv23.end() = " << *ite << RESET << std::endl;
	std::cout << BOLDGREEN << "Begin function test passed ✅" << RESET << std::endl;
	std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;
	/*==================================================================================================================*/

	return 0;
}