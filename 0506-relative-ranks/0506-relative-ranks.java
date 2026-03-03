class Solution {
    public String[] findRelativeRanks(int[] score) {
        int l=score.length;
        int arr[]=new int[l];
        String rank[]=new String[l];
        for(int i=0;i<l;i++){
            arr[i]=score[i];
        }
        int a=l-3;
        Arrays.sort(score);
        int k=4;
        for(int i=0;i<l;i++){
            if(arr[i]==score[l-1]){
                rank[i]="Gold Medal";
            }
            else if(arr[i]==score[l-2]){
                rank[i]="Silver Medal";
            }
            else if(arr[i]==score[l-3]){
                rank[i]="Bronze Medal";
            }
            
            else{
                
                for(int p=0;p<a;p++){
                    if(arr[i]==score[p]){
                        int j=l-p;  
                        String s=Integer.toString(j); 
                        rank[i]=s;

                    }
                }
            }
        }
    return rank;
    }
}