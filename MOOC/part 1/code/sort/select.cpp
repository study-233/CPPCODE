/*

for(int i=0;i<m-1;i++){
    int p=i;
    for(int j=i+1;j<m;j++){
        if(a[p].score<a[j].score) p=j;
        else if(a[p].score==a[j].score && a[p].num>a[j].num){
        p=j;
        }   
    }
    player temp = a[p];
    a[p] = a[i];
    a[i] = temp;
}

*/