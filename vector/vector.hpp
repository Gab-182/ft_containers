#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iostream>
# include <memory>		// For the (allocator) object
# include <cstddef>		// for ptrdiff_t
# include <exception>

# include "../iterator/iterator.hpp"
# include "../iterator/iterator_traits.hpp"
# include "../iterator/reverse_iterator.hpp"
/*=============================================================================================================*/
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector 
	{
		/**
		 ** @Member_types_"Aliases" */
		public:
			typedef					T										value_type;
			typedef					Alloc									allocator_type;
			typedef	typename 		allocator_type::reference				reference;
			typedef	typename		allocator_type::pointer					pointer;
			typedef	typename		allocator_type::const_pointer			const_pointer;
			typedef	typename		allocator_type::const_reference			const_reference;
			typedef	typename		allocator_type::difference_type			difference_type;
			typedef	typename		allocator_type::size_type				size_type;

		/*================================[ Iterator_types ]=====================================*/
		public:
			typedef					ft::iterator<value_type>				iterator;
			typedef					ft::iterator<const value_type>			const_iterator;
			typedef					ft::reverse_iterator<iterator>			reverse_iterator;
			typedef					ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		/**=======================================================================================
		 ** @Private_members */
		private:
			pointer					_array;
			size_type				_size;
			size_type				_capacity;
			allocator_type			_allocator;

		/**
		 **==============================[ Member_functions ]==================================*/
		public:
			/**=========================[ empty constructor ]==================================*/
			explicit
			vector (const allocator_type& alloc = allocator_type())
				: _array(NULL), _size(0), _capacity(0), _allocator(alloc) {};
			/**=========================[ fill constructor ]==================================*/
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
			/**=========================[ range constructor ]==================================*/
			/**
			 * * @TODO: vector() ---> RANGE CONSTRUCTOR
			 * * @TODO: assign()
			 * * @TODO: get_allocator()
			 * * @TODO: Non member functions .

			 * * @TODO: Calculate time spent by my containers and compare it to the STL containers.
			 * * @TODO: Calculate the memory used by my containers and compare it to the STL containers.
			 * * @TODO: Check if my containers are exception safe.
			 * * @TODO: Calculate the number of instructions executed by my containers and compare it to the STL containers.
			 * */
			/**=========================[ copy constructor ]==================================*/
			vector (const vector& vec) {
				_allocator = vec._allocator;
				_size = vec._size;
				_capacity = vec._capacity;
				_array = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_array[i], vec._array[i]);
			}

			/**=========================[ destructor ]==================================*/
			~vector() {
				_allocator.deallocate(_array, _capacity);
			}

			/**=========================[ operator= ]==================================*/
			vector&
			operator= (const vector& vec) {
				if (this == &vec)
					return (*this);
				_allocator = vec._allocator;
				_size = vec._size;
				_capacity = vec._capacity;
				_array = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_array[i], vec._array[i]);
				return (*this);
			}

			/**=========================[ Iterators ]==================================*/
			iterator
			begin() {
				return (iterator(_array));
			}
			/**_________________________________________________________*/
			/**
			 * @return
			 ** an object of the const_iterator class that is
			 ** initialized with the member variable _array.
			 */
			const_iterator
			begin() const {
				return (const_iterator(_array));
			}
			/**_________________________________________________________*/
			/**
			 *! NOTE !
			 *!======!
			 ** end(), rbegin() iterators (are valid iterators,
			 ** but they are not de-reference-able) */

			iterator
			end() {
				return (iterator(_array + _size));
			}
			/**_________________________________________________________*/
			const_iterator
			end() const {
				return (iterator(_array + _size));
			}
			/**_________________________________________________________*/
			reverse_iterator
			rbegin() {
				return (reverse_iterator(end()));
			}
			/**_________________________________________________________*/
			const_reverse_iterator
			rbegin() const {
				return (const_reverse_iterator(end()));
			}
			/**_________________________________________________________*/
			reverse_iterator
			rend() {
				return (reverse_iterator(begin()));
			}
			/**_________________________________________________________*/
			const_reverse_iterator
			rend() const {
				return (const_reverse_iterator(begin()));
			}

			/**=========================[ Capacity ]==================================*/
			size_type
			size() const {
				return (_size);
			}
			/**_________________________________________________________*/
			size_type
			max_size() const {
				return (_allocator.max_size());
			}
			/**_________________________________________________________*/
			size_type
			capacity() const {
				return (_capacity);
			}
			/**_________________________________________________________*/
			/**
			 **  @brief  Resizes the vector to the specified number of elements.
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
			/**_________________________________________________________*/
			bool
			empty() const {
				if (_size == 0)
					return (true);
				return (false);
			}
			/**_________________________________________________________*/
			/**
			 **  @brief  Attempt to preallocate enough memory for specified
			 * 			number of elements.
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

			/**=========================[ Element access ]==================================*/
			reference
			at( size_type pos ) {
				if (pos >= _size)
					throw std::out_of_range("out of range");
				return (_array[pos]);
			};
			/**_________________________________________________________*/
			reference
			operator[] (size_type pos) {
				if (pos >= _size)
					throw std::out_of_range("out of range");
				return (_array[pos]);
			}
			/**_________________________________________________________*/
			reference
			front() {
				if (_size == 0)
					throw std::out_of_range("out of range");
				return (_array[0]);
			}
			/**_________________________________________________________*/
			const_reference
			front() const {
				if (_size == 0)
					throw std::out_of_range("out of range");
				return (_array[0]);
			}
			/**_________________________________________________________*/
			reference
			back() {
				if (_size == 0)
					throw std::out_of_range("out of range");
				return (_array[_size - 1]);
			}
			/**_________________________________________________________*/
			const_reference
			back() const {
				if (_size == 0)
					throw std::out_of_range("out of range");
				return (_array[_size - 1]);
			}
			/**_________________________________________________________*/
			pointer
			data() {
				if (_size == 0)
					return (NULL);
				return (_array);
			}
			/**_________________________________________________________*/
			const_pointer
			data() const {
				if (_size == 0)
					return (NULL);
				return (_array);
			}
		/**===========================[ Modifiers ]=====================================*/
			/**
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
			/**_________________________________________________________*/
			/**
			**  @brief  Removes last element.
			**  It shrinks the vector by one.
			*/
			void
			pop_back() {
				_allocator.destroy(_array + (_size - 1));
				_size--;
			}
			/**_________________________________________________________*/
			/**
			 **  @brief  Swaps data with another vector.
			 **  @param  vec  A vector of the same element and allocator types.
			 **
			 **  This exchanges the elements between two vectors in constant time.
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
			/**_________________________________________________________*/
			void
			clear() {
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(&_array[i]);
				_size = 0;
			}
			/**_________________________________________________________*/
			/**
			 **  @brief  Remove element at given position.
			 **  @param  pos  Iterator pointing to element to be erased.
			 **  @return  An iterator pointing to the next element (or end()).
			 **
			 **  This function will erase the element at the given position and thus
			 **  shorten the vector by one.
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
			/**_________________________________________________________*/
			/**
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
				if (first == last)
					return (first);
				if (first == begin() && last == end()) {
					clear();
					return (end());
				}
				for (iterator it = first; it != last; it++)
					_allocator.destroy(it.base());
				for (iterator it = first; it != end() - (last - first); it++)
					*it = *(it + (last - first));
				_size = _size - (last - first);
				return (last);
			}
			/**_________________________________________________________*/
			/**
			 **  @brief  Inserts given value into vector before specified iterator.
			 **  @param  position  An iterator into the vector.
			 **  @param  val  Data to be inserted.
			 **  @return  An iterator that points to the inserted data.
			 **
			 **  This function will insert a copy of the given value before
			 **  the specified location.
			 *
			 * @Note:
			 * 		Because vectors use an array as their underlying storage,
			 * 		inserting elements in positions other than the vector end
			 * 		causes the container to relocate all the elements that were
			 * 		after position to their new positions.
			 * 		This is generally an inefficient operation compared to the
			 * 		one performed for the same operation by other kinds of sequence
			 * 		containers (such as list or forward_list).
			 */
			iterator
			insert (iterator position, const value_type& val) {
				// Since after reserve() the pointers for the iterators going to be lost;
				// so we need to save some values.
				difference_type val_pos = position - begin();
				
				if (_size == _capacity)
					reserve(_capacity * 2);
				
				for (size_type i = _size; i >= val_pos; i--) {
					/*
					 ** When adding the new value to the beginning
					 ** of the array (val_pos = 0)
					 ** then we break the loop to assign the new val.
					 **/
					if (val_pos == 0 && i == 0)
						break;
					_array[i] = _array[i - 1];
				}
				_array[val_pos] = val;
				_size++;
				return (position);
			}
			/**_________________________________________________________*/
			/**
			 **  @brief  Inserts a number of copies of given data into the vector.
			 **  @param  position  An iterator into the vector.
			 **  @param  n  Number of elements to be inserted.
			 **  @param  val  Data to be inserted.
			 **
			 **  This function will insert a specified number of copies of
			 **  the given data before the location specified by position.
			 *
			 * @Note:
			 * 		Because vectors use an array as their underlying storage,
			 * 		inserting elements in positions other than the vector end
			 * 		causes the container to relocate all the elements that were
			 * 		after position to their new positions.
			 * 		This is generally an inefficient operation compared to the
			 * 		one performed for the same operation by other kinds of sequence
			 * 		containers (such as list or forward_list).
			 */
			void
			insert (iterator position, size_type n, const value_type& val) {
				difference_type val_pos = position - begin();
				for (size_type to_fill = 0; to_fill < n; to_fill++) {
					if (_size == _capacity)
						reserve(_capacity * 2);
					for (size_type i = _size; i >= val_pos; i--) {
						if (val_pos == 0 && i == 0)
							break;
						_array[i] = _array[i - 1];
					}
					_array[val_pos] = val;
					_size++;
				}
			}
			/**_________________________________________________________*/
			/**
			 **  @brief  Inserts a range into the %vector.
			 **  @param  position  An iterator into the %vector.
			 **  @param  first  An input iterator.
			 **  @param  last   An input iterator.
			 **
			 **  This function will insert copies of the data in the range
			 **  [first, last) into the vector before the location specified
			 **  by position.
			 *
			 * @Note:
			 * 		Because vectors use an array as their underlying storage,
			 * 		inserting elements in positions other than the vector end
			 * 		causes the container to relocate all the elements that were
			 * 		after position to their new positions.
			 * 		This is generally an inefficient operation compared to the
			 * 		one performed for the same operation by other kinds of sequence
			 * 		containers (such as list or forward_list).
			 */
			template <class Iter>
			void
			insert (iterator position, Iter first, Iter last) {
				difference_type val_pos = position - begin();
				difference_type rng_iter = last - first;

				for (size_type to_fill = 0; to_fill < rng_iter; to_fill++) {
					if (_size == _capacity)
						reserve(_capacity * 2);
					for (size_type i = _size; i >= val_pos; i--) {
						if (val_pos == 0 && i == 0)
							break;
						_array[i] = _array[i - 1];
					}
					if (last > first) {
						_array[val_pos] = *(last-1);
						last--;
					}
					_size++;
				}
			}
			/**_________________________________________________________*/
	}; // vector
	
}// namespace ft

/*=============================================================================================================*/
#endif //!FT_VECTOR_HPP