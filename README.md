
PROTECTED BY CREATIVE COMMONS SHARE ALIKE LICENCE - 
http://creativecommons.org/licenses/by-sa/3.0/

DO NOT REMOVE THIS COMMENT (unless you are copying the code for some academic project ;)

created by - apoorv kumar, 2011
iit guwahati
apoorv.kumar247@gmail.com

do visit my blog for more codes and computer stuff- 
http://eat-sleep-code.blogspot.com/

#CACHE SIMULATOR::



##DOCUMENTATION:

###compiling :

 *GO TO src
 *run make
 *EXECUTABLE cache_sim GENERATED IN bin/release FOLDER

###running :

 *GENERATE THE TRACE FILE USING trace.c IN DATA FOLDER (an example 'trace' is in this folder)
 *COPY THE TRACE FILE INTO bin/release
 *IN TERMINAL GO TO bin/release FOLDER
 *RUN ./cache_sim
 *ENTER FILE trace AS THE TRACE FILE
 *ENTER FILE config AS THE CONFIGURATION SET FILE
 *PLEASE SEE THE FILE output FOR SIMULATION RESULTS

==============================================================

###trace - FILE GENERATED USING GIVEN C PROGRAM - data/trace.c

config - THE SET OF CONFIGURATIONS TO BE USED IN THE SIMULATION 
	- EDIT AS PER YOUR REQUIREMENTS
	
output - contains results

==============================================================

###config file is in the format

<associativity> <cache_hit_time> <line_size > <replace_policy> <setcount> <write_policy> <cache_miss_penalty>
replacement policy conventions- RAND - 1 ; LRU - 2 ; FIFO - 3
line size - in words
write_back - 1 ; write_through - 2

==============================================================

###LRU IMPLEMENTATION - 
LRU has been implemented using a STL list. When a cache line is accessed in a set,
it's previous entry in list is deleted and a new entry is pushed at the front.
This implies that the LRU entry is the last in list.

###FIFO IMPLEMENTATION-
FIFO has been implemented using a STL queue. The first entry in the queue is to be
deleted as it was first to be inserted

==============================================================

###CLASSES - 
the classes have been divided into files and are self explanatory.

