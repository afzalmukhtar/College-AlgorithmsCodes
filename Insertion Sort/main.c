#include<stdio.h>
#include"session5_sort.h"
#include<stdlib.h>
#include<time.h>
double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
    return t;
}


int main()
{
		int size[] = {32000, 64000, 96000, 128000, 160000, 192000, 224000, 256000};
		
		for(int j = 0; j < 8; j++)
		{
        	struct timespec start, end;
        	long int n = size[j];
        	
       		Record *A, *B, *C, *D;
       		A = B = C = D = (Record*)malloc(sizeof(Record)*n);
        
        	for(int i = 0; i < n; i++)
        	{
        		long int num = rand()*n;
                A[i].serialnumber = num % n;
                A[i].score = num % 100;
                B[i] = C[i] = D[i] = A[i];
			}
        
        	printf("\n\n%d. For Array Size of %ld:\n", j + 1, n);	
        	
        	clock_gettime(CLOCK_REALTIME, &start); 
        	long int a = InsertionSort(A,n);
        	clock_gettime(CLOCK_REALTIME, &end);
        	printf("Insertion Sort :%li %lf\n",a,time_elapsed(start,end));
        	
        	clock_gettime(CLOCK_REALTIME, &start); 
        	long int b = BubbleSort(B,n);
        	clock_gettime(CLOCK_REALTIME, &end);
        	printf("Bubble Sort :%li %lf\n",b,time_elapsed(start,end));\
        	
        	clock_gettime(CLOCK_REALTIME, &start); 
        	long int c = SelectionSort(C,n);
        	clock_gettime(CLOCK_REALTIME, &end);
        	printf("Selection Sort :%li %lf\n",c,time_elapsed(start,end));
        	
        	/*clock_gettime(CLOCK_REALTIME, &start); 
        	long int d = BinaryInsertion(D,n);
        	clock_gettime(CLOCK_REALTIME, &end);
        	printf("BinaryInsertion Sort :%li %lf\n",d,time_elapsed(start,end));*/
        }   
            
        return 0;
        
}
