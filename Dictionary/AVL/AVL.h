// AVL.h -- declaration of AVL-Tree class,				//
// based in Binary Tree, but with better balanced factor//
// -----------------------------------------------------//
// @author Yurii Krasniuk,								//
// Igor Sykorsky KPI									//
//------------------------------------------------------//
// @based on works by Prof. Wade Fagen-Ulmschneider,	//
// @author Eric Huber									//
// University of Illinois Urbana-Champaign				//
//------------------------------------------------------//

// This code based on original works of Prof., and has a
// the main ideas & concepts as shown in lectures about
// AVL (Binary Search) Tree

#ifndef DICTIONARY_AVL_AVL_H_
#define DICTIONARY_AVL_AVL_H_
#include <utility>		// swap()
#include <algorithm>	// max()
#include <stdexcept>	// process exceptions


template <class K, class D>
class AVL
{
public:
	// Constructor, set pointer to null
	AVL() : m_root(nullptr) {}

	// find, insert, remove
	// See AVL.hpp for realization
	const D& find(const K& key) const;
	void insert(const K& key, const D& data);
	const D& remove(const K& key);

	// contains is like a find, but
	// it returns a bool type whether
	// the item exist or not
	// This instance, don't throw exceptions
	bool contains(const K& key) const;

private:
	class TreeNode
	{
	public:
		// Data and Key 
		const K& key;
		const D& data;
		// Pointer to left & right child and height of subtree
		TreeNode* left;
		TreeNode* right;
		int height;
	};

	TreeNode* m_root;

	// We need some internal helper functions,
	// that we will use only in our realization
	// for public methods like find, remove, etc.

	// Find the node with this key and return its data.
	TreeNode*& m_find(const K& key, TreeNode*& cur) const;

	// Actually remove the node that this pointer points to.
	// (This may need to invoke _iopRemove in some cases.)
	const D& m_remove(TreeNode*& node);

	// This is called by "insert" to recursively find the insertion point,
	// insert, and rebalance as it returns.
	void m_find_and_insert(const K& key, const D& data, TreeNode*& cur);
	// This is called by "remove" to recursively remove the correct node
	// and rebalance as it returns.
	const D& m_find_and_remove(const K& key, TreeNode*& cur);

	// _iopRemove: targetNode is the node to remove, we'll want to find the
	// in-order predecessor (IOP) and swap the target with it for removal.
	// To recursively find the IOP, we traverse over the ancestors of the
	// IOP until we find it. The single-argument version of _iopRemove calls
	// the other version of m_iopRemove on the first node to the left, which
	// is the earliest ancestor; this makes things more convenient and helps
	// us avoid making a mistake in the logic.
	const D& m_iopRemove(TreeNode*& targetNode);

	// _swap_nodes: This swaps the node positions (rewiring pointers as
	// necessary) and also swaps the node heights. The intended usage is
	// that node1 is higher (such as some internal node to remove) and node2
	// is one of its descendants (especially the IOP). After calling this,
	// the original node pointers that were passed to the function shouldn't
	// be directly used again, because it's hard to tell what they point to
	// afterward. Instead, the function returns a pointer, by reference,
	// that is the updated node1 pointer.
	TreeNode*& m_swap_nodes(TreeNode*& node1, TreeNode*& node2);

	// Update the height of the specified node, based on the existing
	// heights of its children, which we assume are correct. (This function
	// is not recursive. It can do a fast update of the specified node but
	// this relies on the node's children already having correct, updated
	// heights.)
	void m_updateHeight(TreeNode*& cur);

	// Ensure that the balance factor of specified node has magnitude
	// no greater than 1. This calls rotation functions as necessary to
	// rebalance the subtree rooted here. It also records the updated height
	// in the node. These changes need to cascade upward, so after we call
	// this function, we need to make sure that it also gets called on those
	// nodes on the path of ancestry up towards the root node.
	void _ensureBalance(TreeNode*& cur);

	// These functions perform the specified balancing rotation on the
	// subtree that is rooted at the specified node.
	// Refer to the implementations of _rotateLeft and _rotateRightLeft
	// for more details. The other functions are similar.
	void m_rotateLeft(TreeNode*& cur);
	void m_rotateRight(TreeNode*& cur);
	void m_rotateRightLeft(TreeNode*& cur);
	void m_rotateLeftRight(TreeNode*& cur);

	// _get_height: A wrapper for checking the height of a subtree.
	// If a node doesn't exist (nullptr), then return -1.
	// Otherwise, return the node's previously-recorded subtree height.
	// (This function was just shown as "height(...)" in some of the lecture
	//  videos. It's been renamed here to clarify that it's different from
	//  the node's height member variable.)
	int m_get_height(TreeNode*& node) const {
		if (!node)
		{
			// A non-existent node has a height of 1
			return -1;
		}
		else
		{
			// We assume that an existing node already has an updated height
			return node->height;
		}
	}

	// _get_balance_factor: A helper function for safely calculating the balance
	// factor of the node that is passed as the argument.
	int m_get_balance_factor(TreeNode*& node) const {
		if (!node)
		{
			// A non-existent node has a balance factor of 0
			return 0;
		}
		else
		{
			// Calculate the balance factor safely and return it.
			return m_get_height(node->right) - m_get_height(node->left);
		}
	}

public:
	// empty : Tells whether the tree is empty or not.
	bool empty() const
	{
		return !m_root;
	}

	// clear_tree: Remove the root item until the tree is empty.
	void clear_tree()
	{
		while (m_root)
		{
			// As long as the head pointer isn't null, we can just look at
			// what the key is and call remove based on that.
			remove(head_->key);
		}
	}
	// Destructor: We just clear the tree.
	~AVL()
	{
		clear_tree();
	}

	// printInOrder: Print the tree contents to std::cout using an in-order
	// traversal. The "_printInOrder" version is for internal use by the
	// public wrapper function "printInOrder".
public:
	void printInOrder() const;
private:
	void m_printInOrder(TreeNode* node) const;
};

// Sometimes, your header files might include another header file with
// further templated definitions. The .h and .hpp are both just filename
// extensions for header files.
#include "AVL.hpp"

#endif // !DICTIONARY_AVL_AVL_H_
