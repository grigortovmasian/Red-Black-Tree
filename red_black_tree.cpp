#include "red_black_tree.h"

CRedBlackTree::CRedBlackTree():CBinaryTree() {}

CRedBlackTree::~CRedBlackTree() {}

CNode * CRedBlackTree::insert(int value) {
	CNode_RB * new_node = new CNode_RB();
	new_node->set_value(value);
	if (insert_helper(new_node) == nullptr)
		return nullptr;

	balance_insert(new_node);
	return new_node;
}

bool CRedBlackTree::remove(int value) {

}

void CRedBlackTree::balance_remove(CNode * node) {

}

void CRedBlackTree::balance_insert(CNode * node) {

	CNode_RB * rb_node = dynamic_cast<CNode_RB *> (node);

	if (node == m_root) {
		rb_node->set_black();
		return;
	}

	/* Get parent and uncle colors */
	CNode_RB * rb_node_parent = dynamic_cast<CNode_RB *> (node->get_parent());
	bool par_col;

	/*if parent blacknot need to do something */
	if (rb_node_parent->is_black())
		return;
	else
		par_col = true;

	CNode * uncle;
	bool uncle_col;
	if (node->get_parent()->get_parent()->get_left() == node->get_parent())
		uncle = node->get_parent()->get_parent()->get_right();
	else
		uncle = node->get_parent()->get_parent()->get_left();

	if (uncle == nullptr)
		uncle_col = false;
	else
		uncle_col = dynamic_cast<CNode_RB *> (uncle)->is_red();

	/*case when  uncle is red */
	if (uncle_col) {
		dynamic_cast<CNode_RB *> (node->get_parent())->set_black();
		dynamic_cast<CNode_RB *> (uncle)->set_black();
		dynamic_cast<CNode_RB *> (node->get_parent()->get_parent())->set_red();
		balance_insert(node->get_parent()->get_parent());
		return;
	}

	/* 4 cases when uncle is black */
	if (node->get_parent()->get_parent()->get_left() == node->get_parent()) {
		if (node->get_parent()->get_left() == node) {
			dynamic_cast<CNode_RB *> (node->get_parent())->recolor();
			dynamic_cast<CNode_RB *> (node->get_parent()->get_parent())->recolor();
			right_rotate(node->get_parent());
		} else {
			dynamic_cast<CNode_RB *> (node)->recolor();
			dynamic_cast<CNode_RB *> (node->get_parent()->get_parent())->recolor();
			left_rotate(node);
			right_rotate(node);
		}
	} else {
		if (node->get_parent()->get_left() == node) {
			dynamic_cast<CNode_RB *> (node)->recolor();
			dynamic_cast<CNode_RB *> (node->get_parent()->get_parent())->recolor();
			right_rotate(node);
			left_rotate(node);
		} else {
			dynamic_cast<CNode_RB *> (node->get_parent())->recolor();
			dynamic_cast<CNode_RB *> (node->get_parent()->get_parent())->recolor();
			left_rotate(node->get_parent());
		}
	}

}