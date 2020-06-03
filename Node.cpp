#include "Node.h"

Node::Node(unsigned int new_puzzle[PUZZLE_SIZE][PUZZLE_SIZE]):ptr_parent(nullptr), g(0){
     copy_puzzle(new_puzzle);
	 total_manhattan_distance = 0;
	 for (unsigned int i = 0; i < PUZZLE_SIZE; i++) {
		 for (unsigned int j = 0; j < PUZZLE_SIZE; j++) {
			 unsigned int number = puzzle[i][j];
			 if (number == 0) {
				 blank_x = i;
				 blank_y = j;
			 }
			 else {
				 unsigned int goal_coordinate_x = (number - 1) / PUZZLE_SIZE;
				 unsigned int goal_coordinate_y = (number - 1) % PUZZLE_SIZE;
				 total_manhattan_distance += tile_manhattan_dist(i, j, goal_coordinate_x, goal_coordinate_y);
			 }
		 }
	 }
	 f = total_manhattan_distance;
}
Node::Node(unsigned int swapped_puzzle[PUZZLE_SIZE][PUZZLE_SIZE], unsigned int total_manhattan, unsigned int new_g, Node* parent_node,
	unsigned int new_blank_x, unsigned int new_blank_y): blank_x(new_blank_x), blank_y(new_blank_y),
	                                                     total_manhattan_distance(total_manhattan),
	                                                     g(new_g+1) {
	ptr_parent = parent_node;
	copy_puzzle(swapped_puzzle);
	f = g + total_manhattan;
}

Node::Node(const Node& rhs)
{
	this->f = rhs.f;
	this->g = rhs.g;
	this->total_manhattan_distance = rhs.total_manhattan_distance;
	this->copy_puzzle(rhs.puzzle);
	this->blank_x = rhs.blank_x;
	this->blank_y = rhs.blank_y;
	this->ptr_parent = rhs.ptr_parent;
}


bool Node::operator==(const Node& other) {
	for (unsigned int i = 0; i < PUZZLE_SIZE; i++) {
		for (unsigned int j = 0; j < PUZZLE_SIZE; j++) {
			if (puzzle[i][j] != other.puzzle[i][j]) {
				return false;
			}
		}
	}
	return true;
}

unsigned int Node::tile_manhattan_dist(unsigned int current_coordinate_x, unsigned int current_coordinate_y,
									   unsigned int goal_cordinate_x, unsigned int goal_cordinate_y) {
	int absX = (current_coordinate_x - goal_cordinate_x);
	int absY = (current_coordinate_y - goal_cordinate_y);
	return abs(absX) + abs(absY);
}
unsigned int Node::calc_total_manhattan_for_child(unsigned int before_swap_tile_manhattan_distance,
	                                              unsigned int after_swap_tile_manhattan_distance) {
	if (before_swap_tile_manhattan_distance > after_swap_tile_manhattan_distance) {
	return total_manhattan_distance - 1;
	}
	return total_manhattan_distance + 1;
}

bool Node::check_coordinates(int adj_x, int adj_y) {
	return (adj_x >= 0 && adj_y >= 0 && adj_x < PUZZLE_SIZE && adj_y < PUZZLE_SIZE);
}

void Node::swapping_tiles(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
	unsigned int temp = puzzle[x1][y1];
	puzzle[x1][y1] = puzzle[x2][y2];
	puzzle[x2][y2] = temp;
}

std::vector<Node*> Node::get_children() {
	std::vector<Node*> children;
	for (unsigned int i = 0; i < CORDINATES_SIZE; i++) {
		int adj_coordinate_x = blank_x + x_cordinates[i];
		int adj_coordinate_y = blank_y + y_cordinates[i];
		int adj_number = puzzle[adj_coordinate_x][adj_coordinate_y];
		if (check_coordinates(adj_coordinate_x, adj_coordinate_y)) {
			unsigned int goal_coordinate_x = (adj_number - 1) /PUZZLE_SIZE;
			unsigned int goal_coordinate_y = (adj_number - 1) % PUZZLE_SIZE;
			unsigned int before_swap = tile_manhattan_dist(adj_coordinate_x, adj_coordinate_y, goal_coordinate_x, goal_coordinate_y);
			unsigned int after_swap = tile_manhattan_dist(blank_x, blank_y , goal_coordinate_x, goal_coordinate_y);
			int child_total_manhattan = calc_total_manhattan_for_child(before_swap, after_swap);
			swapping_tiles(adj_coordinate_x, adj_coordinate_y, blank_x, blank_y);
			Node* child = new Node(puzzle, child_total_manhattan, g, this, adj_coordinate_x, adj_coordinate_y);
			swapping_tiles(adj_coordinate_x, adj_coordinate_y, blank_x, blank_y);
			children.push_back(child);
		}
	}
	return children;
}

const unsigned int Node::get_f(){
	return f;
}

const unsigned int Node::get_manhattan(){
	return total_manhattan_distance;
}

const unsigned int Node::get_g(){
	return g;
}

void Node::set_f(unsigned int new_f){
	f = new_f;
}

void Node::set_g(unsigned int new_g){
	g = new_g;
}

void Node::copy_puzzle(const unsigned int parent_puzzle[][PUZZLE_SIZE]) {
	for (size_t i = 0; i < PUZZLE_SIZE; i++) {
		for (size_t j = 0; j < PUZZLE_SIZE; j++) {
			puzzle[i][j] = parent_puzzle[i][j];
		}
	}
}

void Node::printPuzzle() const {
	for (size_t i = 0; i < PUZZLE_SIZE; i++) {
		for (size_t j = 0; j < PUZZLE_SIZE; j++) {
			std::cout << puzzle[i][j];
		}
		std:: cout << std::endl;
	}
	/*	std::cout << "Manhattan value: " << total_manhattan_distance << std::endl;
		std::cout << "G value: " << g << std::endl;
		std::cout << "F value: " << f << std::endl;
		std::cout << std::endl;*/
}



