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
	 * @brief
	 ** [map_data]: the data coming from the user, it is used to create the pair.
	 ** [key]: the key used to compare the nodes, it is used to create the pair with the data.
	 ** [paired_data]: created from the map_data and the key, it is the data that is going to
	 ** 				be stored in the node.
	 ** [compare]: the compare function, used to compare the keys.
	 ** [allocator_type]: the allocator type, used to allocate the nodes.
	 ** [node]: the node type, used to create the nodes.
	 ** [node_allocator]: the node allocator type.
	 ** @NOTE:
	 ** =========================================================
	 ** rebind is for allocating memory for a type that differs
	 ** from the element type of the container being implemented
	 * ==========================================================
	 ** [pointer]: the pointer type, used to point to the nodes.
	 ** [const_pointer]: the const pointer type, used to point to the nodes.
	 ** [size_type]: the type used to represent the size of the tree.
	 **/
	template<class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
	class RedBlack {
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Member_types]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		public:
			typedef		T															map_data;
			typedef		Key															key;
			typedef		ft::pair<const key, map_data>								paired_data;
			typedef		Compare														compare;
			typedef		Allocator													allocator_type;
			typedef		ft::NODE<paired_data>										node;
			typedef		typename allocator_type::template rebind<node>::other		node_allocator;
			typedef		node*														pointer;
			typedef		const pointer												const_pointer;
			typedef		std::size_t													size_type;
		
		/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Private Member]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
		private:
			compare					_compare;
			allocator_type			_alloc_data;
			node_allocator			_alloc_node;
			pointer 				_root;
			size_type				_nodes_count;

		public:
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Default_Constructor]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			/**
			 ** @brief Default constructor
			 ** NOTE:
			 ** ======
			 ** _compare(comp), _alloc_data(alloc), _alloc_node(alloc):
			 ** should should always initialize at the beginning before everything else or an error will occur.
			 ** @param comp
			 ** @param alloc
			 **/
			explicit RedBlack(const compare& comp, const allocator_type& alloc)
				:	_compare(comp),
					_alloc_data(alloc),
					_alloc_node(alloc),
					_root(),
					_nodes_count(0) { }
					
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Copy_Constructor]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			/**
			 ** @brief Copy constructor.
			 ** NOTE:
			 ** ======
			 ** _compare(comp), _alloc_data(alloc), _alloc_node(alloc):
			 ** should should always initialize at the beginning before everything else or an error will occur.
			 ** @param copy: the tree to copy from.
			 **/
			RedBlack(const RedBlack& copy)
				:	_compare(copy._compare),
					_alloc_data(copy._alloc_data),
					_alloc_node(copy._alloc_node),
					_root(copy._root),
					_nodes_count(copy._nodes_count) { }
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Destructor]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			~RedBlack() {
				this->clear();
			}
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Size]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			/**
			 ** @brief Returns the number of nodes in the tree.
			 ** @return size_type
			 **/
			size_type
			size() const {
				return (_nodes_count);
			}
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Empty]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			/**
			 ** @brief Returns true if the tree is empty, false otherwise.
			 ** @return bool
			 **/
			bool
			empty() const {
				return (_nodes_count == 0);
			}
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Max_Size]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			/**
			 * @brief Returns the maximum number of nodes the tree can hold,
			 * and we can get that from the allocator object instance.
			 * @return
			 */
			size_type
			max_size() const {
				return (_alloc_data.max_size());
			}
			/**➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖[Clear]➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖*/
			/**
			 * @brief Clears the tree and deletes all nodes by deallocating them, then sets the root to null.
			 */
			void
			clear() {
				/**
				 ** Destroy all nodes in the left tree.
				 **/
				 if (_root && _root->left) {
					 pointer minNode = node::get_minimum(_root);
					 pointer tmp = minNode->parent;
					 while (tmp != _root) {
						 tmp = minNode->parent;
						 _alloc_node.deallocate(minNode, 1);
						 _alloc_node.destroy(minNode);
						 minNode = tmp;
					 }
				 }
				/**
				 ** Destroy all nodes in the right tree.
				 **/
				if (_root && _root->right) {
					pointer maxNode = node::get_maximum(_root);
					pointer temp = maxNode->parent;
					while (temp != _root) {
						temp = maxNode->parent;
						_alloc_node.deallocate(maxNode, 1);
						_alloc_node.destroy(maxNode);
						maxNode = temp;
					}
				}
				/**
				 ** Destroy the root node.
				 **/
				 if (_root) {
					 _alloc_node.deallocate(_root, 1);
					 _alloc_node.destroy(_root);
					 _root = NULL;
				 }
			}
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
