#include "binary_tree.h"

CBinaryTree::CBinaryTree():m_root(nullptr) {}

CBinaryTree::~CBinaryTree() {

}

CNode * CBinaryTree::insert(int value) {
	CNode * new_node = new CNode();
	new_node->set_value(value);

	if (m_root == nullptr) {
		m_root = new_node;
		return new_node;
	}

	CNode * iter = m_root;
	while (true)
	{
		if (iter->get_value() == value)
			return nullptr;

		if (iter->get_value() > value)
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

CNode * CBinaryTree::remove(int value) {

}
void CBinaryTree::print_inorder() {

}

void CBinaryTree::print_postorder() {

}

void CBinaryTree::print_preorder() {

}

void CBinaryTree::left_rotate(CNode * node) {

}

void CBinaryTree::right_rotate(CNode * node) {

}

void CBinaryTree::balance(CNode *) {

}

void CBinaryTree::delete_recursive_helper() {

}