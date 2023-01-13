#ifndef FT_VECTOR_ITERATOR_HPP
#define FT_VECTOR_ITERATOR_HPP

# include "./iterator.hpp"
# include "./iterator_traits.hpp"

namespace ft {
	template<class T >
	class vector_iterator {
		/*---------------------------------------------------------------------------------------------------*/
		public:
		/**
		 * @Member_Types
		 */
			typedef			T									value_type;
			typedef			std::ptrdiff_t						difference_type;
			typedef			T*									pointer;
			typedef			T&									reference;
			typedef			std::random_access_iterator_tag		iterator_category;
			
		private:
			pointer			_ptr;
		public:
			/**
			 * @Member_functions
			 */
			vector_iterator() {
				_ptr = NULL;
			};
			
			explicit vector_iterator(pointer ptr) {
				_ptr = ptr;
			};
			
			vector_iterator(const vector_iterator &other) {
				_ptr = other._ptr;
			};
			
			~vector_iterator() {};
			
			/**
			 * @Operator_overloads:
			 * We can't return a reference from arithmetic operations, since they produce a new value.
			 * [operator+] and [operator-] don't act on this object, but return a new object
			 * that is the summation (or subtraction) of this object from another.
			 * [operator=] is different because it's actually assigning something to this object.
			 * [operator+=] and [operator-=] would act on this object, and are a closer analog to [operator=
			 * ]
			 * The only (sensible) way to return a new value is to return it by value.
			 */
			vector_iterator& operator=(const vector_iterator &other) {
				if (this != &other)
					_ptr = other._ptr;
				return (*this);
			};
			
			reference operator*() const {
				return (*_ptr);
			};
			
			pointer operator->() const {
				return (_ptr);
			};
			
			vector_iterator& operator++() {
				++_ptr;
				return (*this);
			};
			
			vector_iterator& operator++(int) {
				vector_iterator tmp(*this);
				++_ptr;
				return (tmp);
			};
			
			vector_iterator& operator--() {
				--_ptr;
				return (*this);
			};
			
			vector_iterator& operator--(int) {
				vector_iterator tmp(*this);
				--_ptr;
				return (tmp);
			};
			
			/**
			 * Constructing new iterator, not modifying the current one.
			 * which means that the current iterator is not incremented.
			 * @param n
			 * @return vector_iterator
			 */
			vector_iterator operator+(difference_type n) const {
				vector_iterator tmp(*this);
				tmp._ptr += n;
				return (tmp);
			};
			
			vector_iterator operator-(difference_type n) const {
				vector_iterator tmp(*this);
				tmp._ptr -= n;
				return (tmp);
			};
			
			vector_iterator& operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			};
			
			vector_iterator& operator-=(difference_type n) {
				_ptr -= n;
				return (*this);
			};
			
		/*---------------------------------------------------------------------------------------------------*/
		}; //? vector_iterator
		
		/*---------------------------------------------------------------------------------------------------*/
	} //? namespace ft


#endif //FT_VECTOR_ITERATOR_HPP
