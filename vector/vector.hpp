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
			};
			/**_________________________________________________________*/
			const_reverse_iterator
			rbegin() const {
				return (const_reverse_iterator(end()));
			};
			/**_________________________________________________________*/
			reverse_iterator
			rend() {
				return (reverse_iterator(begin()));
			};
			/**_________________________________________________________*/
			const_reverse_iterator
			rend() const {
				return (const_reverse_iterator(begin()));
			};

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
			void
			reserve (size_type n) {
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
			void
			pop_back() {
				_allocator.destroy(&_array[_size - 1]);
				_size--;
			}
			/**_________________________________________________________*/
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
//			iterator
//			erase(iterator pos) {
//
//			}

			/**=========================================================================*/
	}; // vector
	
}// namespace ft

/*=============================================================================================================*/
#endif //!FT_VECTOR_HPP