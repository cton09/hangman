#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

array<string,7> men {"________\n|/      |\n|\n|\n|\n|\n|","________\n|/     |\n|      O\n|\n|\n|\n|","________\n|/     |\n|      O\n|      |\n|\n|","________\n|/     |\n|      O\n|     \\|\n|      |\n|\n|","________\n|/     |\n|      O\n|     \\|/\n|      |\n|\n|","________\n|/     |\n|      O\n|     \\|/\n|      |\n|     /\n|","________\n|/     |\n|      O\n|     \\|/\n|      |\n|     / \\\n|"};
array<string,12> words {"soup","antidisestablishmentarianism","india","pakistan","nepal","malaysia","philippines","australia","iran","ethiopia","oman","indonesia"};
string randomWord(){
    return words[rand()%words.size()];
}

string displayStr(string word,vector<char> guesses){
    string op = "";
    for(int i = 0 ; i < word.length(); i++){
        op+="_ ";
    }
    for(char guess: guesses){
        int n = 0;
        int index = word.find(guess,n);
        while(index!=-1){
            op = op.replace(index*2,1,&guess);
            n=index+1;
            index = word.find(guess,n);
        }
    }
    return op;
}

int main(){
    srand(time(0));
    string word = randomWord();
    int lives = 6;
    int wrong = 0;
    char guess;
    bool won = false;
    vector<char> guesses;
    cout << men[0] << endl;
    cout << displayStr(word,guesses) << endl;
    while(wrong<lives && !won){
        cin >> guess;
        guesses.push_back(guess);
        string guessStr = displayStr(word,guesses);
        if(word.find(guess)==-1){
            wrong++;
        }else if(guessStr.find('_')==-1){
            cout << "You WON!" << endl;
            won=true;
            break;
        }
        cout << men[wrong] << endl;
        cout << guessStr << endl;
        cout << "Guesses left: " << lives-wrong << endl;
    }
    if(!won){
        cout << "You LOST!" << endl;
    }
}
