#ifndef FT_REVERSE_ITERATOR_HPP
#define FT_REVERSE_ITERATOR_HPP

/**===================================================================================================*/
# include "./iterator.hpp"
# include "./iterator_traits.hpp"
# include "./RedBlack_iterator/RB_iterator.hpp"
# include "./RedBlack_iterator/RB_const_iterator.hpp"
/**===================================================================================================*/
namespace ft {
/**===================================================================================================*/
	template <class T>
	class reverse_iterator {
		public:
		/*=====================================[Member types]=====================================*/


			/**
			 * iterator_type: A type that provides the underlying iterator for a reverse_iterator. */
		 	typedef 				T												iterator_type;
			typedef typename		ft::iterator_traits<T>::value_type				value_type;
			/**
			 * A type that provides a pointer to an element addressed by a reverse_iterator. */
			typedef typename		ft::iterator_traits<T>::value_pointer			pointer;
			typedef typename		ft::iterator_traits<T>::value_reference			reference;
			
			/**
			 * difference_type: A type that provides the difference between two reverse_iterators
			 * referring to elements within the same container. */
			typedef typename		ft::iterator_traits<T>::difference_type			difference_type;
			typedef typename		ft::iterator_traits<T>::iterator_category		iterator_category;

		private:
			iterator_type			_current_iter;
			pointer _root;
			

		public:
			/*—————————————————————————————————[Empty Constructor]—————————————————————————————————*/
			reverse_iterator()
				: _current_iter() { }
			
			/*—————————————————————————————————[Constructor]———————————————————————————————————————*/
//			explicit
			reverse_iterator (iterator_type rev_it)
				: _current_iter(rev_it) { }
			
			/*—————————————————————————————————[Copy Constructor]———————————————————————————————————*
			 * @Copy_constructor
			 * A reverse_iterator across other types can be copied if the underlying iterator
			 * can be converted to the type of current
			 * @tparam Iter
			 * @param rev_it
			 */
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it)
				: _current_iter(rev_it.base()) { }
				
			/*———————————————————————————————[Assignment operator]—————————————————————————————————*
			 * @Assignment_operator
			 * A reverse_iterator across other types can be assigned if the underlying iterator
			 * can be converted to the type of current
			 * @tparam Iter
			 * @param rev_it
			 * @return *this
			 */
			reverse_iterator&
			operator= (const reverse_iterator& rev_it) {
				if (this != &rev_it)
					_current_iter = rev_it.base();
				return (*this);
			}
			
			/*———————————————————————————————————[Base]————————————————————————————————————————————*
			 * @Member_function
			 * Recovers the underlying iterator from its reverse_iterator.
			 */
			inline iterator_type
			base() const {
				return (_current_iter);
			}

			/**——————————————————————————————[Operator*]———————————————————————————————————————————*
			 ** Returns a reference or pointer to the element previous to current.
			 ** Equivalent to
			 ** Iter tmp = current;
			 ** return *--tmp;
			 */
			inline reference
			operator*() const {
				iterator_type tmp(_current_iter);
				return *--tmp;
			}
		
			/**——————————————————————————————[Operator->]———————————————————————————————————————————*
			 ** Returns a pointer to the element previous to current.
			 **/
			inline pointer
			operator->() const {
				return &(operator*());
			}
			
			/**——————————————————————————————[Operator++]———————————————————————————————————————————*
			**  @return  *this
			**  Decrements the underlying iterator.
			*/
			inline reverse_iterator&
			operator++() {
				--_current_iter;
				return (*this);
			}
			
			/**——————————————————————————————[Operator++]———————————————————————————————————————————*
			 **  @return  The original value of *this
			 **  Decrements the underlying iterator.
			*/
			inline reverse_iterator
			operator++(int) {
				reverse_iterator tmp(*this);
				--_current_iter;
				return (tmp);
			}
			
			/**——————————————————————————————[Operator--]———————————————————————————————————————————*
			 **  @return  *this
			 **  Increments the underlying iterator.
			*/
			inline reverse_iterator&
			operator--() {
				++_current_iter;
				return (*this);
			}
			
			/**——————————————————————————————[Operator--]———————————————————————————————————————————*
			 **  @return  A reverse_iterator with the previous value of *this
			 **  Increments the underlying iterator.
			*/
			inline reverse_iterator
			operator--(int) {
				reverse_iterator tmp(*this);
				++_current_iter;
				return (tmp);
			}
			
			/**——————————————————————————————[Operator+]————————————————————————————————————————————*
			 **  @return  A reverse_iterator that refers to (_current_iter - n)
			 **  The underlying iterator must be a Random Access Iterator.
			*/
			inline reverse_iterator
			operator+(difference_type n) const {
				return (reverse_iterator(_current_iter - n));
			}
			
			/**——————————————————————————————[Operator+=]———————————————————————————————————————————*
			 **  @return  *this
			 **  Moves the underlying iterator backwards (n steps).
			 **  The underlying iterator must be a Random Access Iterator.
			*/
			inline reverse_iterator&
			operator+=(difference_type n) {
			_current_iter = _current_iter - n;
				return (*this);
			}
			
			/**——————————————————————————————[Operator-]————————————————————————————————————————————*
			 **  @return  A reverse_iterator that refers to (_current_iter - n)
			 **  The underlying iterator must be a Random Access Iterator.
			*/
			inline reverse_iterator
			operator-(difference_type n) const {
				return (reverse_iterator(_current_iter + n));
			}
			
			/**——————————————————————————————[Operator-=]———————————————————————————————————————————*
			 **  @return  *this
			 **  Moves the underlying iterator forwards (n steps).
			 **  The underlying iterator must be a Random Access Iterator.
			*/
			inline reverse_iterator&
			operator-=(difference_type n) {
			_current_iter = _current_iter + n;
				return (*this);
			}
			
			/**——————————————————————————————[Operator[]]———————————————————————————————————————————*
			 **  @return  The value at (_current_iter - n - 1)
			 **  The underlying iterator must be a Random Access Iterator.
			*/
			reference
			operator[] (difference_type n) const {
				return *(_current_iter - n - 1);
			}
			
/**===================================================================================================*/
	}; // reverse_iterator
	/*——————————————————————————————————————————————————————————————————————————————————————*
	——————————————————————————————————[Non Member Functions]—————————————————————————————————
	————————————————————————————————————————————————————————————————————————————————————————*/
	template<class T >
	std::ostream&
	operator<<(std::ostream& os, const reverse_iterator<T> &it) {
		os << *it;
		return (os);
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class Iter1, class Iter2>
	bool operator==(const reverse_iterator<Iter1> &iter_1, const reverse_iterator<Iter2> &iter_2) {
		return iter_1.base() == iter_2.base();
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class Iter1, class Iter2>
	bool operator!=(const reverse_iterator<Iter1> &iter_1, const reverse_iterator<Iter2> &iter_2) {
		return iter_1.base() != iter_2.base();
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class Iter1, class Iter2>
	bool operator<(const reverse_iterator<Iter1> &iter_1, const reverse_iterator<Iter2> &iter_2) {
		return iter_1.base() > iter_2.base();
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class Iter1, class Iter2>
	bool operator<=(const reverse_iterator<Iter1> &iter_1, const reverse_iterator<Iter2> &iter_2) {
		return iter_1.base() >= iter_2.base();
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class Iter1, class Iter2>
	bool operator>(const reverse_iterator<Iter1> &iter_1, const reverse_iterator<Iter2> &iter_2) {
		return iter_1.base() < iter_2.base();
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class Iter1, class Iter2>
	bool operator>=(const reverse_iterator<Iter1> &iter_1, const reverse_iterator<Iter2> &iter_2) {
		return iter_1.base() <= iter_2.base();
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class Iter1, class Iter2>
	typename reverse_iterator<Iter1>::difference_type
	operator-(const reverse_iterator<Iter1> &iter_1, const reverse_iterator<Iter2> &iter_2) {
		return iter_2.base() - iter_1.base();
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class Iterator>
	reverse_iterator<Iterator>
	operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it) {
		return reverse_iterator<Iterator>(rev_it.base() + n);
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class Iter1, class Iter2>
	typename reverse_iterator<Iter1>::difference_type
	operator+(const reverse_iterator<Iter1> &iter_1, const reverse_iterator<Iter2> &iter_2) {
		return iter_1.base() + iter_2.base();
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class Iterator>
	reverse_iterator<Iterator>
	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it) {
		return reverse_iterator<Iterator>(rev_it.base() - n);
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
} // name space ft
/**===================================================================================================*/
#endif //FT_REVERSE_ITERATOR_HPP
