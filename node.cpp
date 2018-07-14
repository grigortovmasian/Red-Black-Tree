#include "node.h"

CNode::CNode():m_value(0),m_parent(nullptr),
			m_left(nullptr),m_right(nullptr) {
}

CNode::~CNode() { }

CNode * CNode::get_left() {
	return m_left;
}

CNode * CNode::get_parent() {
	return m_parent;
}

CNode * CNode::get_right() {
	return m_right;
}

int CNode::get_value() {
	return m_value;
}

void CNode::set_left(CNode * l) {
	m_left = l;
}

void CNode::set_parent(CNode * p) {
	m_parent = p;
}

void CNode::set_right(CNode * r) {
	m_right = r;
}

void CNode::set_value(int v) {
	m_value = v;
}
