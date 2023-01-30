#ifndef BST_HPP
#define BST_HPP

# include <iostream>
/*=============================================================================================================*/
template <typename T>
class Node {
	public:
		/**———————————————————[ Member Types ]—————————————————————————————**/
		T				data;
		Node*			left;
		Node*			right;
		
		/**—————————————————[ empty constructor ]——————————————————————————**/
		Node()
			: data(0), left(), right() { }
			
		/**———————————————————[ Constructor ]—————————————————————————————**/

};

/*=============================================================================================================*/
template <typename T>
class BST {
	public:
		/**———————————————————[ Member Types ]—————————————————————————————**/
		Node<T>*		root;
		size_t			size;
	
		/**———————————————————[ Constructor ]—————————————————————————————**/
		BST()
			: root() { }
		
		/**———————————————————[ Destructor ]——————————————————————————————**/
		
		/**———————————————————————[ Insert ]——————————————————————————————**
		 ** @brief Inserts a new node into the tree.
		 ** @param newNode
		 */
		void
		InsertNode(Node<T>* newNode) {
			if (!root) {
				root = newNode;
				return;
			}
			else {
				Node<T>* currentNode = root;
				while (currentNode) {
					// if the new node is less than the current node, go left
					if (newNode->data < currentNode->data) {
						// if the left node is empty, insert the new node
						if (!currentNode->left) {
							currentNode->left = newNode;
							return;
						}
						// if the left node is not empty, go left
						else {
							currentNode = currentNode->left;
						}
					}
					// if the new node is greater than the current node, go right
					else if (newNode->data > currentNode->data) {
						// if the right node is empty, insert the new node
						if (!currentNode->right) {
							currentNode->right = newNode;
						}
						// if the right node is not empty, go right
						else {
							currentNode = currentNode->right;
						}
					}
					// if the new node is equal to the current node, go left
					else {
						// if the left node is empty, insert the new node
						if (!currentNode->left) {
							currentNode->left = newNode;
							return;
						}
						// if the left node is not empty, go left
						else {
							currentNode = currentNode->left;
						}
					}
				}
			}
		}
		
		/**———————————————————————[ Search ]——————————————————————————————**
		 ** @brief Searches for a node in the tree.
		 ** @param data
		 */
		
};

/*=============================================================================================================*/

#endif //BST_HPP
