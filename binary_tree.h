#pragma once

#include "node.h"

class CBinaryTree {
public:
	CBinaryTree();
	virtual ~CBinaryTree();
	virtual CNode * insert(int value);
	CNode * find(int value);
	virtual CNode * remove(int value);
	void print_inorder();
	void print_preorder();
	void print_postorder();
protected:
	CNode * m_root;
	/* functions only for inherit clases */
	void left_rotate(CNode *);
	void right_rotate(CNode *);
	virtual void balance(CNode *);
private:
	void delete_recursive_helper();
};