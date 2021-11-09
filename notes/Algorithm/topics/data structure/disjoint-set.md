# Disjoint Set/Union-Find Forest

## Operations

### Making New Sets

    function Make(x) {
      if(x is not already in the forest) {
        x.parent = x
      }
    }

### Finding Set Representatives

    function Find(x) {
      if(x.parent == x) {
        return x
      } else {
        x.parent = Find(x.parent)
        return x.parent
      }
    }

### Merging two Sets

    function Merge(x, y) {
      if(Find(x) != Find(y)) {
        y.parent = x
      }
    }

## Applications

1. [Kruskal's Algorithm(to find minimum spanning tree)](../kruskal's%20algorithm.md)
