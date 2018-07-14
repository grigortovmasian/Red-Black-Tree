#pragma once

struct CNode {
public:
	CNode();
	virtual ~CNode();
	void set_parent(CNode *);
	void set_left(CNode *);
	void set_right(CNode *);
	void set_value(int value);
	CNode * get_parent();
	CNode * get_left();
	CNode * get_right();
	int get_value();

private:
	int m_value;
	CNode *m_left;
	CNode *m_right;
	CNode *m_parent;
};