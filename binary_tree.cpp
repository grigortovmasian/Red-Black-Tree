#include "binary_tree.h"
#include<iostream>

CBinaryTree::CBinaryTree():m_root(nullptr) {}

CBinaryTree::~CBinaryTree() {
		delete_recursive_helper(m_root);
}

CNode * CBinaryTree::insert(int value) {
	CNode * new_node = new CNode();
	new_node->set_value(value);

	return insert_helper(new_node);
}

CNode * CBinaryTree::find(int value) {

	CNode * ret = m_root;

	while (ret)
	{
		if (ret->get_value() == value)
			return ret;

		if (ret->get_value() > value)
			ret = ret->get_left();
		else
			ret = ret->get_right();
	}

	return ret;
}

bool CBinaryTree::remove(int value) {

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

	remove_helper(rm_node);
	return true;
}
void CBinaryTree::print_inorder() {
	inorder_recursive(m_root);
}

void CBinaryTree::print_postorder() {
	postorder_recursive(m_root);
}

void CBinaryTree::print_preorder() {
	preorder_recursive(m_root);
}

void CBinaryTree::left_rotate(CNode * node) {

	CNode * l_node = node->get_parent();
	if (l_node == nullptr)
		return;

	if (l_node == m_root)
		m_root = node;

	if (l_node->get_parent())
		if (l_node->get_parent()->get_left() == l_node)
			l_node->get_parent()->set_left(node);
		else
			l_node->get_parent()->set_right(node);

	node->set_parent(l_node->get_parent());
	l_node->set_parent(node);
	l_node->set_right(node->get_left());
	node->set_left(l_node);
}

void CBinaryTree::right_rotate(CNode * node) {

	CNode * r_node = node->get_parent();
	if (r_node == nullptr)
		return;

	if (r_node == m_root)
		m_root = node;

	if (r_node->get_parent())
		if (r_node->get_parent()->get_left() == r_node)
			r_node->get_parent()->set_left(node);
		else
			r_node->get_parent()->set_right(node);

	node->set_parent(r_node->get_parent());
	r_node->set_parent(node);
	r_node->set_left(node->get_right());
	node->set_right(r_node);
}

void CBinaryTree::balance_insert(CNode *) {}

void CBinaryTree::balance_remove(CNode *) {}

void CBinaryTree::delete_recursive_helper(CNode * node) {

	if (node == nullptr)
		return;

	delete_recursive_helper(node->get_left());
	delete_recursive_helper(node->get_right());
	delete node;
}

CNode * CBinaryTree::find_prev(CNode * node) {

	CNode * ret = node->get_left();
	if (ret == nullptr)
		return ret;
	while (ret->get_right())
	{
		ret = ret->get_right();
	}

	return ret;
}

void CBinaryTree::postorder_recursive(CNode * node) {

	if (node == nullptr)
		return;

	postorder_recursive(node->get_left());

	postorder_recursive(node->get_right());

	std::cout << "value = " << node->get_value() << std::endl;

}

void CBinaryTree::preorder_recursive(CNode * node) {

	if (node == nullptr)
		return;

	std::cout << "value = " << node->get_value() << std::endl;

	preorder_recursive(node->get_left());

	preorder_recursive(node->get_right());
}

void CBinaryTree::inorder_recursive(CNode * node) {

	if (node == nullptr)
		return;

	inorder_recursive(node->get_left());

	std::cout << "value = " << node->get_value() << std::endl;

	inorder_recursive(node->get_right());
}

CNode * CBinaryTree::insert_helper(CNode * new_node) {

	if (m_root == nullptr) {
		m_root = new_node;
		return new_node;
	}

	CNode * iter = m_root;
	while (true)
	{
		if (iter->get_value() == new_node->get_value()) {
			delete new_node;
			return nullptr;
		}

		if (iter->get_value() > new_node->get_value())
			if (iter->get_left())
				iter = iter->get_left();
			else {
				new_node->set_parent(iter);
				iter->set_left(new_node);
				return new_node;
			}
		else
			if (iter->get_right())
				iter = iter->get_right();
			else {
				new_node->set_parent(iter);
				iter->set_right(new_node);
				return new_node;
			}
	}

}

CNode * CBinaryTree::remove_helper(CNode * rm_node) {

	CNode * ret;

	if (!rm_node->get_left() && !rm_node->get_right()) {
		if (rm_node == m_root) {
			delete m_root;
			m_root = nullptr;
		}
		else {
			if (rm_node->get_parent()->get_left() == rm_node)
				rm_node->get_parent()->set_left(nullptr);
			else
				rm_node->get_parent()->set_right(nullptr);

			delete rm_node;
		}

		return nullptr;
	}

	if (rm_node->get_left()) {
		ret = rm_node->get_left();
		rm_node->get_left()->set_parent(rm_node->get_parent());
		if (rm_node == m_root)
			m_root = rm_node->get_left();
		else
			if (rm_node->get_parent()->get_left() == rm_node)
				rm_node->get_parent()->set_left(rm_node->get_left());
			else
				rm_node->get_parent()->set_right(rm_node->get_left());
	}
	else {
		ret = rm_node->get_right();
		rm_node->get_right()->set_parent(rm_node->get_parent());

		if (rm_node == m_root)
			m_root = rm_node->get_right();
		else
			if (rm_node->get_parent()->get_left() == rm_node)
				rm_node->get_parent()->set_left(rm_node->get_right());
			else
				rm_node->get_parent()->set_right(rm_node->get_right());
	}

	delete rm_node;
	return ret;
}