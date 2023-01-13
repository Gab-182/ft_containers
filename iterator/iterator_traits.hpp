#ifndef	FT_ITERATOR_TRAITS_HPP
# define FT_ITERATOR_TRAITS_HPP

# include <cstddef>
# include <iterator>

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
	 * @tparam T
	 ** is the type of iterator for which the traits are being defined.
	 * @Note
	 ** If T is not an iterator, The std::iterator_traits<T>::iterator_category
	 ** will be a specialization std::void_t and the template struct definition will be implicit instanciated.
	 */
	
	template< typename T >
	struct iterator_traits {
		/// [value_type]: The type of object that the iterator points to.
		typedef					T												value_type;
		/// [pointer]: pointer to an object of the value_type.
		typedef					T*												pointer;
		/// [reference]: reference to an object of the value_type.
		typedef					T&												reference;
		/// [difference_type]: signed integer type that can represent the difference between two iterators.
		typedef					std::ptrdiff_t									difference_type;
		//? [iterator_category]: The category of the iterator.
			// * std::random_access_iterator_tag,
			// * std::bidirectional_iterator_tag,
			// * or std::forward_iterator_tag,
		typedef typename	 	std::iterator_traits<T>::iterator_category		iterator_category;
	};
	/*---------------------------------------------------------------------------------------------------*/
	/***
	 * @Specializations*/
	/***
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
		typedef					std::random_access_iterator_tag					iterator_category;
	};
	/*---------------------------------------------------------------------------------------------------*/
	template< typename T >
	struct iterator_traits<const T*> {
		typedef					T												value_type;
		typedef					const T*										pointer;
		typedef					const T&										reference;
		typedef					std::ptrdiff_t									difference_type;
		typedef					std::random_access_iterator_tag					iterator_category;
	};
	/*---------------------------------------------------------------------------------------------------*/
} //! namespace ft


/*=============================================================================================================*/
#endif //! FT_ITERATOR_TRAITS_HPP