# Exercises

## Chapter 1

1. What are the three main purposes of an operating system?

Execute user programs and make solving user problems easier, make computer system convenient to use and use the computer hardware in an efficient manner.

2. We have stressed the need for an operating system to make efficient use of the computing hardware. When is it appropriate for the operating system to forsake this principle and to “waste” resources? Why is such a system not really wasteful?

When the resources aren't shared between different users, such as personal computers, these users want convenience, ease of use and good performance, in this case it's appropriate to "waste" resources to provide an easy to use interface, for example.

<!--
3. What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?

4. Keeping in mind the various definitions of operating system, consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that it should not, and support your answers.

5. How does the distinction between kernel mode and user mode function as a rudimentary form of protection (security) system?

6. Which of the following instructions should be privileged?
a.Set value of timer.
b.Read the clock.
c.Clear memory.
d.Issue a trap instruction.
e.Turn off interrupts.
f.Modify entries in device-status table.
g.Switch from user to kernel mode.
h.Access I/O device.

7. Some early computers protected the operating system by placing it in
a memory partition that could not be modified by either the user job
or the operating system itself. Describe two difficulties that you think
could arise with such a scheme.
8. Some CPUs provide for more than two modes of operation. What are
two possible uses of these multiple modes?
9. Timers could be used to compute the current time. Provide a short
description of how this could be accomplished.
10. Give two reasons why caches are useful. What problems do they solve?
What problems do they cause? If a cache can be made as large as the
device for which it is caching (for instance, a cache as large as a disk),
why not make it that large and eliminate the device?
11. Distinguish between the client–server and peer-to-peer models of
distributed systems.

12. In a multiprogramming and time-sharing environment, several users
share the system simultaneously. This situation can result in various
security problems.
a.What are two such problems?
b.Can we ensure the same degree of security in a time-shared
machine as in a dedicated machine? Explain your answer.

13. The issue of resource utilization shows up in different forms in different
types of operating systems. List what resources must be managed
carefully in the following settings:
a.Mainframe or minicomputer systems
b.Workstations connected to servers
c.Mobile computers
14. Under what circumstances would a user be better off using a time-
sharing system than a PC or a single-user workstation?
15. Describe the differences between symmetric and asymmetric multipro-
cessing. What are three advantages and one disadvantage of multipro-
cessor systems?
16. How do clustered systems differ from multiprocessor systems? What is
required for two machines belonging to a cluster to cooperate to provide
a highly available service?
17. Consider a computing cluster consisting of two nodes running a
database. Describe two ways in which the cluster software can manage
access to the data on the disk. Discuss the benefits and disadvantages of
each.
18. How are network computers different from traditional personal com-
puters? Describe some usage scenarios in which it is advantageous to
use network computers.
19. What is the purpose of interrupts? How does an interrupt differ from a
trap? Can traps be generated intentionally by a user program? If so, for
what purpose?
20. Direct memory access is used for high-speed I/O devices in order to
avoid increasing the CPU’s execution load.
a.How does the CPU interface with the device to coordinate the
transfer?
b.How does the CPU know when the memory operations are com-
plete?
c.The CPU is allowed to execute other programs while the DMA
controller is transferring data. Does this process interfere with
the execution of the user programs? If so, describe what forms
of interference are caused.
21. Some computer systems do not provide a privileged mode of operation
in hardware. Is it possible to construct a secure operating system for
these computer systems? Give arguments both that it is and that it is not
possible.
22. Many SMP systems have different levels of caches; one level is local to
each processing core, and another level is shared among all processing
cores. Why are caching systems designed this way?
23. Consider an SMP system similar to the one shown in Figure 6. . Illustrate
with an example how data residing in memory could in fact have a
different value in each of the local caches.
24. Discuss, with examples, how the problem of maintaining coherence of
cached data manifests itself in the following processing environments:
a.Single-processor systems
b.Multiprocessor systems
c.Distributed systems
25. Describe a mechanism for enforcing memory protection in order to
prevent a program from modifying the memory associated with other
programs.
26. Which network configuration— LAN or WAN —would best suit the
following environments?
a.A campus student union
b.Several campus locations across a statewide university system
c.A neighborhood
27. Describe some of the challenges of designing operating systems for
mobile devices compared with designing operating systems for traditional PCs.
28. What are some advantages of peer-to-peer systems over client-server
systems?
29. Describe some distributed applications that would be appropriate for a
peer-to-peer system.
30. Identify several advantages and several disadvantages of open-source
operating systems. Include the types of people who would find each
aspect to be an advantage or a disadvantage. -->

## Chapter 2

01. What is the purpose of system calls?
02. What are the five major activities of an operating system with regard to process management?
03. What are the three major activities of an operating system with regard to memory management?
04. What are the three major activities of an operating system with regard to secondary-storage management?
05. What is the purpose of the command interpreter? Why is it usually separate from the kernel?

06. What system calls have to be executed by a command interpreter or shell in order to start a new process?
07. What is the purpose of system programs?
08. What is the main advantage of the layered approach to system design? What are the disadvantages of the layered approach?
09. List five services provided by an operating system, and explain how each creates convenience for users. In which cases would it be impossible for user-level programs to provide these services? Explain your answer.
10. Why do some systems store the operating system in firmware, while others store it on disk?
11. How could a system be designed to allow a choice of operating systems from which to boot? What would the bootstrap program need to do?
12. The services and functions provided by an operating system can be divided into two main categories. Briefly describe the two categories, and discuss how they differ.
13. Describe three general methods for passing parameters to the operating
system.
14. Describe how you could obtain a statistical profile of the amount of time
spent by a program executing different sections of its code. Discuss the
importance of obtaining such a statistical profile.
15. What are the five major activities of an operating system with regard to
file management?
16. What are the advantages and disadvantages of using the same system-
call interface for manipulating both files and devices?
17. Would it be possible for the user to develop a new command interpreter
using the system-call interface provided by the operating system?
18. What are the two models of interprocess communication? What are the
strengths and weaknesses of the two approaches?
19. Why is the separation of mechanism and policy desirable?
20. It is sometimes difficult to achieve a layered approach if two components
of the operating system are dependent on each other. Identify a scenario
in which it is unclear how to layer two system components that require
tight coupling of their functionalities.
21. What is the main advantage of the microkernel approach to system
design? How do user programs and system services interact in a
microkernel architecture? What are the disadvantages of using the
microkernel approach?
22. What are the advantages of using loadable kernel modules?

23. How are iOS and Android similar? How are they different?
24. Explain why Java programs running on Android systems do not use the
standard Java API and virtual machine.
25. The experimental Synthesis operating system has an assembler incorporated in the kernel. To optimize system-call performance, the kernel
assembles routines within kernel space to minimize the path that the
system call must take through the kernel. This approach is the antithesis
of the layered approach, in which the path through the kernel is extended
to make building the operating system easier. Discuss the pros and cons
of the Synthesis approach to kernel design and system-performance
optimization.



## Chapter 3

