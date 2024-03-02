#include <iostream>
#include <string>
using namespace std;

void compressArray(const string &data) {
    char output[500];
    int batas = data.length(); 
    int count = 1;
    int index = 0;

    for (int i = 0; i < batas; i++) {
        if (i + 1 < batas && data[i] == data[i + 1]) {
            count++;
        } else {
            output[index++] = data[i];
            output[index++] = '0' + count;
            count = 1;
        }
    }

    cout << "Output = [";
    for (int k = 0; k < index; k++) {
        cout << "'" << output[k] << "'";
        if (k + 1 != index) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    string data;
    cout << "Input String : ";
    cin >> data;

    compressArray(data);

    cout << "\nProgram ini dibuat oleh : Rolis Liu" << endl;
    cout << "NPM : 2310631170117" << endl;

    return 0;
}

