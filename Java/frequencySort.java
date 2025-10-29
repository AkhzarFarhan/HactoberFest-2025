class Solution {
    public String frequencySort(String s) {
        HashMap<Character,Integer> hm = new HashMap<>();
        String st = "";

        for(int i=0;i<s.length();i++){
            if(hm.containsKey(s.charAt(i))){
                hm.put(s.charAt(i),hm.get(s.charAt(i))+1);
            }else{
                hm.put(s.charAt(i),1);
            }
        }
        PriorityQueue<Character> pq = new PriorityQueue<>((a, b) -> hm.get(b) - hm.get(a));
         pq.addAll(hm.keySet());

        while(pq.size()>0){
           char c = pq.remove();

           for(int i=0;i<hm.get(c);i++){
            st+=c;
           }
        }
        return st;
    }
}
