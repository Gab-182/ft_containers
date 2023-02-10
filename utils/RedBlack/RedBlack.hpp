#ifndef REDBLACK_HPP
#define REDBLACK_HPP

/*=============================================================================================================*/
# include <cstddef>		// for ptrdiff_t
# include <memory>      // for allocator

# include "../pair.hpp"
# include "./TreeNode.hpp"
# include "../../iterator/reverse_iterator.hpp"
# include "../../iterator/RedBlack_iterator/RB_iterator.hpp"
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
			/**———————————————————————————————————————————————————————————*
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
			**  🟢 1) begin()
			**  🟢 2) end()
			**  🟢 3) rbegin()
			**  🟢 4) rend()
			**/
			/**———————————————————————————————————————————————————————————*
			 ** @brief Returns an iterator to the first element in the tree,
			 ** which is the left most node.
			 **/
			inline iterator
			begin() {
				node_pointer MinNode = ft::NODE<value_type>::get_minimum(_root);
				return (iterator(MinNode));
			}
			
			/**———————————————————————————————————————————————————————————*
			 ** @brief Returns an iterator to the first element in the tree.
			 **/
			inline const_iterator
			begin() const {
				node_pointer MinNode = ft::NODE<value_type>::get_minimum(_root);
				return (const_iterator(MinNode));
			}
			
			/**———————————————————————————————————————————————————————————*
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
		
			/**———————————————————————————————————————————————————————————*
			 ** @brief Returns an iterator to the last element in the tree,
			 ** which is the right most node.
			 **/
			
			inline const_iterator
			end() const {
				node_pointer MaxNode = ft::NODE<value_type>::get_maximum(_root);
				return (const_iterator(MaxNode->right));
			}
			
			/**———————————————————————————————————————————————————————————*
			 ** @brief Returns a reverse iterator to the first element in the tree,
			 ** which is the right most node.
			 **/
			inline reverse_iterator
			rbegin() {
				node_pointer MaxNode = ft::NODE<value_type>::get_maximum(_root);
				return (reverse_iterator(MaxNode));
			}
			
			/**———————————————————————————————————————————————————————————*
			 ** @brief Returns a reverse iterator to the first element in the tree,
			 ** which is the right most node.
			 **/
			inline const_reverse_iterator
			rbegin() const {
				node_pointer MaxNode = ft::NODE<value_type>::get_maximum(_root);
				return (const_reverse_iterator(MaxNode));
			}

			/**———————————————————————————————————————————————————————————*
			 ** @brief Returns a reverse iterator to the last element in the tree,
			 ** which is the left most node.
			 **/
			inline reverse_iterator
			rend() {
				node_pointer MinNode = ft::NODE<value_type>::get_minimum(_root);
				return (reverse_iterator(MinNode));
			}
			
			/**———————————————————————————————————————————————————————————*
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
			 **  🟢 1) operator[]
			 **  🟢 2) at
			 **/
			/**———————————————————————————————————————————————————————————
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
				it = insert(ft::make_pair(k, mapped_type()));
				return (it->second);
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
			/**———————————————————————————————————————————————————————————*
			 ** @brief Inserts a new node in the tree that holds the given value,
			 ** if the node already exists, it will not be inserted.
			 ** the tree will be balanced after insertion.
			 ** the value is created by ft::make_pair(key, mapped_type()) or if the value is already
			 ** created, it will be passed by reference, to avoid copying the value.
			 **
			 ** @param val The paired_data that the new node will hold.
			 ** @return void
			 **/
			inline iterator
			insert(const value_type& value ) {
				node_pointer new_node = _alloc_node.allocate(sizeof(node));
				_alloc_node.construct(new_node, node(value));
				
				if (_root == nullptr) {
					_root = new_node;
					_nodes_count++;
					return (iterator(new_node));
				}
				node_pointer current_node = _root;
				while (current_node != nullptr) {
					if (new_node->paired_data.first < current_node->paired_data.first) {
						if (current_node->left == nullptr) {
							current_node->left = new_node;
							new_node->parent = current_node;
							_nodes_count++;
							return (iterator(new_node));
						}
						current_node = current_node->left;
					} else if (new_node->paired_data.first > current_node->paired_data.first) {
						if (current_node->right == nullptr) {
							current_node->right = new_node;
							new_node->parent = current_node;
							_nodes_count++;
							return (iterator(new_node));
						}
						current_node = current_node->right;
					} else {
						return (iterator(current_node));
					}
				}
				return (iterator(new_node));
			}
		
			/**———————————————————————————————————————————————————————————*/
			/**———————————————————————————————————————————————————————————*/
			/**———————————————————————————————————————————————————————————*/
			/**———————————————————————————————————————————————————————————*/
			
		/*——————————————————————————————————————————————————————————————————————————————————————*
		———————————————————————————————————————[Operations]——————————————————————————————————————
		—————————————————————————————————————————————————————————————————————————————————————————
		**
		**  🟢 1) find()
		**  🟢 2) count()
		**  🟢 3) lower_bound()
		**  🟢 4) upper_bound()
		**  🟢 5) equal_range()
		**/
		/**———————————————————————————————————————————————————————————*
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
		/**———————————————————————————————————————————————————————————*
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
		
		/**———————————————————————————————————————————————————————————*
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
		/**———————————————————————————————————————————————————————————*
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
		
		/**———————————————————————————————————————————————————————————*
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
/*=============================================================================================================*/
	};
/*=============================================================================================================*/
}
/*=============================================================================================================*/

#endif //REDBLACK_HPP
