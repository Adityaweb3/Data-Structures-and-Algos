struct trieNode {
    trieNode *children[26];
    bool isEnd;

    trieNode() {
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isEnd = false;
    }
};

class WordDictionary {
    trieNode *root;

public:
    WordDictionary() {
        root = new trieNode();
    }

    void addWord(string word) {
        trieNode *temp = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(temp->children[idx] == nullptr)
                temp->children[idx] = new trieNode();
            temp = temp->children[idx];
        }
        temp->isEnd = true;
    }

    bool search(string word) {
        return solve(word, 0, root);
    }

private:
    bool solve(const string &word, int index, trieNode *node) {
        if(!node) return false;
        if(index == word.size())
            return node->isEnd;

        char ch = word[index];
        if(ch == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->children[i] && solve(word, index + 1, node->children[i]))
                    return true;
            }
            return false;
        } else {
            return solve(word, index + 1, node->children[ch - 'a']);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */