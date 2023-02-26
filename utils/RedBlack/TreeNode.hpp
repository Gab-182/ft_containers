#ifndef TREENODE_HPP
#define TREENODE_HPP

/*=============================================================================================================*/
# include <iostream>
/*=============================================================================================================*/

namespace ft {
/*=============================================================================================================*/
	/**
	 ** @brief The AVL && RedBlack RedBlack node base struct,
	 ** it contains the
	 * [paired data]: is pair<const Key, T> which is the data coming
	 * 				from make_pair() or the already existing pair.
	 * [color of the node]: is the color of the node, red(1) or black(0).
	 * [parent]: is the pointer to the parent node.
	 * [height]: is the height of the node, which is the maximum
	 * 			height of the left and right subtrees + 1.
	 * [pointers to the left child]: is the pointer to the left child node.
	 * [pointers to the right child]: is the pointer to the right child node.
	 ** @tparam T
	 **/
	
	enum Color {RED = false, BLACK = true};
	
	template <class T>
	struct NODE {
		/**———————————————————————————————[ Types ]————————————————————————————————————————**/
		typedef 				T 													data_type;
		typedef 				NODE<T>* 											node_pointer;
		typedef 				NODE<T>& 											node_reference;
		
		/**———————————————————————————————[ Data Members ]—————————————————————————————————**/
		data_type		paired_data;
		node_pointer	parent;
		node_pointer	left;
		node_pointer	right;
		Color 			color;
		
		/**————————————————————————————[ Default Constructor ]———————————————————————————*
		 ** @brief Default constructor, the node is going to be a leaf node.
		 ** and the default color will be black.
		 **/
		NODE()
				: paired_data(),
				parent(nullptr), left(nullptr),
				right(nullptr), color(BLACK) { }
		
		/**———————————————————————————————[ Constructor ]————————————————————————————————*
		 ** @brief Parametrized Constructor, the default color will be red.
		 ** @param paired_data
		 **/
		NODE(T paired_data)
				: paired_data(paired_data),
				parent(nullptr), left(nullptr),
				right(nullptr), color(RED) { }
		
		/**———————————————————————————————[ Grand Parent ]———————————————————————————————*
		 ** @brief Get the grand parent for the node.
		 **/
		node_pointer
		grandparent() {
			// if the node is the tree root.
			if (parent == nullptr)
				return nullptr;
			// else return the parent of the parent.
			return parent->parent;
		}
		
		/**—————————————————————————————————[ Uncle ]————————————————————————————————————*
		 ** @brief Get the Uncle for the node.
		 **/
		node_pointer
		uncle() {
			node_pointer grand_parent = grandparent();
			
			// if the parent is the tree root, then there is no uncle.
			if (grand_parent == nullptr)
				return nullptr;
			// if the parent is the left child of the grandparent,
			// then the uncle is the right child for the grandparent.
			if (parent == grand_parent->left)
				return grand_parent->right;
			// if the parent is the right child of the grandparent,
			// then the uncle is the left child for the grandparent.
			else
				return grand_parent->left;
		}
		
		/**—————————————————————————————————[ Brother ]————————————————————————————————————*
		 ** @brief Get the brother for the node.
		 **/
		 node_pointer
		 brother() {
			// if the node is tree root
			if (parent == nullptr)
		 		return nullptr;
			// if the node is the left child
		 	if (this == parent->left)
		 		return parent->right;
			// if the node is the right child
		 	else
		 		return parent->left;
		 }
		/**———————————————————————————————[ Get Minimum ]————————————————————————————————*
		 ** @brief Get the minimum node in the subtree, which is the far left node.
		 **/
		static node_pointer
		get_minimum(node_pointer current) {
			while (current != nullptr && current->left != nullptr)
				current = current->left;
			return current;
		}
		
		/**———————————————————————————————[ Get Maximum ]————————————————————————————————*
		 ** @brief Get the maximum node in the subtree, which is the far right node.
		 **/
		static node_pointer
		get_maximum(node_pointer current) {
			while (current != nullptr && current->right != nullptr)
				current = current->right;
			return current;
		}
		
		/**———————————————————————————————[ Change Color ]————————————————————————————————*
		 ** @brief Change the color of the node, if it's red, make it black, and vice versa.
		 **/
		void
		change_color() {
			if (this->color == RED)
				this->color = BLACK;
			else
				this->color = RED;
		}
/*=============================================================================================================*/
	};//struct NODE
	
/*=============================================================================================================*/
}

/*=============================================================================================================*/
#endif //TREENODE_HPP
