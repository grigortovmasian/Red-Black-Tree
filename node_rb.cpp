#include "node_rb.h"

CNode_RB::CNode_RB():CNode(),m_color(true) {}

CNode_RB::~CNode_RB() {}

void CNode_RB::set_black() {
	m_color = false;
}

void CNode_RB::set_red() {
	m_color = true;
}

bool CNode_RB::is_black() {
	return !m_color;
}

bool CNode_RB::is_red() {
	return m_color;
}