#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the trie
    void insert(string word) {
        TrieNode* current = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    
    // Search for a word in the trie
    bool search(string word) {
        TrieNode* node = searchNode(word);
        return (node != nullptr && node->isEndOfWord);
    }
    
    // Check if there is any word that starts with the given prefix
    bool startsWith(string prefix) {
        return searchNode(prefix) != nullptr;
    }
    
private:
    TrieNode* searchNode(string word) {
        TrieNode* current = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(!current->children[index]) {
                return nullptr;
            }
            current = current->children[index];
        }
        return current;
    }
};

// Driver code to test the Trie implementation
int main() {
    Trie* trie = new Trie();
    
    // Insert some words
    trie->insert("hello");
    trie->insert("world");
    trie->insert("help");
    
    // Test the implementation
    cout << "Search 'hello': " << (trie->search("hello") ? "Found" : "Not found") << endl;
    cout << "Search 'help': " << (trie->search("help") ? "Found" : "Not found") << endl;
    cout << "Search 'hel': " << (trie->search("hel") ? "Found" : "Not found") << endl;
    cout << "Starts with 'hel': " << (trie->startsWith("hel") ? "Yes" : "No") << endl;
    cout << "Search 'world': " << (trie->search("world") ? "Found" : "Not found") << endl;
    
    return 0;
}
