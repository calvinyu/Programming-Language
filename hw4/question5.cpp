#include "Q5_foldl.h"
#include <iostream>
#include <list>
#include <stdlib.h>
#include <algorithm>
#include <iterator>

using namespace std;
int add (int x, int y) { return x+y; }

int a(){return rand()%100;}

void call_stl(){
	srand(time(NULL));
	int myArray[10]; // primitive array
	const int N = 10;
	// Note: Primitive arrays don’t have a begin() or end() function.
	const int* begin = myArray;
	const int* end = myArray + N;
	// Write your code here...
	generate_n(myArray, N, a); 
	random_shuffle((int*)begin, (int*)end);
	stable_sort((int*)begin, (int*)end);
	// Print the sorted sequence to standard out
	copy(begin,end, ostream_iterator<int>(cout,"\n"));
}

void call_foldl(){
	// array, Random Access container (a refinement of Forward Container)
	int begin[] = { 1, 2, 3, 4, 5 };
	int N = sizeof(begin) / sizeof(int);
	// Should output 15
	cout << foldl( begin, begin+N, add, 0 ) << endl;
	// Linked list, a Sequence (refinement of Forward Container)
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	// Should output 15
	cout << foldl( l.begin(), l.end(), add, 0 ) << endl;
}

int main()
{
	call_foldl();
	call_stl();
	return 0;
}

