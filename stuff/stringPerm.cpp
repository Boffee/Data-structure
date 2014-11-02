#include <iostream>

using namespace std;


class printAllPerm{
public:
    printAllPerm(string word) : word(word) {}
    
    void print(string usedLetters, string subString){
        if (subString.length() == 0) {
            cout << usedLetters << endl;
            return;
        }
        for (int i = 0; i < subString.length(); i++){
            bool repeat = false;
            for( int j = i+1; j < subString.length(); j++){
                if( subString[i] == subString[j]) {
                    repeat = true;
                }
            }
            if (!repeat) {
                print(usedLetters+subString[i], subString.substr(0,i)+subString.substr(i+1));
            }
        }
    }
    
private:
    string word;
};

int main() {
    string word;
    cout << "please enter a word: ";
    cin >> word;
    printAllPerm printAllPerm(word);
    cout << endl;
    printAllPerm.print("", word);
    return 0;
}

