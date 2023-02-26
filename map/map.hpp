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
				typedef				T																				mapped_type;
				typedef				Key																				key_type;
				typedef				ft::pair<key_type, mapped_type>													value_type;
				typedef				ft::pair<key_type, mapped_type>													const_value_type;
				typedef				Compare																			key_compare;
				typedef				Allocator																		allocator_type;
				typedef	typename 	allocator_type::reference														reference;
				typedef	typename 	allocator_type::const_reference													const_reference;
				typedef typename 	allocator_type::pointer															pointer;
				typedef typename 	allocator_type::const_pointer													const_pointer;
				typedef 			RedBlack<Key, T,Compare,Allocator >												tree;
				
				/**[Node_types]*/
				typedef				ft::NODE<value_type>															node;
				typedef	typename	allocator_type::template rebind<node>::other									node_allocator;
				typedef	typename	node_allocator::pointer															node_pointer;
				typedef	typename	node_allocator::reference														node_reference;
				typedef typename 	node_allocator::const_pointer													const_node_pointer;
				
				typedef				std::ptrdiff_t																	difference_type;
				typedef				std::size_t																		size_type;
				
				/**[Iterator_types]*/
				typedef				ft::RB_iterator<node_pointer, value_type, difference_type>						iterator;
				typedef				ft::RB_const_iterator<node_pointer, const value_type, difference_type>			const_iterator;
				typedef				ft::reverse_iterator<iterator>													reverse_iterator;
				typedef				ft::reverse_iterator<const_iterator>											const_reverse_iterator;
				
				
				/**———————————————————————————————————[Private Member]—————————————————————————————————————*/
			private:
				key_compare				_compare;
				allocator_type			_alloc_data;
//				node_allocator			_alloc_node;
				tree					_tree;
				

			public:
				/**——————————————————————————————[Default_Constructor]—————————————————————————————————*/
				explicit map (const key_compare& comp = key_compare(),
							  const allocator_type& alloc = allocator_type())
						: _compare(comp), _alloc_data(alloc), _tree(comp, alloc) { }
				
				/**——————————————————————————————[Range_Constructor]———————————————————————————————————*/
				template <class InputIterator>
				map (InputIterator first, InputIterator last,
					 const key_compare& comp = key_compare(),
					 const allocator_type& alloc = allocator_type())
					 						: _compare(comp), _alloc_data(alloc), _tree(first, last, comp, alloc) { }

				/**——————————————————————————————[Copy_Constructor]———————————————————————————————————*/
				map (const map& copy)
						: _compare(copy._compare), _alloc_data(copy._alloc_data), _tree(copy._tree) { }
			
			/**—————————————————————————————————[Destructor]——————————————————————————————————————*/
				~map() { }
				
				/**——————————————————————————————————[Operator=]——————————————————————————————————————*/
				map &operator=(const map &copy) {
					if (this != &copy) {
						_compare = copy._compare;
						_alloc_data = copy._alloc_data;
						_tree = copy._tree;
					}
					return *this;
				}
				
				/**—————————————————————————————————[Iterators]————————————————————————————————————————*/
				iterator begin() {
					return iterator(_tree.begin());
				}

				const_iterator begin() const {
					return const_iterator(_tree.begin());
				}

				iterator end() {
					return iterator(_tree.end());
				}

				const_iterator end() const {
					return const_iterator(_tree.end());
				}

				reverse_iterator rbegin() {
					return reverse_iterator(_tree.end());
				}

				const_reverse_iterator rbegin() const {
					return const_reverse_iterator(_tree.end());
				}

				reverse_iterator rend() {
					return reverse_iterator(_tree.begin());
				}

				const_reverse_iterator rend() const {
					return const_reverse_iterator(_tree.begin());
				}
				
				/**—————————————————————————————————[Capacity]————————————————————————————————————————*/
				bool empty() const {
					return _tree.empty();
				}

				size_type size() const {
					return _tree.size();
				}

				size_type max_size() const {
					return _tree.max_size();
				}
				
				/**—————————————————————————————————[Element access]———————————————————————————————————*/
				mapped_type& operator[](const key_type &key) {
					return _tree[key];
				}
				
				mapped_type& at(const key_type &key) {
					return _tree.at(key);
				}
				/**—————————————————————————————————[Modifiers]————————————————————————————————————————*/
				ft::pair<iterator, bool> insert(const value_type &val) {
					return _tree.insert(val);
				}

//				iterator insert(iterator position, const value_type &val) {
//					return _tree.insert(position, val);
//				}
//
				template <class InputIterator>
				void insert(InputIterator first, InputIterator last) {
					_tree.insert(first, last);
				}
//
//				void erase(iterator position) {
//					_tree.erase(position);
//				}
//
				size_type erase(const key_type &k) {
					return _tree.erase(k);
				}

				void erase(iterator first, iterator last) {
					_tree.erase(first, last);
				}

				void swap(map &x) {
					_tree.swap(x._tree);
				}

				void clear() {
					_tree.clear();
				}
				
				/**—————————————————————————————————[Observers]————————————————————————————————————————*/
				key_compare key_comp() const {
					return _compare;
				}

//				value_compare value_comp() const {
//					return value_compare(_compare);
//				}
				
				/**—————————————————————————————————[Operations]————————————————————————————————————————*/
				iterator find(const key_type &k) {
					return _tree.find(k);
				}

				const_iterator find(const key_type &k) const {
					return _tree.find(k);
				}

				size_type count(const key_type &k) const {
					return _tree.count(k);
				}

				iterator lower_bound(const key_type &k) {
					return _tree.lower_bound(k);
				}
//
//				const_iterator lower_bound(const key_type &k) const {
//					return _tree.lower_bound(k);
//				}

				iterator upper_bound(const key_type &k) {
					return _tree.upper_bound(k);
				}
//
//				const_iterator upper_bound(const key_type &k) const {
//					return _tree.upper_bound(k);
//				}

//				ft::pair<const_iterator, const_iterator>
//				equal_range(const key_type &k) const {
//					return _tree.equal_range(k);
//				}

				ft::pair<iterator, iterator>
				equal_range(const key_type &k) {
					return _tree.equal_range(k);
				}
				
				/**—————————————————————————————————[Allocator]————————————————————————————————————————*/
				allocator_type get_allocator() const {
					return _alloc_data;
				}
		};// Map
	/**———————————————————————————————————[Non-member function overloads]—————————————————————————————————————*/
		template <class Key, class T, class Compare, class Alloc>
		bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
			return lhs._tree == rhs._tree;
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
			return lhs._tree != rhs._tree;
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
			return lhs._tree < rhs._tree;
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
			return lhs._tree <= rhs._tree;
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
			return lhs._tree > rhs._tree;
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
			return lhs._tree >= rhs._tree;
		}

		template <class Key, class T, class Compare, class Alloc>
		void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) {
			x.swap(y);
		}
/*=============================================================================================================*/
}// FT

/*=============================================================================================================*/
#endif //MAP_HPP
