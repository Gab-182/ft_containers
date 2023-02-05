#ifndef REDBLACK_HPP
#define REDBLACK_HPP

/*=============================================================================================================*/
# include "../pair.hpp"
# include "./TreeNode.hpp"
# include <cstddef>		// for ptrdiff_t
# include <memory>      // for allocator
# include <map>
/*=============================================================================================================*/
namespace ft {
/*=============================================================================================================*/
	/**
	 * @brief
	 ** [map_data]: the data coming from the user, it is used to create the pair.
	 ** [key]: the key used to compare the nodes, it is used to create the pair with the data.
	 ** [paired_data]: created from the (map_data, the key), it is the data that is going to
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
		/**——————————————————————————————————[Member_types]————————————————————————————————————————*/
		public:
		/**[Tree_types]*/
			typedef				T														mapped_type;
			typedef				Key														key_type;
			typedef				ft::pair<const key_type, mapped_type>					value_type;
			typedef				Compare													key_compare;
			typedef				Allocator												allocator_type;
			typedef	typename 	allocator_type::reference								reference;
			typedef	typename 	allocator_type::const_reference							const_reference;
			typedef typename 	allocator_type::pointer									pointer;
			typedef typename 	allocator_type::const_pointer							const_pointer;
			
			/**[Iterator_types]*/

			/**[Node_types]*/
			typedef				ft::NODE<value_type>									node;
			typedef	typename	allocator_type::template rebind<node>::other			node_allocator;
			typedef	typename	node_allocator::pointer									node_pointer;
			typedef typename 	allocator_type::const_pointer							const_node_pointer;
		
			typedef				std::ptrdiff_t											difference_type;
			typedef				std::size_t												size_type;
		
		/**———————————————————————————————————[Private Member]—————————————————————————————————————*/
		private:
			key_compare				_compare;
			allocator_type			_alloc_data;
			node_allocator			_alloc_node;
			node_pointer 			_root;
			size_type				_nodes_count;

		public:
			/**——————————————————————————————[Default_Constructor]—————————————————————————————————*/
			/**
			 ** @brief Default constructor
			 ** NOTE:
			 ** ======
			 ** _compare(comp), _alloc_data(alloc), _alloc_node(alloc):
			 ** should should always initialize at the beginning before everything else or an error will occur.
			 ** @param comp
			 ** @param alloc
			 **/
			explicit RedBlack(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				:	_compare(comp),
					_alloc_data(alloc),
					_alloc_node(alloc),
					_root(),
					_nodes_count(0) { }
		
			/**——————————————————————————————[Range_Constructor]———————————————————————————————————*/
//			template <class InputIterator>
//			RedBlack (InputIterator first, InputIterator last,
//					  const key_compare& comp = key_compare(),
//					  const allocator_type& alloc = allocator_type()) {
//
//			}
			/**——————————————————————————————[Copy_Constructor]————————————————————————————————————*/
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
			/**———————————————————————————————————[Destructor]—————————————————————————————————————*/
			~RedBlack() {
			}
		
			/*——————————————————————————————————————————————————————————————————————————————————————*
			——————————————————————————————————————[Capacity]—————————————————————————————————————————
			—————————————————————————————————————————————————————————————————————————————————————————
			**
			**  🟢 1) size()
			**  🟢 2) empty()
			**  🟢 3) max_size()
			**/
			/**
			 ** @brief Returns the number of nodes in the tree.
			 ** @return size_type
			 **/
			size_type
			size() const {
				return (_nodes_count);
			}
		
			/**———————————————————————————————————————————————————————————*
			 ** @brief Returns true if the tree is empty, false otherwise.
			 ** @return bool
			 **/
			bool
			empty() const {
				return (_nodes_count == 0);
			}
		
			/**———————————————————————————————————————————————————————————*
			 * @brief Returns the maximum number of nodes the tree can hold,
			 * and we can get that from the allocator object instance.
			 * @return
			 */
			size_type
			max_size() const {
				return (_alloc_data.max_size());
			}
			
			/*——————————————————————————————————————————————————————————————————————————————————————*
			——————————————————————————————————[Elements access]——————————————————————————————————————
			—————————————————————————————————————————————————————————————————————————————————————————
			**
			**  🟢 1) operator[]
			**  🟢 2) at
			**/
			/**———————————————————————————————————————————————————————————
			 ** @brief
			 ** - If k matches the key of an element in the container,
			 ** the function returns a reference to its mapped value.
			 ** - If k does not match the key of any element in the container,
			 ** the function inserts a new element with that key and returns a reference to its mapped value.
			 ** Note:
			 ** =====
			 ** That this always increases the container size by one,
			 ** even if no mapped value is assigned to the element
			 ** (the element is constructed using its default constructor).
			 **
			 **/
			inline mapped_type&
			operator[] (const key_type& k) {
				return *(this->insert(make_pair(k,mapped_type())).first);
			}
			
			/**———————————————————————————————————————————————————————————*/
			
			/*——————————————————————————————————————————————————————————————————————————————————————*
			———————————————————————————————————————[Modifies]————————————————————————————————————————
			—————————————————————————————————————————————————————————————————————————————————————————
			**
			**  🟢 1) insert
			**  🟢 2) erase
			**  🟢 3) swap
			**  🟢 4) clear
			**
			**/
			/**
			 * @brief Inserts a new node in the tree that holds the given value,
			 * if the node already exists, it will not be inserted.
			 * the tree will be balanced after insertion.
			 * the value is created by ft::make_pair(key, mapped_type()) or if the value is already
			 * created, it will be passed by reference, to avoid copying the value.
			 *
			 * @param val The paired_data that the new node will hold.
			 * @return void
			 *
			 * @TODO: Check if the node already exists, by
			 * @TODO: Balance the tree after insertion.
			 */
//			void
//			insert(const value_type& val) {
//			}
		
			/**———————————————————————————————————————————————————————————*
			* @brief Clears the tree and deletes all nodes by deallocating them, then sets the root to null.
			*/
//			void
//			clear() {
//			}
			/**———————————————————————————————————————————————————————————*/
			/**———————————————————————————————————————————————————————————*/
			/**———————————————————————————————————————————————————————————*/
};
/*=============================================================================================================*/
}
/*=============================================================================================================*/

#endif //REDBLACK_HPP
