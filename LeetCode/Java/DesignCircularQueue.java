class MyCircularQueue {
    int length;
     int rear, front;
     int[] q;

    public MyCircularQueue(int k) {
        q = new int[k];
        length = 0;
        front = 0;
        rear = -1;
    }

    public boolean enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % (q.length);
        q[rear] = value;
        length++;
        return true;
    }

    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % (q.length);
        length--;
        return true;
    }

    public int Front() {
        return isEmpty() ? -1 : q[front];
    }

    public int Rear() {
        return isEmpty() ? -1 : q[rear];
    }

    public boolean isEmpty() {
        return length == 0;
    }

    public boolean isFull() {
        return length == q.length;
    }
}