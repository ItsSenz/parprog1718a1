#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// compile like:  gcc -Wall -O2 -DNROWS=10000 matrix1.c -o matrix1
// prospelash ana sthlh tou pinaka


#define NCOLS 100

void get_walltime(double *wct) {
  struct timeval tp;
  gettimeofday(&tp,NULL);
  *wct = (double)(tp.tv_sec+tp.tv_usec/1000000.0);
}


int main() {
FILE *pFile;
double *table;
double ts,te;
pFile=fopen("results.csv", "a");


  table = (double *)malloc(NROWS*NCOLS*sizeof(double)); 
  if (table==NULL) {
    printf("alloc error!\n");
    exit(1);
  }

  // warmup

  for (i = 0; i <NROWS* NCOLS; i++){
	table[i] = 5.0; 
  }

  // get starting time (double, seconds) 
  get_walltime(&ts);
  
  // workload

  for(i=0;i < NROWS;i++){
	for(j=0;j < NCOLS; j++){			
		table[j*NROWS + i] = table[j*NROWS + i] + 2.0;

	}
}

  // get ending time
  get_walltime(&te);

  // check results
  
  for (i = 0; i <NROWS* NCOLS; i++){
	  if(table[i] != 7.0){	
		  printf ("Wups something went wrong ... Check your code..\n");
		  break;
	  }
  }

  // print time elapsed and/or Maccesses/sec
  
  double time = te - ts;
          
	printf("ok\n time took = %lf\n",time);
	printf("Megaccess/sec = %lf\n",(2.0 * NROWS*NCOLS)/(time*1e6));
	fprintf(pFile, "%lf \n",time);
	fprintf(pFile, "%lf \n",(2.0*NROWS*NCOLS)/(time*1e6)); 
  
  free(table);

  return 0;
}

