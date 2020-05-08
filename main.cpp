#include "kmp.h"
//#include <iostream>

//using namespace std;
//ABCDABCDEFABCDABCDAG

int main(void)
{
	//KMP kmp("ABCDACBCDEFABCDABCDAG", "AG");
	//KMP kmp("ABCDACBCDEFABCDABCDAG", "ABC");
	KMP kmp("ABC   DACBC   DEFA BCDABCDAG", "ABCABC");
	cout << "kmp.return_find_s_size(): " << kmp.return_find_s_size() << endl;
	cout << "kmp.return_find_s()" << kmp.return_find_s() << endl;
	kmp.print_all_next_item();
	kmp.print_all_get_item();
	cout << "OK!" << endl;
	return EXIT_SUCCESS;
}

