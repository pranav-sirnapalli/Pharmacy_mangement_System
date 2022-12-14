
#include<stdio.h>

char stack[20];
int top=-1, n;
char b[20],finalPath[20];
char ajMat[20][20];
int fp=0,count;


//Push Operation
void push(char val)
{
   top=top+1;
   stack[top]=val;
}

//Pop Operation
char pop()
{
   return stack[top--];
}

//To check if all adjecent nodes are visited

int allVisited(int i)
{
   int j;
   for(j=0;j<n;j++)
   {
      if(ajMat[i][j]=='y')
          return 0;
   }
   return 1;
}

//To get the current index of node in the array b[] of nodes
int getNo(char c)
{
   int l=0;
   while(c!=b[l])
     l++;
   return l;
}

// To display euler path/circuit
void displayPath()
{
     int i;
     for(i=0;i<fp;i++)
     {
          printf("%c ->",finalPath[i]);
     }
}

// To display Euler circuit/path and store it in finalPath[]
void eularFind(int root)
{
   int l,j;
   //Pushing root
    push(b[root]);
    while(top!=-1)
    {
         l=getNo(stack[top]);
         if(allVisited(l))
         {
             finalPath[fp++]=pop();
         }

         else
         {
            for(j=0;j<n;j++)
            {
               if(ajMat[l][j]=='y')
               {
                        ajMat[l][j]='n';
                        ajMat[j][l]='n';
                        push(b[j]);
                        break;
               }
            }
          }
    }
}

// To get degree
int getDegree(int i)
{
    int j,deg=0;
    for(j=0;j<n;j++)
    {
       if(ajMat[i][j]=='y') deg++;
    }
    return deg;
}

int findRoot()
{

    int i,cur=1;
    for(i=0;i<n;i++)
    {
        if(getDegree(i)%2!=0)
        {
           count++;
           cur = i;
        }
    }
   if(count != 0 && count != 2)     
   {
             return 0;
   }
     else
         return cur;
}

void main()
{
   char v;
   int i,j,l;
   printf("Enter the number of nodes in a graph\n");
   scanf("%d",&n);
   printf("Enter the value of node of graph\n");
   for( i=0; i<n; i++)
   {
       scanf("%s",&b[i]);//store the nodes in b[] array
   }
   printf("Enter the value in adjancency matrix in from of 'Y' or 'N'\n");
   printf("\nIf there is an edge between the two vertices then enter 'Y' or 'N'\n");
   for( i=0; i<n; i++)
       printf(" %c ",b[i]);
   for( i=0;i<n; i++)
   {
       printf("\n%c ",b[i]);
       for( j=0; j<n; j++)
       {
          printf("%c ",v=getchar());
          ajMat[i][j]=v;
       }
       printf("\n\n");
   }
   int root;
   if(root=findRoot())
   {
       if(count)
               printf("Available Euler Path is\n");
       else
               printf("Available Euler Circuit is\n");
       eularFind(root);
       displayPath();
   }
   else
     printf("Euler path or circuit not available\n");
}