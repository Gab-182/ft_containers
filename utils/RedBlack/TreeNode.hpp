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
		int				height;
		node_pointer	parent;
		node_pointer	left;
		node_pointer	right;
		Color 			color;
		bool			is_nil;
		
		/**————————————————————————————[ Default Constructor ]———————————————————————————*
		 * @brief Default constructor, the node is going to be a leaf node.
		 * and the default color will be black.
		 */
		NODE()
				: paired_data(), height(0),
				parent(NULL), left(NULL),
				right(NULL), color(BLACK), is_nil(true){ }
		
		/**———————————————————————————————[ Constructor ]————————————————————————————————*
		 * @brief Parametrized Constructor, the default color will be red.
		 * @param paired_data
		 */
		NODE(T paired_data)
				: paired_data(paired_data), height(1),
				parent(NULL), left(NULL),
				right(NULL), color(RED), is_nil(false) { }
		
		/**———————————————————————————————[ Get Minimum ]————————————————————————————————*
		 * @brief Get the minimum node in the subtree, which is the far left node.
		 */
		static node_pointer
		get_minimum(node_pointer current) {
			while (current->left != NULL)
				current = current->left;
			return current;
		}
		
		/**———————————————————————————————[ Get Maximum ]————————————————————————————————*
		 * @brief Get the maximum node in the subtree, which is the far right node.
		 */
		static node_pointer
		get_maximum(node_pointer current) {
			while (current->right != NULL)
				current = current->right;
			return current;
		}
		
		/**———————————————————————————————[ Change Color ]————————————————————————————————*
		 * @brief Change the color of the node, if it's red, make it black, and vice versa.
		 */
		void
		change_color() {
			if (this->color == RED)
				this->color = BLACK;
			else
				this->color = RED;
		}
		
	};//struct NODE
	
/*=============================================================================================================*/
}

/*=============================================================================================================*/
#endif //TREENODE_HPP
