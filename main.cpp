#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[]){
    
    //read in file
    if(argc == 2){ //check that they entered a file name
        string file_name = argv[1];
        ifstream text_file(file_name + ".txt");
        string text_word;
        set<string> scripture_words;
        while(!text_file.eof()){ //store text from file in set
            text_file >> text_word;
            string::iterator it = text_word.begin();
            while(it != text_word.end()){ //removes punctuation 
                if(!isalpha(*it)){
                    text_word.erase(it);
                } else{
                    ++it;
                }
            }
            scripture_words.insert(text_word);
        }
        text_file.close();
        
        // now a vector
        vector<string> scripture_words_v;
        ifstream text_file_again(file_name + ".txt");
        while(!text_file_again.eof()){
            text_file_again >> text_word;
            string::iterator it = text_word.begin();
            while(it != text_word.end()){ // remove punctuation
                if(!isalpha(*it)){
                    text_word.erase(it);
                } else{
                    ++it;
                }
            }
            scripture_words_v.push_back(text_word);
        }
        text_file_again.close();
        
        //write the set words to a file
        ofstream output_file;
        output_file.open(file_name + "_set.txt");
        for(set<string>::iterator it = scripture_words.begin(); it != scripture_words.end(); ++it){
            output_file << *it << endl;
        }
        output_file.close();
        
        //write the vector words to a file
        ofstream outpute_file(file_name + "_vector.txt");
        for(int i = 0; i < scripture_words_v.size(); ++i){
            outpute_file << scripture_words_v.at(i) << endl;
        }
        outpute_file.close();
        
        //put vector of words into a map or strings and string
        map<string, string> firstmap;
        vector<string>::iterator it = scripture_words_v.begin();
        string last = "";
        for(it != scripture_words_v.end()){
            firstmap[last] = *it;
            last = *it;
            ++it;
        }
        //output map to file
        ofstream map_output(file_name + "_1_1.txt");
        for(map<string, string>::iterator it = firstmap.begin(); it !=)
    }
    
    
    
    
    
    
    
    return 0;
}



