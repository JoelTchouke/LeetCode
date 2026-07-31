class Foo(object):
    def __init__(self):
        self.order = "first"
        self.lock = threading.Condition()


    def first(self, printFirst):
        """
        :type printFirst: method
        :rtype: void
        """
        with self.lock:
            # printFirst() outputs "first". Do not change or remove this line.
            printFirst()
            self.order = "second"
            self.lock.notify_all()


    def second(self, printSecond):
        """
        :type printSecond: method
        :rtype: void
        """
        with self.lock:
            while self.order != "second":
                self.lock.wait()
            # printSecond() outputs "second". Do not change or remove this line.
            printSecond()
            self.order = "third"
            self.lock.notify_all()
            
            
    def third(self, printThird):
        """
        :type printThird: method
        :rtype: void
        """
        with self.lock:
            while self.order != "third":
                self.lock.wait()
            # printThird() outputs "third". Do not change or remove this line.
            printThird()