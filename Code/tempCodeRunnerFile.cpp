    *b = t;
}
int main()
{
    char str[100000];
    char p[100000];
    cin>>str>>p;
    int c=0;
    char start=p[0];
    int size = strlen(str);
    cout<<start<<endl;
    for(int i=0;i<size;i++){
        if(str[i]<=start){
            c++;
        }
    }
    cout<<c<<endl;
    char str1[100000];
    for(int i=0;i<size;i++){
        str1[i]=str[i];
    }
    qsort(str1, size, sizeof(str[0]), compare);
    char str2[100000];
    for (int i = 0; i < c-1; i++)
    {
        str2[i] = str1[i];