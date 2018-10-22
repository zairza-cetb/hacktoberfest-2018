#include<stdio.h>+
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


typedef struct TrieNode
{
    struct Trie_Node * arr[26] ;
    bool  End ;
} trie ;

trie* createNode()
{
    int i ;
    trie* nn = (trie*)malloc(sizeof(trie)) ;
    nn->End = false ;
    for(i = 0; i < 26; i++)
    {
        nn->arr[i] = NULL ;
    }
    return nn ;
}


void insert(trie * curr, char * str)
{
    int i ;
    for(i = 0; i < strlen(str); i++)
    {
        if(curr->arr[str[i] - 'a'])
        {
            curr = curr->arr[str[i] - 'a'] ;
        }
        else
        {
            trie *nn = createNode() ;
            curr->arr[str[i] - 'a'] = nn ;
            curr = nn ;
        }
    }
    curr->End = true ;
}
int search(trie * root, char * str)
{
    int i, y ;
    for(i = 0; i < strlen(str); i++)
    {
        char x = str[i] ;
        if(!root->arr[x - 'a'])
        {
            return 0 ;
        }
        root = root->arr[x-'a'] ;
    }
    if(root->End == true )  // if suffix is to be searched skip the if condition only return true
        return 1 ;
}



int main()
{
    char * key[4] = {"tree","trie","mask","man"} ;
    int i ;
    trie * root = createNode() ;
    for(i = 0; i < 4; i++)
    {
        insert(root, key[i]) ;
    }
    assert(search(root,"tree") == 1)  ;
    assert(search(root,"the") == 0) ;
    assert(search(root,"mask") == 1) ;
    assert(search(root,"tre") == 1) ;
    printf("all test cases passed") ;
}

