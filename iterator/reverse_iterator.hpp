#ifndef FT_REVERSE_ITERATOR_HPP
#define FT_REVERSE_ITERATOR_HPP


# include <iterator>		// For the iterator_category.
# include "iterator_traits.hpp"

namespace ft {
	
	template <class IT>
	class reverse_iterator {
		public:
		/**
		 * Member types:
		 */
		 	typedef 				IT														iterator_type;
			typedef typename		ft::iterator_traits<IT>::iterator_category				iterator_category;
			typedef typename		ft::iterator_traits<IT>::value_type						value_type;
			typedef typename		ft::iterator_traits<IT>::difference_type				difference_type;
			typedef typename		ft::iterator_traits<IT>::pointer						pointer;
			typedef typename		ft::iterator_traits<IT>::reference						reference;
			
			
		public:
		/**
		 * Member Functions
		 */
			reverse_iterator() {
			
			}
		
			explicit reverse_iterator(iterator_type it) {
			
			}
			/*---------------------------------------[Copy Constructor]-------------------------------------*/
			reverse_iterator (const reverse_iterator& copy_iter) {
			
			}
	};
	
} // ft

#endif //FT_REVERSE_ITERATOR_HPP
