public class LinkedListStack<T> implements  Stack<T>{
    private Node<T> top;
    private int size;
    
    public LinkedListStack(){
        top = null;
        size = 0;
    }
    
    @Override
    public void push(T value) {
    Node<T> n=new Node<>(value);
    n.setLink(top);
    top=n;
    size++;
    }

    @Override
    public T pop() throws Exception {
    if(getSize()>0){
        Node<T> t = top;
        top = top.getLink();
        size--;
        return t.getValue();
    }
    else {
	throw new Exception("The stack is empty");
    }
    }

    @Override
    public int getSize() {
    return size;
    }

    @Override
    public void clear() {
    top.setLink(null);
    size = 0;
    }
    
    @Override
    public String toString(){
      if(size>0){
      String res = "top [ ";
      Node<T> curr = top;
      while(curr!=null){
          res+=  curr.getValue()+" ";
          curr = curr.getLink();}
      return res +" ]";
      }
      else {
          return "Stack is empty";
      }
    }}
