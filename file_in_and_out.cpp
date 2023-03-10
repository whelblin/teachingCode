#include <iostream>
#include <fstream>
#include <string>

using std::endl; using std::cout; using std::cin;
using std::string; using std::ios;

/*
    argc and argv allow us to get input from the commandline
    argc is an int that holds the number of arguments
    argv is an array of strings that hold each of these arguments
    the first argument is always the execuatable and is at argv[0]
    everything after that is user inputted arguments
*/
int main(int argc, char* argv[]){

    // gets the user input to ask for reading or writing
    char input;
    cout<< "Would You like to read the file or write to the file(w/r)" <<endl;
    cin >> input;
    // checks if the input is a w
    if(input == 'w'){

        // opens the file stored in argv[1] for writing
        // fout is very similer to cout. cout is console output where 
        // fout is file output. the ios::app tells the program to open the file
        // and add words to the end of the file
        std::ofstream fout(argv[1], ios::app);
        string word;
        cout<<"enter words to add to the end of a file and -1 to exit" <<endl;

        // this is a do while loop. It is very similar to while loops but always runs at least once
        // before checking the conditional
        do{
            // gets in a word from the user
            cin >>word;
            // if it is not a -1, print it to the file
            if(word != "-1") fout << word<< " ";
        }while(word != "-1"); // while input is not -1

        fout.close(); // close the file
    }

    else if(input == 'r'){

        // opens the file stored in argv[1] for reading
        // fout is very similer to cin. cout is console input where 
        // fin is file input. It will read a string from thr file and 
        // store it in word
        std::ifstream fin(argv[1]);
        string word;

        // loop through the file intil fin hits the end of the file
        while(fin >> word){
        // prints the word to the console
            cout<<word << " ";
        }
        cout<<endl;
        fin.close(); // closes the file
    }
    else{
        cout<<"invalid input" <<endl;
        return -1;
    }

}
