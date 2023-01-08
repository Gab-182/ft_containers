#ifndef	FT_ITERATOR_TRAITS_HPP
# define FT_ITERATOR_TRAITS_HPP

# include <cstddef>

/*=============================================================================================================*/
namespace ft {

	template< typename T >
	struct iterator_traits {
		typedef	typename	T				value_type;
		typedef		T*						pointer;
		typedef		T&						reference;
		typedef		ptrdiff_t				difference_type;
	};

	template< typename T >
	struct iterator_traits<T*> {
		typedef		T						value_type;
		typedef		T*						pointer;
		typedef		T&						reference;
		typedef		ptrdiff_t				difference_type;
	};
	
	template< typename T >
	struct iterator_traits<const T*> {
		typedef		T						value_type;
		typedef		const T*				pointer;
		typedef		T&						reference;
		typedef		ptrdiff_t				difference_type;
	};
}


/*=============================================================================================================*/
#endif // !FT_ITERATOR_TRAITS_HPP