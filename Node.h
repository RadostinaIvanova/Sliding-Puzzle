#ifndef _NODE_H
#define _NODE_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <queue>

const unsigned int PUZZLE_SIZE = 3;
const unsigned int CORDINATES_SIZE = 4;
const int x_cordinates[CORDINATES_SIZE] = { -1 , 1 , 0 , 0 }; 
const int y_cordinates[CORDINATES_SIZE] = { 0 , 0 , -1 , 1 }; 

class Node {
private:
	unsigned int puzzle[PUZZLE_SIZE][PUZZLE_SIZE];
	unsigned int g;
	unsigned int total_manhattan_distance;
	unsigned int f;
	unsigned int blank_x;
	unsigned int blank_y;
public:
	Node* ptr_parent;
 
	void copy_puzzle(const unsigned int parent_puzzle[][PUZZLE_SIZE]);
	bool check_coordinates(int adj_x, int adj_y);
	void swapping_tiles(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
	unsigned int calc_total_manhattan_for_child(unsigned int parent_tile_manhattan, unsigned int child_tile_manhattan);///calculates the total manhatta; // distance for child based on the parent's one
    unsigned int tile_manhattan_dist(unsigned int current_coordinate_x,unsigned int current_coordinate_y, //calculates the manhattan distance
		                             unsigned int goal_coordinate_x ,  unsigned int goal_coordinate_y);//for tile before and after swap;
	

public:
	Node(unsigned int new_puzzle[PUZZLE_SIZE][PUZZLE_SIZE]);
	Node(unsigned int swapped_puzzle[PUZZLE_SIZE][PUZZLE_SIZE], unsigned int total_manhattan, unsigned int new_g, Node* parent_node,
	unsigned int new_blank_x, unsigned int new_blank_y);
	Node(const Node& rhs);
	bool operator==(const Node& other);

	std::vector<Node*> get_children();
	const unsigned int get_f();
	const unsigned int get_manhattan();
	const unsigned int get_g();
	void set_f(unsigned int new_f);
	void set_g(unsigned int new_g);
	void printPuzzle() const;
};
#endif