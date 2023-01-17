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
			iterator() {
				_ptr = NULL;
			};

			explicit
			iterator(pointer ptr) {
				_ptr = ptr;
			};

			iterator(const iterator &other) {
				_ptr = other._ptr;
			};

			~iterator() {};
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
			iterator&
			operator=(const iterator &other) {
				if (this != &other)
					_ptr = other._ptr;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reference
			operator*() const {
				return (*_ptr);
			};
		/*---------------------------------------------------------------------------------------------------*/
			pointer
			operator->() const {
				return (_ptr);
			};
		/*---------------------------------------------------------------------------------------------------*/
			iterator&
			operator++() {
				++_ptr;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
			const iterator<T>
			operator++(int) {
				iterator tmp(*this);
				++_ptr;
				return (tmp);
			};
		/*---------------------------------------------------------------------------------------------------*/
			iterator&
			operator--() {
				--_ptr;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
			const iterator<T>
			operator--(int) {
				iterator tmp(*this);
				--_ptr;
				return (tmp);
			};
		/*---------------------------------------------------------------------------------------------------*/
			/**
			 * Constructing new iterator, not modifying the current one.
			 * which means that the current iterator is not incremented.
			 * @param n
			 * @return iterator
			 */
			iterator
			operator+(difference_type n) const {
				iterator tmp(*this);
				tmp._ptr += n;
				return (tmp);
			};
		/*---------------------------------------------------------------------------------------------------*/
			iterator
			operator-(difference_type n) const {
				iterator tmp(*this);
				tmp._ptr -= n;
				return (tmp);
			};
		/*---------------------------------------------------------------------------------------------------*/
			iterator&
			operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
			iterator&
			operator-=(difference_type n) {
				_ptr -= n;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
		}; //? iterator
		// overload << operator:
		template<class T >
		std::ostream&
		operator<<(std::ostream& os, const iterator<T> &it) {
			os << *it;
			return (os);
		}
		/*---------------------------------------------------------------------------------------------------*/
} // namespace ft

#endif //! FT_ITERATOR_HPP