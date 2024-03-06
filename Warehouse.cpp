// Description
// A truck is planned to arrive at some stations among N stations 1, 2, . . ., N located on a line. Station i (i = 1,…,N) has coordinate i and has following information
// a
// i 
// : amount of goods
// t
// i
//  : pickup time duration for taking goods
// The route of the truck is a sequence of stations x1 < x2 < . . . < xk (1 ≤ xj ≤ N, j = 1,…, k). Due to technical constraints, the distance between two consecutive stations that the truck arrives xi and xi+1 is less than or equal to D and the total pickup time duration cannot exceed T. Find a route for the truck such that total amount of goods picked up is maximal.
// Input
// Line 1: N, T, D (1 <= N <= 1000, 1 <= T <= 100, 1 <= D <= 10)
// Line 2: a
// 1
// ,. . ., a
// N
//  (1 <= a
// i
//  <= 10)
// Line 3: t
// 1
// , . . ., t
// N
//  (1 <=  t
// i
//  <= 10)
// Output
// Write the total amount of goods that the truck picks up in the route.
