#include "iostream"
#include <stdexcept>
#include <iostream>
#include <string>
#include<list>
#include <stdexcept>
#include <vector>

using namespace std;

class  Movie {
	//This Movie is an abstract class and can not be instantiated
protected:
	float _price;
public:
	Movie(float price) :_price(price) {}
	virtual string getTypeMovie() = 0;// The =0 means that this fucntion is pure virtural 
	virtual float  getPrice() = 0; // The =0 means that this fucntion is pure virtural 
	virtual double  getCharge() = 0; // The =0 means that this fucntion is pure virtural 
	void printMovieDetails() {
		cout << "Genre:  " << this->getTypeMovie() << 
			"    Price: " << this->getPrice() <<
			"    Charge: " << this->getCharge() << endl << endl;
	};
	virtual ~Movie() {};
};
class Children : public Movie{
public:
	Children(float price)
		:Movie(price) {}

	float getPrice() {
		return _price;
	}
	double getCharge() {
		return _price;
	}
	string getTypeMovie() {

		return "Children";
	}
};
class NewRelease : public Movie
{
public:
	NewRelease(float price)
		:Movie(price) {}
	float getPrice() {
		return _price;
	}
	double getCharge() {
		return _price + 2;
	}
	string getTypeMovie() {

		return "NewRelease";
	}
};
class Action : public Movie
{
public:
	Action(float price)
		:Movie(price) {}
	float getPrice() {
		return _price ;
	}
	double getCharge() {
		return _price * 2;
	}
	string getTypeMovie() {
		return "Action";
	}
};
int main() {
	Movie * movie1= new Children(3.5);
	Movie * movie2 = new NewRelease(3.5);
	Movie * movie3 = new Action(3.5);
	//size_t is unsigned integer type
	//Print the price of each object
	movie1->printMovieDetails();
	movie2->printMovieDetails();
	movie3->printMovieDetails();

	vector <Movie *> movies(3); //create vector of three bass-class pointers
	//initialize vector with various kinds of Movies
	movies[0] = movie1;
	movies[1] = movie2;
	movies[2] = movie3;
	//polymorpichally process each element in vector movies
	for (size_t i = 0; i < movies.size(); i++) { 
		//downcast pointer.
		Children *derivePtr = dynamic_cast <Children *> (movies[i]);
		//determine whether elemnts points to Children Movie
		if (derivePtr != 0) {// 0 if not a Children Movie
			cout << "This an object is ";
			cout << derivePtr->getTypeMovie();
			cout << "  Movie and the price is $" << derivePtr->getPrice() << endl;
		}//end if
	}//end for
	std::getchar();
	delete movie1;
	delete movie2;
	delete movie3;

	return 0;
}

