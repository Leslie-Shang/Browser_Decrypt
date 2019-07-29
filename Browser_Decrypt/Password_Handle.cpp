#include "Chrome(Opera)_Decrypt.h"
#include <algorithm>
string Password_Handle(char* input) {
	string s = input;
	int* a = new int[11];
	a[0] = s.find("\x1");
	a[1] = s.find("\x2");
	a[2] = s.find("\x3");
	a[3] = s.find("\x4");
	a[4] = s.find("\x5");
	a[5] = s.find("\x6");
	a[6] = s.find("\x7");
	a[7] = s.find("\x8");
	a[8] = s.find("\x9");
	a[9] = s.find("\a");
	a[10] = s.find("\b");
	for (int i = 0; i < 11; i++)
	{
		if (a[i] == -1) {
			a[i] = 100;
		}
	}
	int n = *min_element(a, a + 11);
	return s.substr(0, n);
}