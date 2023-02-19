#ifndef MAP_HPP
#define MAP_HPP

# include "../utils/pair.hpp"
# include "../utils/RedBlack/TreeNode.hpp"
# include "../utils/RedBlack/RedBlack.hpp"
/*=============================================================================================================*/
namespace ft {
	
	
	/**
	 **  @brief A standard container made up of (key,value) pairs.
	 **
	 **  @tparam Key  Type of key objects.
	 **  @tparam  T  Type of mapped objects.
	 **  @tparam Compare  Comparison function object type, defaults to less<_Key>.
	 **  @tparam Allocator  Allocator type, defaults to allocator<pair<const _Key, T>.
	 **
	 **  Maps support bidirectional iterators.
	*/
/*=============================================================================================================*/
	template <
			class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
		class map {
				/**——————————————————————————————————[Member_types]————————————————————————————————————————*/
			public:
				/**[Tree_types]*/
				typedef				T														mapped_type;
				typedef				Key														key_type;
				typedef				ft::pair<key_type, mapped_type>							value_type;
				typedef				Compare													key_compare;
				typedef 			RedBlack<Key, T, Compare, Allocator>					tree;
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
				tree					_tree;
				key_compare				_compare;
				allocator_type			_alloc_data;
				
			public:
				/**——————————————————————————————[Default_Constructor]—————————————————————————————————*/
				explicit map(const key_compare &comp = key_compare(),
							 const allocator_type &alloc = allocator_type())
							 : _tree(comp, alloc), _compare(comp), _alloc_data(alloc) { }
				
//				/**——————————————————————————————[Range_Constructor]———————————————————————————————————*/
//				template <class InputIterator>
//				map(InputIterator first, InputIterator last,
//					const key_compare &comp = key_compare(),
//					const allocator_type &alloc = allocator_type()) : {
//
//				}

//				/**——————————————————————————————[Copy_Constructor]———————————————————————————————————*/
				map(const map &copy)
						: _tree(copy._tree), _compare(copy._compare), _alloc_data(copy._alloc_data) {
				}
				
				/**——————————————————————————————[Destructor]———————————————————————————————————————*/
				~map() { }
				
				/**——————————————————————————————[Operator=]———————————————————————————————————————*/
				map &operator=(const map &copy) {
					if (this != &copy) {
						_tree = copy._tree;
						_compare = copy._compare;
						_alloc_data = copy._alloc_data;
					}
					return *this;
				}
				
				/**——————————————————————————————[Iterators]———————————————————————————————————————*/
				iterator begin() {
					return iterator(_tree.begin());
				}
				
				
/*=============================================================================================================*/
		};// Map
/*=============================================================================================================*/
}// FT

/*=============================================================================================================*/
#endif //MAP_HPP
