#ifndef RB_CONST_ITERATOR_HPP
#define RB_CONST_ITERATOR_HPP

/*=============================================================================================================*/
#include <iostream>
# include <cstddef>		// for ptrdiff_t
# include "../iterator_traits.hpp"

/*=============================================================================================================*/
namespace ft {
/*=============================================================================================================*/
	/**
	 * @brief Red-Black Tree const Iterator, it is a random access iterator.
	 * The member types are:
	 * [node_pointer]: a pointer to the node.
	 * [value_type]: the type of the value, which is passed as pair<const Key, T>.
	 * @tparam T a pointer to the node.
	 * @tparam val the value.
	 */
	template <class T, class val>
	class RB_const_iterator {
	public:
		typedef			T										node_pointer;
		typedef			const val*								const_value_pointer;
		typedef			const val&								const_value_reference;
		typedef			std::ptrdiff_t							difference_type;
		typedef			ft::random_access_iterator_tag			iterator_category;
	
	private:
		node_pointer	_ptr;
	
	public:
		/**——————————————————————————[Constructors && Destructor]——————————————————————————————*/
		RB_const_iterator()
				: _ptr(NULL) {};
		
		RB_const_iterator(const node_pointer& ptr)
				: _ptr(ptr) {};
		
		RB_const_iterator(const RB_const_iterator& copy)
				: _ptr(copy._ptr) {};
		
		~RB_const_iterator() {};
		
		/**——————————————————————————————[Operator=]———————————————————————————————————————————*/
		inline RB_const_iterator&
		operator=(const RB_const_iterator& copy) {
			if (this != &copy)
				_ptr = copy._ptr;
			return *this;
		};
		
		/**——————————————————————————————[Operator*]———————————————————————————————————————————*/
		inline const_value_reference
		operator*() const {
			return (_ptr->paired_data);
		};
		
		/**——————————————————————————————[Operator->]——————————————————————————————————————————*/
		inline const_value_pointer
		operator->() const {
			return &(_ptr->paired_data);
		};
		
		/**——————————————————————————————[Operator++]——————————————————————————————————————————*/
		/**
		 ** @brief Prefix increment operator, it returns the iterator to the next node.
		 ** which have the larger key.
		 ** @return RB_iterator&
		 **/
		inline RB_const_iterator&
		operator++() {
			if (_ptr->right != NULL) {
				_ptr = _ptr->right;
				while (_ptr->left != NULL)
					_ptr = _ptr->left;
			}
			else {
				while (_ptr->parent != NULL && _ptr->parent->right == _ptr)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
			return *this;
		}
		
		/**——————————————————————————————[Operator--]——————————————————————————————————————————
		 * @brief Prefix decrement operator, it returns the iterator to the previous node.
		 * which have the smaller key.
		 * @return RB_iterator&
		 **/
		inline RB_const_iterator&
		operator--() {
			// if the node has left child, then the previous node is the rightmost node of the left subtree.
			if (_ptr->left != NULL) {
				_ptr = _ptr->left;
				while (_ptr->right != NULL)
					_ptr = _ptr->right;
			}
				// if the node has no left child, then the previous node is the parent.
			else {
				// if the node is the right child of its parent, then the parent is the previous node.
				while (_ptr->parent != NULL && _ptr->parent->left == _ptr)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
			return *this;
		}
		
		/**———————————————————————————————————————————————————————————————————————————————————*/
	};
/*=============================================================================================================*/
}
#endif //RB_CONST_ITERATOR_HPP