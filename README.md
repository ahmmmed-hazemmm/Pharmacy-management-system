# 💊 Pharmacy Management System

## 📋 Overview
A comprehensive Pharmacy Management System designed to streamline and automate the day-to-day operations of a pharmacy. This system helps pharmacists and pharmacy staff manage inventory, prescriptions, sales, and customer information efficiently.


### 💻 Core Architecture
- **Programming Language**: C++ with Structured Programing
- **GUI Framework**: Native Windows Forms
- 

### 📊 Data Models
- **Inventory Management**
  ```cpp
  struct Medicine {
      string NDC;          // National Drug Code
      string name;
      double price;
      int stockLevel;
      Date expiryDate;
      vector<string> interactions;
  };
  ```
- **User Management**
  ```cpp
  struct User {
      int userID;
      string username;
      Role userRole;
      vector<Permission> permissions;
      byte[] passwordHash;
  };
  ```

