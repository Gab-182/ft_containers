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

			// The type of a reference to an element in the container (T&) or allocator_type::reference:
			// cause (allocator_type::reference) is a reference to (T)
			typedef		typename	allocator_type::reference				reference;
			typedef		typename	allocator_type::const_reference			const_reference;

			typedef		typename	allocator_type::pointer					pointer;
			typedef		typename	allocator_type::const_pointer			const_pointer;
	
			typedef					ptrdiff_t							difference_type;
			typedef		typename	allocator_type::size_type				size_type;
		/*-------------------------------------------------------------------------------------------*/
		private:
			pointer					_array;
			size_type				_size;
			size_type				_capacity;
			allocator_type			_allocator;
		/*-------------------------------------------------------------------------------------------*/
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

			size_type	max_size() const {
				return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			}
			/*_______________________________________________________________________________________*/
			/*------------------------------[Element access]-----------------------------------------*/


			/*_______________________________________________________________________________________*/
			/*------------------------------[Modifiers]-----------------------------------------------*/


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