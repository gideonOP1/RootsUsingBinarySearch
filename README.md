# RootsUsingBinarySearch
A simple C++ code that finds the approximate root of a polynomial P(x)

1) The imput polynomial is read as a string, example x^2-1 must be entered as x2-1 
2) Iteration is done in a range of -1000 to 1000 to find a sign change in P(x) (i.e. range where functions changes from -ve to +ve OR +ve to -ve)
3) Binary search is performed in the obtained range so that the results starts converging to a set precision
4) The input polynomial must cross the x-axis (change its sign) for x>=-1000 and x<=1000
5) The polynomial class is inherited from user "lastchance" from cpluslus.com, I am thankful to him
