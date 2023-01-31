#ifndef MAP_HPP
#define MAP_HPP

# include "../utils/pair.hpp"
# include <string>
# include <map>
/*=============================================================================================================*/
namespace ft {
	
	
	/**
	 **  @brief A standard container made up of (key,value) pairs.
	 **
	 **  @tparam Key  Type of key objects.
	 **  @tparam  T  Type of mapped objects.
	 **  @tparam Compare  Comparison function object type, defaults to less<_Key>.
	 **  @tparam Allocator  Allocator type, defaults to
	 **                  allocator<pair<const _Key, T>.
	 **
	 **  Maps support bidirectional iterators.
	*/
	template<
			class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> >
		class map {
		
	};
}

/*=============================================================================================================*/
#endif //MAP_HPP
