/*	ReadWriteTown.c

	Read in and display given town files and write towns out to files 
*/

#include <stdio.h>
#include <string.h>

#include "../graph.h"
#include "../graph.c"

typedef struct ReadWriteTown
{
	char *townName;
	graph townMap;
	
}ReadWriteTown;
#define MAXNODES  99

ReadWriteTown readInTown(char *filePath){
	char line[255];
	ReadWriteTown newTown;
	graph newMap;
	FILE *fp;
	char *token;
	char delem[2] = ",";
	char newEdge[3][100];
	int edgeCount = 0;
	char *nodesMapping[MAXNODES][100];

	initialize_graph(&newMap, false);
	fopen(filePath, 'r');

	fgets(newTown.townName, 255, fp);

	while(fgets(line, 255, fp) != NULL){
		int x;
		int y;
		int weight;
		token = strtok(line, delem);
		int z =0;
		
		while( token != NULL){
			strcpy(newEdge[z], token);
			print( " %s\n", token);
			z++;
			token = strtok(NULL, delem);
		}
		weight = atoi(newEdge[0]);
		for(int i=1; i<3; i++){
			int *index;
			index = (i==1)? &x : &y;
			for(int j=0; j<MAXNODES; j++){
				if(strcmp(newEdge[i], nodesMapping[j]) == 0){
					*index = j;
				}else if(nodesMapping[j] == NULL){
					strcpy(nodesMapping[j], newEdge[i]);
					*index = i;
					break;
				}
			}
		}
		
		insert_edge(&newMap, x, y, false, weight);
		edgeCount++;
	}
	newTown.townMap = newMap;
	return newTown;
}

int main(){
	char filePath[] = "./MiniTown.dat";
	ReadWriteTown town = readInTown(&filePath);
	print_graph(&town.townMap);
	return 0;
}
