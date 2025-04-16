## Overview

This project implements a simulation of a growing fruit garden using manually managed, memory-efficient data structures in pure C++. The program models a garden consisting of trees, branches, and fruits.

## Features

### Custom Data Structures

- Implementation uses linked lists
- Manual memory management using raw pointers.
- Structures are designed with efficiency and clarity in mind.

### TREE_CLASS (Tree)

- Each tree has a unique ID and a specific height.
- Branches can grow at specified heights.
- Supports fading, growing, and harvesting operations.

### BRANCH_CLASS (Branch)

- Each branch has a defined length.
- Can hold a list of fruits.
- Can be cloned or harvested.

### FRUIT_CLASS (Fruit)

- Each fruit has a weight and length.
- Attached to a specific branch.
- Can grow, fade (reduce weight), or be plucked.

## Implemented Functionality

### GARDEN_CLASS

- `getWoodsTotal()` – Returns the number of trees in the garden.
- `getBranchesTotal()` – Returns the number of branches across all trees.
- `getFruitsTotal()` – Returns the number of fruits in the garden.
- `getWeight()` – Returns the total weight of fruits in the garden.
- `add()` – Adds a new tree with the smallest available ID.
- `extendWood(unsigned int)` – Grows a new branch at a specified height.
- `fadeGarden()` – Calls fade operations across the entire garden.
- `harvestGarden(unsigned int)` – Harvests all fruits above a specified height.
- `cutBranch(unsigned int)` – Removes all fruits from branches of specified length.

### WOOD_CLASS

- `getBranchesTotal()` – Returns number of branches in the tree.
- `getFruitsTotal()` – Returns number of fruits in the tree.
- `getWeight()` – Returns total weight of fruits in the tree.
- `extendWood(unsigned int)` – Grows a branch at a given height.
- `fadeBranch(unsigned int)` – Decreases fruit weights on branches of given length.
- `harvestBranch(unsigned int)` – Removes fruits above given length.
- `cutBranch(unsigned int)` – Removes all fruits from branches of given length.
- `clone(const BRANCH_CLASS*)` – Clones a given branch and attaches it to this tree.

### BRANCH_CLASS

- `getFruitsTotal()` – Returns number of fruits on the branch.
- `getWeight()` – Returns total fruit weight on the branch.
- `growthBranch()` – Increases fruit weight by 1.
- `fadeBranch()` – Decreases fruit weight by 1.
- `pluckBranch()` – Resets weight of all fruits to zero.
- `cutBranch()` – Removes all fruits from the branch.

### FRUIT_CLASS

- `getLength()` – Returns the fruit’s length.
- `getWeight()` – Returns the fruit’s weight.
- `growthFruit()` – Increases weight by 1.
- `fadeFruit()` – Decreases weight by 1 (minimum 0).
- `pluckFruit()` – Resets weight to 0.
- `getBranchPointer()` – Returns a pointer to the parent branch.
- `getNext()` / `setNext()` – Used for linked list structure.
- `setParent()` – Updates the parent branch reference.
