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
			size_type				_nodes_count;

		public:
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Default_Constructor]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			explicit RedBlack(const compare& comp, const allocator_type& alloc)
				:	_nodes_count(0),
					_root(),
					_compare(comp),
					_alloc_data(alloc),
					_alloc_node(alloc) { }
					
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Copy_Constructor]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			RedBlack(const RedBlack& copy)
				:	_nodes_count(copy._nodes_count),
					_root(copy._root),
					_compare(copy._compare),
					_alloc_data(copy._alloc_data),
					_alloc_node(copy._alloc_node) { }
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Destructor]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			~RedBlack() { }
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Size]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			size_type
			size() const {
				return (_nodes_count);
			}
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Empty]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			bool
			empty() const {
				return (_nodes_count == 0);
			}
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Max_Size]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			size_type
			max_size() const {
				return (_alloc_data.max_size());
			}
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
