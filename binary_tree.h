#pragma once

#include "node.h"

class CBinaryTree {
public:
	CBinaryTree();
	virtual ~CBinaryTree();
	virtual CNode * insert(int value);
	CNode * find(int value);
	virtual bool remove(int value);
	void print_inorder();
	void print_preorder();
	void print_postorder();
protected:
	CNode * m_root;
	/* functions only for inherit clases */
	void left_rotate(CNode *);
	void right_rotate(CNode *);
	CNode * find_prev(CNode *);
	virtual void balance_insert(CNode *);
	virtual void balance_remove(CNode *);
	CNode * insert_helper(CNode *);
	CNode * remove_helper(CNode *);
private:
	void delete_recursive_helper(CNode *);
	void inorder_recursive(CNode *);
	void preorder_recursive(CNode *);
	void postorder_recursive(CNode *);
};