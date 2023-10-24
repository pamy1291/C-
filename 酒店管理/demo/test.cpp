#include <iostream>
#include <cstdio>
#include <list>
//#include <iterator>
using namespace std;

class Test {
public:
	int num;
	list<int> n_list;
	Test(int num):num(num) {

	}
};
int main(int argc,const char* argv[])
{
	Test t(1);
	cout << sizeof(Test) << endl;
	t.n_list.push_back(2);
	t.n_list.push_back(3);
	cout << sizeof(Test) << endl;
	FILE* f = fopen("test.txt", "w+");
	int size = t.n_list.size();
	int num[size];
	int i=0;
	for (list<int>::iterator it = t.n_list.begin(); 
			it != t.n_list.end(); it++) {
		num[i++] = *it;
	}
	fprintf(f, "%d\n%d %d",t.num, num[0], num[1]);
	return 0;
}
