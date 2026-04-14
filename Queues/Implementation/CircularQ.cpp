//This is Just the Function to Implement a circular queue

class MyCircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        //check if queue is already full or not
        if((front == 0 && rear == size-1) || ((rear+1)%size == front)){
            return false;
        }
        else if(front == -1){ //insertion of 1st element
           front = rear = 0;
           arr[rear] = value;
        }
        else if(rear == size-1 && front != 0){//rear last element pe ho aur front 0 na ho
           rear = 0;
           arr[rear] = value;
        }
        else{ //normal condition 
           rear++;
           arr[rear] = value;
        }
        return true;
    }
    
    bool deQueue() {
        //check if array is empty or not

        if(front == -1){ //Empty condition 
           return false;
        }
        else if(front == rear){ //means only single element is present
           front = rear = -1;   //means we removed the element 
        }
        else if(front == size-1){ //front pop krte krte last pe pahuch gaye 
           front = 0;
        }
        else{
            front++;
        }
        return true;
    }
    
    int Front() {
        if(front == -1) return -1;
        else return arr[front];
    }
    
    int Rear() {
        if(rear == -1) return -1;
        else return arr[rear];
    }
    
    bool isEmpty() {
        if(front ==-1 && rear == -1) return true;
        else return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size-1) || ((rear+1)%size == front)){
            return true;
        }
        else{
            return false;
        }
    }
};

