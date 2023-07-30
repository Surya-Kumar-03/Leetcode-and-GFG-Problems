class TrieNode{
    public:
        char data;
        vector<TrieNode*> children;
        bool isTerminal;

        TrieNode(char data){
            this->data  = data;
            for(int i = 0; i < 26; i++)
            {
                children.push_back(NULL);
            }
            isTerminal = false;
        }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root =  new TrieNode('\0');
    }
    
    void ourInserter(TrieNode* root,string word)
    {
        if(word == "")
        {
            root -> isTerminal = true; //indicates last letter
            return;
        }
        //check whether 1st index character exists
        int index =  word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL) //exists
            child = root -> children[index];
        else //does not exist
        {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        ourInserter(child, word.substr(1));
    }

    void insert(string word) {
        ourInserter(root, word);
    }
    
    bool ourSearcher(TrieNode* root, string word)
    {
        if(word == "")
        {
            if(root->isTerminal) return true;
            else return false;
        }
        int index = word[0] - 'a';
        if(root-> children[index] != NULL) 
            return ourSearcher(root->children[index], word.substr(1));
        else return false;
    }

    bool search(string word) {
        return ourSearcher(root, word);
    }
    
    bool ourStartsWith(TrieNode* root, string prefix)
    {
        if(prefix == "")
            return true;
        int index = prefix[0] - 'a';
        if(root-> children[index] != NULL)
            return ourStartsWith(root->children[index], prefix.substr(1));
        else return false;
    }

    bool startsWith(string prefix) {
        return ourStartsWith(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */