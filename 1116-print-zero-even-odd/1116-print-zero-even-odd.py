import threading

class ZeroEvenOdd(object):
    def __init__(self, n):
        self.n = n
        # FIXED: Added '_event' suffix to prevent overwriting the class methods
        self.even_event = threading.Event()
        self.odd_event = threading.Event()
        self.zero_event = threading.Event()

        self.zero_event.set()
        
    def zero(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for num in range(self.n):
            self.zero_event.wait()
            self.zero_event.clear()
            printNumber(0)
            if (num + 1) % 2 == 0:
                self.even_event.set()
            else:
                self.odd_event.set()
        
    def even(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        internal_num = 2
        while internal_num <= self.n:
            # FIXED: even() now waits on even_event
            self.even_event.wait()
            self.even_event.clear()
            printNumber(internal_num)
            internal_num += 2
            self.zero_event.set()
        
    def odd(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        internal_num = 1
        while internal_num <= self.n:
            # FIXED: Updated property names to match __init__
            self.odd_event.wait()
            self.odd_event.clear()
            printNumber(internal_num)
            internal_num += 2
            self.zero_event.set()
