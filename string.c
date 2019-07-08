/******************************************************************************
 @author: Saurav Rai
The task is to ask user from which character and till where he wants to create another string.
for eg: if the user enters 4 and 7, the output should be "king".

*******************************************************************************/

int main()
{
    char a[]="Working with string is fun\n";
    printf("%s",a);
    int s,e,j=0; 
    printf("Enter s and e\n");
    scanf("%d%d",&s,&e);
    char b[e-s+2];
    for(int i=s-1;i<=e-1;i++){
        b[j]=a[i];
        j++;
    }
    b[j]='\0';
    printf("%s",b);
}