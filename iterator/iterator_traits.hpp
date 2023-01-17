#ifndef	FT_ITERATOR_TRAITS_HPP
# define FT_ITERATOR_TRAITS_HPP

# include <cstddef>
# include "iterator.hpp"

/*=============================================================================================================*/
namespace ft {
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	/*---------------------------------------------------------------------------------------------------*/
	/**
	 * @Iterator_traits */
	 /**
	 * @brief
	 ** This struct is usually used as a base class of other iterator template classes,
	 ** so that it can be used with STL algorithm and containers.
	 * @tparam Iter
	 ** is the type of iterator for which the traits are being defined.
	 * @Note
	 ** If Iter is not an iterator, The std::iterator_traits<Iter>::iterator_category
	 ** will be a specialization std::void_t and the template struct definition will be implicit instanciated.
	 */
	
	template< typename Iter >
	struct iterator_traits {
		typedef 	typename 	Iter::iterator_category 	iterator_category;
		typedef 	typename 	Iter::value_type        	value_type;
		typedef 	typename 	Iter::difference_type   	difference_type;
		typedef 	typename 	Iter::pointer           	pointer;
		typedef 	typename 	Iter::reference         	reference;
	};
/*=============================================================================================================
 * @Note:
 * For the iterator_category, we use the iterator_category of the iterator<Iter> struct if valid.
 * otherwise,
 * std::random_access_iterator_tag if Iter satisfies __LegacyRandomAccessIterator
 * __LegacyRandomAccessIterator:
 * which will be satisfied all the time.
 */
	
	/*---------------------------------------------------------------------------------------------------*/
	/**
	 * @Specializations*/
	/*---------------------------------------------------------------------------------------------------
	 * @brief
	 ** Specialization of iterator_traits for pointer types.
	 ** The standard library provides partial specializations for pointer types T*,
	 ** which makes it possible to use all iterator-based algorithms with raw pointers.
	 * @tparam T
	 */
	template< typename T >
	struct iterator_traits<T*> {
		typedef					T												value_type;
		typedef					T*												pointer;
		typedef					T&												reference;
		typedef					std::ptrdiff_t									difference_type;
		typedef					ft::random_access_iterator_tag					iterator_category;
	};

	/*---------------------------------------------------------------------------------------------------*/
	template< typename T >
	struct iterator_traits<const T*> {
		typedef					T												value_type;
		typedef					const T*										pointer;
		typedef					const T&										reference;
		typedef					std::ptrdiff_t									difference_type;
		typedef					ft::random_access_iterator_tag					iterator_category;
	};
	/*---------------------------------------------------------------------------------------------------*/
} //! namespace ft


/*=============================================================================================================*/
#endif //! FT_ITERATOR_TRAITS_HPP