#!/bin/bash

echo "Merging BFS thread caches into master..."
# 1. Append all thread-specific BFS files to the master file
cat answers_cache_[0-9]*.txt >> answers_cache_master.txt 2>/dev/null

# 2. Sort numerically by N (column 1) then K (column 2), and remove duplicates
sort -k1,1n -k2,2n -u answers_cache_master.txt -o answers_cache_master.txt

# 3. Delete the temporary thread files
rm -f answers_cache_[0-9]*.txt


echo "Merging OPT thread caches into master..."
# 1. Append all thread-specific OPT files to the master file
cat opt_cache_[0-9]*.txt >> opt_cache_master.txt 2>/dev/null

# 2. Sort numerically by N (column 1) then K (column 2), and remove duplicates
sort -k1,1n -k2,2n -u opt_cache_master.txt -o opt_cache_master.txt

# 3. Delete the temporary thread files
rm -f opt_cache_[0-9]*.txt

echo "Merge and cleanup complete. Master caches are ready for the next run."