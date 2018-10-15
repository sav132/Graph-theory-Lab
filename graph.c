#include<stdio.h>

int a[10][10],n,d=0,p[10],k=0,h[10][10],c=0,temp=0,i,j,z,e,f,temp1,temp2,temp3,temp4;
int display();
//int circuit();

int main()
{
    printf("WELCOME TO THE WORLD OF DIRECTED CIRCUITS\n");
    printf("ENTER THE NUMBER OF VERTICES:");
    scanf("%d",&n);
    printf("\nFILL THE ADJACENCY MATRIX:");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("\nENTER STATE FROM V%d to V%d:",i,j);
            scanf("%d",&a[i][j]);

        }
    }


    display();
    printf("\n");
    k=1;
    p[1]=1;
    for(z=1;z<=n;z++){
        printf("P%d\t",z);
    }
    printf("\n");
    for(z=1;z<=n;z++){
        printf("%d\t",p[z]);
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            h[i][j]=0;
        }
    }
    i=p[1]+1;
    for(f=0;f<1000;f++){
        if(i>n){
            temp1=p[k];
            temp2=p[1];
            temp4=p[k-1];
            if(a[temp1][temp2]==1){
                printf("DIRECTED CIRCUITS");
            }
            if(k==1){
                printf("\n************************************************************\n");

                p[1]=p[1]+1;
                p[k]=p[1];
                if(p[1]<=n){
                    for(z=1;z<=n;z++){
                        printf("P%d\t",z);
                    }
                    printf("\n");
                    for(z=1;z<=n;z++){
                        printf("%d\t",p[z]);
                    }
                }
                if(p[1]>n){
                    printf("TATAAAAAAAAAAAAAAAAAAAAAAA");
                    break;
                }
                else if(p[1]<n){
                    for(e=1;i<=n;i++){
                        for(f=1;j<=n;j++){
                                h[e][f]=0;
                        }
                    }
                    i=p[1]+1;
                }
                else{
                    continue;
                }
            }//if k==1

            else{
                for(e=1;e<=n;e++){
                    h[temp1][e]=0;
                }
                h[temp4][temp1]=1;
                p[k]=0;
                k=k-1;
                i=p[1]+1;
                printf("\n");
                for(e=1;e<=n;e++){
                        printf("%d\t",p[e]);
                }
            }
        } // if i > n 
        else{
            temp=p[k];
            if(a[temp][i]==1){
                for(z=1;z<=n;z++){
                    if(i==p[z]){
                        c++;
                    }
                }
                if(c>0){
                    i=i+1;
                    c=0;
                }
                else{
                    temp=p[k];
                    if(h[temp][i]==1){
                        i=i+1;
                    }
                    else{
                        k=k+1;
                        p[k]=i;
                        printf("\n");
                        for(z=1;z<=n;z++){
                            printf("%d\t",p[z]);
                        }
                        i=p[1]+1;
                    }
                }
            }
            else{
                i=i+1;
            }
        }
    }
    return 0;
}

int display()
{
    int i,j;
    for(i=1;i<=n;i++){
        printf("\tV%d",i);
    }
    printf("\n");
    for(i=1;i<=n;i++){
        printf("V%d\t",i+1);
        for(j=1;j<=n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
