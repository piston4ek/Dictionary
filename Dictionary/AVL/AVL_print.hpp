// AVL_print.hpp -- AVL methods related with output,	//
// by using some types of print(inOrder etc.)			//
// -----------------------------------------------------//
// @author Yurii Krasniuk,								//
// Igor Sykorsky KPI									//
//------------------------------------------------------//
#ifndef AVL_PRINT_HPP
#define AVL_PRINT_HPP
#include "AVL.hpp"

// public interface for m_printInOrder
template <typename K, typename D>
void AVL<K, D>::printInOrder(std::ostream& os) const 
{
	m_printInOrder(os, m_root);
}

// printInOrder: Print the tree contents to std::cout using an in-order
// traversal. The "m_printInOrder" version is for internal use by the
// public wrapper function "printInOrder".
template <typename K, typename D>
void AVL<K, D>::m_printInOrder(std::ostream& os, TreeNode* node) const
{
	if (node == nullptr) {
		return;
	}

	// First recur to left child
	m_printInOrder(os, node->left);

	// Then print node
	os << node->key << '\t' << node->data << std::endl;

	// Now recur on right child
	m_printInOrder(os, node->right);
}

#endif // !AVL_PRINT_HPP