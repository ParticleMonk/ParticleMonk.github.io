#pragma once
#include "BTNode.h"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

class Decode_Tree {
	//creates a binary tree from struct BTNodes, can translate morse code to alpha 
public:
	Decode_Tree() {
		//constructor for the class
		ifstream fin;
		char letter;
		string morse = "", line = "";
		fin.open("morse.txt");
		if (fin.fail()) {
			//in case of file not found 
			cout << "File not found, exiting system" << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
		while (!fin.eof()) {
			BTNode<string>* current = root;
			fin >> line;
			//line gets broken into two parts, one for the alpha charater at the front
			//and the other is the morse code line 
			letter = line.at(0);
			morse = morse.append(line, 1, line.length());
			while (morse.length() != 0) {
				//the morse code length is variable so we use a while loop 
				if (morse.at(0) == '.') {
					//going left
					if (current->left == NULL) {
						//creats a dummy node is nothing exits 
						current->left = new BTNode<string>("dummy");
					}
					current = current->left;
				}
				else {
					//symbol is "_" so we are going right 
					if (current->right == NULL) {
						//creates a dummy node is nothing exists
						current->right = new BTNode<string>("dummy");
					}
					current = current->right;
				}
				if (morse.size() == 1) {
					//inserting alpha character from txt file
					current->data = letter;
				}
				//decrements the morse code line 
				morse.erase(0, 1);
			}

		}
	}

	void morse_to_alpha(string morse) {
		//for translating a string from alpha to morse
		//NOTE: can take in andy letter, numbers or special characters if they are passed
		//in by strings. They are converted to whitespace characters
		string translation;
		BTNode<string>* position = root;
		for (int i = 0; i < morse.length(); ++i) {
			//symbols chosen for dot '0' and dash '-'
			if (morse[i] == '0') {
				//dot so we go left
				position = position->left;
			}
			else if (morse[i] == '-') {
				//dash so we go right 
				position = position->right;
			}
			else {
				//at end of current morse code so we pull the alpha character associated
				translation += position->data;
				//reset the pointer to the root of the tree
				position = root;
			}
		}
		translation += position->data;
		cout << translation << endl;

	}

private:
	//root of the binary tree, whitespace chosen as character to allow 
	//sentences to be translated 
	BTNode<string>* root = new BTNode<string>(" ");

};
