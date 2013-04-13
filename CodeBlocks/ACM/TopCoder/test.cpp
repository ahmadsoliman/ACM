int saveCreatures(int[] you, int[] computer){
    sort(you.begin(), you.end());
    sort(computer.begin(), computer.end());
    int i=computer.size(), j=i, sum=0;
    while(i&&j){
        if(you[i]>computer[j]){
            sum+=you[i];
            i--;j--;
        }else j--;
    }
    return count;
}
