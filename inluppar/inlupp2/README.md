Simple Webstore Backend

Overview:
This project/assignment is a terminal-based backend for a potential shopping website, building using functions and data structures used in the earlier assignment. 

How to compile and run the appropiate test files:
gcc merch_test.c hashtable.c linked_list.c merch.c utils.c iterator.c -o merch_test -lcunit
valgrind ./merch_test

How to compile and run the program:

Write in the terminal:
gcc merch.c hashtable.c linked_list.c utils.c iterator.c -o merch -lcunit
./merch

Actions:
A: Add Merchandise. Adds a new item with name, description, and price (no duplicates is allowed in the program).
L: List Merchandise. Displays all items alphabetically, 20 at a time.
D: Remove Merchandise. Deletes an item and its stock.
E: Edit Merchandise. Edits item details.
S: Show Stock. Views storage locations and the amount of items.
P: Replenish Stock. Adds stock to an item at a specific location.
C: Create Cart. Starts a new, empty shopping cart.
R: Remove Cart. Delete a cart (confirmation required).
+: Add to Cart. Add items to a cart, checking stock levels.
-: Remove from Cart. Take items out of a cart.
=: Calculate Cost. Get the total cost of items in a cart.
O: Checkout. Completes the purchase of the cart.