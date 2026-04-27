# online-shopping-system-DSA-C-
This project is a console-based Online Shopping System developed in C++ that demonstrates the implementation of fundamental data structures without using the Standard Template Library (STL). The system simulates core e-commerce functionalities such as managing a shopping cart, wishlist, and order processing. 
# 🛒 Online Shopping System (C++ - No STL)

##  Overview

This project is a simple console-based Online Shopping System built in C++. It demonstrates the use of fundamental data structures such as arrays, stacks, and queues without relying on the Standard Template Library (STL).

The system allows users to:

* Add and view items in a cart
* Manage a wishlist
* Place and process orders

## Features

###  Cart (Array)

* Stores items using a fixed-size array (max 100 items)
* Add items to cart
* View all cart items

### Wishlist (Stack - Linked List)

* Implements LIFO (Last In First Out)
* Recently added items appear first
* Dynamic memory allocation using pointers

### 📦 Orders (Queue - Linked List)

* Implements FIFO (First In First Out)
* Orders are processed in the order they are placed

---

## Data Structures Used

| Feature  | Data Structure | Implementation |
| -------- | -------------- | -------------- |
| Cart     | Array          | Static Array   |
| Wishlist | Stack          | Linked List    |
| Orders   | Queue          | Linked List    |

---

##  Menu Options

```
1. Add item to cart
2. View cart
3. Add to wishlist
4. View wishlist
5. Place order
6. Process next order
7. Exit
```

