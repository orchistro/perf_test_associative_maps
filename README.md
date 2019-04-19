# Performance test of associative maps/sets for eliminating duplicate items

Test result:

| container type | emplace | try_emplace |
|---|---|---|
| set | 24.85 | 21.57 |
| unordered_set | 10.36 | 8.09 |
| map | 25.31 | 19.55 |
| unordered_map | 7.79 | 10.37 |


### std::set
```bash
$ /usr/bin/time ./foo set emplace 10000000
24.49user 0.38system 0:24.85elapsed 100%CPU (0avgtext+0avgdata 499908maxresident)k
0inputs+0outputs (0major+125012minor)pagefaults 0swaps

$ /usr/bin/time ./foo set try_emplace 10000000
21.26user 0.32system 0:21.57elapsed 100%CPU (0avgtext+0avgdata 500116maxresident)k
0inputs+0outputs (0major+125064minor)pagefaults 0swaps
```

### std::unordered_set
```bash
$ /usr/bin/time ./foo unordered_set emplace 10000000
9.99user 0.36system 0:10.36elapsed 100%CPU (0avgtext+0avgdata 475972maxresident)k
0inputs+0outputs (0major+133309minor)pagefaults 0swaps

$ /usr/bin/time ./foo unordered_set try_emplace 10000000
7.80user 0.29system 0:08.09elapsed 100%CPU (0avgtext+0avgdata 476032maxresident)k
0inputs+0outputs (0major+133324minor)pagefaults 0swaps
```

### std::map
```bash
$ /usr/bin/time ./foo map emplace 10000000
24.91user 0.42system 0:25.31elapsed 100%CPU (0avgtext+0avgdata 583328maxresident)k
0inputs+0outputs (0major+145867minor)pagefaults 0swaps

$ /usr/bin/time ./foo map try_emplace 10000000
19.21user 0.35system 0:19.55elapsed 100%CPU (0avgtext+0avgdata 583144maxresident)k
0inputs+0outputs (0major+145821minor)pagefaults 0swaps
```

### std::unordered_map
```bash
$ /usr/bin/time ./foo unordered_map emplace 10000000
7.43user 0.36system 0:07.79elapsed 100%CPU (0avgtext+0avgdata 559104maxresident)k
0inputs+0outputs (0major+154092minor)pagefaults 0swaps

$ /usr/bin/time ./foo unordered_map try_emplace 10000000
9.94user 0.44system 0:10.37elapsed 100%CPU (0avgtext+0avgdata 559044maxresident)k
0inputs+0outputs (0major+154077minor)pagefaults 0swaps
```

The test shows somewhat surprising result: the winner is `std::unordered_map` using `emplace()`, not `std::unordered_set` using `try_emplace()`.
But the difference is very small compared to the second winner `std::unordered_set` using `try_emplace()`.

Deciding what to use is up to you.
