#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char word[101];
	int frequency;
} wrdarr ;

typedef struct {
	wrdarr file[3];
	char fileName[101];
	int frequency;
} FileArray ;

Filearray finalarray[101];
wrdarr words[10000];
Filearray files[5];

int cmpWords(const void *f1, const void *f2){
	wrdarr *a = (wrdarr *)f1;
	wrdarr *b = (wrdarr *)f2;
	return (b->frequency - a->frequency);
}

int main(int argc, char *argv[]){

	int counter;
	int isUnique;
	int i;

	for (i = 1; i < argc; i++){
		FILE *file;
		char buff[1000];
		counter = 0;

		if ( argc < 2){
			printf("usage %s filename invalid", argv[i]);
		}

		else{
			file = fopen(argv[i], "r");
			if (file == NULL){
				printf("Couldn't open file\n");
			}
			else {
				while ( (fscanf(file, "%s", buff)) != EOF)
				{
					isUnique = -1;
					int k;
					for (k = 0; k < counter; k++){
						if (strcmp(words[k].word, buff) == 0){
							isUnique = k;
						}
					}
					// If the string is not in the array, put it in the array
					if (isUnique == -1){
						strcpy(words[counter].word, buff);
						words[counter].frequency = 1;
						counter++;
					}
					
					else {
						words[isUnique].frequency++;
					}	
				}	
			}

		}
		// Sort the wordss
		qsort(words, counter, sizeof(wrdarr), cmpWords);

		// top 5 frequent words
		int m;
		for (m = 0; m < 5; m++){
			finalarray[i].file[m] = words[m];
		}
		finalarray[i].frequency = counter;
		strcpy(finalarray[i].fileName, argv[i]);
		fclose(file);

				if (finalarray[i].file[i].word != NULL){
			printf("FileName: %s ", finalarray[i].fileName);
			printf(" Unique Words: %d\n", finalarray[i].frequency);
			int l;
			for (l = 0; l < 5; l++){
				printf("Word%d: '%s' occurs %d times.\n", l+1, finalarray[i].file[l].word, words[l].frequency);
			}
		}
		printf("\n");
	}

	return 0;
}
