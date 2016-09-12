#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct heap_array
{
int size ;
int h_array[1024];
};

void insert_into_array(struct heap_array *h , int element)
{
	h->size ++;
	h->h_array[h->size] = element;
}

void print_array(struct heap_array *print)
{
	int i;
	for(i =0;i<=print->size;i++)
	{
		printf("%d\n",print->h_array[i]);	
	}
}
void heapify_up(int heap_array[], int size )
{
	printf("Entered Heapify_up ,  Size value is %d \n",size);
	int temp,temp_swap;
	if(size >0)
	{
		if (heap_array[size] < heap_array[size/2])
		{	
			printf("Size divided by 2 in heapify_up is %d\n",size/2);
			temp_swap = heap_array[size] ;
			heap_array[size] = heap_array[size/2];
			heap_array[size/2] = temp_swap;
			heapify_up(heap_array,size/2);
		}
		else
		{
			return ;
		}

	}
}
void heapify_down(int heap_array[],int pos,int size)
{
	int min,temp ;
	printf("In Heapify Down , pos value is %d\n",pos);
	if(2*(pos+1) >size )
	{
	return ;
	}
	else
	{
		if(heap_array[2*(pos+1)-1] > heap_array[2*(pos+1)+1-1])
		{
			min = 2*(pos+1)+1-1;
		}
		else
		{
			min = 2*(pos+1)-1;
		}
		if(heap_array[pos] > min)
		{
			temp = heap_array[pos];
			heap_array[pos]= heap_array[min];
			heap_array[min] = temp;
			heapify_down(heap_array,min,size); 
		}
	}

}
void delete_min(struct heap_array *del)
{
	printf("Element Popped out %d\n",del->h_array[0]);
	del->h_array[0] = del->h_array[del->size];
	del->size -- ;
	heapify_down(del->h_array,0,del->size);
} 
void main()
{
	struct heap_array *binary_heap = (struct heap_array*) malloc(sizeof(struct heap_array));
	binary_heap->size = -1;
	int element =0 ;
	while(1)
	{
		printf("Enter elements,  Press -1 to stop\n");
		scanf("%d",&element);
		if(element != -1)
		{
			insert_into_array(binary_heap,element);
			heapify_up(binary_heap->h_array,binary_heap->size);
			print_array(binary_heap);
		}
		else
		{
			break;
		}	
	}
	print_array(binary_heap);
        delete_min(binary_heap);
	print_array(binary_heap);
}
