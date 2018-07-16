#include <iostream>
#include "binary_tree.h"

void test() {
	CBinaryTree obj;
	if (obj.insert(5)) {
		std::cout << "Inserted" << std::endl;
	}
	else {
		std::cout << "Failed to insert: duplication" << std::endl;
	}
	if (obj.insert(25)) {
		std::cout << "Inserted" << std::endl;
	}
	else {
		std::cout << "Failed to insert: duplication" << std::endl;
	}
	if (obj.insert(220)) {
		std::cout << "Inserted" << std::endl;
	}
	else {
		std::cout << "Failed to insert: duplication" << std::endl;
	}
	if (obj.insert(3)) {
		std::cout << "Inserted" << std::endl;
	}
	else {
		std::cout << "Failed to insert: duplication" << std::endl;
	}
	if (obj.insert(1)) {
		std::cout << "Inserted" << std::endl;
	}
	else {
		std::cout << "Failed to insert: duplication" << std::endl;
	}
	if (obj.insert(4)) {
		std::cout << "Inserted" << std::endl;
	}
	else {
		std::cout << "Failed to insert: duplication" << std::endl;
	}
	if (obj.insert(220)) {
		std::cout << "Inserted" << std::endl;
	}
	else {
		std::cout << "Failed to insert: duplication" << std::endl;
	}
	if (obj.insert(6)) {
		std::cout << "Inserted" << std::endl;
	}
	else {
		std::cout << "Failed to insert: duplication" << std::endl;
	}
/*
	if (obj.find(22)) {
		std::cout << "Found" << std::endl;
	}
	else {
		std::cout << "Not Found" << std::endl;
	}

	if (obj.find(1)) {
		std::cout << "Found" << std::endl;
	}
	else {
		std::cout << "Not found" << std::endl;
	}

	if (obj.find(220)) {
		std::cout << "Found" << std::endl;
	}
	else {
		std::cout << "Not Found" << std::endl;
	}

	if (obj.remove(25)) {
		std::cout << "Success" << std::endl;
	} else {
		std::cout << "Failed" << std::endl;
	}
	if (obj.remove(6)) {
		std::cout << "Success" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}
	if (obj.remove(4)) {
		std::cout << "Success" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}
	
	if (obj.remove(3)) {
		std::cout << "Success" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	if (obj.remove(5)) {
		std::cout << "Success" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}
	if (obj.remove(1)) {
		std::cout << "Success" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	if (obj.remove(220)) {
		std::cout << "Success" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}
	*/

	obj.print_inorder();
	obj.print_postorder();
	obj.print_preorder();

	int a;
	std::cin >> a;
}

int main() {
	test();
	return 0;
}