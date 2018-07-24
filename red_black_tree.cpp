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
	CNode * rm_node = find(value);
	if (rm_node == nullptr)
		return false;

	if (rm_node->get_left() && rm_node->get_right()) {
		CNode * prev = find_prev(rm_node);
		int tmp = rm_node->get_value();
		rm_node->set_value(prev->get_value());
		prev->set_value(tmp);
		rm_node = prev;
	}

	bool v_colour = dynamic_cast<CNode_RB *> (rm_node)->is_red();

	CNode * parent = rm_node->get_parent();
	rm_node = remove_helper(rm_node);

	bool u_colour;
	if (rm_node)
		u_colour = dynamic_cast<CNode_RB *> (rm_node)->is_red();
	else
		u_colour = false;

	if (u_colour || v_colour) {
		if (rm_node)
			dynamic_cast<CNode_RB *> (rm_node)->set_black();
	} else {
		CNode_RB * tmp = new CNode_RB();
		tmp->set_black();
		tmp->set_parent(parent);
		if (rm_node == nullptr)
			rm_node = tmp;
		balance_remove(rm_node);
		delete tmp;
	}

	return true;
}

void CRedBlackTree::balance_remove(CNode * node) {
	if (node == m_root)
		return;

	CNode * sibling;
	if (node->get_parent()->get_left() && node->get_parent()->get_right()) {
		if (node->get_parent()->get_left() == node)
			sibling = node->get_left()->get_right();
		else
			sibling = node->get_left()->get_left();

	} else {
		if (node->get_parent()->get_left())
			sibling = node->get_parent()->get_left();
		else
			sibling = node->get_left()->get_right();
	}

	bool sib_col = dynamic_cast<CNode_RB *> (sibling)->is_red();

	if (sib_col) {
		CNode * new_sib;
		if (node->get_parent()->get_left() == sibling) {
			new_sib = sibling->get_right();
			right_rotate(sibling);
		} else {
			new_sib = sibling->get_left();
			left_rotate(sibling);
		}
		sibling = new_sib;
	}

	/* Now sibling is black and not NULL */

	bool sib_r_col;
	bool sib_l_col;
	bool par_col;
	CNode * parent = sibling->get_parent();
	par_col = dynamic_cast<CNode_RB *> (parent)->is_red();

	if (sibling->get_left())
		sib_l_col = dynamic_cast<CNode_RB *> (sibling->get_left())->is_red();
	else
		sib_l_col = false;
	if (sibling->get_right())
		sib_r_col = dynamic_cast<CNode_RB *> (sibling->get_right())->is_red();

	if (!sib_l_col && !sib_r_col) {
		dynamic_cast<CNode_RB *> (sibling)->recolor();
		if (par_col) {
			dynamic_cast<CNode_RB *> (parent)->set_black();
			return;
		}

	} else {
		if (sibling->get_parent()->get_left() == sibling) {
			if (sib_l_col) {
				right_rotate(sibling);
			} else {
				dynamic_cast<CNode_RB *> (sibling)->recolor();
				dynamic_cast<CNode_RB *> (sibling->get_right())->set_black();
				left_rotate(sibling->get_right());
				right_rotate(sibling->get_parent());
			}
		} else {
			if (sib_r_col) {
				left_rotate(sibling);
			} else {
				dynamic_cast<CNode_RB *> (sibling)->set_black();
				dynamic_cast<CNode_RB *> (sibling->get_right())->set_black();
				right_rotate(sibling->get_left());
				left_rotate(sibling->get_parent());
			}
		}

		if (par_col) {
			return;
		}
	}

	balance_remove(parent);
	return;
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