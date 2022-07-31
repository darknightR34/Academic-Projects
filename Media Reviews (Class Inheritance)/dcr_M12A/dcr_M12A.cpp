#include <iostream>
using namespace std;

class Review
{
public:
	Review(string _name, double _score);
	void print() const;
protected:
	string name;
	double score;
};

class MovieReview :public Review
{
public:
	MovieReview(string _name, double _score, string _director, string _genre, int _budget);
	void print() const;
private:
	string director;
	string genre;
	int budget;
};

class ComicReview :public Review
{
public:
	ComicReview(string _name, double score, string _publisher, string _author);
	void print() const;
private:
	string publisher, author;
};

int main()
{
	cout << " Displaying Review (base) Class:" << endl;
	Review r1("Mi apa", 4.5);
	r1.print();
	cout << endl;

	cout << " Displaying MovieReview (derived) Class" << endl;
	MovieReview mr2("Jurassic Park", 4.8, "Steven Spielberg", "Sci-fi Action", 63000000);
	mr2.print();

	cout << "\n Displaying ComicReview (derived) Class" << endl;
	ComicReview cr3("Batman: The Killing Joke", 4.4, "Alan Moore", "DC Comics");
	cr3.print();

	return 0;
}

Review::Review(string _name, double _score)
	:name(_name), score(_score) {}

void Review::print()const {
	cout << " Name: " << name << endl;
	cout << " Score: " << score << " / 5.0" << endl;
}

MovieReview::MovieReview(string _name, double _score, string _director, string _genre, int _budget)
	:Review(_name,_score), director(_director), genre(_genre), budget(_budget) {}

void MovieReview::print() const {
	Review::print();
	cout << " Director: " << director << endl;
	cout << " Genre: " << genre << endl;
	cout << " Budget: $" << budget << endl;

}

ComicReview::ComicReview(string _name, double _score, string _author, string _publisher)
	:Review(_name, _score),author(_author),publisher(_publisher){}

void ComicReview::print() const {
	Review::print();
	cout << " Author: " << author << endl;
	cout << " Publisher: " << publisher << endl;
}