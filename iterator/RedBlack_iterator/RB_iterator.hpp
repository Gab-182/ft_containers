#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP

/*=============================================================================================================*/
#include <iostream>
# include <cstddef>		// for ptrdiff_t
# include "../iterator_traits.hpp"

/*=============================================================================================================*/
namespace ft {
/*=============================================================================================================*/
	/**
	 * @brief Red-Black Tree Iterator, it is a random access iterator.
	 * The member types are:
	 * [node_pointer]: a pointer to the node.
	 * [value_type]: the type of the value, which is passed as pair<const Key, T>.
	 * @tparam T
	 * @tparam val
	 */
	template <class T, class val>
	class RB_iterator {
		public:
			typedef			T									node_pointer;
			typedef			val*								value_pointer;
			typedef			val&								value_reference;
			typedef			std::ptrdiff_t						difference_type;
			typedef			ft::random_access_iterator_tag		iterator_category;
			
		private:
			node_pointer	_ptr;
			
		public:
			/**——————————————————————————[Constructors && Destructor]——————————————————————————————*/
			RB_iterator()
				: _ptr(NULL) {};
			
			RB_iterator(const node_pointer& ptr)
				: _ptr(ptr) {};
			
			RB_iterator(const RB_iterator& copy)
				: _ptr(copy._ptr) {};
		
			~RB_iterator() {};
			
			/**——————————————————————————————[Operator=]———————————————————————————————————————————*/
			RB_iterator& operator=(const RB_iterator& copy) {
				if (this != &copy)
					_ptr = copy._ptr;
				return *this;
			};
			
			/**——————————————————————————————[Operator*]———————————————————————————————————————————*/
			value_reference operator*() const {
				return _ptr->paired_data;
			};
	};
/*=============================================================================================================*/
}

#endif //RB_ITERATOR_HPP
