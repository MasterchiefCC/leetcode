class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length())return false;
        HashMap<Character, Character>m_map=new HashMap<>();
        boolean used[]=new boolean[256];
        Arrays.fill(used, Boolean.FALSE);
        
        for(int i=0; i<s.length(); ++i){
            if((m_map.containsKey(s.charAt(i))&&m_map.get(s.charAt(i))!=t.charAt(i))||
               (!m_map.containsKey(s.charAt(i))&&used[t.charAt(i)]))return false;
            m_map.put(s.charAt(i), t.charAt(i));
            used[t.charAt(i)]=Boolean.TRUE;
        }
        char temp[]=s.toCharArray();
        for(int i=0; i<s.length(); ++i)temp[i]=m_map.get(temp[i]);
        s=String.valueOf(temp);
        return s.equals(t);
    }
}