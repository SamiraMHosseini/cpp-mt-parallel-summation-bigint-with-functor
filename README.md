# Effective multi-threaded summation of large numbers
This is a program for parallelizing the calculation of the sum of large numbers using multiple threads. 
The program divides the range of numbers to be summed into smaller segments and assigns each segment to a separate thread for processing.
The individual thread results are then combined to obtain the final sum. This approach speeds up the calculation of the sum, especially for large input ranges,
by utilizing multiple CPU cores in parallel.

# Functor
In C++, functors are objects that act like functions. They are also known as function objects.
Functors are implemented as classes that overload the function call operator operator(). 
When you create an instance of a functor class and call it like a function, 
the operator() function is executed. This allows you to use the functor as if it were a function.
