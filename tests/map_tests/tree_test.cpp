# include <iostream>
# include "../../utils/tree/AVL.hpp"
/*===============================================================================*/

# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */
# define RESET			"\033[0m"				/* Reset the color */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
/*===============================================================================*/
int main()
{
	
	// allocator for string values
	std::allocator<std::string> myAllocator;
	
	// allocate space for three strings
	std::string* str = myAllocator.allocate(3);
	
	// construct these 3 strings
	myAllocator.construct(str, "Geeks");
	myAllocator.construct(str + 1, "for");
	myAllocator.construct(str + 2, "Geeks");
	
	std::cout << str[0] << str[1] << str[2];
	
	// destroy these 3 strings
	myAllocator.destroy(str);
	myAllocator.destroy(str + 1);
	myAllocator.destroy(str + 2);
	
	// deallocate space for 3 strings
	myAllocator.deallocate(str, 3);
}