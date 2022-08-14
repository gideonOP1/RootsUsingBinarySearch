# RootsUsingBinarySearch
A simple C++ code that finds the approximate root of a polynomial P(x)

1) The polynomial is read as a string, example x^2-1 must be entered as x2-1 
2) Iteration is done in a range of -1000 to 1000 to find a sign change in P(x) [i.e. range where functions changes from -ve to +ve OR +ve to -ve]
3) Binary search is performed in the obtained range so that the results starts converging to a set precision
