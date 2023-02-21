#ifndef RB_CONST_ITERATOR_HPP
#define RB_CONST_ITERATOR_HPP

/*=============================================================================================================*/
# include <iostream>
# include <cstddef>		// for ptrdiff_t
# include "../iterator_traits.hpp"
# include "../reverse_iterator.hpp"
# include <map>
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
	template <class T, class val, class DeffType>
	class RB_const_iterator {
	public:
		typedef 		val											value_type;
		typedef			T											node_pointer;
		typedef			val*										value_pointer;
		typedef			val&										value_reference;
		typedef			DeffType									difference_type;
		typedef			ft::bidirectional_iterator_tag				iterator_category;
	
	private:
		node_pointer	_ptr;
		
		/**
		 * @brief By using const_cast, _ptr_non_const converts the const-qualified _ptr into
		 * a non-const pointer and returns it as a node_pointer.
		 * This allows other member functions that require a non-const pointer to
		 * the node to modify it without violating the
		 * const-correctness of the const iterator.
		 * @return
		 */
		node_pointer _ptr_to_non_const() const {
			return const_cast<node_pointer>(_ptr);
		}
	
	
	public:
		/**——————————————————————————[Constructors && Destructor]——————————————————————————————*/
		RB_const_iterator()
				: _ptr(NULL) {};
		
		explicit
		RB_const_iterator(const node_pointer& ptr)
				: _ptr(ptr) {};
		
		template <class NodePointer, class Val, class Diff>
		RB_const_iterator(const RB_iterator<NodePointer, Val, Diff>& copy)
				: _ptr(copy.base()) {};
		
		template <class NodePointer, class Val, class Diff>
		RB_const_iterator(const RB_const_iterator<NodePointer, Val, Diff>& copy)
				: _ptr(copy.base()) {};
		
		~RB_const_iterator() {};
		
		/**————————————————————————————————[base()]————————————————————————————————————————————*/
		inline node_pointer
		base() const {
			return _ptr;
		}
		
		/**——————————————————————————————[Operator=]———————————————————————————————————————————*/
		inline RB_const_iterator&
		operator=(const RB_const_iterator& copy) {
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
			return (*this);
		}
		/**————————————————————————————[Operator++(int)]———————————————————————————————————————*/
		/**
		 ** @brief Prefix increment operator, it returns the iterator to the next node.
		 ** which have the larger key.
		 ** @return RB_iterator
		 ** Note:
		 ** =====
		 ** The operator++(int): return the iterator before increment, not a reference.
		 **/
		inline RB_const_iterator
		operator++(int) {
			RB_const_iterator tmp(*this);
			++(*this);
			return (tmp);
		}
		/**——————————————————————————————[Operator--]——————————————————————————————————————————
		 ** @brief Postfix decrement operator, it returns the iterator to the previous node.
		 ** which have the smaller key.
		 ** @return RB_iterator&
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
			return (*this);
		}

		/**——————————————————————————————[Operator--(int)]—————————————————————————————————————————
		 ** @brief Postfix decrement operator, it returns the iterator to the previous node.
		 ** which have the smaller key.
		 ** @return RB_iterator
		 ** Note:
		 ** =====
		 ** The operator++(int): return the iterator before increment, not a reference.
		 **/
		inline RB_const_iterator
		operator--(int) {
			RB_const_iterator tmp(*this);
			--(*this);
			return (tmp);
		}
		
		/**——————————————————————————————[Operator+=]———————————————————————————————————————————*/
		inline RB_const_iterator&
		operator+=(difference_type n) {
			if (n < 0)
				return (*this -= -n);
			while (n--)
				++(*this);
			return (*this);
		}
		
		/**——————————————————————————————[Operator+]———————————————————————————————————————————*/
		inline RB_const_iterator
		operator+(difference_type n) {
			RB_const_iterator tmp(*this);
			tmp += n;
			return (tmp);
		}
		
		/**——————————————————————————————[Operator-=]———————————————————————————————————————————*/
		inline RB_const_iterator&
		operator-=(difference_type n) {
			if (n < 0)
				return (*this += -n);
			while (n--)
				--(*this);
			return (*this);
		}
		
		/**——————————————————————————————[Operator-]———————————————————————————————————————————*/
		inline RB_const_iterator
		operator-(difference_type n) {
			RB_const_iterator tmp(*this);
			tmp -= n;
			return (tmp);
		}
	};

/*=============================================================================================================*/
	/**——————————————————————————————[Operator(it1 != it2)]———————————————————————————————————————————*/
	template <class T, class val, class Diff>
	inline bool
	operator!=(const RB_const_iterator<T, val, Diff>& lhs, const RB_const_iterator<T, val, Diff>& rhs) {
		return (lhs.base() != rhs.base());
	}
	
	/**——————————————————————————————[Operator(it1 == it2)]———————————————————————————————————————————*/
	template <class T, class val, class Diff>
	inline bool
	operator==(const RB_const_iterator<T, val, Diff>& lhs, const RB_const_iterator<T, val, Diff>& rhs) {
		return (lhs.base() == rhs.base());
	}
/*=============================================================================================================*/
}

#endif