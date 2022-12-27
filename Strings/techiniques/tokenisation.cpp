#include <bits/stdc++.h>

#define printArray(arr) for(auto x : arr) cout << x << " "; cout << endl;

using namespace std;

//Using sstream
vector<string> tokenisationSstream(string str){    
    //create a string stream object
    stringstream ss(str);

    // >> and << operators
    string token;
    vector<string> tokens;
    while (getline (ss, token,' ')) {
        tokens.push_back(token);
    }

    return tokens;
}

//Using strtok with std::string
vector<string> tokenisationStrtok(string str){
    vector<string> tokens;
    char *token = strtok(&str[0]," ");
    while(token != NULL){
        tokens.push_back(token);
        token = strtok(NULL," ");
    }
    return tokens;
}

void tokenisationStrtok2(char *str){
    char *token = strtok(str," ");
    while(token != NULL){
        cout << token << " ";
        token = strtok(NULL," ");
    }
    cout << endl;
}

char *mystrtok(char *str, char delim){
    static char *input = NULL;

    if (str != NULL)
        input = str;

    if (input == NULL)
        return NULL;
    
    char *token = new char[strlen(input)+1];
    int i = 0;
    for( ; input[i] != '\0'; i++){
        if (input[i] == delim){
            token[i] = '\0';
            input += i + 1;
            return token;
        }else {
            token[i] = input[i];
        }
    }
    token[i] = '\0';
    input = NULL;

    return token;
}

int main() {
    
    /* Using std::string */
    //method1();

    /* Using char pointer */
    //method2();

    //Designed strtok 
    char str[1000];
    cin.getline(str,1000);

    char *token = mystrtok(str, ' ');

    while(token != NULL){
        cout << token << endl;
        token = mystrtok(NULL, ' ');
    }

    return 0;
}

void method1(){
    string input;
    getline (cin, input);

    vector<string> output = tokenisationSstream(input);
    //vector<string> output = tokenisationStrtok(input); //Second version using strtok with string
    
    printArray(output);
}

void method2(){
    char input[1000];
    cin.getline(input,1000);

    tokenisationStrtok2(input);
}