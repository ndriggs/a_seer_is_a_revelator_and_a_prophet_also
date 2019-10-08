#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[]){
    
    //read in file
    if(argc == 2){
        string file_name = argv[1];
        ifstream text_file(file_name);
        string text_word;
        set<string> scripture_words;
        while(!text_file.eof()){ //store text from file in set
            text_file >> text_word;
            scripture_words.insert(text_word);
        }
        //write the words to a file
        ofstream output_file;
        output_file.open("1Nephi_set.txt");
        for(set<string>::iterator it = scripture_words.begin(); it != scripture_words.end(); ++it){
            output_file << *it << endl;
        }
        
        output_file.close();
        
        
    }
    
    
    
    
    
    
    
    return 0;
}