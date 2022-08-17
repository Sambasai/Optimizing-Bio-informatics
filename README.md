# Optimizing Needleman Wunsch Algorithm

This project explores different optimization techniques to optimize a very well known algorithm called the Needleman Wunsch Algorithm.

## Team Members:

- Srikar Bhavesh Desu
- Sambasai Reddy Andem

As there is dependency from the left cell, up cell and diagonal cell, the best way to optimize Needleman Wunsch without any dependency is an Anti-Diagonal traversal. This was further optimized using the idea of Tiling.

- **Anti Diagonal Traversal**: Despite the bad spatial locality, we observe that due to high parallelization that is possible, Anti diagonal traversal with parallelization on different CPU cores gives a very good speedup compared to the Baseline performance.
- **Tiling Based Approach**: The $m*n$ matrix can be divided into subtiles of $k*k$ size each, and now we can assume each of these tiles as a particular cell and repeat the same process as before. The tiles itself can be done using parallelization while the traversal in every tile can be done using row major fashion to exploit both very good spatial locality, parallelization and cache coherence.

We could achieve a speed-up of approximately **18x** using the tile based approach as compared to the row major traversal without any optimization.
