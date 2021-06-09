#include<fstream>
#include<iostream>
using namespace std;

const static string FILE_NAME = "file.txt";

void initialWrite() {

	ofstream ofs;
	ofs.open(FILE_NAME, ios::out);

	ofs << "Hello World" << endl;
	ofs << "second line" << endl;

	ofs.close();
}

static ifstream* getIfs() {
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	if (!ifs.is_open()) {
		cout << "failed to open file " << FILE_NAME << endl;
		return &ifs;
	}
	return &ifs;
}

void read1(ifstream* ifs) {
	char buf[1024] = {0};
	while (*ifs >> buf) {
		cout << buf << endl;
	}
}

void read2(ifstream* ifs) {
	char buf[1024] = {0};
	while (*ifs.getline(buf, sizeof(buf))) {
		cout << buf << endl;
	}
}

// void read3(ifstream& ifs) {
// 	char buf[1024] = {0};
// 	while (getline(ifs, buf)) {
// 		cout << buf << endl;
// 	}
// }

void read4(ifstream* ifs) {
	char c;
	while ((c = *ifs.get()) != EOF) {
		cout << c;
	}
}

static void closeIfs(ifstream* ifs) {
	*ifs.close();
}

int main() {

	initialWrite();

	ifstream* ifs = getIfs();

	read1(ifs);
	read2(ifs);
	// read3(ifs);
	read4(ifs);
	closeIfs(ifs);


	return 0;
}

