#include<bits/stdc++.h>
using namespace std;

int skip_whitespace(const string &sentence, int idx) {
    while (idx < sentence.length() && sentence[idx] == ' ') {
        idx += 1;
    }

    return idx;
}

int normalize_word(string &sentence, int idx) {
    if (idx < sentence.length() && sentence[idx] != ' ') {
        sentence[idx] = toupper(sentence[idx]);
        idx += 1;
    }

    while (idx < sentence.length() && sentence[idx] != ' ') {
        sentence[idx] = tolower(sentence[idx]);
        idx += 1;
    }

    return idx;
}

//Course Solution
//O(n) - time  (Maybe O(n*m) where m is average length of word from the sentence)
//O(1) - space
string normalize(const string &sentence) {
    string copy = sentence;
    int idx = 0;

    while (idx < copy.length()) {
        idx = skip_whitespace(copy, idx);
        idx = normalize_word(copy, idx);
    }

    return copy;
}


//Ryan Solution
//O(n) - time
//O(1) - space
string normalize2(const string &sentence) {
    string copy = sentence;

    if (not (copy.length() >= 1))
        return copy;

    for(int i = 1; i < copy.length(); i++){
        if (copy[i-1] == ' ')
            copy[i] = toupper(copy[i]);
        else
            copy[i] = tolower(copy[i]);
    }
    copy[0] = toupper(copy[0]); //Here (down below loop) cause the corner case: input = "a"
    
    return copy;
}

int main(){
    cout << normalize("This is SO MUCH FUN!") << endl; //This Is So Much Fun!
    cout << normalize("i lIKE cODE") << endl; //I Like Code
    cout << normalize("tHe LiFe Is BeAuTiFuL") << endl; //The Life Is Beautiful
    cout << normalize("a") << endl; //A
}