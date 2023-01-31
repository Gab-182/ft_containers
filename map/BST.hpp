#ifndef BST_HPP
#define BST_HPP


/*=============================================================================================================*/
# include "../utils/pair.hpp"
# include <iostream>
# include <memory>
# include <map>
/*=============================================================================================================*/

template <class T>
class Node {
	public:
	// pair<const Key, T>	data;
		T				data;
		Node*			left;
		Node*			right;
		
		Node()
			: data(0), left(), right() { }
			
		Node(T data)
			: data(data), left(), right() { }
};

/*=============================================================================================================*/
template <class Key,class T, class Allocator = std::allocator< ft::pair< const Key, T > > >
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
							break ;
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
							break ;
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
							break ;
						}
						// if the left node is not empty, go left
						else {
							currentNode = currentNode->left;
						}
					}
				}
			}
			this->size++;
		}
		
		/**———————————————————————[ Search ]——————————————————————————————**
		 ** @brief Searches for a node in the tree.
		 ** @param data
		 */
		
		/**———————————————————————[ Remove ]——————————————————————————————**
		 * @brief Removes a node from the tree.
		 */
		 
		/**———————————————————————[ Print ]———————————————————————————————**
		 * @brief Prints the tree from left to right.
		 */
		void
		PrintTree(Node<T>* current) {
			if (!current) {
				std::cout << "The tree is empty." << std::endl;
				return;
			}
			else if (current->left)
				std::cout << "L ➤ " << current->left->data << RESET << std::endl;
			else if (current->right)
				std::cout << "R ➤ " << current->right->data << RESET << std::endl;
			if (current->left)
				current = current->left;
			else if (current->right)
				current = current->right;
			else
				return;
			PrintTree(current);
		}
		
		/**—————————————————————[ Find root node ]————————————————————————**
		 * @brief return the root node for the tree.
		 */
		Node<T>*
		RootNode() {
			return (this->root);
		}
}

/*=============================================================================================================*/

#endif //BST_HPP
