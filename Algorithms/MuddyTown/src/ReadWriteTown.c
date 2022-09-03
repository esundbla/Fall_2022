/*	Town.c

	Read in and display given town files and write towns out to files 
*/

#include <stdio.h>
#include <string.h>


#include "../graph.c"


typedef struct Town
{
	char townName[255];
	graph townMap;
	
}Town;
#define MAXNODES  99

Town readInTown(char filePath[]){
	char line[255];
	Town newTown;
	graph newMap;
	FILE * fp;
	int vertexCount = 0;
	char *token;
	char delem[2] = ",";
	char newEdge[3][100];
	char nodesMapping[MAXNODES][100];

	initialize_graph(&newMap, false);
	fp = fopen(filePath, "r");

	fgets(line, 255, fp);
	strcpy(newTown.townName, line);

	while(fgets(line, 255, fp) != NULL){
		int x;
		int y;
		int weight;
		line[strcspn(line, "\n")] = 0;
		token = strtok(line, delem);
		int z =0;
		
		while( token != NULL){
			strcpy(newEdge[z], token);
			//printf( " %s\n", token);
			z++;
			token = strtok(NULL, delem);
		}
		weight = atoi(newEdge[0]);
		int *index;
		for(int i=1; i<3; i++){
			index = (i==1)? &x : &y;
			for(int j=0; j<MAXNODES; j++){			
				if(strcmp(newEdge[i], nodesMapping[j]) == 0){
					*index = j;
					break;
				}else if(strlen(nodesMapping[j]) == 0){
					strcpy(nodesMapping[j], newEdge[i]);
					*index = j;
					vertexCount++;
					break;
				}
			}
		}
		insert_edge(&newMap, x, y, false, weight);
	}
	newMap.nvertices = vertexCount;
	newTown.townMap = newMap;
	return newTown;
}

int main(){
	char filePath[] = "MiniTown.dat";
	Town town = readInTown(filePath);
	printf(" %s", town.townName);
	print_graph(&town.townMap);
	return 0;
}