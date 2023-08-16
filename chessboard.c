#include<stdio.h>
#include<stdlib.h>



typedef struct chesscell
		{       int cx,cy;
			int distance;
			int value;
			struct chesscell *next;
		}cell,*cellptr;


typedef struct queue
		{
			cellptr start;
			cellptr end;
		}queuetype,*qptr;


qptr dequeue(qptr );
qptr enqueue (qptr ,cellptr );
	
int main()
	{

		int row[]={2,2,-2,-2,1,1,-1,-1};
		int col[]={-1,1,1,-1,2,-2,2,-2};
		
		int i,j,k;

		cellptr cell[8][8];
		for(i=0;i<=7;i++)
		{
			for(j=0;j<=7;j++)
			{
				cell[i][j]=(cellptr) malloc (sizeof(cell));
				cell[i][j]->cx=i;				
				cell[i][j]->cy=j;
				cell[i][j]->distance=0;
				cell[i][j]->value=0;
				cell[i][j]->next=NULL;
			}
		}
		int sx,sy,dx,dy,x,y;
		printf("enter source x and y co-ordinates\n");
		scanf("%d%d",&sx,&sy);
		printf("enter destination x and y co-ordinates\n");
		scanf("%d%d",&dx,&dy);


		if(!( (0<=sx) && (sx<=7) && (0<=sy) && (sy<=7) && (0<=dx) && (dx<=7) && (0<=dy) && (dy<=7) ))
		{
		printf("invalid source or destination co-ordinates\n");
		return 0;
		}

		
		x=sx;
		y=sy;

		qptr Q = (qptr)malloc(sizeof(queuetype));
		Q->start=NULL;
		Q->end=NULL;

		Q=enqueue(Q,cell[x][y]);

		int tempx,tempy;
		
		do
		{
			if(((cell[x][y]->cx)==dx)&&((cell[x][y]->cy)==dy))
			{
				Q->start=NULL;
				Q->end=NULL;
				printf("minimum distance=%d\n",cell[x][y]->distance);
			}
			else
			{
				
				for(k=0;k<=7;k++)
				{       
					tempx=(cell[x][y]->cx)+row[k];
					tempy=(cell[x][y]->cy)+col[k];

					if((0<=tempx)&&(tempx<=7)&&(0<=tempy)&&(tempy<=7))
					{
						if((cell[tempx][tempy])->value == 0)
                                                {       
							cell[tempx][tempy]->value =1;
							cell[tempx][tempy]->distance =(cell[x][y]->distance)+1;
							printf("%d %d\n",tempx,tempy);
							Q=enqueue(Q,cell[tempx][tempy]);
					
						}
					}			



				}
						
			  	Q=dequeue(Q);
                                x=(Q->start)->cx;
				y=(Q->start)->cy;

			}
		}while(!((Q->start==NULL)&&(Q->end==NULL)));
	
  return 0;		
}	



qptr enqueue (qptr Q2,cellptr c)
	{
		if((Q2->start==NULL)&&(Q2->end==NULL))		
		{
			Q2->start=c;
			Q2->end=c;
			return Q2;
		}
		else
		{
			Q2->end->next=c;
			Q2->end=c;
			return Q2;
		}
	}
			
			
qptr dequeue(qptr Q2)
	{
		Q2->start=Q2->start->next;
                return Q2;
	}





