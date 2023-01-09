#ifndef	FT_ITERATOR_TRAITS_HPP
# define FT_ITERATOR_TRAITS_HPP

# include <cstddef>
# include <iterator>

/*=============================================================================================================*/
namespace ft {
	
	template< typename T >
	struct iterator_traits {
		typedef					T												value_type;
		typedef					T*												pointer;
		typedef					T&												reference;
		typedef					ptrdiff_t										difference_type;
		typedef typename	 	std::iterator_traits<T>::iterator_category		iterator_category;
	};

	template< typename T >
	struct iterator_traits<T*> {
		typedef					T												value_type;
		typedef					T*												pointer;
		typedef					T&												reference;
		typedef					ptrdiff_t										difference_type;
	};
	
	template< typename T >
	struct iterator_traits<const T*> {
		typedef					T												value_type;
		typedef					const T*										pointer;
		typedef					const T&										reference;
		typedef					ptrdiff_t										difference_type;
	};
	
} // namespace ft


/*=============================================================================================================*/
#endif // !FT_ITERATOR_TRAITS_HPP