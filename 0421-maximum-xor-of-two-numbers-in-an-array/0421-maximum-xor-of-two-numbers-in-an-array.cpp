class Trie{
public:
    struct TrieNode{
        TrieNode* left=nullptr;
        TrieNode* right;
    };
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }

    void insert(TrieNode* &root,int num){
        TrieNode* crawl=root;
        for(int i=31;i>=0;i--){
            int ind=num>>i;
            if((ind&1)==0)
            {   if(crawl->left==NULL)
                crawl->left=new TrieNode();
                crawl=crawl->left;
            }
            else if((ind&1)==1)
            {
                if(crawl->right==NULL)
                crawl->right=new TrieNode();
                crawl=crawl->right;
            }
        }
    }
};
class Solution {
public:
    int findXOR(Trie::TrieNode* root,int n)
    {
        Trie::TrieNode* crawl=root;
        int value=0;
        for(int i=31;i>=0;i--){
            int ind=n>>i;
            ind=(ind&1);
            if(ind==0)
            {
              if(crawl->right!=NULL)
              {
                 value+=pow(2,i);
                 crawl=crawl->right;
              }
              else if(crawl->left!=NULL)
              {
                crawl=crawl->left;
              }
            }
            else if(ind==1)
            {
              if(crawl->left!=NULL)
              {
                 value+=pow(2,i);
                 crawl=crawl->left;
              }
              else if(crawl->right!=NULL)
              {
                crawl=crawl->right;
              }
            }
            
        }
        return value;
    }
    int findMaximumXOR(vector<int>& nums) {
        Trie* T=new Trie();
        for(int &i:nums)
        {
            T->insert(T->root,i);
        }

        int maxxor=0;
        for(int i:nums)
        {
            int x=findXOR(T->root,i);
            maxxor=max(maxxor,x);
        }
        return maxxor;
    }
};