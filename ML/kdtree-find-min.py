# Find min in a kd tree in target dimension
import numpy as np

data = [[30, 40], [5,25], [10, 12], [70, 70], [50, 30], [35, 45]]

class Node():
    def __init__(self, entry):
        """
        Initialize node
        """
        self.root = entry
        self.left = 0
        self.right = 0

    def insert(self, entry, dim):
        if (entry[dim]<=self.root[dim]):
            if (self.left==0):
                self.left = Node(entry)
                print(str(entry) + " [L]")
            else:
                self.left.insert(entry, (dim+1)%2)
        else:
            if (self.right==0):
                self.right = Node(entry)
                print(str(entry) + " [R]")
            else:
                self.right.insert(entry, (dim+1)%2)

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
for d in data[1:]:
    tree.insert(d, 0)
print(" ")

print(tree.find_minimum(0, 1))




