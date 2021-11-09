# Kruskal's Algorithm

## Background

> In graph theory, a *tree* is a undirected graph where any two vertices are **connected by exactly one path**, or equivalently a **connected acyclic undirected graph**.

> A *minimum spanning tree* of a connceted weighted graph is a subset of edges that form a tree that includes **all the vertices**, where the **sum of weights of all the edges in the tree is minimized**.

## Algorithm

- create a forest `F`, where each vertex in the graph is a seperate tree.
- create a set `S` that includes all edges in the graph.
- while `S` is *nonempty* and `F` is *not yet spanning*:
  - remove the edge with minimum weight from `S`.
  - if the removed edge connects two differents tree then add it to `F`, combining to trees in to single one.

## Pseudocode

    algorithm Kruskal(G) is
    F:= ∅
    for each v ∈ G.V do
        MAKE-SET(v)
    for each (u, v) in G.E ordered by weight(u, v), increasing do
        if FIND-SET(u) ≠ FIND-SET(v) then
            F:= F ∪ {(u, v)} ∪ {(v, u)}
            UNION(FIND-SET(u), FIND-SET(v))
    return F
