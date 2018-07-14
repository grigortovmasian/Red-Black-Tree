#pragma once

#include "node.h"

class CNode_RB : public CNode {
public:
	CNode_RB();
	~CNode_RB();
	void set_black();
	void set_red();
	bool is_black();
	bool is_red();


private:
	/* 1 - Red (By default)
	 * 0 - Black
	 */
	bool m_color;
};