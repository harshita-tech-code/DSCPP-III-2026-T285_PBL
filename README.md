# TiffinGrid (C++ Data Structures & Algorithms Project)

## Dataset & Environment
- University Campus & Local Tiffin Vendor Graph Network
- Built using C++ (STL, OOP Paradigm)

## Phases
- Phase 1: Requirements & Design
- Phase 2: Core Implementation
- Phase 3: Integration & Benchmarking

## Project Overview
TiffinGrid is an end-to-end hyper-local tiffin ordering and delivery management system designed specifically for campus environments. By leveraging core C++ Data Structures and Algorithms-including Binary Search Trees, Min-Heap Priority Queues, and Graph Traversal-the project addresses localized challenges such as vendor discovery, recurring subscription scheduling, and optimal campus delivery routing.

# Phase 1: Requirements & Design
Data Source: Localized Campus & PG Accommodation Graph Mapping.

System Scope: Vendor discovery, recurring meal subscriptions, urgent delivery prioritization, and graph-based route optimization.

# Phase 2: Core Implementation
Modules & Structures Built:
- **Vendor & Menu Discovery:** Binary Search Tree (BST) for key-based search and indexing.
- **Meal-Plan Management:** Polymorphic OOP hierarchy with base `MealPlan` and derived `DailyTiffin` and `MonthlyTiffin` classes.
- **Delivery Scheduling:** Min-Heap Priority Queue for time-slot urgency.
- **Campus Route Optimization:** Dynamic Adjacency List representing campus nodes and edges.

Key Insights: 
- **Architecture:** The choice of a Binary Search Tree enables O(log n) average-time key lookups for vendor indexing, replacing inefficient linear searching.

- **Subscription Handling:** Polymorphism via C++ class hierarchies allows flexible management of daily and monthly subscription models without code duplication.

# Phase 3: Integration & Benchmarking
Algorithms & Models Used:
- Binary Search Tree (BST)
- Min-Heap / Priority Queue
- Breadth-First Search (BFS) Algorithm

Best Performing Approach: 
- **Graph Traversal via Breadth-First Search (BFS)**  
- **Primary Optimization:** Shortest Path Delivery Routing
- **Why?:**
    - **1. Unweighted Shortest Path Execution:** BFS guarantees finding the minimum-hop route across campus locations when traveling between vendor locations and student PG accommodations.
    - **2. Heap-Driven Urgency Priority:** Integrating a Min-Heap ensures that orders approaching their scheduled delivery windows are popped first (O(log n) insertion/deletion), preventing delivery delays.
    - **3. Algorithmic Scalability:** Utilizing dynamic adjacency lists reduces space complexity to O(V + E), allowing the campus network representation to scale cleanly without memory bloat.