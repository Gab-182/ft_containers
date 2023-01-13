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
			iterator_type			_current_iter;
		/*---------------------------------------------------------------------------------------------------*/
		public:
			reverse_iterator() {
				_current_iter = NULL;
			};
		/*---------------------------------------------------------------------------------------------------*/
			explicit reverse_iterator (iterator_type rev_it) {
			_current_iter = rev_it;
			};
		/*---------------------------------------------------------------------------------------------------*/
			/**
			 * @Copy_constructor
			 * A reverse_iterator across other types can be copied if the underlying iterator
			 * can be converted to the type of current
			 * @tparam Iter
			 * @param rev_it
			 */
			template <class Iter>
			explicit reverse_iterator (const reverse_iterator<Iter>& rev_it) {
				_current_iter = rev_it._current_iter;
			};
		/*---------------------------------------------------------------------------------------------------*/
		/***
		 * @Member_function
		 * Recovers the underlying iterator from its reverse_iterator.
		 */
			iterator_type base() const {
				return (_current_iter);
			};
		/*---------------------------------------------------------------------------------------------------*/
			/**
			 * Returns a reference or pointer to the element previous to current.
			 * Equivalent to
			 * Iter tmp = current;
			 * return *--tmp;
			 */
			reference operator*() const {
				iterator_type tmp = _current_iter;
				return (*--tmp);
			};
		/*---------------------------------------------------------------------------------------------------*/
			pointer operator->() const {
				return (&(operator*()));
			};
		/*---------------------------------------------------------------------------------------------------*/
		/**
		*  @return  @c *this
		*
		*  Decrements the underlying iterator.
		*/
			reverse_iterator& operator++() {
				--_current_iter;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
		/**
		 *  @return  The original value of @c *this
		 *
		 *  Decrements the underlying iterator.
		*/
			reverse_iterator operator++(int) {
				reverse_iterator tmp(*this);
				--_current_iter;
				return (tmp);
			};
		/*---------------------------------------------------------------------------------------------------*/
		/**
		 *  @return  @c *this
		 *
		 *  Increments the underlying iterator.
		*/
			reverse_iterator& operator--() {
				++_current_iter;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
		/**
		 *  @return  A reverse_iterator with the previous value of @c *this
		 *
		 *  Increments the underlying iterator.
		*/
			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				++_current_iter;
				return (tmp);
			};
		/*---------------------------------------------------------------------------------------------------*/
		/**
		 *  @return  A reverse_iterator that refers to (@c _current_iter - @a n)
		 *
		 *  The underlying iterator must be a Random Access Iterator.
		*/
			reverse_iterator operator+(difference_type n) const {
				return (reverse_iterator(_current_iter - n));
			};
		/*---------------------------------------------------------------------------------------------------*/
		/**
		 *  @return  *this
		 *
		 *  Moves the underlying iterator backwards @a (n steps).
		 *  The underlying iterator must be a Random Access Iterator.
		*/
			reverse_iterator& operator+=(difference_type n) {
			_current_iter = _current_iter - n;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
		/**
		 *  @return  A reverse_iterator that refers to @c (_current_iter - @a n)
		 *
		 *  The underlying iterator must be a Random Access Iterator.
		*/
			reverse_iterator operator-(difference_type n) const {
				return (reverse_iterator(_current_iter + n));
			};
		/*---------------------------------------------------------------------------------------------------*/
		/**
		 *  @return  *this
		 *
		 *  Moves the underlying iterator forwards @a (n steps).
		 *  The underlying iterator must be a Random Access Iterator.
		*/
			reverse_iterator& operator-=(difference_type n) {
			_current_iter = _current_iter + n;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
			reverse_iterator& operator=(const reverse_iterator& rev_it) {
				_current_iter = rev_it._current_iter;
				return (*this);
			};
		/*---------------------------------------------------------------------------------------------------*/
		/**
		 *  @return  The value at @c (_current_iter - @a n - 1)
		 *
		 *  The underlying iterator must be a Random Access Iterator.
		*/
			reference operator[] (difference_type n) const {
				return (_current_iter[-n - 1]);
			};
		/*---------------------------------------------------------------------------------------------------*/
		
	}; // reverse_iterator
	/*---------------------------------------------------------------------------------------------------*/
	
	/*---------------------------------------------------------------------------------------------------*/
} // name space ft

#endif //FT_REVERSE_ITERATOR_HPP
