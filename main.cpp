#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <list>
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
        string last = "";
        for(vector<string>::iterator it = scripture_words_v.begin(); it != scripture_words_v.end(); ++it){
            firstmap[last] = *it;
            last = *it;
        }
        //output map to file
        ofstream map_output(file_name + "_1_1.txt");
        for(map<string, string>::iterator it = firstmap.begin(); it != firstmap.end(); ++it){
            map_output << it->first << ", " << it->second << endl;
        }
        map_output.close();
        
        //creating scripture, take 1
        string state = "";
        cout << endl << "Take 1!" << endl;
        for(int i = 0; i < 100; i++){
            cout << firstmap[state] << " ";
            state = firstmap[state];
        }
        cout << endl; // clear the buffer
        
        //scripture map 2.0
        map<string, vector<string>> map2point0;
        state = "";
        for(vector<string>::iterator it = scripture_words_v.begin(); it != scripture_words_v.end(); ++it){
            map2point0[state].push_back(*it);
            state = *it;
        }
        /** 
        //print out vector corresponding to 6th entry in map
        for(map<string, vector<string>>::iterator it = map2point0.begin(); it != map2point0.end(); ++it){
            int i = 0;
            if(i = 5){ //access 6th entry
                for(int j = 0; j < it->second.size(); j++){
                    cout << it->second[j] << ", ";
                }
                cout << endl; //clear the buffer
            } 
            i += 1;
        }**/
        
        //creating scripture --- take 2!
        srand(time(NULL)); //initialize random rumber generator
        state = "";
        cout << endl << "Version 2: " << endl;
        for(int i = 0; i < 100; i++){
           int index = rand() % map2point0[state].size();
           state = map2point0[state][index];
           cout << state << " ";
        }
        cout << endl;
        
        //let's use a map of a list and vector!
        const int M = 2;
        map<list<string>, vector<string>> map3point0;
        list<string> context;
        for(int i = 0; i < M; i++){
            context.push_back("");
        }
        //add some context to our new map
        for(vector<string>::iterator it = scripture_words_v.begin(); it != scripture_words_v.end(); ++it){
            map3point0[context].push_back(*it);
            context.push_back(*it);
            context.pop_front();
        }
        
        //now let's print it~ we're publishing baby!
        context.clear();
        for(int i = 0; i < M; i++){
            context.push_back("");
        }
        cout << endl << "The best one yet!" << endl;
        for(int i = 0; i < 100; i++){
            int index = rand() % map3point0[context].size();
            cout << map3point0[context][index] << " ";
            context.push_back(map3point0[context][index]);
            context.pop_front();
        }
        
        
    }
    
    
    
    
    
    
    
    return 0;
}



