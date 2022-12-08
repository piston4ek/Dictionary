// AVL.h -- declaration & definition of AVL-Tree class, //
// based in Binary Tree, but with better balanced factor//
// -----------------------------------------------------//
// @author Yurii Krasniuk,								//
// Igor Sykorsky KPI									//
//														//
// @based on works by Prof. Wade Fagen-Ulmschneider,	//
// University of Illinois Urbana-Champaign				//
//------------------------------------------------------//

// This code based on original works of Prof., and has a
// the main ideas & concepts as shown in lectures about
// AVL (Binary Search) Tree

#ifndef AVL_H_
#define AVL_H_
#include <utility>		// swap()
#include <algorithm>	// max()


template <class K, class D>
class AVL
{
public:

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
};


#endif // !AVL_H_
