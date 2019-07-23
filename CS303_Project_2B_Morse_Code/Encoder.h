#pragma once
#include<iostream>?
#include <map>?
#include <string>?
#include <cstring>?
#include <fstream>?

using namespace std;

struct Encoder_Map {

	map<char, string>alpha_to_morse_encoder; // declares the map
	map<char, string>::iterator iter; //makes it so you can print the map

	//takes in the file and emplaces contents into map
	Encoder_Map() {
		ifstream fin("morse.txt"); //reads in file
		if (fin.fail()) { //checks if file is read in, if not, exits code as failure
			cout << "Failed to open morse.txt";
			system("PAUSE");
			exit(EXIT_FAILURE);
		}
		char letter;
		string morse = "", line = "";
		while (fin.eof() != true) {
			fin >> line; //streams in line for letter and morse code
			letter = line.at(0); //takes in the first part of the line (letter)
			morse = morse.append(line, 1, line.length()); // variably takes in the rest of the line
			morse += " ";
			alpha_to_morse_encoder.emplace(letter, morse); //splits the line into the map
			morse = ""; //resets morse to be appended to again
		}
	}
	void print_map() {
		//to print out map
		for (iter = alpha_to_morse_encoder.begin(); iter != alpha_to_morse_encoder.end(); ++iter) {
			cout << iter->first << ":" << iter->second << endl;
		}
	}
	void alpha_to_morse(string word) {
		for (int i = 0; i < word.length(); ++i) {
			if (alpha_to_morse_encoder.count(tolower(word[i]))) { //checks to see if the letter is equal to target
				cout << alpha_to_morse_encoder.at(tolower(word[i])); //outputs the letter
			}
		}
		cout << endl;
	}
};