#include<stdlib.h>
#include<stdio.h>


struct node{
int info;
struct node * link;
};
typedef struct node* NODE;
NODE createnode();
void Display(NODE);
NODE createnode()
{
NODE NN;
NN=(NODE)malloc(sizeof(struct node));
return NN;
}
void Display(NODE pf)
{
while(pf!=NULL)
{
printf("%d\n",pf->info);
pf=pf->link;
}
}
NODE cpyu(NODE);
NODE cpyu(NODE pf)
{NODE NN,cpy,ccpy;
 NN=createnode();
 ccpy=cpy=NN;
 cpy->info=pf->info;
 cpy->link=pf->link;
 pf=pf->link;
 while (pf!=NULL)
{NN=createnode();
 cpy=NN;
 cpy->info=pf->info;
 cpy->link=pf->link;
 pf=pf->link;
 }
 cpy->link=NULL;
 return ccpy;
 }

NODE revu(NODE);
NODE revu(NODE pf)
{NODE NN,rev;
 NN=createnode();
 rev=NN;
 rev->info=pf->info;
 rev->link=NULL;
 pf=pf->link;
 while (pf!=NULL)
{NN=createnode();
 NN->link=rev;
 rev=NN;
 rev->info=pf->info;
 pf=pf->link;
 }

 return rev;
 }




void main()
{

NODE First=createnode();
NODE NN=createnode();
NODE cpy,rev;
First->link=NN;
NN=createnode();
First->link->link=NN;
First->info=10;
(First->link)->info=20;
((First->link)->link)->info=30;
Display(First);
cpy=cpyu(First);
Display(cpy);
rev=revu(First);
Display(rev);

}

