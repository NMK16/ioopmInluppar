Run your program on each input file and inspect the result. Answer the following questions.

For each input, what are the top 3 functions?

16k-words.txt 
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 37.50      0.01     0.01    21086     0.00     0.00  ioopm_hash_table_lookup
 37.50      0.03     0.01    21086     0.00     0.00  recursive_lookup
 25.00      0.04     0.01    16992     0.00     0.00  process_word


10k-words.txt
  %   cumulative   self              self     total      
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
  0.00      0.00     0.00    59933     0.00     0.00  string_eq
  0.00      0.00     0.00    10372     0.00     0.00  string_sum_hash
  0.00      0.00     0.00    10186     0.00     0.00  ioopm_hash_table_lookup

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

For each input, are the top 3 functions in your code (that you have written), or is it in library functions?
Are the top 3 functions in your code consistent across the inputs? Why? Why not?

Not quite, the top functions aren’t the same for all the input files. In 16k-words.txt, the functions that we wrote took the lead, while for smaller files such as 1k-long-words.txt and small.txt, the given functions string_eq and string_sum_hash shows up more. This difference likely comes from the size and complexity of the input files, which changes how often the functions are called.

Is there some kind of trend? (Possibly several)


Are the Top 3 Functions in Your Code Consistent Across the Inputs? Why? Why Not?
No, the top functions aren’t the same for all the input files. In 16k-words.txt, the functions that I wrote take the lead, while for smaller files like 1k-long-words.txt and small.txt, the built-in library functions like string_eq and string_sum_hash show up more. This difference likely comes from the size and complexity of the input files, which changes how often the functions are called.

Is There Some Kind of Trend? (Possibly Several)
Yes, there seems to be a trend! As the size of the input files gets smaller, the use of library functions like string_eq and string_sum_hash increases. On the other hand, with larger input files, the time spent on functions I created goes up. This shows that when dealing with bigger datasets, the operations related to the hash table become more important.


Do the results correspond with your expectations?
The results mostly match what I expected. I thought that the functions I wrote would take more time with larger input files because they often involve looking things up in the hash table. However, it was surprising to see the library functions being so frequently called in the smaller files. This suggests that these functions are used a lot in those situations.

Based on these results, do you see a way to make your program go faster?

Optimizing hash table operations is crucial for improving the performance of your program, especially since the profiling results indicate significant time is spent in functions like ioopm_hash_table_lookup. 

If the load factor (the ratio of the number of elements to the number of buckets) becomes too high, the performance of the hash table may degrade. To maintain efficiency: