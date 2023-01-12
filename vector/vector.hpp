#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iostream>
# include <memory>		// For the (allocator) object
# include <limits>		// for max_size()
# include <cstddef>		// for ptrdiff_t

# include <iterator>
# include "../iterator/iterator_traits.hpp"
# include "../iterator/iterator.hpp"
/*=============================================================================================================*/
namespace ft
{
/*---------------------------------------------------------------------------------------------------*/
	template < class T, class Alloc = std::allocator<T> >
	class vector 
	{
		/*-------------------------------------------------------------------------------------------*/
		/**
		 ** @Member_types_"Aliases"
		 */
		public:
			typedef					T										value_type;
			typedef					Alloc									allocator_type;
			typedef					value_type&								reference;
			typedef					value_type*								pointer;
			typedef					const value_type*						const_pointer;
			typedef					const value_type&						const_reference;
			typedef					ptrdiff_t								difference_type;
			typedef					size_t									size_type;

		/**
		 ** Iterator types
		 * */
//		public:
//			typedef					ft::iterator<std::random_access_iterator_tag , value_type>				iterator;
//			typedef					ft::iterator<const value_type>			const_iterator;
//			typedef					ft::reverse_iterator<iterator>			reverse_iterator;
//			typedef					ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		/**
		 ** @Private_members
		 */
		private:
			pointer					_array;
			size_type				_size;
			size_type				_capacity;
			allocator_type			_allocator;

		/**
		 ** @Member_functions
		 */
		public:
			/**-------------------------------[Empty Constructor]------------------------------------*/
			explicit vector (const allocator_type& alloc = allocator_type()) {
				_allocator = alloc;
				_size = 0;
				_capacity = 0;
		 		_array = NULL;
			}
			/**---------------------------[Fill Constructor]------------------------------------------*/
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
			/**---------------------------[Range Constructor]-----------------------------------------*/


			/**---------------------------[Copy Constructor]------------------------------------------*/
			vector (const vector& vec) {
				_allocator = vec._allocator;
				_size = vec._size;
				_capacity = vec._capacity;
				_array = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_array[i], vec._array[i]);
			}

			/**------------------------------[Destructor]---------------------------------------------*/
			~vector() {
				_allocator.deallocate(_array, _capacity);
			}
			/**------------------------------[Assignation]--------------------------------------------*/
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
			/**------------------------------[Iterators]----------------------------------------------*/

			/**------------------------------[Capacity]-----------------------------------------------*/
			size_type	size() const {
				return (_size);
			}
			/**_____________________________________________________________________________*/
			size_type	max_size() const {
				return (_allocator.max_size());
			}
			/**_____________________________________________________________________________*/
			size_type	capacity() const {
				return (_capacity);
			}
			/**_____________________________________________________________________________*/
			void	resize (size_type n, value_type val = value_type()) {
				while (n < _size)
					pop_back();
				while (n > _size)
					push_back(val);
				if (n > _capacity)
					reserve(n);
			}
			/**_____________________________________________________________________________*/
			bool	empty() const {
				if (_size == 0)
					return (true);
				return (false);
			}
			/**_____________________________________________________________________________*/
			void	reserve (size_type n) {
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
			/**------------------------------[Element access]-----------------------------------------*/
			

			/**------------------------------[Modifiers]-----------------------------------------------*/
			void	push_back (const value_type& val) {
				if (_size + 1 > _capacity) {
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
				}
				_allocator.construct(&_array[_size], val);
				_size++;
			}
		/**__________________________________________________________________________*/
			void	pop_back() {
				_allocator.destroy(&_array[_size - 1]);
				_size--;
			}
		/**__________________________________________________________________________*/
			void	swap(vector& vec) {
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
			/**__________________________________________________________________________*/
			void	clear() {
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(&_array[i]);
				_size = 0;
			}
			
			/**------------------------------[Operations]---------------------------------------------*/

			/**---------------------------------------------------------------------------------------*/
		reference	operator[] (size_type n) {
			return (_array[n]);
		}
	};
}

/*=============================================================================================================*/
#endif //!FT_VECTOR_HPP