# Bank System (OOP & 3-Tier Architecture)

A robust bank management system developed in C++ using pure Object-Oriented Programming (OOP) principles and a 3-Tier Architecture.

This project implements a complete banking solution with a focus on creating a modular, maintainable, and extensible codebase. The architecture strictly separates concerns between the user interface, business logic, and data access layers.

## Core Architecture

The system is built on two key foundations:

1.  **3-Tier Architecture:** A layered design that separates the system into:
    * **Presentation Layer (UI):** Manages all user interaction and screen rendering.
    * **Business Logic Layer (BLL):** Contains the core business rules, logic, and operations (e.g., transfer validation, permission checks).
    * **Data Access Layer (DAL):** Responsible for all communication with the data source (file-based storage).
      

2.  **Object-Oriented Principles (OOP):** The design effectively applies the four pillars of OOP:
    * **🔒 Encapsulation:** Protecting data integrity by bundling data and methods, with controlled access.
    * **🎭 Abstraction:** Hiding complex implementation details and exposing only necessary functionalities.
    * **🧬 Inheritance:** Reusing and extending common functionalities (e.g., a base `clsScreen` class for all UI screens).
    * **🔄 Polymorphism:** Enhancing flexibility, allowing objects to be treated as instances of their parent class.
      
<img width="600" alt="2" src="https://github.com/user-attachments/assets/df21d51b-8f3d-445e-be6f-2d8588fd9d33" />

## 🎯 Key Features

The system simulates a real-world banking environment with the following functionalities:

* **Client & User Management:** Full CRUD (Create, Read, Update, Delete) operations for clients and system users.
* **Transaction Management:**
    * Deposits
    * Withdrawals
    * Transfers (with validation)
* **Security & Access Control:**
    * Secure user login system.
    * Role-Based Access Control (RBAC) using **Bitwise Operations** to manage complex user permissions efficiently.
    * System lock-out after three failed login attempts.
* **Auditing & Logging:**
    * Logs all login attempts and user activity.
    * Maintains a detailed transaction history.
* **Dynamic UI:**
    * All screens automatically display the current system date and the logged-in user.
    * Modular menu-driven interface.

## 📈 Development Milestones

The system was built iteratively, with each major feature demonstrating a specific design concept:

| Milestone | Feature | Key Concept |
| :--- | :--- | :--- |
| **01** | Add Date and Logged-In User to All Screens | Inheritance |
| **02** | Lock the System After 3 Failed Logins | Encapsulation |
| **03** | User Permissions & Access Control | Abstraction |
| **04** | Transaction Screens (Deposit/Withdraw/Transfer) | Polymorphism |
| **05** | Login Records and Audit Trail | Data Persistence |
| **06** | Transfer Screen | Modularization |
| **07** | Manage Users Screen | Access Management |
| **08** | Show Total Balances | Aggregation |
| **09** | System Polishing & Final Improvements | Scalability |

## ⚙️ Technical Stack

* **Language:** C++
* **Core Design:** Object-Oriented Design (OOP) & 3-Tier Architecture
* **Data Storage:** File-Based System
* **Key Techniques:** Bitwise Operations (for permissions), Inheritance, Abstraction, Polymorphism.

## 📂 File Structure

The project directory is organized following the 3-Tier Architecture pattern:
