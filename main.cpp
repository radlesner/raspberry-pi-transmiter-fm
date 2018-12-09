#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

string frequency();
string type();

int main(int argc, char **argv) {
	string freq = frequency();
	string type_file = type();
	cout << argv[1] << type_file << endl;

	system(("sox -t "+type_file+" "+argv[1]+" -t wav - | sudo binaries/pi_fm_rds -freq "+freq+" -audio -").c_str());

	return 0;
}

string frequency() {
        string line;
        int nr_line=1;

        string freq;

        ifstream file("config.txt");

        if(file.good()==false)
                cout << "Error 002: Not found file \"systeminfo-distro.txt\"" << endl;

        while (getline(file, line)) {
                switch (nr_line) {
                        case 2: freq=line; break;
                }
                nr_line++;
        }

        file.close();
        return freq;
}

string type() {
	string line;
        int nr_line=1;

        string type_file;

        ifstream file("config.txt");

        if(file.good()==false)
                cout << "Error 002: Not found file \"systeminfo-distro.txt\"" << endl;

        while (getline(file, line)) {
                switch (nr_line) {
                        case 5: type_file = line; break;
                }
                nr_line++;
        }

        file.close();
        return type_file;
}
