
#include "snowman.hpp"
#include "snowman.cpp"
#include <iostream>
#include <stdexcept>
using namespace std;



int main() {
	cout << ariel::snowman(21114411) << endl;   /*
 ___ 
.....
(.,.)
( : )
( : )
	*/
	

	try {
		cout << ariel::snowman(5) << endl;   
	} catch (exception& ex) {
	 	cout << "  FIND exception: " << ex.what() << endl;  
	}

    try {
		cout << ariel::snowman(55555555) << endl;   
	} catch (exception& ex) {
	 	cout << "  FIND exception: " << ex.what() << endl;  
	}

    return 0;
}