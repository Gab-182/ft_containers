#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

/**———————————————————————————————————————————————————————————————————**
 * @NOTE:
 * =================================
 * This implementation defines a struct (enable_if) that has two template
 * parameters: a bool and a type T.
 * The struct has a type member that is only defined if the first
 * template parameter is true.
 *
 *———————————————————————————————————————————————————————————————————**/

/**———————————————————————————————————————————————————————————————————**
 * @NOTE: the usage of (ft::enable_if)
 * =================================
 *
 * 		in c++11: --> we can use enable_if in the template parameters.
 *
 * 		template <typename T>
 * 		do_something(T x, typename enable_if<ft::is_integral<T>::value>::type) {
 * 			// code that should only be enabled for integral types
 * 		}
 *
 * 		-------------------------------------------------------------------------
 * 		in c++98: --> we should use enable_if in the function parameters.
 *
 * 		template <typename T>
 * 		do_something(T x, typename enable_if<ft::is_integral<T>::value>::type) {
 * 			// code that should only be enabled for integral types
 * 		}
 *
 * In this example, the function (do_something) will only be enabled for
 * types that are integral (as determined by the ft::is_integral type trait).
 *
 *———————————————————————————————————————————————————————————————————**/


namespace ft {
	/**———————————————————————————————————————————————————————————*/
	template <bool B, typename T = void>
	struct enable_if {};
	/**———————————————————————————————————————————————————————————*/
	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};
	/**———————————————————————————————————————————————————————————*/
};

#endif //ENABLE_IF_HPP