#include <map>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    // check paremeter
    if (argc != 3) {
        cout << "paremeter error!" << endl;
        cout << "./a.out filename num" << endl;
        return 0;
    }

    string input = string(argv[1]);
    int bucket = atoi(argv[2]);

    ifstream ifs;
    ifs.open(input, ios::in);
    if (!ifs.is_open()) {
        cout << "open file " << input << "error!" << endl;
    }

    // create output directory
    string dir = "splitFiles";
    string command = "mkdir -p " + dir;
    system(command.c_str());

    // create output file
    map<int, ofstream*> mp;
    for (int i = 0; i < bucket; ++i) {
        string output = dir + "/part" + to_string(i); 
        mp[i] = new ofstream(output, ios::app);
    }


    // split input data to output file
    string buf;
    while (getline(ifs, buf)) {
        if (buf[0] == '#') {
			continue;
        }
	
		int num = stoi(buf);
		int x = num % bucket;
		*mp[x] << buf << endl;
    }

    // free pointer
    for (auto& pair : mp) {
        delete pair.second;
        pair.second = 0;
    }

    return 0;
}
