#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
int c=0,k=0;
struct frame {
    int data;
    int count;
    struct frame *next;

};
struct frame *start=NULL;
void create (int frame_size){
  struct frame *newnode,*temp;
  int frame_data = -1;
  int frame_count =-1;
  if(frame_size!=0){

    newnode = malloc(sizeof(struct frame));
    start = newnode;
    temp = start;
    start->data = frame_data;
    start->count = frame_count;

  for (int i = 2; i <= frame_size; i++) {
				newnode = malloc(sizeof(struct frame));
				temp->next = newnode;
				newnode->data = frame_data;
        newnode->count = frame_count;
				temp = temp->next;
			}
}
}
int check_min(int frame_size){
  int min_index=0;

  struct frame *temp;
  temp = start;
  int min = temp->count;
  for( int j =0;j<frame_size;j++){
    if(min>=temp->count){
      min=temp->count;
      min_index=j;
    }
    temp=temp->next;
  }return min_index;
}
void initial(int value){
  struct frame *temp;
  temp = start;
  for(int j =0;j<k;j++){
    temp=temp->next;
  }
  k++;
  temp->data=value;
  temp->count=c++;
}
int search(int value, int frame_size){
    int j=0;
    struct frame *temp;

    temp= start;
    if(temp == NULL){

        return -1;
    }
    else{

        for(int i =0;i<frame_size;i++){
            if(temp->data==value){

                return j;
            }
              j++;
                temp= temp->next;

        }


        return -1;
    }

}
void update(int n,int value){
  struct frame* temp;
  temp = start;
  for(int i =0;i<n;i++){
    temp=temp->next;
  }
  temp->data=value;
  temp->count= c++;
}
void display(int frame_size){
  struct frame* temp;

  	// List is empty
  	if (start == NULL)
  		printf("\nList is empty\n");

  	// Else print the LL
  	else {
  		temp = start;
  		for(int i =0;i<frame_size;i++) {
  			printf("Data = %d\t", temp->data);
        printf("count = %d\t\n", temp->count);
  			temp = temp->next;
  		}
  	}

}
int main() {
  int i,traverse,choice;
  printf("Enter your choice : 1.FIFO 2.LRU 3.Exit\n" );
  scanf("%d",&choice );
  int frame_size, page_size;
  FILE* fp = fopen("input.txt","a+");
  fscanf(fp,"%d",&frame_size);
//  printf("%d\n",frame_size );
  fscanf(fp,"%d",&page_size);
//  printf("%d\n",page_size );
  do{if(choice==1){
    int page[page_size];
    for (i = 0; i < page_size; i++)
      {
          fscanf(fp, "%d", &page[i]);
      }




    create(frame_size);
    for (i = 0; i < frame_size; i++)
    { printf("Data Entered : %d\n", page[i]);
        initial(page[i]);
        display( frame_size);
        printf("\n");
    }
    for (i = frame_size; i < page_size; i++)
    {
        printf("Data Entered : %d\n", page[i]);
        traverse=search(page[i],frame_size);
        if(search(page[i],frame_size)>=0){
        //  update(traverse,page[i]);
          display( frame_size);
          printf("\n");
        }
        else{
          update(check_min(frame_size),page[i]);
          display( frame_size);
          printf("\n");
          //printf("\n");
            //printf("%d\n",check_min(frame_size) );
        }

      }


    fclose(fp);
    return 0;
  }
  else if(choice==2){
    int page[page_size];
    for (i = 0; i < page_size; i++)
      {
          fscanf(fp, "%d", &page[i]);
      }





    create(frame_size);
    for (i = 0; i < frame_size; i++)
    { printf("Data Entered : %d\n", page[i]);
        initial(page[i]);
        display( frame_size);
        printf("\n");
    }
    for (i = frame_size; i < page_size; i++)
    {
        printf("Data Entered : %d\n", page[i]);
        traverse=search(page[i],frame_size);
        if(search(page[i],frame_size)>=0){
          update(traverse,page[i]);
          display( frame_size);
          printf("\n");
        }
        else{
          update(check_min(frame_size),page[i]);
          display( frame_size);
        //  printf("\n");
        //  printf("\n");
            //printf("%d\n",check_min(frame_size) );
        }

      }


    fclose(fp);
    return 0;
  }}while(choice!=3);



}
