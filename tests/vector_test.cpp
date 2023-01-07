# include "../vector/vector.hpp"
# include <iostream>
# include <vector>
# include <cstring>
# include <iterator>
#include <cassert>

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
		std::cout << BOLDYELLOW << "[1]. (default constructor):\n" << RESET << std::endl;
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
		std::cout << BOLDYELLOW << "[2]. (Test the size constructor):\n" << RESET << std::endl;

		ft::vector<int> mv2(5);
		
		assert(mv2.size() == 5);

		std::cout << BOLDWHITE << "The vector (mv2) size = [" << mv2.size() << "]" << RESET << std::endl;
		
		std::cout << BOLDGREEN << "Size constructor test passed ✅" << RESET << std::endl;
		std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;
	}
	/*==================================================================================================================*/
	{ // 3. (Test the fill constructor):
		std::cout << BOLDYELLOW << "[3]. (Test the fill constructor):\n" << RESET << std::endl;
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
		std::cout << BOLDYELLOW << "[4]. (Test the range constructor):\n" << RESET << std::endl;

		int arr[5] = {1, 2, 3, 4, 5};
		std::vector<int> v4(arr, arr + 5);
		// arr is the memory location for the beginning of the array.
		// arr + 5 is the memory location for the end of the array.

		assert(v4.size() == 5);
		assert(v4[0] == 1);
		assert(v4[4] == 5);

		std::cout << BOLDWHITE << "v4[0] = [" << v4[0] << "]" << RESET << std::endl;
		std::cout << BOLDWHITE << "v4[4] = [" << v4[4] << "]" << RESET << std::endl;
		std::cout << BOLDWHITE << "The vector (v4) size = [" << v4.size() << "]" << RESET << std::endl;
		std::cout << BOLDGREEN << "Range constructor test passed ✅" << RESET << std::endl;
		std::cout << BOLDYELLOW << "--------------------------------------------------------------" << RESET << std::endl;
	}
	/*==================================================================================================================*/
	{ // 5. (Test the copy constructor):
		std::cout << BOLDYELLOW << "[5]. (Test the copy constructor):\n" << RESET << std::endl;
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
		std::cout << BOLDYELLOW << "[6]. (Test the operator=):\n" << RESET << std::endl;
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
	// std::cout << BOLDYELLOW << "6. (Test the push_back function):" << RESET << std::endl;
	// std::vector<int> v6;
	// v6.push_back(1);
	// v6.push_back(2);
	// v6.push_back(3);
	// v6.push_back(4);
	// v6.push_back(5);

	// assert(v6.size() == 5);
	// assert(v6[0] == 1);
	// assert(v6[1] == 2);
	// assert(v6[2] == 3);
	// assert(v6[3] == 4);
	// assert(v6[4] == 5);

	// for (int i = 0; i < v6.size(); i++)
	// 	std::cout << BOLDWHITE << v6[i] << RESET << std::endl;
	// std::cout << BOLDWHITE << "The vector (v6) size = [" << v6.size() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Push_back function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "7. (Test the pop_back function):" << RESET << std::endl;
	// std::vector<int> v7(v6);
	// v7.pop_back();
	// v7.pop_back();

	// assert(v7.size() == 3);
	// assert(v7[0] == 1);
	// assert(v7[1] == 2);
	// assert(v7[2] == 3);

	// for (int i = 0; i < v7.size(); i++)
	// 	std::cout << BOLDWHITE << v7[i] << RESET << std::endl;
	// std::cout << BOLDWHITE << "The vector (v7) size = [" << v7.size() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Pop_back function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/

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

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "10. (Test the clear function):" << RESET << std::endl;
	// std::vector<int> v10(v9);
	// v10.clear();

	// assert(v10.size() == 0);

	// for (int i = 0; i < v10.size(); i++)
	// 	std::cout << BOLDWHITE << v10[i] << RESET << std::endl;
	// std::cout << BOLDWHITE << "The vector (v10) size = [" << v10.size() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Clear function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/
	// std::cout << BOLDYELLOW << "11. (Test the resize function):" << RESET << std::endl;
	// std::vector<int> v11;
	// v11.resize(5);
	// assert(v11.size() == 5);
	// v11.resize(10);
	// assert(v11.size() == 10);

	// std::cout << BOLDWHITE << "The vector (v11) size = [" << v11.size() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Resize function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/

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

	// /*==================================================================================================================*/
	
	// std::cout << BOLDYELLOW << "15. (Test the empty function):" << RESET << std::endl;
	
	// std::vector<int> v15;
	// assert(v15.empty() == true);
	// v15.push_back(1);
	// assert(v15.empty() == false);

	// std::cout << BOLDWHITE << "v15.empty() = [" << v15.empty() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Empty function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/
	// /**
	//  * max_size() is the theoretical maximum number of items that could be put in your vector.
	//  * On a 32-bit system, you could in theory allocate 4Gb == 2^32 which is: 
	//  * 2^32 char values, 
	//  * 2^30 int values or 2^29 double values.
	//  * 
	//  * max_size() function is going to return (4611686018427387903) built as 64-bit target
	//  * max_size() function is going to return (1073741823) built as 32-bit target
	//  */
	
	// std::cout << BOLDYELLOW << "16. (Test the max_size function):" << RESET << std::endl;
	
	// std::vector<int> v16;
	// assert(v16.max_size() == 4611686018427387903);

	// std::cout << BOLDWHITE << "v16.max_size() = [" << v16.max_size() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Max_size function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/
	// /**
	//  * Size: the number of items currently in the vector
	//  * Capacity: how many items can be fit in the vector before it is "full". Once full,
	//  * adding new items will result in a new, larger block of memory being allocated and the existing items being copied to it
	//  */
	// std::cout << BOLDYELLOW << "17. (Test the capacity function):" << RESET << std::endl;

	// std::vector<int> v17(17);
	// assert(v17.capacity() == 17);

	// std::cout << BOLDWHITE << "v17.capacity() = [" << v17.capacity() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Capacity function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "18. (Test the reserve function):" << RESET << std::endl;

	// std::vector<int> v18;
	// v18.reserve(18);
	// assert(v18.capacity() == 18);

	// std::cout << BOLDWHITE << "v18.capacity() = [" << v18.capacity() << "]" << RESET << std::endl;
	// std::cout << BOLDGREEN << "Reserve function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

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

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "21. (Test the swap function):" << RESET << std::endl;

	// std::vector<int> v21(3);
	// std::vector<int> v22(3);

	// v21[0] = 1;
	// v21[1] = 2;
	// v21[2] = 3;

	// v22[0] = 4;
	// v22[1] = 5;
	// v22[2] = 6;

	// v21.swap(v22);

	// assert(v21[0] == 4);
	// assert(v21[1] == 5);
	// assert(v21[2] == 6);

	// assert(v22[0] == 1);
	// assert(v22[1] == 2);
	// assert(v22[2] == 3);

	// std::cout << BOLDWHITE << "v21 = [" << v21[0] << ", " << v21[1] << ", " << v21[2] << "]" << RESET << std::endl;
	// std::cout << BOLDWHITE << "v22 = [" << v22[0] << ", " << v22[1] << ", " << v22[2] << "]" << RESET << std::endl;

	// std::cout << BOLDGREEN << "Swap function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "22. (Test the data function):" << RESET << std::endl;

	// std::vector<int> v23(3);
	// v23[0] = 1;
	// v23[1] = 2;
	// v23[2] = 3;

	// int *p = v23.data();

	// assert(p[0] == 1);
	// assert(p[1] == 2);
	// assert(p[2] == 3);

	// std::cout << BOLDWHITE << "p = [" << p[0] << ", " << p[1] << ", " << p[2] << "]" << RESET << std::endl;

	// std::cout << BOLDGREEN << "Data function test passed ✅" << RESET << std::endl;
	// std::cout << BOLDYELLOW << "--------------------------------------------------------------\n" << RESET << std::endl;

	// /*==================================================================================================================*/

	// std::cout << BOLDYELLOW << "23. (Test the get_allocator function):" << RESET << std::endl;


	// /*==================================================================================================================*/

	return 0;
}