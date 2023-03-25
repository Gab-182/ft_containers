#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iostream>
# include <memory>		// For the (allocator) object
# include <cstddef>		// for ptrdiff_t
# include <exception>

# include "../includes/utils/enable_if.hpp"
# include "../includes/utils/is_integral.hpp"
# include "../includes/utils/Algorithms.hpp"
# include "../includes/iterator/iterator.hpp"
# include "../includes/iterator/iterator_traits.hpp"
# include "../includes/iterator/reverse_iterator.hpp"
/*=============================================================================================================*/
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector 
	{
		/**
		 ** @Member_types_"Aliases" */
		public:
			typedef				T										value_type;
			typedef				Alloc									allocator_type;
			typedef	typename 	allocator_type::reference				reference;
			typedef	typename	allocator_type::pointer					pointer;
			typedef	typename	allocator_type::const_pointer			const_pointer;
			typedef	typename	allocator_type::const_reference			const_reference;
			typedef	typename	allocator_type::difference_type			difference_type;
			typedef	typename	allocator_type::size_type				size_type;

		/*===============================[ Iterator_types ]=====================================*/
		public:
			typedef				ft::iterator<value_type>				iterator;
			typedef				ft::iterator<const value_type>			const_iterator;
			typedef				ft::reverse_iterator<iterator>			reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		/**======================================================================================
		 ** @Private_members */
		private:
			pointer					_array;
			size_type				_size;
			size_type				_capacity;
			allocator_type			_allocator;
	
	public:
			/*——————————————————————————————————————————————————————————————————————————————————————*
			—————————————————————————————————[Member functions]——————————————————————————————————————
			—————————————————————————————————————————————————————————————————————————————————————————
			**
		**  🟢 1) Empty constructor
		**  🟢 2) Fill constructor
		**  🟢 3) Range constructor
		**  🟢 4) Copy constructor
		**  🟢 5) Destructor
		**  🟢 6) Assignment operator
		**  🟢 7) assign()
		**  🟢 8) get_allocator()
		**
		**/
		/**—————————————————[ empty constructor ]——————————————————————————*
		**  @brief  Creates a vector with no elements.
		**  @param  alloc  An allocator object.
		*/
		explicit
		vector (const allocator_type& alloc = allocator_type())
			: _array(NULL), _size(0), _capacity(0), _allocator(alloc) {};
		
		/**—————————————————[ fill constructor ]———————————————————————————*
		**  @brief  Creates a vector with copies of an exemplar element.
		**  @param  n  The number of elements to initially create.
		**  @param  val  An element to copy.
		**  @param  alloc  An allocator.
		**
		**  This constructor fills the vector with n copies of val.
		*/
		explicit
		vector (size_type n,
						const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) {
			_allocator = alloc;
			_size = n;
			_capacity = n;
			_array = _allocator.allocate(_capacity); // **[Note]
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&_array[i], val); // **[Note]
		}
		
		/**—————————————————[ range constructor ]—————————————————————————*
		**  @brief  Builds a vector from a range.
		**  @param  first  An input iterator.
		**  @param  last  An input iterator.
		**  @param  alloc  An allocator.
		**
		**  Create a vector consisting of copies of the elements from
		**  [first,last).
		**
		**  If the iterators are forward, bidirectional, or
		**  random-access, then this will call the elements' copy
		**  constructor N times (where N is distance(first,last)) and do
		**  no memory reallocation.  But if only input iterators are
		**  used, then this will do at most 2N calls to the copy
		**  constructor, and logN memory re-allocations.
		 *
		 * @NOTE how to use enable_if with overloads:
		 * ==========================================
		 * [https://stackoverflow.com/questions/38908260/how-to-use-enable-if-with-overloads].
		*/
		template <class Iterator>
		vector (Iterator first,
				Iterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<Iterator>::value, Iterator>::type* = 0) {
			_allocator = alloc;
			_size = 0;
			_capacity = 0;
			_array = NULL;
			assign(first, last);
		}
		
		/**—————————————————[ copy constructor ———————————————————————————*
		**  @brief  Vector copy constructor.
		**  @param  vec  A vector of identical element and allocator types.
		**
		**  All the elements of vec are copied, but any unused capacity in
		**  vec  will not be copied
		**  (i.e. capacity() == size() in the new vector).
		**
		**  The newly-created vector uses a copy of the allocator object used
		**  by vec (unless the allocator traits dictate a different object).
		*/
		vector (const vector& vec) {
			_allocator = vec._allocator;
			_size = vec._size;
			_capacity = vec._size;
			_array = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&_array[i], vec._array[i]);
		}

		/**—————————————————————[ destructor ]————————————————————————————*
		**  The dtor only erases the elements, and note that if the
		**  elements themselves are pointers, the pointed-to memory is
		**  not touched in any way.  Managing the pointer is the user's
		**  responsibility.
		*/
		~vector() {
			_allocator.deallocate(_array, _capacity);
		}

		/**————————————————————[ operator= ]——————————————————————————————*
		**  @brief  Vector assignment operator.
		**  @param  vec  A vector of identical element and allocator types.
		**
		**  All the elements of vec are copied, but any unused capacity in
		**  vec will not be copied.
		**
		**  Whether the allocator is copied depends on the allocator traits.
		*/
		vector&
		operator= (const vector& vec) {
			if (this == &vec)
				return (*this);
			_allocator = vec._allocator;
			_size = vec._size;
			_capacity = vec._size;
			_array = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&_array[i], vec._array[i]);
			return (*this);
		}
		
		/**————————————————————[ assign ]—————————————————————————————————*
		**  @brief  Assigns a given value to a vector.
		**  @param  n  Number of elements to be assigned.
		**  @param  val  Value to be assigned.
		**
		**  This function fills a vector with n copies of the given
		**  value.
		**  Note that the assignment completely changes the
		**  vector and that the resulting vector's size is the same as
		**  the number of elements assigned.
		**/
		void
		assign (size_type n, const value_type& val) {
			/**
			 **  NOTE --> {diff between destroy & deallocate}
			 **  A question answered from slack, on the resources page.
			 **  _allocator.destroy(_array);
			 **/
			_allocator.deallocate(_array, _capacity);
			_size = n;
			_capacity = _size;
			_array = _allocator.allocate(n);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&_array[i], val);
		}
		
		/**———————————————————————————————————————————————————————————*/
	private:
		template<class InputIterator>
		difference_type
		distance (InputIterator first, InputIterator last)
		{
			difference_type rtn = 0;
			while (first != last)
			{
				first++;
				rtn++;
			}
			return (rtn);
		}
		
	public:
		/**———————————————————————————————————————————————————————————*
		**  @brief  Assigns a range to a vector.
		**  @param  first  An input iterator.
		**  @param  last   An input iterator.
		**
		**  This function fills a vector with copies of the elements in the
		**  range [first, last).
		**
		**  Note that the assignment completely changes the vector and
		**  that the resulting vector's size is the same as the number
		**  of elements assigned.
		*/
		template <class Iter>
		void
		assign (Iter first,
				Iter last,
				typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = 0) {
			_allocator.deallocate(_array, _capacity);
			_size = distance(first, last);
			_capacity = _size;
			_array = _allocator.allocate(_size);
			
			size_type i = 0;
			for (;first != last; ++first)
				_allocator.construct(&_array[i++], *first);
		}

		/**————————————————————[ get_allocator ]——————————————————————————
		 ** @brief  Returns a copy of the memory allocation object.
		 **/
		allocator_type
		get_allocator() const {
			return (_allocator);
		}
		
		/*——————————————————————————————————————————————————————————————————————————————————————*
		—————————————————————————————————————[Iterators]—————————————————————————————————————————
		—————————————————————————————————————————————————————————————————————————————————————————
		**
		**  🟢 1) begin()
		**  🟢 2) end()
		**  🟢 3) rbegin()
		**  🟢 4) rend()
		**/
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read/write iterator that points to the first
		**  element in the vector.  Iteration is done in ordinary
		**  element order.
		*/
		iterator
		begin() {
			return (iterator(_array));
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read-only (constant) iterator that points to the
		**  first element in the vector.  Iteration is done in ordinary
		**  element order.
		*/
		const_iterator
		begin() const {
			return (const_iterator(_array));
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read/write iterator that points one past the last
		**  element in the vector.  Iteration is done in ordinary
		**  element order.
		**! NOTE !
		**!======!
		*** end(), rbegin() iterators (are valid iterators,
		*** but they are not de-reference-able) */
		iterator
		end() {
			return (iterator(_array + _size));
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read-only (constant) iterator that points one past
		**  the last element in the vector.  Iteration is done in
		**  ordinary element order.
		*/
		const_iterator
		end() const {
			return (iterator(_array + _size));
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read/write reverse iterator that points to the
		**  last element in the vector.  Iteration is done in reverse
		**  element order.
		*/
		reverse_iterator
		rbegin() {
			return (reverse_iterator(end()));
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read-only (constant) reverse iterator that points
		**  to the last element in the vector.  Iteration is done in
		**  reverse element order.
		*/
		const_reverse_iterator
		rbegin() const {
			return (const_reverse_iterator(end()));
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read/write reverse iterator that points to one
		**  before the first element in the vector.  Iteration is done
		**  in reverse element order.
		*/
		reverse_iterator
		rend() {
			return (reverse_iterator(begin()));
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read-only (constant) reverse iterator that points
		**  to one before the first element in the vector.  Iteration
		**  is done in reverse element order.
		*/
		const_reverse_iterator
		rend() const {
			return (const_reverse_iterator(begin()));
		}
		
		/*——————————————————————————————————————————————————————————————————————————————————————*
		——————————————————————————————————————[Capacity]—————————————————————————————————————————
		—————————————————————————————————————————————————————————————————————————————————————————
		**
		**  🟢 1) size
		**  🟢 2) max_size
		**  🟢 3) capacity
		**  🟢 4) resize
		**  🟢 5) empty
		**  🟢 6) reserve
		**  🟢 7) clear
		**
		**/
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  The number of elements in the vector.
		**  */
		size_type
		size() const {
			return (_size);
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  The size() of the largest possible %vector.
		**  */
		size_type
		max_size() const {
			return (_allocator.max_size());
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  The total number of elements that the vector can
		**  hold before needing to allocate more memory.
		*/
		size_type
		capacity() const {
			return (_capacity);
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @brief  Resizes the vector to the specified number of
		** elements.
		**  @param  n  Number of elements the vector should contain.
		**  @param  val  Data with which new elements should be populated.
		**
		**  This function will resize the vector to the specified
		**  number of elements.  If the number is smaller than the
		**  vector's current size the vector is truncated, otherwise
		**  the vector is extended and new elements are populated with
		**  given data.
		*/
		void
		resize (size_type n, value_type val = value_type()) {
			while (n < _size)
				pop_back();
			while (n > _size)
				push_back(val);
			if (n > _capacity)
				reserve(n);
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  True if the vector is empty.  (Thus begin() would
		**  equal end().)
		*/
		bool
		empty() const {
			return (begin()== end());
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @brief  Attempt to preallocate enough memory for specified
		** 			number of elements.
		**  @param  n  Number of elements required.
		**  @throw  std::length_error  If  n exceeds  max_size().
		**
		**  This function attempts to reserve enough memory for the
		**  vector to hold the specified number of elements.  If the
		**  number requested is more than max_size(), length_error is
		**  thrown.
		*/
		void
		reserve (size_type n) {
			if (n > max_size())
				throw std::length_error("Length error");
			if (n > _capacity) {
				pointer temp_array = _allocator.allocate(n);
			for (size_type i = 0; i < _size; i++) {
				_allocator.construct(&temp_array[i], _array[i]);
			}
			_allocator.deallocate(_array, _capacity);
			_array = temp_array;
			_capacity = n;
			}
		}
		
		/**———————————————————————————————————————————————————————————*
		**  Erases all the elements.  Note that this function only
		**  erases the elements, and that if the elements themselves are
		**  pointers, the pointed-to memory is not touched in any way.
		**  Managing the pointer is the user's responsibility.
		*/
		void
		clear() {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(&_array[i]);
			_size = 0;
		}
		/*——————————————————————————————————————————————————————————————————————————————————————*
		——————————————————————————————————[Elements access]——————————————————————————————————————
		—————————————————————————————————————————————————————————————————————————————————————————
		**
		** 🟢 1) at
		** 🟢 2) operator[]
		** 🟢 3) front
		** 🟢 4) back
		** 🟢 5) data
		**
		**/
		/**———————————————————————————————————————————————————————————*
		**  @brief  Provides access to the data contained in the vector.
		**  @param pos The index of the element for which data should be
		**  accessed.
		**  @return  Read/write reference to data.
		**  @throw  std::out_of_range  If pos is an invalid index.
		**
		**  This function provides for safer data access.  The parameter
		**  is first checked that it is in the range of the vector.  The
		**  function throws out_of_range if the check fails.
		*/
		reference
		at( size_type pos ) {
			if (pos >= _size)
				throw std::out_of_range("out of range");
			return (_array[pos]);
		}
		
		/**———————————————————————————————————————————————————————————*
		 * @brief Provides access to the data contained in the vector.
		**  @param pos The index of the element for which data should be
		**  accessed.
		**  @return  Read/write reference to data.
		**  @throw  std::out_of_range  If pos is an invalid index.
		**
		**  This function provides for safer data access.  The parameter
		**  is first checked that it is in the range of the vector.  The
		**  function throws out_of_range if the check fails.
		*/
		const_reference
		at(size_type pos) const {
			if (pos >= _size)
				throw std::out_of_range("out of range");
			return (_array[pos]);
		}
		/**———————————————————————————————————————————————————————————*
		**  @brief  Subscript access to the data contained in the vector.
		**  @param pos The index of the element for which data should be
		**  accessed.
		**  @return  Read-only (constant) reference to data.
		**
		**  This operator allows for easy, array-style, data access.
		**  Note that data access with this operator is unchecked and
		**  out_of_range lookups are not defined. (For checked lookups
		**  see at().)
		**/
		reference
		operator[] (size_type pos) const {
			// make sure that the index is not out of range or negative
			if (pos >= _size || pos < 0)
				throw std::out_of_range("out of range");
			return (_array[pos]);
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read/write reference to the data at the first
		**  element of the vector.
		*/
		reference
		front() {
			// make sure that the vector is not empty
			if (_size == 0)
				throw std::out_of_range("out of range");
			return (_array[0]);
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read-only (constant) reference to the data at the first
		**  element of the vector.
		*/
		const_reference
		front() const {
			// make sure that the vector is not empty
			if (_size == 0)
				throw std::out_of_range("out of range");
			return (_array[0]);
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read/write reference to the data at the last
		**  element of the %vector.
		*/
		reference
		back() {
			// make sure that the vector is not empty
			if (_size == 0)
				throw std::out_of_range("out of range");
			return (_array[_size - 1]);
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a read-only (constant) reference to the data at the
		**  last element of the vector.
		*/
		const_reference
		back() const {
			// make sure that the vector is not empty
			if (_size == 0)
				throw std::out_of_range("out of range");
			return (_array[_size - 1]);
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @returns
		**  a pointer such that [data(), data() + size()) is a valid
		**  range.  For a non-empty vector, data() == &front().
		*/
		pointer
		data() {
			if (_size == 0)
				return (NULL);
			return (&front());
		}
		
		/**———————————————————————————————————————————————————————————*/
		const_pointer
		data() const {
			if (_size == 0)
				return (NULL);
			return (&front());
		}
		
		/*——————————————————————————————————————————————————————————————————————————————————————*
		———————————————————————————————————————[Modifies]————————————————————————————————————————
		—————————————————————————————————————————————————————————————————————————————————————————
		**
		**  🟢 1) push_back
		**  🟢 2) pop_back
		**  🟢 3) swap
		**  🟢 4) erase
		**  🟢 5) insert
		**
		**/
		/**———————————————————————————————————————————————————————————*
		**  @brief  Add data to the end of the vector.
		**  @param  val  Data to be added.
		**
		**  This is a typical stack operation.  The function creates an
		**  element at the end of the vector and assigns the given data
		**  to it.
		*/
		void
		push_back (const value_type& val) {
			if (_size + 1 > _capacity) {
				if (_capacity == 0)
					reserve(1);
				else
					reserve(_capacity * 2);
			}
			_allocator.construct(&_array[_size], val);
			_size++;
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @brief  Removes last element.
		**  It shrinks the vector by one.
		*/
		void
		pop_back() {
			_allocator.destroy(_array + (_size - 1));
			_size--;
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @brief  Swaps data with another vector.
		**  @param  vec  A vector of the same element and allocator
		** types.
		**
		**  This exchanges the elements between two vectors in constant
		** time.
		*/
		void
		swap(vector& vec) {
			size_type temp_size = _size;
			size_type temp_capacity = _capacity;
			pointer temp_array = _array;
			
			_size = vec._size;
			_capacity = vec._capacity;
			_array = vec._array;
			
			vec._size = temp_size;
			vec._capacity = temp_capacity;
			vec._array = temp_array;
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @brief  Remove element at given position.
		**  @param  pos  Iterator pointing to element to be erased.
		**  @return  An iterator pointing to the next element (or end()).
		**
		**  This function will erase the element at the given position
		** and thus shorten the vector by one.
		**/
		iterator
		erase(iterator pos) {
			if (pos == end())
				return (pos);
			_allocator.destroy(pos.base());
			for (iterator it = pos; it != end() - 1; it++)
				*it = *(it + 1);
			--_size;
			return (pos);
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @brief  Remove a range of elements.
		**  @param  first  Iterator pointing to the first element to be erased.
		**  @param  last  Iterator pointing to one past the last element to be
		**                  erased.
		**  @return  An iterator pointing to the element pointed to by last
		**           prior to erasing (or end()).
		**
		**  This function will erase the elements in the range
		**  [first, last) and shorten the vector accordingly.
		**/
		iterator
		erase( iterator first, iterator last ) {
			for (iterator it = first; it != end() - (last - first); it++)
				*it = *(it + (last - first));
			for (iterator it = first; it != last; it++) {
				_allocator.destroy(it.base());
				--_size;
			}
			return (first);
		}
		
		/**———————————————————————————————————————————————————————————*
		**  @brief  Inserts given value into vector before specified iterator.
		**  @param  position  An iterator into the vector.
		**  @param  val  Data to be inserted.
		**  @return  An iterator that points to the inserted data.
		**
		**  This function will insert a copy of the given value before
		**  the specified location.
		**
		**  @Note:
		**  		Because vectors use an array as their underlying storage,
		**  		inserting elements in positions other than the vector end
		**  		causes the container to relocate all the elements that were
		**  		after position to their new positions.
		**  		This is generally an inefficient operation compared to the
		**  		one performed for the same operation by other kinds of sequence
		**  		containers (such as list or forward_list).
		*/
		iterator
		insert (iterator position, const value_type& val) {
			difference_type val_index = distance(begin(), position);
			if (_size == 0)
				reserve(1);
			else if (_size == _capacity)
				reserve(_capacity * 2);
			for (size_type i = val_index + 1; i <= _size; i++)
				std::swap(_array[val_index], _array[i]);
			_allocator.construct(&_array[val_index], val);
			_size++;
			return position;
		}
		
		/**———————————————————————————————————————————————————————————*
		 **  @brief  Inserts a number of copies of given data into the vector.
		 **  @param  position  An iterator into the vector.
		 **  @param  n  Number of elements to be inserted.
		 **  @param  val  Data to be inserted.
		 **
		 **  This function will insert a specified number of copies of
		 **  the given data before the location specified by position.
		 **
		 ** @Note:
		 **  		Because vectors use an array as their underlying storage,
		 **  		inserting elements in positions other than the vector end
		 **  		causes the container to relocate all the elements that were
		 **  		after position to their new positions.
		 **  		This is generally an inefficient operation compared to the
		 **  		one performed for the same operation by other kinds of sequence
		 **  		containers (such as list or forward_list).
		 */
		void
		insert (iterator position, size_type n, const value_type& val) {
			// get the index of the new element
			difference_type val_index = distance(begin(), position);
			
			// if the vector is empty, reserve (n) spaces
			if (_size == 0)
				reserve(n);
			// if the vector is not empty, but there is not enough space
			else if ((_size + n) > _capacity)
					reserve(_size + n);
			// move all elements after the position to the right, starting from the end.
			for (difference_type i = _size - 1; i >= val_index; i--)
				_allocator.construct(&_array[i + n], _array[i]);

			// insert (n) elements at the position
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(&_array[val_index], val);
				val_index++;
			}
			_size += n;
		}
		
		/**———————————————————————————————————————————————————————————*
		 **  @brief  Inserts a range into the %vector.
		 **  @param  position  An iterator into the %vector.
		 **  @param  first  An input iterator.
		 **  @param  last   An input iterator.
		 **
		 **  This function will insert copies of the data in the range
		 **  [first, last) into the vector before the location specified
		 **  by position.
		 **
		 **  @Note:
		 **  		Because vectors use an array as their underlying storage,
		 **  		inserting elements in positions other than the vector end
		 **  		causes the container to relocate all the elements that were
		 **  		after position to their new positions.
		 **  		This is generally an inefficient operation compared to the
		 **  		one performed for the same operation by other kinds of sequence
		 **  		containers (such as list or forward_list).
		 *
		 ** NOTE:
		 * ======-----------------------------------------------------------
		 **  the use of long long in this example is a way to ensure that
		 **  the code works correctly and predictably on different systems,
		 **  regardless of the size of the difference_type.
		 * ------------------------------------------------------------------
		 */
		template <class Iter>
		void
		insert (iterator position, Iter first, Iter last,
				typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = 0) {
			
			// get the index of the new element
			difference_type value_index = distance(begin(), position);
			// get the number of elements to insert
			difference_type range = distance(first, last);
			
			// static_cast the index to size_t.
			long long index = static_cast<long long>(value_index);
			// static_cast the range to size_t.
			size_t n = static_cast<size_t>(range);
			
			// if the vector is empty, reserve (n) spaces
			if (_size == 0)
				reserve(n);
			// if the vector is not empty, but there is not enough space:
			// reserve the maximum between (_size + n) and (_capacity * 2)
			else if ((_size + n) > _capacity)
				reserve(std::max(_size + n, _capacity * 2));
			
			// move all elements after the position to the right, starting from the end.
			for (long long i = _size - 1; i >= index; i--)
				_allocator.construct(&_array[i + n], _array[i]);
			
			// insert (n) elements at the position
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(&_array[index++], *first);
				first++;
			}
			
			// increase the size of the vector
			_size += n;
		}
		/**—————————————————————————————————————————————————————————————————————————————*/
	}; // vector
	
	/*——————————————————————————————————————————————————————————————————————————————————————*
	——————————————————————————————————[Non Member Functions]—————————————————————————————————
	—————————————————————————————————————————————————————————————————————————————————————————
	**
	**  1) 🟢 operator==
	**  2) 🟢 operator!=
	**  3) 🟢 operator<
	**  4) 🟢 operator<=
	**  5) 🟢 operator>
	**  6) 🟢 operator>=
	**  7) 🟢 swap
	**/
	/**—————————————————————————————————————————————————————————————————————————————————**/
	/**
	 * @Note:
	 * Cause _size is private, we can't use it in the operator==.
	 * So, we need to use the size() method.
	 */
	template <class T, class Alloc>
	inline bool
	operator== (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		if (lhs.size() == rhs.size()) {
			for (size_t i = 0; i < lhs.size(); i++) {
				if (lhs[i] != rhs[i])
					return (false);
			}
			return (true);
		}
		return (false);
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class T, class Alloc>
	inline bool
	operator!= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return (!(lhs == rhs));
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class T, class Alloc>
	inline bool
	operator!= (const typename ft::vector<T>::iterator& lhs, const typename ft::vector<T>::const_iterator& rhs) {
		return (!(lhs == rhs));
	}
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class T, class Alloc>
	inline bool
	operator< (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(),
											rhs.begin(), rhs.end());
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	/**
	 * @Note: return (!(rhs < lhs));
	 * =============================
	 * 1) if rhs > lhs, return true
	 * 2) if rhs == lhs, return true
	 * otherwise, return false.
	 *
	 * The function simply negates the result of the comparison using the ! operator.
	 * If the comparison returns true, the function will return false,
	 * and if the comparison returns false, the function will return true.
	 */
	template <class T, class Alloc>
	inline bool
	operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return (!(rhs < lhs));
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class T, class Alloc>
	inline bool
	operator> (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return (rhs < lhs);
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	/**
	 * @Note: return (!(rhs < lhs));
	 * =============================
	 * The function simply negates the result of the comparison using the ! operator.
	 * If the comparison returns true, the function will return false,
	 * and if the comparison returns false, the function will return true.
	 */
	template <class T, class Alloc>
	inline bool
	operator>= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return (!(lhs < rhs));
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	template <class T, class Alloc>
	inline void
	swap(ft::vector<T, Alloc>& vec1, ft::vector<T, Alloc>& vec2) {
		vec1.swap(vec2);
	}
	
	/**—————————————————————————————————————————————————————————————————————————————————**/
	
}// namespace ft

/*=============================================================================================================*/
#endif //!FT_VECTOR_HPP