import java.util.* ;

class TrieNode
{
    boolean EndOfWord ;
    Map<Character, TrieNode> m ;
    TrieNode()
    {
        m = new HashMap<Character, TrieNode>() ;
    }
}
class Trie
{
    public static TrieNode newNode()
    {
        TrieNode t = new TrieNode() ;
        t.EndOfWord = false ;
        return t ;
    }

    public static void insert(TrieNode root, String s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(!root.m.containsKey(s.charAt(i)))
            {
                root.m.put(s.charAt(i), newNode()) ;
            }
            root = root.m.get(s.charAt(i)) ;
        }
        root.EndOfWord = true;
    }

    public static int search(TrieNode root, String s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(!root.m.containsKey(s.charAt(i)))
            {
                return 0 ;
            }
            root  = root.m.get(s.charAt(i)) ;
        }
        if(root.EndOfWord == true)
        {
            return 1 ;
        }
        return 0 ;
    }

    public static void main(String [] args)
    {
        String[] s = new String[3] ;
        s[0] = "Hello" ;
        s[1] = "Heel" ;
        s[2] = "Mask" ;
        TrieNode root = new TrieNode() ;
        for(int i = 0; i < s.length; i++)
        {
            insert(root, s[i]) ;
        }
        assert(search(root, "Hello") == 1) ;
        assert(search(root, "Heel") == 1) ;
        assert(search(root, "Avc") == 0) ;
        System.out.println("All test cases passed") ;
    }
}
