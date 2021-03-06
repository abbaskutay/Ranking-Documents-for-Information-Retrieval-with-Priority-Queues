#include <string.h>
#include <stdlib.h>
#include <stdio.h>
static int c=0;
int H[50];
int size = -1;
void swap(int xp, int yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
int parent(int i)
{

    return (i - 1) / 2;
}

int leftChild(int i)
{

    return ((2 * i) + 1);
}

int rightChild(int i)
{

    return ((2 * i) + 2);
}
void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i]) {

        // Swap parent and current node
        swap(H[parent(i)], H[i]);

        // Update i to parent of i
        i = parent(i);
    }
}

void shiftDown(int i)
{
    int maxIndex = i;

    // Left Child
    int l = leftChild(i);

    if (l <= size && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

    // Right Child
    int r = rightChild(i);

    if (r <= size && H[r] > H[maxIndex]) {
        maxIndex = r;
    }

    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

// Function to insert a new element
// in the Binary Heap
void insert(int p)
{
    size = size + 1;
    H[size] = p;

    // Shift Up to maintain heap property
    shiftUp(size);
}

// Function to extract the element with
// maximum priority
int extractMax()
{
    int result = H[0];

    // Replace the value at the root
    // with the last leaf
    H[0] = H[size];
    size = size - 1;

    // Shift down the replaced element
    // to maintain the heap property
    shiftDown(0);
    return result;
}

int getMax()
{

    return H[0];
}

// Function to remove the element
// located at given index
void remove1(int i)
{
    H[i] = getMax() + 1;

    // Shift the node to the root
    // of the heap
    shiftUp(i);

    // Extract the node
    extractMax();
}

int readfile(char student[50]){
		c++;
	    int num =0;
        char word[20];
        word[0]='\0';
        char string[50];
        char q[5];
		itoa(c, q, 10);
		strcat(word,"\0");
		strcat(word, "doc");
		strcat(word, q);
		strcat(word, ".txt");
		strcat(word, "\0");
		printf(word);
        {
                FILE *in_file = fopen(word, "r");
                if (in_file == NULL)
                {
                        printf("Error file missing\n");
                        exit(-1);
                }


                while ( fscanf(in_file,"%s", string) == 1)
                {
                        //Add a for loop till strstr(string, student) does-not returns null.
                        if(strstr(string, student)!=0) {//if match found
                                num++;
                        }
                }
                printf(" Found the word %s in the file %d times\n",student,num );
                fclose(in_file);


    }
    return num;
}
void swap1(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n,int arr2[])
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] < arr[j+1]){

              swap1(&arr[j], &arr[j+1]);
              swap1(&arr2[j], &arr2[j+1]);
          }
}
int main(int argc, char const *argv[])
{
	char student[50];
	int array[42];
	printf("please enter a word(enter 0 to end)\n");
    scanf("%s", student);
    int i=0;
    int j=0;
    for(i=0;i<42;i++)
    array[i]=readfile(student);
    int array2[42];
  for(i=0;i<42;i++){
  	array2[i]=i+1;
  }
   int n = sizeof(array)/sizeof(array[0]);
    bubbleSort(array, n,array2);

    i=0;
    for(i=0;i<5;i++){
    	insert(array[i]);
	}

    i = 0;

    // Priority queue before extracting max
    printf("Priority Queue : ");
    while (i <= size) {
        printf("\nDocument number %d",array2[i]);
        printf(" with words count %d",H[i]);
        printf("\n");
        i++;
    }

    printf("\n");

     // Document with Maximum Priority
    printf("Document with Maximum Priority is doc%d",array2[0]);
    printf(" with words count %d",extractMax());

  return 0;
}
