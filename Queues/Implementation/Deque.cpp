//This is the Function of Implementation of Doubly Ended Queue

class myDeque {
    int *arr;
    int front;
    int rear;
    int size;
  public:
    myDeque(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void insertFront(int x) {//pushfront krna h
       //check for full -- if array is full or not
       
       if((front == 0 && rear == size-1) || ((rear+1) % size == front)){
           return ;
       }
       
       else if(front == -1){ //1st element to be inserted
           front = rear = 0;
           arr[front] = x;
       }
       else if(front == 0 && rear != size -1){ // front zero ho jaye aur rear last na ho
           front = size-1;
           arr[front] = x;
       }
       else {
           front--;
           arr[front] = x;
       }
        
    }

    void insertRear(int x) { //pushback krna h
       //check for full -- if array is full or not
       
       if((front == 0 && rear == size-1) || ((rear+1) % size == front)){
           return ;
       }
       else if(front == -1){ //1st element to be inserted
          front = rear = 0;
          arr[rear] = x;
       }
       else if(rear == size-1 && front != 0){ //rear end pe h aur front 0 pe nhi h mtlb space h
           rear = 0;
           arr[rear] = x;
       }
       else{
           rear++;
           arr[rear] = x;
       }
    }

    int deleteFront() {
       //check if its already empty
       if(front == -1 && rear == -1){
           return -1; //empty h
       }
       int ans = arr[front];
       
       if(front == rear){ //means ek element to hai
           front = rear = -1;
       }
       else if(front == size-1){ //front pop krte krte end pe aa gaya
           front = 0;
       }
       else{
           front++;
       }
       return ans;
    }

    int deleteRear() {
       //check if its already empty
       if(front == -1 && rear == -1){
           return -1; //empty h
       }
       
       int ans = arr[rear];
       
       if(front == rear){ //means ek element to hai
           front = rear = -1;   
       }
       
       else if(rear == 0){
           rear = size - 1;
       }
       else{
           rear--;
       }
       return ans;
    }

    int frontEle() {
       if(front == -1) return -1;
       return arr[front];
    }

    int rearEle() {
        if(rear == -1) return -1;
        return arr[rear];
    }
};
