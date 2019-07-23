#include <string>
#include <cstring>
#include "Decoder.h"
#include "Encoder.h"


using namespace std;

int main() {
	Encoder_Map sentance_one;
	sentance_one.alpha_to_morse("the quick brown fox jumped over the lazy dog");

	Decode_Tree sentance_two;
	//one space between characters, two spaces between words; 
	sentance_two.morse_to_alpha("- 0000 0  --0- 00- 00 -0-0 -0-  -000 0-0 --- 0-- -0  00-0 --- -00-  0--- 00- -- 0--0 0 -00  --- 000- 0 0-0  - 0000 0  0-00 0- --00 -0--  -00 --- --0");


	system("pause");
	return 0;
}