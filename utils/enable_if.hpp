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
 * 		template <typename T>
 * 		typename enable_if<ft::is_integral<T>::value>::type
 *
 * 		do_something(T x) {
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
		using type = T;
	};
	/**———————————————————————————————————————————————————————————*/
};

#endif //ENABLE_IF_HPP