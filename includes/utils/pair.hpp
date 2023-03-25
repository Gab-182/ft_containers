#ifndef PAIR_HPP
#define PAIR_HPP

# include <utility>
/*=============================================================================================================*/
namespace ft {

	/**—————————————————————————————————————————————————————————————————————————————————**/
	template<class T1, class T2 >
	struct pair {
		
		// The type of the `first` member
		typedef		T1		first_type;
		// The type of the `second` member
		typedef		T2		second_type;
		
		// The first member
		T1 		first;
		// The second member
		T2 		second;
		/*➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*
		➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[ Member_functions ]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*
		➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**
		 ** @brief: The default constructor creates first and second using their
		 **  respective default constructors.
		 * */
		pair()
			: first(), second() { }

		/**———————————————————————————————————————————————————————————**/
		/**
		 ** @brief: Two objects may be passed to a pair constructor to be copied.
		 **/
		pair( const T1& x, const T2& y)
			: first(x), second(y) { }
			
		/**———————————————————————————————————————————————————————————**/
		/**
		 ** @brief: There is also a templated constructor to convert from other pairs.
		 **/
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p )
			: first(p.first), second(p.second) { }
		
		~pair() { }
		/**———————————————————————————————————————————————————————————**/
		inline pair&
		operator=( pair const& other ) {
			first = other.first;
			second = other.second;
			return *this;
		}
		
		/**———————————————————————————————————————————————————————————**/
}; // pair

/*➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*
➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[ Non Member Functions ]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*
➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
/**
 **  @brief A convenience wrapper for creating a pair from two objects.
 **  @param  first  The first object.
 **  @param  second  The second object.
 **  @return   A newly-constructed pair<> object of the appropriate type.
 **
 **  The C++98 standard says the objects are passed by reference-to-const,
 **  but C++03 says they are passed by value (this was LWG issue #181).
 */
template <class T1, class T2>
ft::pair<T1, T2>
make_pair( T1 first, T2 second ) {
	return (ft::pair<T1, T2>(first, second));
}

/**———————————————————————————————————————————————————————————**/
/**
 **  @brief: Two pairs of the same type are equal iff their members are equal.
 **/
template<typename T1, typename T2>
inline bool
operator==(const pair<T1, T2>& x, const pair<T1, T2>& y) {
	return ((x.first == y.first) && (x.second == y.second));
}
/**———————————————————————————————————————————————————————————**/
/**
 **  @brief: Uses operator== to find the result.
 **/
template<typename T1, typename T2>
inline bool
operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
	return !(x == y);
}

/**———————————————————————————————————————————————————————————**/
/**
 **  @brief: Defines a lexicographical order for pairs.
 **
 **  For two pairs of the same type, `P` is ordered before `Q` if
 **  `P.first` is less than `Q.first`, or if `P.first` and `Q.first`
 **  are equivalent (neither is less than the other) and `P.second`
 **  is less than `Q.second`.
 **/
template<typename T1, typename T2>
inline bool
operator<(const pair<T1, T2>& x, const pair<T1, T2>& y) {
	return (x.first < y.first) || (!(y.first < x.first) && x.second < y.second);
}

/**———————————————————————————————————————————————————————————**/
/**
 **  @brief: Uses (operator<) to find the result.
 **/
template<typename T1, typename T2>
inline bool
operator>(const pair<T1, T2>& x, const pair<T1, T2>& y) {
	return (y < x);
}

/**———————————————————————————————————————————————————————————**/
/**
 ** @brief: Uses (operator<) to find the result.
 **/
template<typename T1, typename T2>
inline bool
operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
	return !(y < x);
}

/**———————————————————————————————————————————————————————————**/
/**
 ** @brief: Uses (operator<) to find the result.
 **/
template<typename T1, typename T2>
inline bool
operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
	return !(x < y);
}

/**———————————————————————————————————————————————————————————**/

} // ft
/*=============================================================================================================*/
#endif //PAIR_HPP
