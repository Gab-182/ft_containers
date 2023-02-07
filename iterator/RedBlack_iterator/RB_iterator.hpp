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
			
			explicit RB_iterator(const node_pointer& ptr)
				: _ptr(ptr) {};
			
			RB_iterator(const RB_iterator& copy)
				: _ptr(copy._ptr) {};
		
			~RB_iterator() {};
			
			/**————————————————————————————————[base()]————————————————————————————————————————————*/
			inline node_pointer
			base() const {
				return _ptr;
			};
			/**——————————————————————————————[Operator=]———————————————————————————————————————————*/
			inline RB_iterator&
			operator=(const RB_iterator& copy) {
				if (this != &copy)
					_ptr = copy._ptr;
				return *this;
			};
			
			/**——————————————————————————————[Operator*]———————————————————————————————————————————*/
			inline value_reference
			operator*() const {
				return (_ptr->paired_data);
			};
			
			/**——————————————————————————————[Operator->]——————————————————————————————————————————*/
			inline value_pointer
			operator->() const {
				return &(_ptr->paired_data);
			};
			
			/**——————————————————————————————[Operator++]——————————————————————————————————————————*/
			/**
			 ** @brief Prefix increment operator, it returns the iterator to the next node.
			 ** which have the larger key.
			 ** @return RB_iterator&
			 **/
			inline RB_iterator&
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
				return (*this);
			}
			/**————————————————————————————[Operator++(int)]———————————————————————————————————————*/
			/**
			 ** @brief Prefix increment operator, it returns the iterator to the next node.
			 ** which have the larger key.
			 ** @return RB_iterator&
			 * @TODO: check if it is correct, should i return a reference of the iterator? or the iterator itself?
			 **/
			inline RB_iterator&
			operator++(int) {
				RB_iterator tmp(*this);
				
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
				return (tmp);
			}
			/**——————————————————————————————[Operator--]——————————————————————————————————————————
			 * @brief Prefix decrement operator, it returns the iterator to the previous node.
			 * which have the smaller key.
			 * @return RB_iterator&
			 **/
			inline RB_iterator&
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
				return RB_iterator(_ptr);
			}
			
			/**———————————————————————————————————————————————————————————————————————————————————*/
	};
/*=============================================================================================================*/
	template <class T, class val >
	inline bool
	operator!=(const RB_iterator<T, val>& lhs, const RB_iterator<T, val>& rhs) {
		return (lhs.base() != rhs.base());
	}
/*=============================================================================================================*/
}

#endif //RB_ITERATOR_HPP