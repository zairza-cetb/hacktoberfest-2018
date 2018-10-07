'''
    - Queue is a linear data structure which follows a particular order in which the operations are performed
    - The order is FIFO(First In First Out)
    - Queue operations:
        - Enqueue O(1)
        - Dequeue O(1)
'''

class UnderflowException(Exception):
    pass

class OverflowException(Exception):
    pass

class Queue(object):
    def __init__(self):
        self._queue = []
        self.__rear = 0
        self.__front = 0

    def __str__(self):
        return ', '.join([str(i) for i in self._queue])

    def is_empty(self):
        return self._queue == []

    def enqueue(self, element):
        '''
            :param element: element to be inserted (enqueued) in the queue
        '''
        self.__rear += 1
        self._queue.insert(0, element)
        return
    
    def dequeue(self):
        '''
            :return: popped element from the front of queue
        '''
        self.__front += 1
        if self.is_empty():
            raise UnderflowException
        return self._queue.pop()
    
    def get_rear(self):
        '''
            :return: rear element from the queue
        '''
        return self.__rear

    def get_front(self):
        '''
            :return: front element from the queue
        '''
        return self.__front

if __name__ == '__main__':
    queue = Queue()
    for i in range(10):
        queue.enqueue(i)
    print(queue)
    print(queue.dequeue())
    print(queue.dequeue())
    print(queue)
    print(queue.get_front(), queue.get_rear())
