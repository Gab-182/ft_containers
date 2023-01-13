#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {
	template <class T >
	struct iterator {
		typedef T         							value_type;
		typedef std::ptrdiff_t  					difference_type;
		typedef T*   								pointer;
		typedef T& 									reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};
}

#endif //! FT_ITERATOR_HPP