#include "cachelab.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <math.h>

typedef struct {
    int validbit;
    int tagbit;
    int notused; //how many times the line has not been used
} line;

unsigned long long int bitmanip(unsigned long long int address, int numbits, int shift) {
    int x = address>>numbits;
    int mask = (shift-1);
    //printf("mask = %d\n", mask);
    return mask&x;
}

int main(int argc, char **argv)
{	
	int hflag = 0;
	int vflag = 0;
	int sflag = 0;
	int eflag = 0;
	int bflag = 0;
	int tflag = 0;

	int sindexbits;
	int linesps;
	int blockbits;
	char* filename;

	FILE *fp;

	int c;

	opterr = 0;

	while((c = getopt(argc, argv, "hvs:E:b:t:")) != -1)
		switch (c)
		{
			case 'h':
				hflag = 1;
				fprintf(stderr, "hflag: %d\n", hflag);
				break;
			case 'v':
				vflag =1;
				fprintf(stderr,"vflag: %d\n", vflag);
				break;
			case 's':
				sflag = 1;
			    sindexbits = atoi(optarg);
				fprintf(stderr, "sflag: %d, sindexbits: %d\n", sflag,  sindexbits);
				break;
			case 'E':
				eflag = 1;
				linesps = atoi(optarg);
				fprintf(stderr, "eflag: %d, linesps: %d\n", eflag, linesps);
				break;
			case 'b':
				bflag = 1;
				blockbits = atoi(optarg);
				fprintf(stderr, "bflag: %d, blockbits: %d\n", bflag, blockbits);
				break;
			case 't':
				tflag = 1;
				filename = optarg;
				fprintf(stderr, "tflag: %d, tvalue: %s\n", tflag, filename);
				break;
			default:
				abort();

		}	


	fp = fopen(filename, "r");
	int setindex = pow(2, sindexbits);
    //int blockindex = pow(2, blockbits);

    line **sets = (line**) malloc(setindex*sizeof(line));
    for (int i = 0; i<=(setindex-1); i++) {
        sets[i] = (line*) malloc(linesps*sizeof(line));
        for (int j = 0; j<=(linesps-1); j++) {
            sets[i][j].validbit = 0;
            sets[i][j].tagbit = 0;
            sets[i][j].notused = 0;
        }
    }

"[redacted]"	

	while((fgets(line, 1000, fp)) != NULL) {
        "[redacted]"
            setbits = bitmanip(address, blockbits, setindex);
            //printf("setbits = %llx\n", setbits);

            tag = address>>(blockbits+sindexbits);
            //printf("tagbits = %llx\n", tag);

        if ((type == 'S') || (type == 'L') || (type == 'M')) {
            for (int i = 0; i <= (linesps-1); i++) {
                if ((sets[setbits][i].validbit == 1) && (sets[setbits][i].tagbit == tag)) {
                    hits++;
                    printf("hit\n");
                    sets[setbits][i].notused = 0;
                    success = 1;
                } else {
                    sets[setbits][i].notused++;
            }
            }

            if (success == 0) {
                for (int i = 0; i<=(linesps-1); i++) {
                    if (sets[setbits][i].validbit == 0) {
                        sets[setbits][i].validbit = 1;
                        sets[setbits][i].tagbit = tag;
                        sets[setbits][i].notused = 0;
                        misses++;
                        printf("miss\n");
                        success = 1;
                        break;
                    }
                }
            }

            "[redacted]"
                    }
                }
            }

            if (type == 'M') {
                hits++;
                printf("hit\n");
        }
        }
    }
            
 
           
    printSummary(hits, misses, evictions);
    return 0;
}
