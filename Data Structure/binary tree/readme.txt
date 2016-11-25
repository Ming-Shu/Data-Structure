==================
Rule
==================

1.child nodes are lesser than root node keep on the left side

2.child nodes are greater than root node keep on the right side

==================
Tree Traversal
==================

Pre-order Traversal Algorithm

Step 1 : Visit root node.
Step 2 : Recursively traverse left subtree.
Step 3 : Recursively traverse right subtree.

*********************************************************

In-order Traversal

Step 1 : Recursively traverse left subtree.
Step 2 : Visit root node.
Step 3 : Recursively traverse right subtree.

*********************************************************

Post-order Traversal

Step 1 : Recursively traverse left subtree.
Step 2 : Recursively traverse right subtree.
Step 3 : Visit root node.

*********************************************************
==================
Example	
==================
	       9  <--- root
	     /   \	
	    /	  \
	   4	   15
	 /  \	  /  \
	2    6	 12  17 <--- leaf


input data: 9,4,15,6,12,17,2

	nodes (2, 4, 6) are on left side of root node (9) 
	nodes (12, 15, 17) are on right side of root node (9) 

Display:

Pre Order 

9
4
2
6
15
12
17
--------------------------
In Order 

2
4
6
9
12
15
17
--------------------------
Post Order 

2
6
4
12
17
15
9
