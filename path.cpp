// CPP program to Print all possible paths from 
// top left to bottom right of a mXn matrix 
#include<iostream> 
#include<vector>
using namespace std; 

/* mat: Pointer to the starting of mXn matrix 
i, j: Current position of the robot (For the first call use 0,0) 
m, n: Dimentions of given the matrix 
pi: Next index to be filed in path array 
*path[0..pi-1]: The path traversed by robot till now (Array to hold the 
				path need to have space for at least m+n elements) */
void printAllPathsUtil(vector<vector<int> >v, int i, int j, int m, int n, vector<int>&path, int pi) 
{ 
	// Reached the bottom of the matrix so we are left with 
	// only option to move right 
	if (i == m - 1) 
	{ 
		for (int k = j; k < n; k++) {
			path[pi++] = v[i][k];
        }
		for (int l = 0; l < pi; l++) 
			cout << path[l] << " "; 
		cout << endl; 
		return; 
	} 

	// Reached the right corner of the matrix we are left with 
	// only the downward movement. 
	if (j == n - 1) 
	{ 
		for (int k = i; k < m; k++) 
			path[pi++] = v[k][j];
		for (int l = 0; l < pi; l++) 
			cout << path[l] << " "; 
		cout << endl; 
		return; 
	} 

	// Add the current cell to the path being generated 
	path[pi] = v[i][j];

	// Print all the paths that are possible after moving down 
	printAllPathsUtil(v, i+1, j, m, n, path, pi + 1); 

	// Print all the paths that are possible after moving right 
	printAllPathsUtil(v, i, j+1, m, n, path, pi + 1); 

	// Print all the paths that are possible after moving diagonal 
	// printAllPathsUtil(mat, i+1, j+1, m, n, path, pi + 1); 
} 

// The main function that prints all paths from top left to bottom right 
// in a matrix 'mat' of size mXn 
void printAllPaths(vector<vector<int> >v, int m, int n) 
{ 
	vector<int> path(n+m);
	printAllPathsUtil(v, 0, 0, m, n, path, 0); 
} 

// Driver program to test abve functions 
int main() 
{ 
	vector<vector<int> > v{ {1, 2, 3}, {4, 5, 6} }; 
	printAllPaths(v, 2, 3); 
	return 0; 
} 
