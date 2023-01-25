#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP


# include "./iterator_traits.hpp"

namespace ft {
	template <class T >
	class iterator {
		/*---------------------------------------------------------------------------------------------------*/
		public:
		/**
		 * @Member_Types
		 */
			typedef			T									value_type;
			typedef			std::ptrdiff_t						difference_type;
			typedef			T*									pointer;
			typedef			T&									reference;
			typedef			ft::random_access_iterator_tag		iterator_category;
		/*---------------------------------------------------------------------------------------------------*/
		private:
			pointer			_ptr;

		public:
			/**
			 * @Member_functions */

			iterator()
				: _ptr(NULL) {};

			explicit
			iterator(pointer ptr)
				: _ptr(ptr) {};

			template <class U>
			iterator(const iterator<U>& other)
				: _ptr(other.base()) {}

			~iterator() {}
			/*---------------------------------------------------------------------------------------------------*/
			inline pointer
			base() const {
				return (_ptr);
			}
			/*---------------------------------------------------------------------------------------------------*/
			/**
			 * @Operator_overloads
			 * @attention
			 * We can't return a reference from arithmetic operations, since they produce a new value.
			 * [operator+] and [operator-] don't act on this object, but return a new object
			 * that is the summation (or subtraction) of this object from another.
			 * [operator=] is different because it's actually assigning something to this object.
			 * [operator+=] and [operator-=] would act on this object, and are a closer analog to [operator=
			 * ]
			 * The only (sensible) way to return a new value is to return it by value.
			 */
			inline iterator&
			operator=(const iterator& other) {
				if (this != &other)
					_ptr = other._ptr;
				return (*this);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline reference
			operator*() const {
				return (*_ptr);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline pointer
			operator->() const {
				return (_ptr);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline iterator&
			operator++() {
				++_ptr;
				return (*this);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline const iterator<T>
			operator++(int) {
				iterator tmp(*this);
				++_ptr;
				return (tmp);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline iterator&
			operator--() {
				--_ptr;
				return (*this);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline const iterator<T>
			operator--(int) {
				iterator tmp(*this);
				--_ptr;
				return (tmp);
			}
			/*---------------------------------------------------------------------------------------------------*/
			/**
			 * Constructing new iterator, not modifying the current one.
			 * which means that the current iterator is not incremented.
			 * @param n
			 * @return iterator
			 */
			inline iterator
			operator+(difference_type n) const {
				return iterator(_ptr + n);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline iterator
			operator-(difference_type n) const {
				return iterator(_ptr - n);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline iterator&
			operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline iterator&
			operator-=(difference_type n) {
				_ptr -= n;
				return (*this);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline bool
			operator==(const iterator& rhs) const {
				return (_ptr == rhs._ptr);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline bool
			operator!=(const iterator& rhs) const {
				return (_ptr != rhs._ptr);
			}
			/*---------------------------------------------------------------------------------------------------*/
			/**
			 * @brief return the number of elements between two iterators
			 * @param rhs
			 * @return
			 */
			inline ptrdiff_t
			operator+(const iterator& rhs) const {
				return (_ptr + rhs._ptr);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline ptrdiff_t
			operator-(const iterator& rhs) const {
				return (_ptr - rhs._ptr);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline bool
			operator<=(const iterator &rhs) const {
				return (_ptr <= rhs._ptr);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline bool
			operator>=(const iterator &rhs) const {
				return (_ptr >= rhs._ptr);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline bool
			operator<(const iterator &rhs) const {
				return (_ptr < rhs._ptr);
			}
			/*---------------------------------------------------------------------------------------------------*/
			inline bool
			operator>(const iterator &rhs) const {
				return (_ptr > rhs._ptr);
			}
		}; //? iterator
		
		/*---------------------------------------------------------------------------------------------------*/
		template<class T >
		std::ostream&
		operator<<(std::ostream& os, const iterator<T> &it) {
			os << *it;
			return (os);
		}
		
		/*---------------------------------------------------------------------------------------------------*/
        template <class Iter >
		inline typename iterator<Iter>::difference_type
		operator-(const iterator<Iter>& lhs, const iterator<Iter>& rhs) {
			return (lhs.base() - rhs.base());
		}
		/*---------------------------------------------------------------------------------------------------*/
		template <class Iter >
		inline bool
		operator!=(const iterator<Iter>& lhs, const iterator<Iter>& rhs) {
			return (lhs.base() != rhs.base());
		}
		
		/*---------------------------------------------------------------------------------------------------*/
		template <class Iter >
		inline iterator<Iter>
		operator+(const iterator<Iter>& lhs, typename iterator<Iter>::difference_type rhs) {
			return (lhs.base() + rhs);
		}
		
		/*---------------------------------------------------------------------------------------------------*/
} // namespace ft

#endif //! FT_ITERATOR_HPP