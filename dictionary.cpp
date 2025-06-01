#include <iostream>
#include <map>
#include <fstream>
using namespace std;

class dictionary {
public:
    map<string, string> dict;

    dictionary(){
        string key, val;
        ifstream io("dict.txt");
        while(getline(io, key, ':') && getline(io, val)) {
    
            if (!key.empty() && !val.empty()) 
            {
                dict[key] = val;
            }
        }
        io.close();
    }

    void insert(string word, string meaning) {
        if (dict.find(word) == dict.end()) {
            dict[word] = meaning;
            cout << "Word inserted successfully.\n";
        } else {
            cout << "Word is already present.\n";
        }
    }

    void search(string word) {
        auto itr = dict.find(word);
        if (itr != dict.end()) {
            cout << itr->first << ": " << itr->second << "\n";
        } else {
            cout << "Word not found.\n";
        }
    }

    void display() {
        if (dict.empty()) {
            cout << "Dictionary is empty.\n";
        } else {
            cout<<"our Dictionary :\n";
            for (auto i : dict) {
                cout << i.first << ": " << i.second << "\n";
            }
        }
    }

    void saveDict() {
        ofstream out("dict.txt");
        for (auto i : dict) {
            out << i.first << ":" << i.second << "\n";
        }
    }
    void update(string word,string meaning){
        if(dict.find(word)!=dict.end()){
            dict[word]=meaning;
            cout<<"\n word meaning updated successfully";
        }
        else{
            cout<<"\n word not found";
        }
    }
    void del(string word){
        if(dict.find(word)!=dict.end()){
            dict.erase(word);
            cout<<"\n word deleted successfully:";
        }
        else{
            cout<<"\n word not found"; 
        }
    }
};

int main() {
    dictionary obj;
    int choise;
    string word, meaning;

    do {
        cout << "\nEnter your choice:\n"
             << "1. Insert new word and its meaning\n"
             << "2. Find meaning of a word\n"
             << "3. Display dictionary\n"
             << "4. update  word meaning\n"
             << "5. delete word and their meaning\n"
             << "6. Exit\n"
             << "Choice = ";
        cin >> choise;
        cin.ignore();  
        switch (choise) {
        case 1:
            cout << "Enter word: ";
            getline(cin, word);
            cout << "Enter meaning of '" << word << "': ";
            getline(cin, meaning);
            obj.insert(word, meaning);
            break;

        case 2:
            cout << "Enter word: ";
            getline(cin, word);
            obj.search(word);
            break;

        case 3:
            obj.display();
            break;

        case 4:
            cout << "Enter word: ";
            getline(cin, word);
            cout << "Enter updated meaning of '" << word << "': ";
            getline(cin, meaning);
            obj.update(word,meaning);
            break;
            
        case 5:
            cout << "Enter word: ";
            getline(cin, word);
            obj.del(word);
            break;    
        
        case 6:
            obj.saveDict();
            cout << "Dictionary saved. Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choise != 6);

    return 0;
}

