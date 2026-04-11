//Implementation of Queue Using Array

class myQueue {
    
    int *arr;
    int front;
    int rear;
    int size;
    
  public:
    myQueue(int n) {
        
        size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
        
    }

    bool isEmpty() {
        if(front == rear) return true;
        else return false;
    }

    bool isFull() {
       if(rear == size && front == 0) return true; //front start pe aur end last pe hona chahiye
       else return false;
    }

    void enqueue(int x) {
        //check if array is already full or not
        
        if(rear == size){ //mtlb full hai
            cout<<"Array is full"<<endl;
        }
        else{
            arr[rear] = x;
            rear++; // rear update
        }
    }

    void dequeue() {
        //check if array has elements there or not
        
        if(front == rear){ // mtlb empty hai 
           cout <<"Empty array can't remove"<<endl;
        }
        else{
            arr[front] = -1;
            front++;
          
            if(front == rear){ //agar pop krne k baad aise hota h to dono ko starting me laa do
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront() {
        if(front == rear) return -1; //agar empty h to return 
        else{
            return arr[front]; 
        }
    }

    int getRear() {
        if(front == rear) return -1; //agar empty h to return 
        else{
            return arr[rear-1];  // rear hamesha read element se ek aage rhta h isliye rear element liye arr[rear-1]; 
        }
    }
};
