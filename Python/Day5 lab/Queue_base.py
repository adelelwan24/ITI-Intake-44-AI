class Queue:
    __slots__ = ["__q"]     
    #### TODO: whern we use __slots__, we can't use __dict__ (noticed)
    #### if we put __dict__ in the slots it well print an empty dict when called
    def __init__(self):
        self.__q = []

    def insert(self, value):
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
        print(self.__q)

    def __str__(self):
        return f"The Queue: {self.__q}"
    

if __name__ == "__main__":
    q = Queue()
    # print(q.__dict__)
    q.show()
    q.insert(1)
    q.insert(2)
    q.insert(3)
    q.insert(4)
    q.show()
    q.pop()
    q.show()
    print(q)
    q.insert(1)
    # print(q.__dict__)