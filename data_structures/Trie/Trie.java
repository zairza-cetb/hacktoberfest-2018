import java.util.* ;

class Trie_Node
{
    boolean EndOfWord ;
    Map<Character, Trie_Node> m ;
    Trie_Node()
    {
        m = new HashMap<Character, Trie_Node>() ;
    }
}
class Trie
{
    public static Trie_Node newNode()
    {
        Trie_Node t = new Trie_Node() ;
        t.EndOfWord = false ;
        return t ;
    }

    public static void insert(Trie_Node root, String s)
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

    public static int search(Trie_Node root, String s)
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
        Trie_Node root = new Trie_Node() ;
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
