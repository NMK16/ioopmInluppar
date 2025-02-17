How to run the program: 
1. Download/Git clone all the files in inlupp1 in the repo:
https://github.com/IOOPM-UU/nokh8135

2. To test the program hashtable.c; linked_list.c; iterator.c, where you'll see coverage, tests, and memory (allocs/frees) write (in the terminal): 
bash:
make 
make gcoverage (alt make memtest if you only want valgrind without coverage)
(use "make clean" to clean up)


3. To run the freq-counter that counts how many times a word occurs in a text file, write (in the terminal):
bash:
gcc -g freq-count.c hashtable.c linked_list.c iterator.c -o freq-count
(optional: valgrind) ./freq-count <(the name of a text file in the folder followed by) .txt>

4. If you want to see the profiling of the program
bash:
gcc -pg freq-count.c hashtable.c linked_list.c iterator.c -o freq-count
(optional: valgrind) ./freq-count <(the name of a text file in the folder followed by) .txt>
gprof freq-count gmon.out > profile.txt

The simply open the newly created profile file within the folder

Run your program on each input file and inspect the result. Answer the following questions.

For each input, what are the top 3 functions?

Before optimizing:

write in terminal (for statistics of heap load in 16k-words.txt):
ms_print massifbefore.out.28134

1mill-words.txt
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 33.33      0.01     0.01    21086     0.00     0.00  ioopm_hash_table_lookup
 33.33      0.02     0.01    21086     0.00     0.00  recursive_lookup
 33.33      0.03     0.01     4094     0.00     0.00  find_previous_entry_for_key

16k-words.txt 
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 37.50      0.01     0.01    21086     0.00     0.00  ioopm_hash_table_lookup
 37.50      0.03     0.01    21086     0.00     0.00  recursive_lookup
 25.00      0.04     0.01    16992     0.00     0.00  process_word

10k-words.txt
  %   cumulative   self              self     total      
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
  0.00      0.00     0.00    59933     0.00     0.00  string_eq (given)
  0.00      0.00     0.00    10372     0.00     0.00  string_sum_hash (given)
  0.00      0.00     0.00    10186     0.00     0.00  ioopm_hash_table_lookup (selfmade)

1k-long-words.txt:
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
  0.00      0.00     0.00     1548     0.00     0.00  string_eq (given)
  0.00      0.00     0.00     1046     0.00     0.00  string_sum_hash (given)
  0.00      0.00     0.00     1023     0.00     0.00  ioopm_hash_table_lookup (selfmade)

small.txt:
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
  0.00      0.00     0.00       90     0.00     0.00  string_eq (given)
  0.00      0.00     0.00       79     0.00     0.00  string_sum_hash (given)
  0.00      0.00     0.00       77     0.00     0.00  ioopm_iterator_has_next (selfmade)

After optimizing:

write in terminal (for statistics of heap load in 16k-words.txt):
ms_print massifafter.out.28748

1mill-words.txt
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
100.00      0.01     0.01  1000000     0.00     0.00  process_word 
  0.00      0.01     0.00  1330655     0.00     0.00  string_eq
  0.00      0.01     0.00  1000566     0.00     0.00  string_sum_hash
  0.00      0.01     0.00  1000186     0.00     0.00  ioopm_hash_table_lookup

16k-words.txt 
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
  0.00      0.00     0.00    58281     0.00     0.00  string_eq
  0.00      0.00     0.00    31703     0.00     0.00  string_sum_hash
  0.00      0.00     0.00    21086     0.00     0.00  ioopm_hash_table_lookup

10k-words.txt
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
  0.00      0.00     0.00    12722     0.00     0.00  string_eq
  0.00      0.00     0.00    10566     0.00     0.00  string_sum_hash
  0.00      0.00     0.00    10186     0.00     0.00  ioopm_hash_table_lookup

1k-words.txt
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
  0.00      0.00     0.00     1275     0.00     0.00  string_eq
  0.00      0.00     0.00     1059     0.00     0.00  string_sum_hash
  0.00      0.00     0.00     1023     0.00     0.00  ioopm_hash_table_lookup

small.txt
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
  0.00      0.00     0.00       92     0.00     0.00  string_sum_hash
  0.00      0.00     0.00       77     0.00     0.00  ioopm_iterator_has_next
  0.00      0.00     0.00       58     0.00     0.00  string_eq


Before optimization

Peak Memory Usage: 455.1 KB
Snapshots: 89
Memory Characteristics: Gradual increase in total memory with significant extra-heap usage, showing inefficiencies.

After Optimization

Peak Memory Usage: 389.7 KB 
Snapshots: 61
Memory Characteristics: Reduced total memory usage, with more efficient memory allocation and deallocation.

Key Improvements After Optimization:

Reduced peak memory usage (from 455.1 KB to 389.7 KB).
Fewer snapshots (decreased from 89 to 61), showing more stable memory management.
Improved memory allocation.

For each input, are the top 3 functions in your code (that you have written), or is it in library functions?
It's written if it was given or if we created it in the () in the earlier question

Are the top 3 functions in your code consistent across the inputs? Why? Why not?

Almost, the top functions aren’t the same for all the input files we were given. In 16k-words.txt, the functions that we wrote took up more space and time, while for smaller files such as 1k-long-words.txt and small.txt, the given functions string_eq and string_sum_hash shows up more. This difference likely comes from the size and complexity of the input files, which changes how often the functions are called. Time-wise we cannot fully know since all input files except for the 16k one, were rounded down to 0 due to it being too quick.

Is there some kind of trend? (Possibly several)

Yes, there seems to be a trend where if the size of the input files gets smaller, the use of library functions like string_eq and string_sum_hash increases. Although, with larger input files, the time spent on functions we created goes up. This shows that when dealing with bigger datasets, the operations related to the hash table become more important.

Do the results correspond with your expectations?
The results mostly match what I expected. I thought that the functions I wrote would take more time with larger input files because they often involve looking things up in the hash table. However, it was surprising to see the library functions being so frequently called in the smaller files. This suggests that these functions are used a lot in those situations.

Based on these results, do you see a way to make your program go faster?

Optimizing hash table operations is crucial for improving the performance of your program, especially since the profiling results indicate significant time is spent in functions like ioopm_hash_table_lookup. 

If the load factor (the ratio of the number of elements to the number of buckets) becomes too high, the performance of the hash table may degrade. To maintain efficiency: