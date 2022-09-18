 #define STACK_CAPACITY 1000
class Stack
{
public:
 char stk [STACK_CAPACITY];
 int count;
 Stack(){
   count = 0;
 }
 
 void push(char c){
   if (! isFull()){
     stk[count] = c;
     count++;    
   }  
 }

 char pop(){
   if (! isEmpty()){
    char topchar = stk[count-1];
    for (int i = count-1; i < STACK_CAPACITY - 1; i++)
      stk[i] = stk[i + 1];
    count--;
    return topchar;
   }
 }
 
 char top(){
   return stk[count-1];
 }

 bool isEmpty()
 {
   if (count == 0){
     return true;
   }else{
     return false;
   }
 }

 bool isFull()
 {
   if (count == STACK_CAPACITY)
   {
     return true;
   }else{
     return false;
   }
 }

 ~Stack(){}
};