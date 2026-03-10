#!/bin/bash
set -e
cd "$(dirname "$0")"
echo "Compiling..."
g++ -O2 -std=c++17 -o2 -o bench_bucket bench_bucket.cpp
g++ -O2 -std=c++17 -o2 -o bench_bucket_pmr bench_bucket_pmr.cpp
g++ -O2 -std=c++17 -o2 -o bench_treap bench_treap.cpp
echo "Compilation done."

SIZES=(
    "10000 200000"
    "200000 200000"
    "2000000 20000"
    "2000000 200000"
)
SPLIT_RATIOS=(20 24 28 32 36 40 44 48)
TEST_NAMES=("insert" "erase" "access" "mix")

{
    echo "=========================================="
    echo "  Dynamic Array Benchmark Results"
    echo "=========================================="
    echo ""

    for size_config in "${SIZES[@]}"; do
        read -r N Q <<< "$size_config"
        echo ""
        echo "=== N=$N, Q=$Q ==="
        printf "%-16s %-6s %10s %10s %10s %10s\n" "TYPE" "SPLIT" "insert(ms)" "erase(ms)" "access(ms)" "mix(ms)"
        printf "%s\n" "------------------------------------------------------------------------"

        # BucketList (std::vector)
        for sr in "${SPLIT_RATIOS[@]}"; do
            results=()
            for tt in 0 1 2 3; do
                t=$(./bench_bucket "$N" "$Q" "$tt" "$sr")
                results+=("$t")
            done
            printf "%-16s %-6s %10s %10s %10s %10s\n" "bucket" "$sr" "${results[0]}" "${results[1]}" "${results[2]}" "${results[3]}"
        done

        echo ""

        # BucketList PMR
        for sr in "${SPLIT_RATIOS[@]}"; do
            results=()
            for tt in 0 1 2 3; do
                t=$(./bench_bucket_pmr "$N" "$Q" "$tt" "$sr")
                results+=("$t")
            done
            printf "%-16s %-6s %10s %10s %10s %10s\n" "bucket_pmr" "$sr" "${results[0]}" "${results[1]}" "${results[2]}" "${results[3]}"
        done

        echo ""

        # Treap
        results=()
        for tt in 0 1 2 3; do
            t=$(./bench_treap "$N" "$Q" "$tt")
            results+=("$t")
        done
        printf "%-16s %-6s %10s %10s %10s %10s\n" "treap" "-" "${results[0]}" "${results[1]}" "${results[2]}" "${results[3]}"

        echo ""
    done
} 2>&1 | tee results.txt

echo ""
echo "Results saved to results.txt"
