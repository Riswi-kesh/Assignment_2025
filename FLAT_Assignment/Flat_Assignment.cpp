#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <map>
using namespace fst;
using namespace std;

// Morph struct
struct Morph {
    string pos;
    string gram;
};

// Function to remove suffix and handle double consonants
string removeSuffix(const string& word, const string& suffix) {
    string root = word.substr(0, word.size() - suffix.size());

    // Handle doubled final consonant (e.g., "running" -> "run")
    if (root.size() >= 2) {
        char last = root[root.size()-1];
        char secondLast = root[root.size()-2];
        if (last == secondLast && isalpha(last)) {
            root = root.substr(0, root.size()-1); // remove doubled letter
        }
    }
    return root;
}

int main() {
    // Suffix analysis table
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

    // Find matching suffix
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

    // Print analysis
    cout << word << " → " << root << " + " << pos;
    if (!gram.empty()) cout << " + " << gram;
    cout << endl;

    // Create OpenFst for this word
    StdVectorFst fst;
    int start = fst.AddState();  // start state
    fst.SetStart(start);
    int prev = start;

    // Add arcs for each letter
    for(char c : word) {
        int next = fst.AddState();
        fst.AddArc(prev, StdArc(c, c, 0, next));
        prev = next;
    }

    fst.SetFinal(prev, StdArc::Weight::One());

    return 0;
}