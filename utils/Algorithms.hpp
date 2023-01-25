#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

namespace ft {
	/**—————————————————————————————————————————————————————————————————————————————————**/
	/**
	**  @brief Compares two ranges of elements lexicographically.
	**  Compares the elements in the ranges [first1, last1) and [first2, last2) using the < operator,
	**  and returns true if the first range is lexicographically less than the second range.
	**
	**  @tparam It1 Type of the input iterators for the first range.
	**  @tparam It2 Type of the input iterators for the second range.
	**  @param first1 Iterator pointing to the first element of the first range.
	**  @param last1 Iterator pointing one past the last element of the first range.
	**  @param first2 Iterator pointing to the first element of the second range.
	**  @param last2 Iterator pointing one past the last element of the second range.
	**
	**  @return true if the first range is lexicographically less than the second range, false otherwise
	*/
	/**—————————————————————————————————————————————————————————————————————————————————**/
	/**
	 **  @NOTE:
	 **  ======
	 **  In the end, the statement return (first1 == last1 && first2 != last2);
	 **  that is used to check if the first range is shorter than the second range
	 **  and thus lexicographically less than the second range.
	 **
	 **  If both these conditions are true,
	 **  it means that the first range is shorter than the second range,
	 **  hence the function returns true.
	 **
	 */
	 /**—————————————————————————————————————————————————————————————————————————————————**/
	template< class It1, class It2 >
	inline bool
	lexicographical_compare( It1 first1, It1 last1,
								  It2 first2, It2 last2 ) {
		while (first1 != last1 && first2 != last2) {
			if (*first1 < *first2)
				return true;
			else if (*first2 < *first1)
				return false;
			++first1;
			++first2;
		}
		return (first1 == last1 && first2 != last2);
	}
	/**—————————————————————————————————————————————————————————————————————————————————**/
};

#endif //ALGORITHMS_HPP
