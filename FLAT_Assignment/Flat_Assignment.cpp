#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <map>
using namespace fst;
using namespace std;
struct Morph {
    string pos;
    string gram;
};
string removeSuffix(const string& word, const string& suffix) {
    string root = word.substr(0, word.size() - suffix.size());
    if (root.size() >= 2) {
        char last = root[root.size()-1];
        char secondLast = root[root.size()-2];
        if (last == secondLast && isalpha(last)) {
            root = root.substr(0, root.size()-1); 
        }
    }
    return root;
}

int main() {
    map<string, Morph> suffixes = {
        {"ing", {"V", "GER"}},
        {"ed", {"V", "PAST"}},
        {"er", {"ADJ", "COMP"}},
        {"est", {"ADJ", "SUPER"}},
        {"ly", {"ADV", ""}}
    };

    string word;
    cout << "Enter a word: ";
    cin >> word;

    string root = word;
    string pos = "Unknown";
    string gram = "";
    for (auto &suf : suffixes) {
        string suffix = suf.first;
        if (word.size() > suffix.size() &&
            word.substr(word.size() - suffix.size()) == suffix) {
            root = removeSuffix(word, suffix);
            pos = suf.second.pos;
            gram = suf.second.gram;
            break;
        }
    }
    cout << word << " → " << root << " + " << pos;
    if (!gram.empty()) cout << " + " << gram;
    cout << endl;

    return 0;

}
