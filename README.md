> Project's Title:
   CPU SCHEDULER

> Project Description:
   This project implements a CPU scheduler simulation to optimize process scheduling using various algorithms. The backend logic and algorithms are implemented in C++, organized into separate header files for 
   clarity and modularity. The frontend interface is developed using HTML, CSS, and JavaScript, allowing users to input parameters such as scheduling algorithms, time quantum (for Round Robin), and details for 
   multiple processes.
   cpprestsdk is used as modern asynchronus c++ api design facilitating communication between the frontend and backend. It handles incoming requests, processes user inputs, and invokes the C++ backend 
   (scheduler.exe) 

> How to run the project-
   compile the c++ file by giving the command "g++ -o scheduler main.cpp" to the terminal and then either command "./scheduler" to execute and successfully run it in the terminal or run the node server using 
   "node server.js" command in the directory of CPU SCHEDULER to run the server at the port mentioned in the server.js file to interact with the scheduler.

> The internal working of your project:
   The CPU scheduler project aims to optimize CPU resource allocation using scheduling algorithms like FCFS, SJF, RR, and Priority. It implements these algorithms in C++ for efficiency and utilizes Node.js to 
   interface with a frontend, where users can input process details and observe real-time scheduling outcomes. The project aims to minimize process turnaround time and waiting time while maximizing system 
   throughput, offering insights into the impact of different scheduling strategies on system performance.

> Your learning takeaways from the project:
   Developed a deep understanding of various CPU scheduling algorithms such as FCFS, SJF, Round Robin, and Priority Scheduling. Learned their principles, advantages, and scenarios where each algorithm is most 
   suitable. Also learned about the premptive and non premptive scheduling in operating system and plotting of gantt charts to calculate the required average turnaround time and average wait time for the incoming 
   processes and successfully executed these calculations using c++ files.

> The resources/references you used while working on the project:

  neso academy playlist for various scheduling algorithms
   https://www.youtube.com/playlist?list=PLBlnK6fEyqRitWSE_AyyySWfhRgyA-rHk
 
  geek for geeks article on cpu scheduling in operating system
   https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/

 








