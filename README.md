**S_malloc Library**

Smalloc is a Run-Time Memory Debugger Library.

It can be Integrate with any Project's Source Code with minimal code changes.

The Version 1.0 of this Library provides a basic but useful functionality: It gives you a list of

Memory Addresses (along with Memory-Size) allocated at the Heap.

If you free a node, this List will be updated immediately & delete this Memory Address from the Listing.

Hence, at any instant, you can easily find out how much Heap Memory was allocated & still in use by your Application.

I will be adding more features to this Library in the later versions.

*Current Version is Available as a Static Library*

The Current Version of S_malloc Library is provided in the form of a Static Library.
I may provide a separate Makefile if you intend to use it as a Dynamic Library, in the near future.

*What Changes are required in your Source Code to Integrate it with S_malloc Library*

Very small Changes are required to Integrate S_malloc Library with your Source Code.

Pre-requisite:

You must be using some wrapper functions to call malloc() and free() Library Functions.

As shown in the file *sample_test_stub.c* provided with the S_malloc source code, you just need 
to call 2 functions: *add_allocated_node()* and *remove_allocated_node* in your wrapper functions 
for malloc() and free() Library Functions.


*How To Link S_malloc Library To Your Source Code*

In your Project, you must be creating some final executable by Linking .o (object) Files.

To Integrate S_malloc Library with your Source Code, you just need to add it to the list of Static Libraries
while creating your Final Executable.

Example:

*gcc -c -ansi -Wall -pedantic sample_test_stub.c*

*gcc sample_test_stub.o -L lib/ -lSmalloc -o test_executable*


*S_malloc Logs*

Once you have Integrated this Library with your executable, a Log-File named: *S_malloc_logs.txt* will be generated at 
the same path from where you are executing your executable.

*Comments/Feedback*

If you like to share any feedback/comments on this Utility, please feel free to mail me at sandeepsinghmails@gmail.com

