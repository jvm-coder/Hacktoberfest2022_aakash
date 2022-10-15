class QueueEmptyException(Exception):
    """A custom Queue Exception"""

class Queue:
    def __init__(self) -> None:
        self.q = []
        self.r = -1
    def is_empty(self):
        return self.r == -1
    def size(self):
        return self.r + 1
    def view(self):
        print(*self.q)
    def enqueue(self,obj):
        self.r += 1
        self.q.insert(0, obj)
    def dequeue(self):
        if self.is_empty():
            raise QueueEmptyException("Queue is empty. Cannot dequeue from an empty queue.")
        else:
            self.r -= 1
            return self.q.pop(0)
    def front(self):
        if self.is_empty():
            raise QueueEmptyException("Queue is empty. Cannot access front of an empty queue.")
        else:
            return self.q[0]
