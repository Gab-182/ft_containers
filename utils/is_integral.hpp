#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

# include <string>

/**———————————————————————————————————————————————————————————————————**
 * @NOTE: the usage of (static) keyword here:
 * ==========================================
 *
 * In the case of the is_integral struct,
 * the value member is defined as a static constexpr bool.
 * This means that there is only one instance of the value member,
 * shared across all specializations of the is_integral struct.
 *
 * This allows the value member to be accessed through the
 * class name, without the need to create an instance of
 * the class.
 *
 * Additionally, it's important to know that static variables
 * are allocated in the data segment of the program, not on the stack,
 * hence it's lifetime is the same as the program.
 *———————————————————————————————————————————————————————————————————**/

/**———————————————————————————————————————————————————————————————————**
 * @NOTE: the usage of (const_expr) instead of (const) keyword here
 * =================================================================
 *
 * In the case of the is_integral struct,
 * the value member is defined as a (static constexpr bool).
 * This means that there is only one instance of the value member,
 * shared across all specializations of the is_integral struct.
 *
 * This allows the value member to be accessed through the
 * class name, without the need to create an instance of
 * the class.
 *
 * Additionally, it's important to know that (static) variables
 * are allocated in the data segment of the program, not on the stack,
 * hence it's lifetime is the same as the program.
 *———————————————————————————————————————————————————————————————————**/


/**———————————————————————————————————————————————————————————————————**
 * @NOTE: the usage of (is_integral)
 * =================================
 * 		ft::is_integral<int>::value;      // true
 * 		ft::is_integral<double>::value;   // false
 *———————————————————————————————————————————————————————————————————**/



namespace ft {
	/**———————————————————————————————————————————————————————————*/
	template <typename T>
	struct is_integral {
		static constexpr bool value = false;
	};

	template <>
	struct is_integral<char> {
		static constexpr bool value = true;
	};

	template <>
	struct is_integral<signed char> {
		static constexpr bool value = true;
	};

	template <>
	struct is_integral<unsigned char> {
		static constexpr bool value = true;
	};

	template <>
	struct is_integral<short> {
		static constexpr bool value = true;
	};

	template <>
	struct is_integral<unsigned short> {
		static constexpr bool value = true;
	};

	template <>
	struct is_integral<int> {
		static constexpr bool value = true;
	};

	template <>
	struct is_integral<unsigned int> {
		static constexpr bool value = true;
	};

	template <>
	struct is_integral<long> {
		static constexpr bool value = true;
	};

	template <>
	struct is_integral<unsigned long> {
		static constexpr bool value = true;
	};

	template <>
	struct is_integral<long long> {
		static constexpr bool value = true;
	};

	template <>
	struct is_integral<unsigned long long> {
		static constexpr bool value = true;
	};

	/**———————————————————————————————————————————————————————————*/
	struct true_type { };
	struct false_type { };
	/**———————————————————————————————————————————————————————————*/
	
	//
	// Integer types
	//
	template<typename Tp>
	struct is_integeral
	{
		enum { value = 0 };
		typedef false_type type;
	};
	
	template<>
	struct is_integeral<bool>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
	template<>
	struct is_integeral<char>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
	template<>
	struct is_integeral<signed char>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
	template<>
	struct is_integeral<unsigned char>
	{
		enum { value = 1 };
		typedef true_type type;
	};


	template<>
	struct is_integeral<wchar_t>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integeral<short>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
	template<>
	struct is_integeral<unsigned short>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
	template<>
	struct is_integeral<int>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
	template<>
	struct is_integeral<unsigned int>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
	template<>
	struct is_integeral<long>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
	template<>
	struct is_integeral<unsigned long>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
	template<>
	struct is_integeral<long long>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
	template<>
	struct is_integeral<unsigned long long>
	{
		enum { value = 1 };
		typedef true_type type;
	};
	
};

#endif //IS_INTEGRAL_HPP
