#include "arrayQueue.h"

int main(){
    ArrayQueue<int> *queue = new ArrayQueue<int>(8);
    int option;
    int result;
    cin>>option;

    if(option==1){
        cout<<(queue->isEmpty()==1)<<endl;
    }else if(option==2){
        cout<<(queue->isFull()==0)<<endl;
    }else{
        queue->enqueue(10);
        queue->enqueue(20);
        if(option==3){
            cout<<(queue->getFront()==0 && queue->getRear()==1)<<endl;
        }
        else{
            queue->enqueue(30);
            queue->enqueue(40);
            queue->enqueue(50);
            queue->enqueue(60);
            queue->enqueue(70);
            queue->enqueue(80);
            if(option==4){
                cout<<(queue->getFront()==0 && queue->getRear()==7)<<endl;
            }else if(option==5){
                queue->enqueue(90);
                cout<<(queue->getFront()==0 && queue->getRear()==7)<<endl;
            }
            else if(option==6){
               result =  queue->dequeue();
               cout<<(result==10&&queue->getFront()==1)<<endl;
            }else{
                queue->dequeue();
                queue->dequeue();
                queue->dequeue();
               result= queue->dequeue();
               if(option==7){
                   cout<<(result==40&&queue->getFront()==4)<<endl;
               }else if(option<=9){
                   queue->enqueue(90);
                   queue->enqueue(100);
                   queue->enqueue(110);
                   if(option==8){
                       cout<<(queue->getFront()==4&&queue->getRear()==2)<<endl;
                   }else if(option==9){
                       queue->dequeue();
                       queue->dequeue();
                       queue->dequeue();
                       queue->dequeue();
                       queue->dequeue();
                       queue->dequeue();
                       cout<<(queue->getFront()==2&&queue->getRear()==2)<<endl;
                   }
               }
            }
        }
    }


    delete queue;
    return 0;
}