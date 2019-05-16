/***************
Name: Bryan Cagle
Course: CSCE 3110.001
Assignment: Programming Assignment 5 - Breadth First Search
Due Date: May 6, 2016 11:59pm

Desciprtion: the purpose of this program is to implement
a adjacency matrix based off of an input file, and perform a breadth
first search, prints the results, and conclude whether the 
graph is connected or not.

The output of this program is as follows:

-Print the adjacency list from the file input
-Print whether the graph is determined to be connected or not
-Print the BFS (only if the graph is confirmed to be connected)
***************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int vertCount=0;
	
//This function takes the data input from the txt file in the command line and puts it into a 2D integer matrix, which_open_mode
//proceeds to place the integer matrix into the adjacency list graph.
int convertInput(int inputStore[1000][1000])
{
	char buffer[1000]={'\0'};
	int i=0,j=0,k=0;
	int size=0, first=0;
	int tempConversion[1000][1000]={0};
	
		//Reads the input from the file, stores integers in a matrix as they appear in the matrix
		while(cin >> noskipws >> buffer[k]){
				if(buffer[k]==' '){
					buffer[k]=0;
					inputStore[i][j]=atoi(buffer);
					k=0;
					j++;
					memset(buffer, '\0', sizeof(buffer));
				}
				else if(buffer[k]=='\n'){
					buffer[k]=0;
					inputStore[i][j]=atoi(buffer);
					k=0;
					j=0;
					i++;
					size++;
					vertCount++;
					memset(buffer, '\0', sizeof(buffer));
				}
				else
					k++;	
			}
		inputStore[i][j]=atoi(buffer); //Stores the final input after the file is done beind read
		vertCount++;
		
		//takes the first input vertex value, which should also be the smallest, and stores it as the starting point for the BFS
		first=inputStore[0][0];
		
		//Displays the input of the user of the adjacency list
		cout << "\nAdjacency List input: \n\n";
		for(i=0;i<1000;i++){
			for(j=0;j<1000;j++){
				if(inputStore[i][j]!=0){
				if(j==0)
				cout << "[" << inputStore[i][j] << "]" << " -> ";
				else
				cout << inputStore[i][j] << " -> ";
				}
			}
			cout << "\b\b\b\b    "; // removes extra arrow at the end of output
			if(inputStore[i][j]!=0)
			cout << endl;
		}
	
		//converts the adjacency list form to adjacency matrix form
		for(i=0;i<1000;i++){
			for(j=0;j<1000;j++){
				if(inputStore[i][j]!=0){
				tempConversion[inputStore[i][0]][inputStore[i][j]]=1;
				}
			}
		}
		for(int i=0; i<1000; i++){
			for(int j=0; j<1000; j++){
			inputStore[i][j]=tempConversion[i][j];
			}
		}
		return first;
}

//Performs the breadth first search given the adjacency matrix
int BFS(int inputStore[1000][1000], int first)
{
	int start = -1,end = -1;
    int queue[1000];
	bool visited[1000]={false};
	int visCount=1; //Counts the number of visited vertexes
    int v=first; //The starting point for the BFS
	
	//BFS process for the adjacency list
    visited[v]=true;
    end++;
    start++;
    queue[end]=v;
    while(start<=end)
    {
        v=queue[start];
        start++;
        for(int i=1;i<=1000;i++)
        {
            //Checks for an unvisited vertex and marks it as visited
            if( inputStore[v][i]==1 && visited[i]==false)
            {
                visited[i]=true;
                end++;
                queue[end]=i;
				visCount++;
				
             }
        }
    }

	//Determines if the graph is connected or not by matching the number of vertexes to the number of vertexes visited
	//The only case where they would not be equal is if the graph is not connected
	if(vertCount!=visCount){
		cout << "\nThe graph is not connected" << endl << endl;
		return 0;
	}
	cout << "\nThe graph is connected" << endl << endl;
	cout << "Result of Breadth First Search: \n";
	for(int i=0; i<1000; i++){
		if((queue[i]!=0)&&(queue[i]!=1000))
		cout << queue[i] << " ";
	}
	cout << endl << endl;
}

main()
{
	int inputStore[1000][1000]={0};
	int first = convertInput(inputStore); //Converts user input into adjacency matrix
	BFS(inputStore,first); //Takes adjacency matrix and the first vertex and performs the BFS
}