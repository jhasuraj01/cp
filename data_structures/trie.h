#include <vector>
using std::vector;

class TrieNode {
public:
    int end_here;
    int count;
    vector<TrieNode*> children;
    TrieNode() {
        children = vector<TrieNode*>(27, NULL);
        end_here = 0;
        count = 0;
    }

public:
    void insert(string s) {
        TrieNode* node = this;
        for(char c: s) {
            int index = c - 'a';
            if(node->children[index] == NULL)
                node->children[index] = new TrieNode();
            node = node->children[index];
            node->count++;
        }
        node->end_here++;
    }

    int is_ambiguous(string s) {
        int n = s.size();

        // deb(s);

        TrieNode* node = this;
        for(int i = 0; i < n; ++i) {
            int index = s[i] == ' ' ? 26 : s[i] - 'a';
            if(node->children[index] == NULL)
                break;
            node = node->children[index];
            // deb(s[i], node->count);
        }
        return node->count > 1;
    }

    pair<int, string> matching_word(string s) {
        int n = s.size();

        // deb(s);

        int len = 0;
        string word = "";

        TrieNode* node = this;
        for(int i = 0; i < n; ++i) {
            int index = s[i] == ' ' ? 26 : s[i] - 'a';
            if(node->children[index] == NULL)
                break;
            node = node->children[index];
            word += s[i];
            len += 1;
            // deb(s[i], node->count);
        }

        while(node->end_here == 0) {
            for(int i = 0; i <= 26; ++i) {
                if(node->children[i] != NULL) {
                    node = node->children[i];
                    word += i == 26 ? ' ' : 'a' + i;
                    break;
                }
            }
        }

        return {len, word};
    }
};