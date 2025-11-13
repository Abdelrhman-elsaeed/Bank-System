# Bank System Project (OOP)

A C++ Bank System project demonstrating Object-Oriented Programming (OOP) principles. This repository showcases the rebuilding of a procedural bank system into a structured, reusable, and extensible OOP-based design.

It was developed in phases to apply and practice real-world OOP concepts:
* **Encapsulation**
* **Abstraction**
* **Inheritance**
* **Polymorphism**

---

## 🎯 Project Objectives

* Refactor an old **procedural bank system** into a robust **OOP-based architecture**.
* Effectively apply the **four pillars of OOP**.
* Build a **layered architecture** separating:
    * **Presentation Layer (UI)**
    * **Business Logic Layer**
    * **Data Access Layer**
* Design the system for **scalability**, **clean code**, and **ease of modification**.

---

## 🧱 System Overview

The project simulates a **real-world banking system** with all major operations:

* Manage clients and user accounts.
* Perform deposits, withdrawals, and transfers.
* Log login attempts and transactions.
* Assign and verify user permissions.
* Secure the system with role-based access control.
* Automatically display the current date and logged-in user on all screens.
* Lock the system after three failed login attempts.
* Generate reports and audit records.

---

## 🏗️ Architecture
📂 Bank-System ┣ 📁 Core ┃ ┣ clsPerson.h / clsUser.h / clsBankClient.h ┃ ┗ clsScreen.h / clsMainScreen.h ┣ 
📁 BusinessLogic ┃ ┗ Transaction and Access Control Classes ┣ 
📁 Data ┃ ┗ File Handling and Storage ┣ 
📁 UI ┃ ┗ Screens and Menus ┗ main.cpp
This structure allows easy debugging, testing, and future scalability — reflecting how large enterprise systems are organized.

---

## ⚙️ Technologies Used

* 💻 **C++** — main implementation language.
* 🧰 **Object-Oriented Design (OOP)**
* 📁 **File-based Data Storage**
* 🧮 **Bitwise Operations** for permission handling.
* 🧠 **Encapsulation & Inheritance** for reusability and abstraction.

---

## 🧩 Extensions Implemented

Each extension adds a new layer of functionality to the system:

| Extension | Feature | Key Concept |
| :--- | :--- | :--- |
| 01 | Add Date and Logged-In User to All Screens | Inheritance |
| 02 | Lock the System After 3 Failed Logins | Encapsulation |
| 03 | User Permissions & Access Control | Abstraction |
| 04 | Transaction Screens (Deposit/Withdraw/Transfer) | Polymorphism |
| 05 | Login Records and Audit Trail | Data Persistence |
| 06 | Transfer Screen | Modularization |
| 07 | Manage Users Screen | Access Management |
| 08 | Show Total Balances | Aggregation |
| 09 | System Polishing & Final Improvements | Scalability |

---

## 🧠 Key Takeaways — The Power of OOP

Working on this project was more than just coding — it was **a mindset transformation**. Through consistent practice, OOP becomes a **natural way of thinking**.

Here’s what was learned:

* Adding a new feature (like showing the current user and date) took **only a few seconds** — one edit in the base class affected the whole system.
* When everything is **structured and inherited properly**, maintenance becomes effortless.
* Using **abstraction**, private logic is hidden from users who don’t need to see it — keeping interfaces clean and simple.
* The system **grew larger but stayed organized**, thanks to OOP and the **divide-and-conquer** approach.
* This same system could easily continue to grow for years — because its foundation is solid and scalable.

💡 **That’s the real power of Object-Oriented Programming** — it’s not just about syntax; it’s about thinking, designing, and scaling like a true software engineer.

---

## 🧾 Final Notes

This repository represents a full journey — from procedural coding to professional OOP design.

Every line of code was written with understanding and purpose.

---

## 🏷️ Hashtags

#OOP #Encapsulation #Abstraction #Inheritance #Polymorphism #CPlusPlus #Programming #Debugging #SoftwareDevelopment #ProblemSolving #CodeOptimization #TechCareer #KeepLearning #Algorithms #LearningByDoing #TechJourney #ProgrammingJourney #Cplusplus #LearnToCode #ObjectOrientedProgramming #Developers #CleanCode #SoftwareEngineering #CodingLife #TechSkills #CodeLearning #CppProjects #ProgrammingCommunity #BuildInPublic #DeveloperMindset #ComputerScience #BankSystem #PracticeMakesPerfect #ProgrammerLifestyle
