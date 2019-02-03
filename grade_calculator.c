#include <stdio.h>

// function prototypes
unsigned int line();
void chart(unsigned int SIZE, unsigned int answer[]);
void mean(unsigned int SIZE, const unsigned int answer[]);
void onequarter(unsigned int SIZE, unsigned int answer[]);
void median(unsigned int SIZE, unsigned int answer[]);
void threequarters(unsigned int SIZE, unsigned int answer[]);
void bubbleSort(unsigned int SIZE, unsigned int a[]);
void printArray(unsigned int SIZE, const unsigned int a[]);

int main(void)
{
   unsigned int SIZE = line();
   // initialize array response
   unsigned int response[SIZE];
	
   // Reading and printing a sequential file
   file(SIZE, response);

   // process responses
   bubbleSort(SIZE, response);
   chart(SIZE, response);
   printf("\nTotal Number: %d\n", SIZE);
   mean(SIZE, response);
   onequarter(SIZE, response);
   median(SIZE, response);
   threequarters(SIZE, response);
   
}

// determine most frequent response
void chart(unsigned int SIZE, unsigned int answer[])
{
	printf("\n%s\n\n","Grade Calculator");
	
   // initialize array frequency
	unsigned int frequency[10] = {0};
   
   // summarize frequencies (0~89)
    for(unsigned int i = 0; i < 90; i+=10) {
	   for (unsigned int j = 0; j < SIZE; ++j) {
	   		if(answer[j] >= i && answer[j] <= i+9) {
	   			++frequency[i/10];
			}
	   } 
	}
	
   // summarize frequencies (90~100)
	for (unsigned int j = 0; j < SIZE; ++j) {
	   		if(answer[j] >= 90 && answer[j] <= 100) {
	   			++frequency[9];
			}
	   } 
	
	printf(" %s %13s%16s\n", "Grade", "frequency", "Histogram");
	
	// output histogram bar representing frequency value
	printf(" %s%10d           ", "00~09", frequency[0]);
	for (int k = 1; k <= frequency[0]; ++k) {
		    printf("%c", '*');                                  
	}
	puts("");  
	for (int j = 1; j < 9; j++) {
		column(j);
	    printf("%9d           ", frequency[j]);
	      
		for (int k = 1; k <= frequency[j]; ++k) {
		    printf("%c", '*');                                  
		}
		puts("");    
	}
	printf(" %s%9d           ", "90~100", frequency[9]);
	for (int k = 1; k <= frequency[9]; ++k) {
		    printf("%c", '*');                                  
	}
	puts("");  
} 

// output column head
void column(unsigned int i) {
    printf("%3u~%u ", i*10, i*10+9);
}

// calculate average of all response values
void mean(unsigned int SIZE, const unsigned int answer[])
{
   unsigned int total = 0; // variable to hold sum of array elements

   // total response values
   for (size_t j = 0; j < SIZE; ++j) {
      total += answer[j];
   } 

   printf("\nAverage: %.4f\n", (double) total / SIZE);
} 

// calculate onequarter of all response values
void onequarter(unsigned int SIZE, unsigned int answer[])
{
   // display onequarter element
   if(SIZE % 4 == 0) {
	   printf("\nOne-quarter: Number: %.2f  Value: %u\n",
	           (float)(((SIZE/4) + (float)((SIZE/4)+1))/2), (answer[SIZE/4] + answer[(SIZE/4) + 1])/2);
	}
   else {
		printf("\nOne-quarter: Number: %u  Value: %u\n",
	           SIZE/4 + 1, answer[SIZE/4 + 1]);	
	}
}

// calculate median of all response values
void median(unsigned int SIZE, unsigned int answer[])
{
   // display median element
   if(SIZE % 2 == 0) {
	   printf("\nMedian: Number: %.2f  Value: %u\n",
	           (float)(((SIZE/2) + (float)((SIZE/2)+1))/2), (answer[SIZE/2] + answer[(SIZE/2) + 1])/2);
	}
   else {
		printf("\nMedian: Number: %u  Value: %u\n",
	           (SIZE + 1)/2, answer[(SIZE + 1)/2]);	
	}
} 

// calculate threequarter of all response values
void threequarters(unsigned int SIZE, unsigned int answer[])
{
   // display threequarter element
   // display median element
   if(SIZE % 4 == 0) {
	   printf("\nThree-quarters: Number: %.2f  Value: %u\n",
	           (float)((((SIZE/4)*3) + (float)(((SIZE/4)*3)+1))/2), (answer[((SIZE/4)*3)] + answer[((SIZE/4)*3)+1])/2);
	}
   else {
		printf("\nThree-quarters: Number: %u  Value: %u\n",
	    		(SIZE*3)/4 + 1, answer[(SIZE*3)/4 + 1]);
	}
}

// function that sorts an array with bubble sort algorithm
void bubbleSort(unsigned int SIZE, unsigned int a[])
{
   // loop to control number of passes
   for (unsigned int pass = 1; pass < SIZE; ++pass) {

      // loop to control number of comparisons per pass
      for (size_t j = 0; j < SIZE - 1; ++j) {

         // swap elements if out of order
         if (a[j] > a[j + 1]) {
            unsigned int hold = a[j];
            a[j] = a[j + 1];
            a[j + 1] = hold;
         } 
      } 
   } 
} 

// output array contents (20 values per row)
void printArray(unsigned int SIZE, const unsigned int a[])
{
   // output array contents
   for (size_t j = 0; j < SIZE; ++j) {

      if (j % 20 == 0) { // begin new line every 20 values
         puts("");
      } 

      printf("%2u", a[j]);
   } 
} 

unsigned int line() {
	unsigned int inPut;
	unsigned int LINE;
	// cfPtr = grade.txt file pointer
	FILE *cfPtr;
	
	// fopen opens file; exits program if file cannot be opened 
	if ((cfPtr = fopen("grade.txt", "r")) == NULL) {
		puts("File could not be opened");
	}
	
	else { // read grade
	  
	  // keep track of total number
	  while (!feof(cfPtr)) {
	  	fscanf(cfPtr, "%d", &inPut);
        ++LINE;
      }

      fclose(cfPtr); // fclose closes the file   
   } 
   return LINE;
}

// Reading and printing a sequential file
void file(unsigned int SIZE, unsigned int response[]) {
	
	// cfPtr = grade.txt file pointer
	FILE *cfPtr;
	
	// fopen opens file; exits program if file cannot be opened 
	if ((cfPtr = fopen("grade.txt", "r")) == NULL) {
		puts("File could not be opened");
	}

	else { // read grade
      
	  for(unsigned int i = 0; i <= SIZE; i++) {
	  	fscanf(cfPtr, "%d", &response[i]);
	  }
      
      // while not end of file
      while (!feof(cfPtr)) { 
         printf("%d", response);
         for(unsigned int i = 0; i <= SIZE; i++) {
	  	 	fscanf(cfPtr, "%d", &response[i]);
	     }
      } 

      fclose(cfPtr); // fclose closes the file   
   } 
}

