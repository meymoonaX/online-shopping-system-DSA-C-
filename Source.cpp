 #include <iostream>
#include <string>

using namespace std;

// Cart using Array
class Cart {
    string items[100];
    int count;
public:
    Cart() : count(0) {}
    void addItem(const string& item) {
        if (count < 100) {
            items[count++] = item;
            cout << item << " added to cart.\n";
        }
        else {
            cout << "Cart is full.\n";
        }
    }
    void viewCart() {
        if (count == 0) {
            cout << "Cart is empty.\n";
            return;
        }
        cout << "Items in cart:\n";
        for (int i = 0; i < count; ++i)
            cout << "- " << items[i] << "\n";
    }
};

// Wishlist using Stack (Linked List)
class WishlistNode {
public:
    string item;
    WishlistNode* next;
    WishlistNode(const string& item) : item(item), next(nullptr) {}
};

class Wishlist {
    WishlistNode* top;
public:
    Wishlist() : top(nullptr) {}
     void addItem(const string& item) {
        WishlistNode* newNode = new WishlistNode(item);
        newNode->next = top;
        top = newNode;
        cout << item << " added to wishlist.\n";
    }
    void viewWishlist() {
        if (!top) {
            cout << "Wishlist is empty.\n";
            return;
        }
        cout << "Recently added wishlist items:\n";
        WishlistNode* temp = top;
        while (temp) {
            cout << "- " << temp->item << "\n";
            temp = temp->next;
        }
    }
    ~Wishlist() {
        while (top) {
            WishlistNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// Orders using Queue (Linked List)
class OrderNode {
public:
    string item;
    OrderNode* next;
    OrderNode(const string& item) : item(item), next(nullptr) {}
};

class Orders {
    OrderNode* front;
    OrderNode* rear;
public:
    Orders() : front(nullptr), rear(nullptr) {}
    void placeOrder(const string& item) {
        OrderNode* newNode = new OrderNode(item);
        if (!rear) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Order for " << item << " placed.\n";
    }
    void processOrder() {
        if (!front) {
            cout << "No orders to process.\n";
            return;
        }
        cout << "Processing order for " << front->item << ".\n";
        OrderNode* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }
    ~Orders() {
        while (front) {
            OrderNode* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Cart cart;
    Wishlist wishlist;
    Orders orders;

    int choice;
    string input;
    do {
        cout << "\n--- Online Shopping System Menu ---\n";
        cout << "1. Add item to cart\n";
        cout << "2. View cart\n";
        cout << "3. Add to wishlist\n";
        cout << "4. View recently added wishlist items\n";
        cout << "5. Place order\n";
        cout << "6. Process next order\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume the newline character

        switch (choice) {
        case 1:
            cout << "Enter item to add to cart: ";
            getline(cin, input);
            cart.addItem(input);
            break;
        case 2:
            cart.viewCart();
            break;
             case 3:
                cout << "Enter item to add to wishlist: ";
                getline(cin, input);
                wishlist.addItem(input);
                break;
            case 4:
                wishlist.viewWishlist();
                break;
            case 5:
                cout << "Enter item to place order: ";
                getline(cin, input);
                orders.placeOrder(input);
                break;
            case 6:
                orders.processOrder();
                break;
            case 7:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
