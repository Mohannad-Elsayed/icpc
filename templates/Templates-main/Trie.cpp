struct vertex {
    char alphabet;
    bool exist;
    vector<vertex*> child;
    vertex(char a) : alphabet(a), exist(false) { child.assign(52, NULL); }
};

class Trie {  // this is TRIE
   private:   // NOT Suffix Trie
    vertex* root;

   public:
    Trie() { root = new vertex('!'); }

    void insert(string word) {  // insert a word into trie
        vertex* cur = root;
        for (int i = 0; i < (int)word.size(); ++i) {  // O(n)
            int alphaNum =
                isupper(word[i]) ? word[i] - 'A' : word[i] - 'a' + 26;
            if (cur->child[alphaNum] == NULL)  // add new branch if NULL
                cur->child[alphaNum] = new vertex(word[i]);
            cur = cur->child[alphaNum];
        }
        cur->exist = true;
    }

    bool search(string word) {  // true if word in trie
        vertex* cur = root;
        for (int i = 0; i < (int)word.size(); ++i) {  // O(m)
            int alphaNum = word[i] - 'A';
            if (cur->child[alphaNum] == NULL)  // not found
                return false;
            cur = cur->child[alphaNum];
        }
        return cur->exist;  // check exist flag
    }

    bool startsWith(string prefix) {  // true if match prefix
        vertex* cur = root;
        for (int i = 0; i < (int)prefix.size(); ++i) {
            int alphaNum =
                isupper(prefix[i]) ? prefix[i] - 'A' : prefix[i] - 'a' + 26;
            if (cur->child[alphaNum] == NULL)  // not found
                return false;
            cur = cur->child[alphaNum];
        }
        return true;  // reach here, return true
    }

    int countStartsWith(string prefix) {  // count strings with given prefix
        vertex* cur = root;
        for (int i = 0; i < (int)prefix.size(); ++i) {
            int alphaNum =
                isupper(prefix[i]) ? prefix[i] - 'A' : prefix[i] - 'a' + 26;
            if (cur->child[alphaNum] == NULL)  // not found
                return 0;
            cur = cur->child[alphaNum];
        }
        return countSubtree(cur);  // count all words in subtree
    }

   private:
    int countSubtree(vertex* node) {  // helper function
        if (!node) return 0;
        int count = node->exist ? 1 : 0;  // count this node if it's a word
        for (auto child : node->child)    // recursively count children
            count += countSubtree(child);
        return count;
    }
};