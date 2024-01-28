import sys
import pickle

class QueueOutOfRangeException(Exception):
    pass

class Queue:
    instances = {}
    __slots__ = ["__q", "name", "__size"]     
    #### TODO: whern we use __slots__, we can't use __dict__ (noticed)
    #### if we put __dict__ in the slots it well print an empty dict when called
    def __init__(self, name, size =5 ):
        self.__q = []
        self.name = name
        #### TODO: setter function to the size and set as private 
        self.__qsizeSetter = size
        Queue.instances[name] = self

    @property
    def size(self):
        return self.__size

    @size.setter
    def __qsizeSetter(self, s):
        if isinstance(s, int):
            self.__size = s
        else:
            raise ValueError("Size must be an Integer!!")

    def insert(self, value):
        if len(self) >= self.size:
            raise QueueOutOfRangeException(f"Out of range of the queue!! Size {self.size}!!")
        self.__q.append(value)

    def pop(self):
        if self.is_empty():
            print("The queue is empty!!")
            return None
        return self.__q.pop(0)
        
    def is_empty(self):
        size = len(self.__q)
        if size == 0:
            return True
        return False
    
    def show(self):
        print(self)

    def __str__(self):
        return f"The Queue {self.name}: {self.__q}\nThe size: {self.size}\t The length: {len(self)}"
    
    def __len__(self) -> int:
        return len(self.__q)
    
    def __del__(self):
        Queue.delQueueByName(self.name)
        print(f"This the destructor of queue {self.name}")

    @classmethod
    def getAll(cls):
        return cls.instances   

    @classmethod
    def getQueueByName(cls, name):
        return cls.instances.get(name, None)
    
    @classmethod
    def delQueueByName(cls, name):
        cls.instances.pop(name, None)
    
    @classmethod
    def save(cls, file_name = "queue_instances.pk"):
        print(f"{'=' * 20} Saving {'=' * 20}")
        try:
            with open(file_name, "wb") as f:
                pickle.dump(cls.getAll(), f, pickle.HIGHEST_PROTOCOL)
        except Exception as e:
            print(f"Saving Objects Failled!! {e.message}")
    
    @classmethod
    def load(cls, file_name = "queue_instances.pk"):
        print(f"{'=' * 20} Loading {'=' * 20}")
        try:
            with open(file_name, "rb") as f:
                cls.instances = pickle.load(f)
        except FileNotFoundError as e:
            print(e)
        except Exception as e:
            print(f"Loading Objects Failled!! {e.message}")

if __name__ == "__main__":
    #### TODO => Test the main components of the class (constructor, attributes, property, methods, special methods)
    q = Queue("numbers")
    q.show()
    q.insert(1)
    q.insert(2)
    q.insert(3)
    q.insert(4)
    q.show()
    q.pop()
    print(q)
    # q.__qsizeSetter = 3
    q.insert(1)
    print(q)

    #### TODO => keep track with all queues instances that has been created through this class
    # s = Queue('chars', 28)
    # print(Queue.getAll())
    # Queue.save()


    #### TODO => test deleting an instance ==> Python manages the memory with the concept called Reference counting
        #### (deletion in python works with reference count => the object isn't deleted untill all the refs are deleted first)
    # print(sys.getrefcount(s))     #### => used to get the reference count of an object
    # del s
    # print(Queue.getAll())
    # del q

    #### TODO => Test saving the objects
    # print(Queue.getAll())
    # Queue.save()

    #### TODO => Test loading the objects and test getting any queue of them using its name
    # print(Queue.getAll())
    # Queue.load()
    # q = Queue.getQueueByName("numbers")
    # q.show()
    # print(Queue.getAll())

    pass