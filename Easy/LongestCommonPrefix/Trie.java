package LongestCommonPrefix;

public class Trie {
    TrieNode root;     
    private class TrieNode{
        TrieNode[]children;
        boolean isWord;
        char val;
        int wc;
        public TrieNode(char c){
            this.children = new TrieNode[26];
            this.isWord = false;
            this.val = c;
            this.wc = 1;
        }
    }
    public Trie(){
        root = new TrieNode(' ');
    }
    protected void insert(String s){
        char[]c = s.toLowerCase().toCharArray();
        TrieNode current = root;
        for(int i = 0 ; i < c.length ; i++){
            int index = c[i] - 'a';
            if(current.children[index] == null){
                TrieNode node = new TrieNode(c[i]);
                current.children[index] = node;
                current = node;
            }
            else{
                current.wc++;
                current = current.children[index];
                
            }
        }
        current.isWord = true;
    }
    protected boolean searchWord(String s){
        char[] c = s.toLowerCase().toCharArray();
        TrieNode current = root;
        for(int i = 0 ; i < c.length ; i++){
            int index = c[i] - 'a';
            if(current.children[index] !=null){
                System.out.print(current.val + " -->");
                current = current.children[index];
            }
            else{
                break;
            }
        }
        return current.isWord;
    }
    String searchCommonPrefix(String[] strs){
        int n = strs.length;
        for (int i = 0; i < n; i++) {
            insert(strs[i]);
        }
        TrieNode current = root;
        char[] c = strs[strs.length - 1].toLowerCase().toCharArray();
        String prefix = " ";
        for (int i = 0; i < c.length; i++) {
            int index = c[i] - 'a';
            if (current.wc == 3) {
                current = current.children[index];
                prefix = prefix+c[i];
            } else {
                break;
            }
        }
        String fix = prefix.replaceAll("\\s", "");
        return fix;
    }
}
