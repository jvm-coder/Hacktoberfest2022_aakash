class Solution {        
        public List<List<Integer>> getSkyline(int[][] buildings){ 
        int pt[][] = new int[buildings.length * 2][2];
        int itr = 0;
        for(var b:buildings){
            pt[itr++] = new int[]{b[0],-b[2]};
            pt[itr++] = new int[]{b[1],b[2]};
        }
        Arrays.sort(pt,(a,b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        List<List<Integer>> ans = new ArrayList<>();
        PriorityQueue<Integer> ht = new PriorityQueue<>(Collections.reverseOrder());
        ht.add(0);
        int c_ht = 0;
        for(int i = 0;i < pt.length;i++){
            int x = pt[i][0];
            int h = pt[i][1];
            
            if(h < 0) ht.add(-h);
            else ht.remove(h);
            
            if(c_ht != ht.peek()){
                ans.add(Arrays.asList(x,ht.peek()));
                c_ht = ht.peek();
            }
        }
        return ans;
    }
}
