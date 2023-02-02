#ifndef REDBLACK_HPP
#define REDBLACK_HPP

/*=============================================================================================================*/
# include "../pair.hpp"
# include "./TreeNode.hpp"
# include <iostream>
# include <memory>
/*=============================================================================================================*/
namespace ft {
/*=============================================================================================================*/
	/**
	 * @TODO: try to make the Node allocate him self by moving :
	 * typedef typename allocator_type::template rebind<node>::other		node_allocator;
	 * to the node, and make the constructor do the rest.
	 *
	 * @brief
	 * [map_data]:
	 * [key]:
	 * [paired_data]:
	 * [compare]:
	 * [allocator_type]:
	 * [node]:
	 * [node_allocator]:
	 * @NOTE:
	 * =======
	 * rebind is for allocating memory for a type that differs
	 * from the element type of the container being implemented

	 * [pointer]:
	 * [const_pointer]:
	 * [size_type]:
	 */
	template<class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
	class RedBlack {
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Member_types]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		public:
			typedef T															map_data;
			typedef Key															key;
			typedef ft::pair<const key, map_data>								paired_data;
			typedef Compare														compare;
			typedef Allocator													allocator_type;
			typedef ft::NODE<paired_data>										node;
			typedef typename allocator_type::template rebind<node>::other		node_allocator;
			typedef node*														pointer;
			typedef const pointer												const_pointer;
			typedef std::size_t													size_type;
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Private Member]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		private:
			compare					_compare;
			allocator_type			_alloc_data;
			node_allocator 			_alloc_node;
			pointer 				_root;
			node 					_nil;
			
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Default_Constructor]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Parametrized_Constructor]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Copy_Constructor]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Destructor]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Size]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Empty]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Max_Size]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Clear]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Operator=]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Iterators]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Insert]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Erase]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Swap]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Search]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		
	};
/*=============================================================================================================*/
}
/*=============================================================================================================*/

#endif //REDBLACK_HPP
