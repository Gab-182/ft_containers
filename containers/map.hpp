#ifndef MAP_HPP
#define MAP_HPP

# include "../includes/utils/pair.hpp"
# include "../includes/utils/RedBlack/TreeNode.hpp"
# include "../includes/utils/RedBlack/RedBlack.hpp"
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
				typedef				T																		mapped_type;
				typedef				Key																		key_type;
				typedef				ft::pair<key_type, mapped_type>											value_type;
				typedef				ft::pair<key_type, mapped_type>											const_value_type;
				typedef				Compare																	key_compare;
				typedef				Allocator																allocator_type;
				typedef	typename 	allocator_type::reference												reference;
				typedef	typename 	allocator_type::const_reference											const_reference;
				typedef typename 	allocator_type::pointer													pointer;
				typedef typename 	allocator_type::const_pointer											const_pointer;
				typedef 			RedBlack<Key, T,Compare,Allocator >										tree;
				
				/**[Node_types]*/
				typedef				ft::NODE<value_type>													node;
				typedef	typename	allocator_type::template rebind<node>::other							node_allocator;
				typedef	typename	node_allocator::pointer													node_pointer;
				typedef	typename	node_allocator::reference												node_reference;
				typedef typename 	node_allocator::const_pointer											const_node_pointer;
				
				typedef				std::ptrdiff_t															difference_type;
				typedef				std::size_t																size_type;
				
				/**[Iterator_types]*/
				typedef				ft::RB_iterator<node_pointer, value_type, difference_type>				iterator;
				typedef				ft::RB_const_iterator<node_pointer, const value_type, difference_type>	const_iterator;
				typedef				ft::reverse_iterator<iterator>											reverse_iterator;
				typedef				ft::reverse_iterator<const_iterator>									const_reverse_iterator;
			
				/**————————————————————————————————————[Member Class]——————————————————————————————————————*/
				class value_compare : public std::binary_function<value_type, value_type, bool> {
					
					friend class map;
				protected:
					key_compare m_comp;
					value_compare(key_compare comp) : m_comp(comp) {}
				
				public:
					bool operator()(const value_type &lhs, const value_type &rhs) const {
						return m_comp(lhs.first, rhs.first);
					}
				}; // class value_compare
				
				/**———————————————————————————————————[Private Member]—————————————————————————————————————*/
			private:
				key_compare				_compare;
				allocator_type			_alloc_data;
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
					 						: _compare(comp), _alloc_data(alloc) {
					insert(first, last);
				}

				/**——————————————————————————————[Copy_Constructor]———————————————————————————————————*/
				map (const map& copy)
						: _compare(copy._compare), _alloc_data(copy._alloc_data) {
					insert(copy.begin(), copy.end());
				}
			
			/**—————————————————————————————————[Destructor]——————————————————————————————————————*/
				~map() { }
				
				/**——————————————————————————————————[Operator=]——————————————————————————————————————*/
				map &operator=(const map &copy) {
					if (this != &copy) {
						clear();
						_compare = copy._compare;
						_alloc_data = copy._alloc_data;
						this->insert(copy.begin(), copy.end());
					}
					return (*this);
				}
				
				/**—————————————————————————————————[Iterators]————————————————————————————————————————*/
				iterator begin() {
					return _tree.begin();
				}

				const_iterator begin() const {
					return _tree.begin();
				}

				iterator end() {
					return _tree.end();
				}

				const_iterator end() const {
					return _tree.end();
				}

				reverse_iterator rbegin() {
					return _tree.rbegin();
				}

				const_reverse_iterator rbegin() const {
					return _tree.rbegin();
				}

				reverse_iterator rend() {
					return _tree.rend();
				}

				const_reverse_iterator rend() const {
					return _tree.rend();
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

				iterator insert(iterator position, const value_type &val) {
					return _tree.insert(position, val);
				}

				template <class InputIterator>
				void insert(InputIterator first, InputIterator last) {
					_tree.insert(first, last);
				}

				void erase(iterator pos) {
					_tree.erase(pos);
				}

				size_type erase(const key_type &k) {
					return _tree.erase(k);
				}

				void erase(iterator first, iterator last) {
					_tree.erase(first, last);
				}

				void swap(map &x) {
					this->_tree.swap(x._tree);
				}

				void clear() {
					_tree.clear();
				}
				
				/**—————————————————————————————————[Observers]————————————————————————————————————————*/
				key_compare key_comp() const {
					return key_compare();
				}
			
				value_compare value_comp() const {
					return (value_compare(key_compare()));
				}
				
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

				const_iterator lower_bound(const key_type &k) const {
					return _tree.lower_bound(k);
				}

				iterator upper_bound(const key_type &k) {
					return _tree.upper_bound(k);
				}

				const_iterator upper_bound(const key_type &k) const {
					return _tree.upper_bound(k);
				}

				ft::pair<const_iterator, const_iterator>
				equal_range(const key_type &k) const {
					return _tree.equal_range(k);
				}

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
	
	/**———————————————————————————————————————————[map1 == map2]——————————————————————————————————————————————*/
		template <class Key_1, class T_1, class Compare_1, class Alloc_1,
				class Key_2, class T_2, class Compare_2, class Alloc_2>
		bool operator==(const map<Key_1, T_1, Compare_1, Alloc_1> &lhs,
						const map<Key_2, T_2, Compare_2, Alloc_2> &rhs) {
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	
	/**———————————————————————————————————————————[map1 != map2]——————————————————————————————————————————————*/
		template <class Key_1, class T_1, class Compare_1, class Alloc_1,
				class Key_2, class T_2, class Compare_2, class Alloc_2>
		bool operator!=(const map<Key_1, T_1, Compare_1, Alloc_1> &lhs,
						const map<Key_2, T_2, Compare_2, Alloc_2> &rhs) {
			return !(lhs == rhs);
		}

	/**———————————————————————————————————————————[map1 < map2]——————————————————————————————————————————————*/
		template <class Key, class T, class Compare, class Alloc>
		bool operator<(const map<Key, T, Compare, Alloc> &lhs,
						const map<Key, T, Compare, Alloc> &rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

	/**———————————————————————————————————————————[map1 <= map2]——————————————————————————————————————————————*/
		template <class Key, class T, class Compare, class Alloc>
		bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
			return !(rhs < lhs);
		}

	/**———————————————————————————————————————————[map1 > map2]——————————————————————————————————————————————*/
		template <class Key, class T, class Compare, class Alloc>
		bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
			return rhs < lhs;
		}

	/**———————————————————————————————————————————[map1 >= map2]——————————————————————————————————————————————*/
		template <class Key, class T, class Compare, class Alloc>
		bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
			return !(lhs < rhs);
		}

	/**———————————————————————————————————————————[swap(map1, map2)]——————————————————————————————————————————————*/
		template <class Key, class T, class Compare, class Alloc>
		void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) {
			x.swap(y);
		}
/*=============================================================================================================*/
}// FT

/*=============================================================================================================*/
#endif //MAP_HPP
