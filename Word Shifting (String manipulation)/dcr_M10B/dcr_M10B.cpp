#include <iostream>
#include <string>

using namespace std;

void rotate(string& word);
void translate(string sentence[]);

int main()
{
	string sentence[10];
	
	cout << " Enter a 10-word sentence:\n ";
	for (int i = 0; i < 10; i++) {
		cin >> sentence[i];
	}

	cout << " Translated sentence:\n ";
	translate(sentence);
	cout << endl;
	return 0;
}

void translate(string sentence[]) {
	string translation[10];
	string ay = "ay";

	for (int i = 0; i < 10; i++) {
		string word = sentence[i];

		rotate(word);
		word += ay;

		translation[i] += word;

		cout << translation[i] << ' ';
	}
}

void rotate(string& word) {
	char temp;

	for (int i = 0; i < (word.length() - 1); i++) {

		temp = word[i + 1];
		word[i + 1] = word[i];
		word[i] = temp;
	
	}
}