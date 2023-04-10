#include "../../Text.h"
#include "test_text.h"

void testText(std::string str, int expected_num_of_words, int num_test) {
	Text text(str);

	if (text.getSize() == expected_num_of_words) {
		std::cout << "Test " << num_test << " passed \n";
	}
	else {
		std::cout << "Test " << num_test << " failed \n";
	}

	std::cout << "{ Text: " << str << ", Vector: " ;

	for (int i = 0; i < text.getSize(); i++) {
		std::cout << text[i].getWord() << " ";
	}

	std::cout << std::endl;
	std:: cout << "  Text size: " << expected_num_of_words << ",\t Vector size: " << text.getSize() << " }" << std::endl;
}

void testingTextClass() {
	testText("Hello world bbb", 3, 1);
	testText("MIREA", 1, 2);
	testText("", 0, 3);
	testText("You spin me right 'round, baby, right 'round", 8, 4);
}