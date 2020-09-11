# CS154 Projects
This repository has three projects from the class CS 154: Introduction to Computer Systems. All were done in C and completed in Fall 2019.

A note: Most files within these folders were part of what was given in the project, meaning I did not create them.
The files that I changed are as follows:

1. p1bitmanip: bits.c
2. p3cache: csim.c
3. p4shell: myshell.c

Note: These will not run and may not make total sense, as I have removed some code in order to prevent it from being plagiarized by following cohorts of CS 154. 

## Explanations
Below are some short description of the projects and lists of my successes, things that could be improved, and takeaways. If you want to see the assignments themselves, each of the README's for each project are in their respective directories. My final grade for each of these projects are also in their respective directories. 

### P1: Bit Manipulation
This is a pretty straight forward project, so these listings won't be very long. This project is focused on manipulating bits with bit operators.

**Successes**
- All tasks were completed successfully
- Organization is clear and concise 

**Room for Improvement**
- My variable names are lacking here. I realized afterwards that it would be very hard to keep track of variables and their changes just using letters. 

**Takeaways**
- A clearer understanding of bit manipulation
- Understanding new ways to use bit manipulation within other projects.

### P3: Cache
This project focuses on simulating a working cache. It returns hits, misses, and evictions.

**Successes**
- Mostly effecient, ran most cases seemlessly. 
- Code is clearly labeled and fairly easy to follow

**Room for Improvement**
- As seen from my score, I did not get the fully optimal result (97.9/100). There are a few cases that were not optimized through my code. 
- Not afraid to admit that I still struggle with understanding caches. It has been a while since I completed this project so I'm a little rusty on cache optimization. 
- I think I could add comments to describe what each section is actively doing, it could definitely help those who look at my code after me. 

**Takeaways**
- How caches work, understanding their hit and miss rates
- More work with structs and arrays

### P4: Shell
Probably my favorite project from this quarter, after P2: Bomb (which is not listed here because it is not a traditional coding project). In this project, I simulate a working shell with multiple capabilities such as built-in commands and redirection.

**Successess**
- I'm really proud of the work I did here. The code is particularly clear and well-labeled with different sections broken up. Even a year after making this I'm still able to follow the code.
- Everything was completed, and all the tasks from the assignment worked successfully.

**Room for Improvement**
- You could say some things are hard-coded such as the buffer at the beginning for the input. Although this works, this isn't necessarily the "right" way to do things. Would want to look at this in the future. 
- I think there was room for more helper functions. I've struggled in the past with being open to helper function, so working on implementing that more often in my code is something I want to achieve. 

**Takeaways**
- C functions for writing and altering files
- How to use and develop forking functions
- A better understanding of shell!
