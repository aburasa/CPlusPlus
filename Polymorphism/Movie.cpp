#include "iostream"
#include <stdexcept>
#include <iostream>
#include<string>
using namespace std;
class Movie{
public:
	enum Type { ChildrenMovie, ActionMovie, NewRelaseMovie};

	Movie(Type type, float price) :_type(type), _price(price) {}; 
	float getCharge() { // retuen charge
		switch (_type)
		{
		case Movie::ChildrenMovie:
			return _price;
		case Movie::ActionMovie:
			return _price*2;
		case Movie::NewRelaseMovie:
			return _price+2;
		default:
			throw std::runtime_error("Should be unrechable");
			break;
		}
	}//end getCharge method
	string getTypeMovie() {//return type of the movie
		switch (_type)
		{
		case Movie::ChildrenMovie:
			return "Children Movie";
		case Movie::ActionMovie:
			return "Action Movie";
		case Movie::NewRelaseMovie:
			return "NewRelase Movie";

		default:
			throw std::runtime_error("Should be unrechable");
			break;
		}
	}//end get TyoeMovie
	float getPrice() {
			return _price;
	}
private:
	Type _type;
	float _price;
	double _charge;
};


int main() {

	Movie movie1(Movie::ChildrenMovie, 3.5); //declare Childern movie
	cout << "Genre:  " <<  movie1.getTypeMovie();
	cout << "    Price: " << movie1.getPrice() <<
		"    Charge: " << movie1.getCharge() << endl << endl;

	Movie movie3(Movie::NewRelaseMovie, 3.5);//declare NewRelase movie
	cout << "Genre:  " << movie3.getTypeMovie();
	cout << "    Price: " << movie3.getPrice() <<
		"    Charge: " << movie3.getCharge() << endl << endl;

	Movie movie2(Movie::ActionMovie, 3.5);//declare Action movie
	cout << "Genre:  " << movie2.getTypeMovie();
	cout << "    Price: " << movie2.getPrice() <<
		"    Charge: " << movie2.getCharge() << endl << endl;
	std::getchar();
	return 0;
}