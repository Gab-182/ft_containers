#ifndef FT_REVERSE_ITERATOR_HPP
#define FT_REVERSE_ITERATOR_HPP


# include "./iterator.hpp"
# include "./iterator_traits.hpp"

namespace ft {
	/*---------------------------------------------------------------------------------------------------*/
	template <class T>
	class reverse_iterator {
		public:
		/**
		 * @Member_types
		 */
			/**
			 * iterator_type: A type that provides the underlying iterator for a reverse_iterator.
			 */
		 	typedef 				T												iterator_type;
			typedef typename		ft::iterator_traits<T>::value_type				value_type;
			/**
			 * A type that provides a pointer to an element addressed by a reverse_iterator.
			 */
			typedef typename		ft::iterator_traits<T>::pointer					pointer;
			typedef typename		ft::iterator_traits<T>::reference				reference;
			
			/**
			 * difference_type: A type that provides the difference between two reverse_iterators
			 * referring to elements within the same container. */
			typedef typename		ft::iterator_traits<T>::difference_type			difference_type;
			typedef typename		ft::iterator_traits<T>::iterator_category		iterator_category;
		/*---------------------------------------------------------------------------------------------------*/
		private:
			iterator_type			_iter;
		/*---------------------------------------------------------------------------------------------------*/
		public:
			reverse_iterator() {
				_iter = NULL;
			};
		/*---------------------------------------------------------------------------------------------------*/
			explicit reverse_iterator (iterator_type iter) {
			_iter = iter;
			};
		/*---------------------------------------------------------------------------------------------------*/
			template <class Iter>
			explicit reverse_iterator (const reverse_iterator<Iter>& rev_it) {
				if (this != &rev_it)
					_iter = rev_it;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
		/***
		 * @Member_function
		 * Recovers the underlying iterator from its reverse_iterator.
		 */
			iterator_type base() const {
				return (_iter);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reference operator*() const {
				return &(*_iter);
			};
		/*---------------------------------------------------------------------------------------------------*/
			pointer operator->() const {
				return (&_iter);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reverse_iterator& operator++() {
				--_iter;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reverse_iterator operator++(int) {
				reverse_iterator tmp(*this);
				--_iter;
				return (tmp);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reverse_iterator& operator--() {
				++_iter;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				++_iter;
				return (tmp);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reverse_iterator operator+(difference_type n) const {
				return (reverse_iterator(_iter - n));
			};
		/*---------------------------------------------------------------------------------------------------*/
			reverse_iterator& operator+=(difference_type n) {
				_iter = _iter - n;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reverse_iterator operator-(difference_type n) const {
				return (reverse_iterator(_iter + n));
			};
		/*---------------------------------------------------------------------------------------------------*/
			reverse_iterator& operator-=(difference_type n) {
				_iter = _iter + n;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reverse_iterator& operator=(const reverse_iterator& rev_it) {
				if (this != &rev_it)
					_iter = rev_it;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reference operator[] (difference_type n) const {
				return (_iter[-n - 1]);
			};
		/*---------------------------------------------------------------------------------------------------*/
		
	}; // reverse_iterator
	/*---------------------------------------------------------------------------------------------------*/
	std::ostream& operator<< (std::ostream& out, const reverse_iterator& rev_it) {
		out << *rev_it;
		return (out);
	}
	
	/*---------------------------------------------------------------------------------------------------*/
} // name space ft

#endif //FT_REVERSE_ITERATOR_HPP
