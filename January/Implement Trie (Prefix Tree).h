Implement Trie (Prefix Tree)

class Trie {
public:
    struct trieNode 
    {
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode()
    {
        trieNode* node= new trieNode();
        node->isEndOfWord=false;

        for(int i=0;i<26;i++)
        {
            node->children[i]=NULL;
        }

        return node;
    }

    trieNode* root;

    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        trieNode* crawl=root;
        int n=word.length();

        for(int i=0;i<n;i++)
        {
            int idx=word[i]-'a';

            if(crawl->children[idx]==NULL)
                crawl->children[idx]=getNode();
            
            crawl=crawl->children[idx];
        }

        crawl->isEndOfWord=true;
    }
    
    bool search(string word) {
        trieNode* crawl=root;
        int n=word.length();

        for(int i=0;i<n;i++)
        {
            int idx=word[i]-'a';

            if(crawl->children[idx]==NULL)
                return false;
            
            crawl=crawl->children[idx];
        }
        if(crawl->isEndOfWord)
            return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl=root;
        int n=prefix.length();

        for(int i=0;i<n;i++)
        {
            int idx=prefix[i]-'a';

            if(crawl->children[idx]==NULL)
                return false;
            
            crawl=crawl->children[idx];
        }

        return true;
    }
};


Time Complexity 
Insertion: O(N),where N is the length of the word being inserted. 
Search: O(N),where N is the length of the word being searched for.
Prefix Search: O(N),where N is the length of the prefix being searched for.

Space Complexity: O(N) where N is the total number of characters across all unique words inserted into the Trie.
For each character in a word, a new node may need to be created leading to space proportional to the number of characters.
