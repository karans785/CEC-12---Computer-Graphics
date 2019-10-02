


This program takes input from an input file "input.txt". First line contains the number of vertices of the 3D shape which is to be projected in different views
The next N lines contain the coordinates of the n vertices.
Next line contains the number of edges, E, followed by E lines, each of which contains a pair denoting the indices of the vertices which form this edge. Eg. 0 1 specifies an edge between the 0th vertex and 1st vertex. (in order of input)
Finally, the 3D shape is drawn and projected in front, side, top, isometric,dimetric and perspective views.
At this stage the user has the option to rotate the shape in 3D space and notice the respective change from the 6 views of projection. Rotation about the x axis can be achieved by pressing 'X' (or 'x') on the keyboard, similarly 'Y' (or 'y') and 'Z' (or 'z') for rotation about the Y and Z axes.


Sample input  : 


5
-40 40 0
-40 -40 0
40 -40 0
40 40 0
0 0 60
8
0 1
1 2
2 3
3 0
0 4
1 4
2 4
3 4
