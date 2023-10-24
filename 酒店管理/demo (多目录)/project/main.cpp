#include <iostream>
#include "tools.h"
#include "hotel.h"
using namespace std;

int main(int argc, char* argv[]) {
	Hotel& hotel = Hotel::get_hotel();
	if(2 != argc) {
		cout << "User: ./HMS <path>" << endl;
		return 0;
	}
	if(!hotel.load(argv[1])) {
		return -1;
	}
	hotel.start();
	return 0;
}
