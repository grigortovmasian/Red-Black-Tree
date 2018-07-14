#pragma once

#include "binary_tree.h"

class CRedBlackTree : public CBinaryTree {
public:
	CRedBlackTree();
	~CRedBlackTree();
	virtual CNode * insert(int);
	virtual CNode * remove(int);
protected:
	virtual void balance(CNode *);
};