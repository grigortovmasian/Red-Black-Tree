#include "node_rb.h"

CNode_RB::CNode_RB():CNode(),m_colour(true) {}

CNode_RB::~CNode_RB() {}

void CNode_RB::set_black() {
	m_colour = false;
}

void CNode_RB::set_red() {
	m_colour = true;
}

bool CNode_RB::is_black() {
	return !m_colour;
}

bool CNode_RB::is_red() {
	return m_colour;
}

void CNode_RB::recolor() {
	m_colour = !m_colour;
}