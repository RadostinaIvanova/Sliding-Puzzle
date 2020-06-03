#pragma once
#include "Node.h"

void printArr(Node* current){
	if (current == nullptr) {
		return;
	}
	printArr(current->ptr_parent);
	current->printPuzzle();
	std::cout << std::endl; 
}
bool compareNodes(Node* n1, Node* n2) {
	return (n1->get_f() > n2->get_f());
}


void deleteNodes(std::vector<Node*> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		delete vec[i];
	}
}

int inversionsCounter(int arr[]) {
	int inversion_cnt = 0;
	for (int i = 0; i < 9 - 1; i++)
		for (int j = i + 1; j < 9; j++)
			if (arr[j] && arr[i] && arr[i] > arr[j])
				inversion_cnt++;
	return inversion_cnt;
}
bool isSolvable(unsigned int puzzle[PUZZLE_SIZE][PUZZLE_SIZE]) {
	int inversion_cnt = inversionsCounter((int*)puzzle);
	return (inversion_cnt % 2 == 0);
}

unsigned int isItInList(Node* child, std::vector<Node*> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		if ((*child) == *vec[i]) {
			return i;
		}
	}
	return vec.size();
}
class Puzzle {
public:
	Puzzle(unsigned int new_puzzle[PUZZLE_SIZE][PUZZLE_SIZE]) {
		if (!isSolvable(new_puzzle)) {
			std::cout << "The puzzle is not solvable" << std::endl;
		}
		else {
			Node* starting_node = new Node(new_puzzle);
			std::vector<Node*> open_list;
			std::vector<Node*> closed_list;
			open_list.push_back(starting_node);
			while (!open_list.empty()) {
				std::sort(open_list.begin(), open_list.end(), compareNodes);
				Node* parent = new Node(*open_list.back());
				closed_list.push_back(parent);
				open_list.pop_back();
				if (parent->get_manhattan() == 0) {
					std::vector<Node> arrPrint;
					std::cout << "Printing steps: " << std::endl;
					printArr(parent);
					deleteNodes(open_list);
					deleteNodes(closed_list);
					break;
				}
				std::vector<Node*> children = parent->get_children();
				while (!children.empty()) {
					Node* child = new Node(*children.back());
					children.pop_back();
					unsigned int index = isItInList(child, open_list);
					bool opened = (index != open_list.size());
					bool closed = (isItInList(child, closed_list) != closed_list.size());
					if (!closed && (!opened || child->get_g() < open_list[index]->get_g())) {
						child->set_g(1 + parent->get_g());
						child->set_f(child->get_g() + child->get_manhattan());
						if (opened) {
							open_list.erase(open_list.begin() + index);
						}
						open_list.push_back(child);
					}
				}
			}
		}
	}
};


