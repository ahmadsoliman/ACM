
int arr[10];

int main(){
    int i,j,k, two10=1<<10, sum, maxsum=1000;
    scanf("%d%d%d%d%d%d%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);
    sum=0;

    for(i=0; i<10; i++){
        sum+=arr[i];
        if(abs(sum-100)<abs(maxsum-100)) maxsum=sum;
        else if(abs(sum-100)==abs(maxsum-100)) maxsum=((sum<maxsum)?maxsum:sum);
    }
    printf("%d\n", maxsum);
    return 0;
}
