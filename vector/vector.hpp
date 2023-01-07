#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>		// For the (allocator) object
# include <limits>		// for max_size()
#include <cstddef>		// for ptrdiff_t
/*=============================================================================================================*/
namespace ft
{
/*---------------------------------------------------------------------------------------------------*/
	template < class T, class Alloc = std::allocator<T> >
	class vector 
	{
		/*-------------------------------------------------------------------------------------------*/
		/**
		 ** Member types 
		 */
		public:
			typedef					T										value_type;
			typedef					Alloc									allocator_type;
			typedef					value_type&								reference;
			typedef					const value_type&						const_reference;
			typedef					value_type*								
			pointer;
			typedef					const value_type*						const_pointer;
			typedef					ptrdiff_t								difference_type;
			typedef					size_t									size_type;

		/**
		 ** Private members
		 */
		private:
			pointer					_array;
			size_type				_size;
			size_type				_capacity;
			allocator_type			_allocator;

		/**
		 ** Member functions
		 */
		public:
			/*_______________________________________________________________________________________*/
			/*---------------------------[Empty Constructor]-----------------------------------------*/
			explicit vector (const allocator_type& alloc = allocator_type()) {
				_allocator = alloc;
				_size = 0;
				_capacity = 0;
				_array = NULL;
			}

			/*_______________________________________________________________________________________*/
			/*---------------------------[Fill Constructor]------------------------------------------*/
			explicit vector (size_type n,
							const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()) {
				_allocator = alloc;
				_size = n;
				_capacity = n;
				_array = _allocator.allocate(_capacity); // **[Note]
				for (size_type i = 0; i < n; i++)
					_allocator.construct(&_array[i], val); // **[Note]
			}
			/*_______________________________________________________________________________________*/
			/*---------------------------[Range Constructor]-----------------------------------------*/


			/*_______________________________________________________________________________________*/
			/*---------------------------[Copy Constructor]------------------------------------------*/
			vector (const vector& vec) {
				_allocator = vec._allocator;
				_size = vec._size;
				_capacity = vec._capacity;
				_array = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_array[i], vec._array[i]);
			}

			/*_______________________________________________________________________________________*/
			/*------------------------------[Destructor]---------------------------------------------*/
			~vector() {
				_allocator.deallocate(_array, _capacity);
			}
			/*_______________________________________________________________________________________*/
			/*------------------------------[Assignation]--------------------------------------------*/
			vector& operator= (const vector& vec) {
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
			/*_______________________________________________________________________________________*/
			/*------------------------------[Iterators]----------------------------------------------*/

			/*_______________________________________________________________________________________*/
			/*------------------------------[Capacity]-----------------------------------------------*/
			size_type	size() const {
				return (_size);
			}

			/*_______________________________________________________________________________________*/
			/*------------------------------[Element access]-----------------------------------------*/


			/*_______________________________________________________________________________________*/
			/*------------------------------[Modifiers]-----------------------------------------------*/
			void	push_back (const value_type& val) {
				if (_size + 1 > _capacity) {
					pointer tmp = _allocator.allocate(_capacity + sizeof(value_type));
					for (size_type i = 0; i < _size; i++)
						_allocator.construct(&tmp[i], _array[i]);
					_allocator.deallocate(_array, _capacity);
					_array = tmp;
					_capacity += sizeof(value_type);
				}
				_allocator.construct(&_array[_size], val);
				_size++;
			}
			/*_______________________________________________________________________________________*/
			void	pop_back() {
				_allocator.destroy(&_array[_size - 1]);
				_size--;
			}
			/*_______________________________________________________________________________________*/

			/*_______________________________________________________________________________________*/
			void	clear() {
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(&_array[i]);
				_size = 0;
			}
			
			/*_______________________________________________________________________________________*/
			/*------------------------------[Operations]---------------------------------------------*/

			/*---------------------------------------------------------------------------------------*/
		reference	operator[] (size_type n) {
			return (_array[n]);
		}
	};
}

/*=============================================================================================================*/
#endif