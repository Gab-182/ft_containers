#ifndef FT_VECTOR_ITERATOR_HPP
#define FT_VECTOR_ITERATOR_HPP

# include<iterator>
# include "./iterator.hpp"
# include "./iterator_traits.hpp"
# include "./reverse_iterator.hpp"

namespace ft {
	template<
			class Category,
			class T,
			class Distance = std::ptrdiff_t,
			class Pointer = T*,
			class Reference = T& >
	class vector_iterator {
		/**---------------------------------------------------------------------------------------*/
		public:
			typedef				T										value_type;
			typedef				Distance								difference_type;
			typedef				Pointer									pointer;
			typedef				Reference								reference;
			typedef				std::random_access_iterator_tag			iterator_category;
		/**---------------------------------------------------------------------------------------*/
		public:
		
		/**---------------------------------------------------------------------------------------*/
		
	}; // class vector_iterator
} // namespace ft


#endif //FT_VECTOR_ITERATOR_HPP

ptr[i] = 5
		ptr.begin() + i = 5