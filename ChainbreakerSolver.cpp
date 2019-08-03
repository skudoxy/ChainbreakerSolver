#include <iostream>

bool algorithm(int seed) {
	using namespace std;
	int links = ( ( (seed ^ 0x141) + (seed ^ 0x7b) ) * 0x533d) % 100;
	if (links < 0) {
		links = -links;
	}
	else if (links == 0) {
		links = 10;
	}
	int bufferInp = seed;
	int count = 0;
	for (int i = 0; (i < 100) && (i < links); i++) {
		int uVar1;
		int local_20;
		if (bufferInp == 0) {
			return false;
		}
		if ((bufferInp < -0x1000) || (local_20 = bufferInp, 0x1000 < bufferInp)) {
			uVar1 = (unsigned int)(bufferInp >> 0x1f) >> 0x14;
			local_20 = -((bufferInp + uVar1 & 0xfff) - uVar1);
		}
		int buf2 = 1;
		for (int i = 0; i < 3; i++) {
			buf2 = buf2 ^ local_20 << (i & 0x1f);
		}
		bufferInp = (long)((seed + ((i + seed) - 1U ^ local_20) + buf2) - 0xf);
		int buffer = bufferInp;
		if (bufferInp < 0) {
			buffer = 0;
		}
		count++;
	}
	if ((seed == bufferInp) && (count == links)) {
		return true;
	}
	else {
		return false;
	}
}

int main(){
	using namespace std;
	int seed = 0;
	bool found = false;
	for (int i = -214748367; i < +2147483647; i++) {
		bool iter = algorithm(i);
		if (iter) {
			seed = i;
			found = true;
			break;
		}
		if (i % 10000000 == 0) {
			cout << "Current seed: " << i << endl;
		}
	}
	if (found) {
		cout << "Seed is: " << seed << endl;
	}
	else {
		cout << "Seed not found!" << endl;
	}
	return 0;
}