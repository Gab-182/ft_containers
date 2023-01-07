#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <cstddef>
# include <cstring>

/*=============================================================================================================*/
namespace ft {

	template< class T >
	class iterator {
		public:
		/**
		 ** Member Types: */
			typedef		T						value_type;
			typedef		T*						pointer;
			typedef		const T*				const_pointer;
			typedef		T&						reference;
			typedef		const T&				const_reference;
			typedef		ptrdiff_t				difference_type;
			
		public:
		/**
		 ** Member Functions: */
		
		
		};
}


/*=============================================================================================================*/
#endif // !ITERATOR_HPP