#include <iostream> 
#include "sort.h"
using namespace std;


int main() {
	Array <float> s = { 1,2,0x12^0x4,4,12.5,6,7 ,'a'-'z',1<<4};
	
	s.sort(true);
	s.print();
	
	
}