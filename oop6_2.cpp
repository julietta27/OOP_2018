#define STACK_MAX 100
#include <iostream>
using std::cout;
using std::endl;
template <class T> class Stack {
    private:
        T data[STACK_MAX];
        int size;
    public:
        Stack() {       // Constructor
            size = 0;
        }
        ~Stack() { }    // Destructor
		bool isEmpty()
		{
			//Проверка стека на отсутствие элементов в нем
			if (size==0)
				return true;
			return false;
		}
        T peek() {//Считывание головного элемента
            if (isEmpty()) {
                cout<<"Error: stack empty, can't make peek()"<<"\n";
                exit(-1);
            }
            return data[size-1];
        }
        void push(T d) { //Добавление элемента в стек
            if (size < STACK_MAX)
                data[size++] = d;
            else
                cout<<"Error: stack full"<<"\n";
        }
        void pop() {//Удаление головного элемента
            if (isEmpty())
                cout<<"Error: stack empty, can't make pop()"<<"\n";
            else
                size--;
        }
		void clear() //Очистка стека
		{
			while (size>0)
				pop();
		}
};

int main()
{
    Stack<int> stack1;

    stack1.push(10.8);
    stack1.push(79);

    cout<<stack1.peek()<<endl;

    stack1.pop();
    cout<<stack1.peek()<<endl;

    stack1.pop();
    cout<<stack1.peek()<<endl;
    return 0;
}