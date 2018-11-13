Compile: 
gcc client1.c -o client1
gcc server1.c -o server1

Run
./server1 & 
./client1 <operation> <numbers to operate>     ( ex ./client1 - 3 5 6 3 8)  
  
Supported mathematical operations are addition, subtraction and multiplication => (+), (-), (x) 
Numbers to operate have a limit of ten
