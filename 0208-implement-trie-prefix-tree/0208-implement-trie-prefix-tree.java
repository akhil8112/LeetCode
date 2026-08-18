class Node{
    Node child[] = new Node[26];
    boolean isLeaf=false;
    public Node(){
        for(int i=0;i<26;i++){
            child[i]=null;
        }

    }

}

class Trie {
    public Node root;
    public Trie() {
        root=new Node();
    }
    
    public void insert(String word) {
        Node curr = root;
        for(int i=0;i<word.length();i++){
            char c=word.charAt(i);
            if(curr.child[c - 'a'] == null){
                Node newNode= new Node();
                curr.child[c - 'a']=newNode;
            }
            curr=curr.child[c-'a'];
        }
        curr.isLeaf=true;
    }
    
    public boolean search(String word) {
        Node temp=root;

        for(int i=0;i<word.length();i++){
            char c=word.charAt(i);
            if(temp.child[c-'a']==null) return false;
            temp = temp.child[c-'a'];

        }
        return temp.isLeaf;
    }
    
    public boolean startsWith(String prefix) {
        Node temp=root;

        for(int i=0;i<prefix.length();i++){
            char c=prefix.charAt(i);
            if(temp.child[c-'a']==null) return false;
            temp = temp.child[c-'a'];

        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */