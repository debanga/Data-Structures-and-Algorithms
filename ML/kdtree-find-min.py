# Find min in a kd tree in target dimension
import numpy as np

data = [[30, 40], [5,25], [10, 12], [70, 70], [50, 30], [35, 45], [75, 80]]

def draw_with_space(loc, txt):
        for _ in range(loc):
            print(" ", end=" ")
        print(txt)

class Node():
    def __init__(self, entry):
        """
        Initialize node
        """
        self.root = entry
        self.left = 0
        self.right = 0

    def insert(self, entry, dim, loc):
        if (entry[dim]<=self.root[dim]):
            if (self.left==0):
                self.left = Node(entry)
                draw_with_space(loc-3, str(entry))
            else:
                loc = loc -3
                self.left.insert(entry, (dim+1)%2, loc)
        else:
            if (self.right==0):
                self.right = Node(entry)
                draw_with_space(loc+3, str(entry))
            else:
                loc = loc + 3
                self.right.insert(entry, (dim+1)%2, loc)

    def find_minimum(self, dim, target_dim):
        if (dim==target_dim):
            if self.left==0:
                return self.root
            else:
                return self.left.find_minimum((dim+1)%2, target_dim)
        else:
            if self.left==0:
                a = self.root
            else:
                a = self.left.find_minimum((dim+1)%2, target_dim)
            if self.right==0:
                b = self.root
            else:
                b = self.right.find_minimum((dim+1)%2, target_dim)
            v = [a,b]
            return v[np.argmin([v[0][target_dim], v[1][target_dim]])]




# Insert data to k-d tree x y x y x y ...
tree = Node(data[0])
draw_with_space(20, str(data[0]))
for d in data[1:]:
    tree.insert(d, 0, 20)
print(" ")

print("Min in dim 0" + str(tree.find_minimum(0, 0)))
print("Min in dim 1" + str(tree.find_minimum(0, 1)))




