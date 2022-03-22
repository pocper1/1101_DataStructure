# Data Structure

## 上機作業

### HW1
1. 第一題
> Please write a program to represent the input sparse matrix by using triplet form as mentioned in class. Then, transpose the matrix and print out the result as shown below. It should be noted that the input data will be integers. Therefore, you only need to check the input matrix is consistent with the input size.(size for input array will not bigger than 100x100.)

2. 第二題
> Please write a program to convert infix expressions to postfix expressions, and calculate the values by the postfix expressions. All of the input data will be fully parenthesized infix expressions, integers are between 0 and 9, and all of the operators include “+”, “-”, “*”, “/”, “(”, and “)”. Round the results to the nearest integer in the end. The program must be implemented by stack, or you will get zero points. [In our rule, -0.5≃-1]

### HW2
1. 第一題
> Please implement several basic operations related to linked list: Creating a Node(with int value and linked list pointer) Add a node to the linked list Traversing the list Reverse the linked list Given total numbers of node and value , return the middle node of value and rest of the node of value and reverse linked list.

2. 第二題
> Please implement several basic operations related to queue:
1. Add (Enqueue) elements at the end of the queue.
2. Output the front element of the queue.
3. Delete (Dequeue) the front element of the queue.
Assume user only input integers and right format. Your program has to read till the input row has only -1.
The program must be implemented by queue, or you will get zero points.

### Input Description: If input “1”, please read another integer x (1 ≤ x ≤ 109) and enqueue the number.
If input “2”, print the front element. If the queue is empty, then output “> -2”.
If input “3”, dequeue the front element. If the queue is empty, then output “> -3”.
If input “-1”, terminate the program.

## HW3
1. 第一題
> Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters. The most frequent character gets the smallest code and the least frequent character gets the largest code. 1. Build a Huffman Tree from input characters. 2. Traverse the Huffman Tree and assign codes to characters.
While building the Huffman tree by bottom-up method, please follow the rules below:
(1) If more two different characters have the same frequencies, order them by their ASCII code.
(2) The value of the right node has to be larger than or equal to the one of the left node. If the character have the same frequencies with the combination, put combination to the right node.
(3) Follow the order in (1) to read the value, and build the tree from the left subtree.
(4) The values of left and right branches are “0” and “1”, respectively.

2. 第二題
> Given a number n (n = -1 or 1 ≤ n ≤ 210) represents n integers. The next row is given n serial integers (-231 ≤ values ≤ 231 - 1), representing the nodes. Please write a program to build a binary search tree and show the preorder and postorder traversals. The root is the first integer of the serial integers. If the upcoming integer equals to an existing node, put it on its right (right-child). For other cases, put the smaller ones on left (left-child), bigger ones on right (right-child). The program must be implemented by linked list, or you will get zero points.


## HW4
1. 第一題
> Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

2. 第二題
> Given graphs represented by adjacency matrices, please implement Prim's Algorithm and build the minimum spanning tree starting from vertex A. The first line will be the number of vertices. Vertices are labeled alphabetically using the letters A-Z. The distance between any two vertices will not exceed 100,000. The output shows the Minimum cost. If the graph is not connected, you need to print “NO connected”.