#ifndef REDBLACK_HPP
#define REDBLACK_HPP

/*=============================================================================================================*/
# include <cstddef>		// for ptrdiff_t
# include <memory>      // for allocator

# include "../pair.hpp"
# include "./TreeNode.hpp"
# include "../../iterator/reverse_iterator.hpp"
# include "../../iterator/RedBlack_iterator/RB_iterator.hpp"
/*===============================================================================*/
# include <iomanip>
# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */
# define RESET			"\033[0m"				/* Reset the color */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
/*===============================================================================*/

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

			/**[Node_types]*/
			typedef				ft::NODE<value_type>									node;
			typedef	typename	allocator_type::template rebind<node>::other			node_allocator;
			typedef	typename	node_allocator::pointer									node_pointer;
			typedef	typename	node_allocator::reference								node_reference;
			typedef typename 	allocator_type::const_pointer							const_node_pointer;
			
		/**[Iterator_types]*/
			typedef				RB_iterator<node_pointer, value_type>					iterator;
			typedef				RB_iterator<const_node_pointer, value_type>				const_iterator;
			typedef				ft::reverse_iterator<iterator>							reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>					const_reverse_iterator;

			typedef				std::ptrdiff_t											difference_type;
			typedef				std::size_t												size_type;
		
		/**———————————————————————————————————[Private Member]—————————————————————————————————————*/
		private:
			key_compare				_compare;
			allocator_type			_alloc_data;
			node_allocator			_alloc_node;
			node_pointer 			_root;
			node_pointer 			_nil;
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
					_root(NULL),
					_nil(NULL),
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
					_nil(copy._nil),
					_nodes_count(copy._nodes_count) { }
			/**———————————————————————————————————[Destructor]—————————————————————————————————————*/
			~RedBlack() {
				clear();
			}
		
			/*——————————————————————————————————————————————————————————————————————————————————————*
			——————————————————————————————————————[Capacity]—————————————————————————————————————————
			—————————————————————————————————————————————————————————————————————————————————————————
			**
			**  🟢☑️ 1) size()
			**  🟢☑️ 2) empty()
			**  🟢☑️ 3) max_size()
			**/
			/**———————————————————————————————————————[ size ]————————————————————————————————————*
			 ** @brief Returns the number of nodes in the tree.
			 ** @return size_type
			 **/
			size_type
			size() const {
				return (_nodes_count);
			}
		
			/**——————————————————————————————————————[ empty ]————————————————————————————————————*
			 ** @brief Returns true if the tree is empty, false otherwise.
			 ** @return bool
			 **/
			bool
			empty() const {
				return (_nodes_count == 0);
			}
		
			/**————————————————————————————————————[ max_size ]———————————————————————————————————*
			 ** @brief Returns the maximum number of nodes the tree can hold,
			 ** and we can get that from the allocator object instance.
			 ** @return
			 **/
			size_type
			max_size() const {
				return (_alloc_data.max_size());
			}

			/*——————————————————————————————————————————————————————————————————————————————————————*
			—————————————————————————————————————[Iterators]—————————————————————————————————————————
			—————————————————————————————————————————————————————————————————————————————————————————
			**
			**  🟢☑️ 1) begin()
			**  🟢☑️ 2) end()
			**  🟢☑️ 3) rbegin()
			**  🟢☑️ 4) rend()
			**/
			/**—————————————————————————————————————[ begin ]—————————————————————————————————————*
			 ** @brief Returns an iterator to the first element in the tree,
			 ** which is the left most node.
			 **/
			inline iterator
			begin() {
				node_pointer MinNode = ft::NODE<value_type>::get_minimum(_root);
				return (iterator(MinNode));
			}
		
			/**—————————————————————————————————————[ begin ]—————————————————————————————————————*
			 ** @brief Returns an iterator to the first element in the tree.
			 **/
			inline const_iterator
			begin() const {
				node_pointer MinNode = ft::NODE<value_type>::get_minimum(_root);
				return (const_iterator(MinNode));
			}
		
			/**——————————————————————————————————————[ end ]——————————————————————————————————————*
			 ** @brief Returns an iterator to the last element in the tree,
			 ** which is the right most node.
			 ** Note:
			 ** ======
			 ** Referencing this iterator will result in undefined behavior,
			 ** cause it's pointing ti the end of the tree (leaf).
			 **/
			 
			inline iterator
			end() {
				node_pointer MaxNode = ft::NODE<value_type>::get_maximum(_root);
				return (iterator(MaxNode->right));
			}
		
			/**——————————————————————————————————————[ end ]——————————————————————————————————————*
			 ** @brief Returns an iterator to the last element in the tree,
			 ** which is the right most node.
			 **/
			
			inline const_iterator
			end() const {
				node_pointer MaxNode = ft::NODE<value_type>::get_maximum(_root);
				return (const_iterator(MaxNode->right));
			}
		
			/**————————————————————————————————————[ rbegin ]—————————————————————————————————————*
			 ** @brief Returns a reverse iterator to the first element in the tree,
			 ** which is the right most node.
			 **/
			inline reverse_iterator
			rbegin() {
				node_pointer MaxNode = ft::NODE<value_type>::get_maximum(_root);
				return (reverse_iterator(MaxNode));
			}
		
			/**————————————————————————————————————[ rbegin ]—————————————————————————————————————*
			 ** @brief Returns a reverse iterator to the first element in the tree,
			 ** which is the right most node.
			 **/
			inline const_reverse_iterator
			rbegin() const {
				node_pointer MaxNode = ft::NODE<value_type>::get_maximum(_root);
				return (const_reverse_iterator(MaxNode));
			}
		
			/**—————————————————————————————————————[ rend ]——————————————————————————————————————*
			 ** @brief Returns a reverse iterator to the last element in the tree,
			 ** which is the left most node.
			 **/
			inline reverse_iterator
			rend() {
				node_pointer MinNode = ft::NODE<value_type>::get_minimum(_root);
				return (reverse_iterator(MinNode));
			}
		
			/**—————————————————————————————————————[ rend ]——————————————————————————————————————*
			 ** @brief Returns a reverse iterator to the last element in the tree,
			 ** which is the left most node.
			 **/
			inline const_reverse_iterator
			rend() const {
				node_pointer MinNode = ft::NODE<value_type>::get_minimum(_root);
				return (const_reverse_iterator(MinNode));
			}

			/*——————————————————————————————————————————————————————————————————————————————————————*
			——————————————————————————————————[Elements access]——————————————————————————————————————
			—————————————————————————————————————————————————————————————————————————————————————————
			 **
			 **  🟢☑️ 1) operator[]
			 **  🟢☑️ 2) at
			 **/
			/**——————————————————————————————————[ operator[] ]———————————————————————————————————*
			 ** @brief
			 ** - If k matches the key of an element in the container,
			 ** the function returns a reference to its mapped value.
			 ** - If k does not match the key of any element in the container,
			 ** the function inserts a new element with that key and returns a reference to its
			 ** mapped value.
			 ** Note:
			 ** =====
			 ** That this always increases the container size by one,
			 ** even if no mapped value is assigned to the element
			 ** (the element is constructed using its default constructor).
			 **/
			inline mapped_type&
			operator[] (const key_type& k) {
				iterator it = find(k);
				if (it != end())
					return(it->second);
				it = insert(ft::make_pair(k, mapped_type())).first;
				return (it->second);
			}
		
			/**—————————————————————————————————————[ at() ]——————————————————————————————————————*
			 ** @brief Returns a reference to the mapped value of the element identified with key k.
			 ** If k does not match the key of any element in the container,
			 ** the function throws an out_of_range exception.
			 **
			 **/
			inline mapped_type&
			at (const key_type& k) {
				iterator it = find(k);
				if (it == end())
					throw std::out_of_range("map::at:  key not found");
				return (it->second);
			}
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
			/**————————————————————————————————————[ insert ]—————————————————————————————————————*
			 ** @brief Inserts a new node in the tree that holds the given value,
			 ** if the node already exists, it will not be inserted.
			 ** the tree will be balanced after insertion.
			 ** the value is created by ft::make_pair(key, mapped_type()) or if the value is already
			 ** created, it will be passed by reference, to avoid copying the value.
			 **
			 ** @param val The paired_data that the new node will hold.
			 ** @return void
			 **
			 ** THE INSERTION FUNCTION IS IMPLEMENTED ACCORDING TO
			 ** THE PSEUDO CODE IN "INTRODUCTION TO ALGORITHMS" BY THOMAS H. (P. 414)
			 **

			 	RB-INSERT(T, new_node)
					parent ← nil
					current ← root
					
					while (current ≠ nil)
						do (parent ← current)
							if (key[new_node] < key[current])
								(current ← left[current])
							else
								current ← right[current]
					p[new_node]←parent
					if (parent = nil)
						(root ← new_node)
					else if( key[new_node] < key[parent])
						(left[parent] ← new_node)
					else
						right[parent] ← new_node
						
					left[new_node] ← nil
					right[new_node] ← nil
					color[new_node] ← RED
					RB-INSERT-FIXUP(T, new_node)

			 **/
			ft::pair<iterator, bool>
			insert(const value_type& value ) {
				// Allocate a new node, and set its value to the given value.
				node_pointer new_node = _alloc_node.allocate(sizeof(node));
				_alloc_node.construct(new_node, node(value));
				
				node_pointer parent = _nil;
				node_pointer current = _root;
				// find the correct location for the new node, and set the parent of the new node.
				while (current != _nil) {
					parent = current;
					if (new_node->paired_data.first < current->paired_data.first)
						current = current->left;
					else {
						current = current->right;
					}
				}
				new_node->parent = parent;
				// if the tree is empty, the new node will be the root.
				if (parent == _nil)
					_root = new_node;
				// if the key of the new node is less than the parent, it will be the left child.
				else if (new_node->paired_data.first < parent->paired_data.first)
					parent->left = new_node;
				// if the key of the new node is greater than the parent, it will be the right child.
				else if (new_node->paired_data.first > parent->paired_data.first)
					parent->right = new_node;
				// if the key already exists:
				//		- delete the new node.
				//		- return an iterator to the existing node.
				else {
					_alloc_node.destroy(new_node);
					_alloc_node.deallocate(new_node, sizeof(node));
					return (ft::make_pair(iterator(parent), false));
				}
				new_node->left = _nil;
				new_node->right = _nil;
				new_node->color = RED;
				++_nodes_count;
				InsertFixup(new_node);
				return (ft::make_pair(iterator(new_node), true));
			}
		private:
			/**—————————————————————————————————[ LeftRotation ]——————————————————————————————————*
			 ** @brief Rotates the node to the left.
			 ** @param node
			 **
			 ** IMPLEMENTED ACCORDING TO THE PSEUDO CODE IN
			 ** "INTRODUCTION TO ALGORITHMS" BY THOMAS H. (P. 312)
			 **

			 LEFT-ROTATE(T, x)
				y ← right[x] 						▹ Set y.
				right[x] ← left[y] 					▹ Turn y's left subtree into x's right subtree.
			 	p[left[y]] ← x
				p[y] ← p[x] 						▹ Link x's parent to y.
				if p[x] = nil[T]
					root[T] ← y
				else if x = left[p[x]]
					left[p[x]] ← y
				else
			 		right[p[x]] ← y
			 	left[y]←x 							▹Put x on y's left.
				p[x]←y

			 **/
			void
			LeftRotation(node_pointer node) {
				node_pointer right_child = node->right;
				node->right = right_child->left;
				
				if (right_child->left != NULL)
					right_child->left->parent = node;
				right_child->parent = node->parent;
				
				if (node->parent == NULL) // if node is the root
					_root = right_child;
				else if (node == node->parent->left) // if node is left child
					node->parent->left = right_child;
				else // if node is right child
					node->parent->right = right_child;
				right_child->left = node;
				node->parent = right_child;
			}
			
			/**—————————————————————————————————[ RightRotation ]—————————————————————————————————*
			 ** @brief Rotates the node to the right.
			 ** @param node
			 **/
			void
			RightRotation(node_pointer node) {
				node_pointer left_child = node->left;
				node->left = left_child->right;
				
				if (left_child->right != NULL)
					left_child->right->parent = node;
				left_child->parent = node->parent;
				
				if (node->parent == NULL) // if node is the root
					_root = left_child;
				else if (node == node->parent->right) // if node is right child
					node->parent->right = left_child;
				else // if node is left child
					node->parent->left = left_child;
				left_child->right = node;
				node->parent = left_child;
			}
			/**——————————————————————————————————[ InsertFixup ]——————————————————————————————————*
			 ** @brief Fixing the tree after insertion, to keep the tree balanced.
			 ** @param node
			 **
			 ** THE INSERTION FUNCTION IS IMPLEMENTED ACCORDING TO
			 ** THE PSEUDO CODE IN "INTRODUCTION TO ALGORITHMS" BY THOMAS H. (P. 415)
			 **

			 RB-INSERT-FIXUP(T, z)
				while (color[p[z]] = RED)
					if p[z] = left[p[p[z]]]				▹ If z's parent is a left child.
						y ← right[p[p[z]]]
					if (color[y] = RED)
						color[p[z]] ← BLACK				▹ Case 1
						color[y] ← BLACK				▹ Case 1
						color[p[p[z]]] ← RED			▹ Case 1
						z ← p[p[z]]						▹ Case 1
					else if (z = right[p[z]])
						z←p[z] 							▹Case2
						LEFT-ROTATE(T, z)				▹Case2
						color[p[z]] ← BLACK				▹Case3
						color[p[p[z]]] ← RED			▹Case3
						RIGHT-ROTATE(T, p[p[z]])		▹Case3
					else
						(same as then clause with "right" and "left" exchanged)
					color[root[T]] ← BLACK

			 **/
			void
			InsertFixup(node_pointer node) {
				node_pointer parent = _nil;
				node_pointer grand_parent = node->grandparent();
				
				while ((node != _root) && (node->color != BLACK) && (node->parent->color == RED)) {
					parent = node->parent;
					grand_parent = parent->parent;
					
					/* If parent is left child of grandparent */
					if (parent == grand_parent->left) {
						node_pointer uncle = grand_parent->right;
						
						/* Case 1: Uncle is also red */
						if (uncle != _nil && uncle->color == RED) {
							grand_parent->color = RED;
							parent->color = BLACK;
							uncle->color = BLACK;
							node = grand_parent;
						}
						else {
							/* Case 2: Node is right child of its parent */
							if (node == parent->right) {
								LeftRotation(parent);
								node = parent;
								parent = node->parent;
							}
							/* Case 3: Node is left child of its parent */
							RightRotation(grand_parent);
							grand_parent->change_color();
							parent->change_color();
							node = parent;
						}
					}
					/* If parent is right child of grandparent */
					else {
						node_pointer uncle = grand_parent->left;
						
						/* Case 1: Uncle is also red */
						if (uncle != _nil && uncle->color == RED) {
							grand_parent->color = RED;
							parent->color = BLACK;
							uncle->color = BLACK;
							node = grand_parent;
						}
						else {
							/* Case 2: Node is left child of its parent */
							if (node == parent->left) {
								RightRotation(parent);
								node = parent;
								parent = node->parent;
							}
							/* Case 3: Node is right child of its parent */
							LeftRotation(grand_parent);
							grand_parent->change_color();
							parent->change_color();
							node = parent;
						}
					}
				}
				_root->color = BLACK;
			}
		private:
			/**—————————————————————————————————[ delete_subtree ]————————————————————————————————*
			 ** @brief Deleting the left subtree, then the right subtree,
			 ** recursively, used as a helper function for the clear() function.
			 **/
			void
			delete_subtree(node_pointer node) {
				if (node == nullptr) {
					return;
				}
				delete_subtree(node->left);
				delete_subtree(node->right);
				_alloc_node.destroy(node);
				_alloc_node.deallocate(node, 1);
			}

		public:
			/**—————————————————————————————————————[ clear ]—————————————————————————————————————*
			 * @brief Deleting all nodes in the tree, starting from the Minimum node
			 * to the root node, then from the Maximum node to the root node.
			 * then deleting the root node.
			 */
			void
			clear() {
				if (_root == nullptr)
					return;
				delete_subtree(_root);
			}
			
			/*——————————————————————————————————————————————————————————————————————————————————————*
			———————————————————————————————————————[Operations]——————————————————————————————————————
			—————————————————————————————————————————————————————————————————————————————————————————
			**
			**  🟢☑️ 1) find()
			**  🟢☑️ 2) count()
			**  🟢☑️ 3) lower_bound()
			**  🟢☑️ 4) upper_bound()
			**  🟢☑️ 5) equal_range()
			**/
			/**—————————————————————————————————————[ find ]——————————————————————————————————————*
			 ** @brief: Searches the container for an element with a key
			 ** equivalent to k and returns an iterator to it if found,
			 ** otherwise it returns an iterator to map::end.
			 **/
			iterator
			find (const key_type& k) {
				iterator it = begin();
				iterator ite = end();
				while (it != ite) {
					if (it->first == k)
						return (it);
					it++;
				}
				return end();
			}
			/**—————————————————————————————————————[ count ]—————————————————————————————————————*
			 ** @brief: Searches the container for elements with a key
			 ** equivalent to k and returns the number of matches.
			 ** Because all elements in a map container are unique,
			 ** the function can only return 1 (if the element is found)
			 ** or zero (otherwise).
			 **/
			size_type
			count (const key_type& k) {
				if (find(k) == end())
					return (0);
				return (1);
			}
		
			/**——————————————————————————————————[ lower_bound ]——————————————————————————————————*
			 ** @brief: Returns an iterator pointing to the first element
			 ** in the container whose key is not considered to go before (k)
			 ** (i.e., either it is equivalent or goes after).
			 ** or map::end if all keys are considered to go before k.
			 **/
			iterator
			lower_bound (const key_type& k) {
				iterator find_k = find(k);
				iterator it = begin();
				
				if (find_k != end())
					return (find_k);
				for (;it != end(); it++) {
					if (it->first > k)
						return it;
				}
				return end();
			}
			/**——————————————————————————————————[ upper_bound ]——————————————————————————————————*
			 ** @brief: Returns an iterator pointing to the first element
			 ** in the container whose key is considered to go after k.
			 ** or map::end if no keys are considered to go after k.
			 **/
			iterator
			upper_bound (const key_type& k) {
				for (iterator it = begin(); it != end(); it++) {
					if (it->first > k)
						return it;
				}
				return end();
			}
		
			/**——————————————————————————————————[ equal_range ]——————————————————————————————————*
			 ** @brief  Returns the bounds of a range that includes all the
			 * elements in the container which have a key equivalent to k.
			 * Because the elements in a map container have unique keys,
			 * the range returned will contain a single element at most.
			 * If no matches are found, the range returned has a length of zero,
			 * with both iterators pointing to the first element that has a key
			 * considered to go after k according to the container's internal
			 * comparison object (key_compare).
			 **/
			pair<iterator,iterator>
			equal_range (const key_type& k) {
				iterator it_start = find(k);
				iterator it_end = find(k);
				
				if (it_start == end()) {
					it_start = upper_bound(k);
					it_end = upper_bound(k);
				}
				return (ft::make_pair(it_start, it_end));
			}
			/**————————————————————————————————————[ get_root ]———————————————————————————————————*
			 ** @brief:  Returns a constant _root of the tree.
			 **/
			node_pointer
			get_root() const {
				return _root;
			}
			
			/**———————————————————————————————————————————————————————————
			 ** @brief: Prints the tree in order.
			 **/
			void
			Inorder(node_pointer root) {
				if (!root) {
					return;
				}
				Inorder(root->left);
				std::cout
				<< std::setfill(' ') << std::setw(10)
				<< BOLDYELLOW << " Key = "
				<< BOLDRED << "[" << BOLDWHITE << root->paired_data.first << BOLDRED << "]"
				<< std::setfill(' ') << std::setw(10)
				<< BOLDYELLOW << " | Value = "
				<< BOLDRED << "[" << BOLDWHITE << root->paired_data.second << BOLDRED << "]"
				<< std::setfill(' ') << std::setw(10)
				<< BOLDYELLOW << " | Color = "
				<< BOLDRED << "[" << BOLDWHITE << root->color << BOLDRED << "]"
				<< RESET << std::endl;
				Inorder(root->right);
			}
			
/*=============================================================================================================*/
	}; // RED_BLACK_TREE
/*=============================================================================================================*/
} // NAMESPACE FT
/*=============================================================================================================*/

#endif //REDBLACK_HPP
