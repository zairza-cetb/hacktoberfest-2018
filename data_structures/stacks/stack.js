// Author: Austin Crane
// this is a node program, you can run this with node stack.js

// Stack simple stack implementation
// accessed via a "private" items array
function Stack() {
  this._items = [];
  return this;
}

// push adds an item onto the stack
Stack.prototype.push = function(n) {
  this._items.push(n);
}

// pop removes the item on the top of the stack
Stack.prototype.pop = function() {
  if (this.size() === 0) {
    // if your trying to access an empty stack that
    // would be considered an error
    console.error('reached end of stack');
    return;
  }
  return this._items.pop();
}

// size gives the size of the stack
Stack.prototype.size = function() {
  return this._items.length;
}

// simple "main" program to work with a stack
function stackExample() {
  var s = new Stack()
  s.push(1);
  s.push(2);
  s.push(3);

  // print size of stack
  console.log(s.size());

  // 3
  console.log(s.pop());
  // 2
  console.log(s.pop());
  // 1
  console.log(s.pop());

  // this will log an error reach end of stack
  console.log(s.pop());
}

stackExample();
