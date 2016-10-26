#Ashena Gorgan Mohammadi, 610394128

import sys

class Node:
    def __init__(self, d, l = None):
        self.data = d
        self.link = l


class CircularLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        if(self.head is None):
            self.head = Node(data)
            self.head.link = self.head
        else:
            node = self.head
            while(node.link != self.head):
                node = node.link
            node.link = Node(data, self.head)


def gas_station_traverse(stations):
    node = stations.head
    position = 1
    gas_required = sys.maxsize
    gas_consumption = 0
    current_pos = 1
    while(True):
        gas_consumption += node.data[0] - node.data[1]
        if(gas_consumption < gas_required):
            if(node.data[0] - node.data[1] >= 0):
                gas_required = gas_consumption
                position = current_pos
        node = node.link
        current_pos += 1
        if(node == stations.head):
            break
    if(gas_consumption >= 0):
        return(position)
    else:
        return 0


stations = CircularLinkedList()
n = int(input('Enter number of gas stations: '))
print('In next', n, 'rows, enter gas amount and distance from next station in order:')
for i in range(n):
    stations.insert(tuple(int(x.strip()) for x in input().split()))
ans = gas_station_traverse(stations)
if(ans != 0):
    print('You should start from gas station NO.', ans)
else:
    print('IMPOSSIBLE!')