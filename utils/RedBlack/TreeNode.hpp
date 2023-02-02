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
		T				paired_data;
		int				height;
		NODE*			parent;
		NODE*			left;
		NODE*			right;
		Color 			color;
		bool			is_nil;
		
		/**————————————————————————————[ Default Constructor ]———————————————————————————*
		 * @brief Default constructor
		 */
		NODE()
				: paired_data(), height(0),
				parent(NULL), left(NULL),
				right(NULL), color(), is_nil(true){ }
		
		/**———————————————————————————————[ Constructor ]————————————————————————————————*
		 * @brief Parametrized Constructor, the default color will be red.
		 * @param paired_data
		 */
		NODE(T paired_data)
				: paired_data(paired_data), height(1),
				parent(NULL), left(NULL),
				right(NULL), color(RED), is_nil(false) { }
		
	};
/*=============================================================================================================*/
}

/*=============================================================================================================*/
#endif //TREENODE_HPP
