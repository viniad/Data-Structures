# Data Structures

Data Structures in Portuguese-BR implemented in C++.

- **LES** *(Static List)*
- **LDE** *(Linked List)*
- **LDDE** *(Doubly Linked List)*
- **Fila** *(Queue)*

## LES *(Static List)*
The Static List has the attributes **n** and **max**
- *n* = number of elements in the list, it's incremented every time a value is insered.
- *max* = maximum elements that can be stored in the list, initialized in the constructor.

![](LES%20(Static%20List)/images/LES.png)

## LDE *(Linked List)*
To implement this List you must have a class named Node with a pointer to the **next** and the value you will
store in the node.

The difference between Linked List and Static List is that in the linked list you do not have to pass a maximum cappacity to the
constructor.
It has a pointer **primeiro (first)** and the attribute **n**.
- *primeiro* = it's a node pointer that points to the first element in the list.
- *n* = number of elements in the list, it's incremented every time a value is insered.

![](LDE%20(Linked%20List)/images/LDE.png)

## LDDE *(Doubly Linked List)*
To implement this List you must have a class named Node with a pointer to the **next** and **previous** node and the value you will
store in the node.

The Doubly Linked List has the pointers **primeiro (first)**, **ultimo (last)** and the attribute **n**.
- *primeiro* = it's a node pointer that points to the first element in the list.
- *ultimo* = it's a node pointer that points to the last element in the list.
- *n* = number of elements in the list, it's incremented every time a value is insered.

![](LDDE%20(Doubly%20Linked%20List)/images/LDDE.png)

