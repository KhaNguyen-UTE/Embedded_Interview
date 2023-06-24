# Hotel Manager
-------------------------------------------------------------
## Description
The program creates an interface to manage employees and customers of a hotel

## Class

- Room
  > contains room management functions
- Customer
  > contains customer management functions
- Employee
  > contains employee management functions
- Check
  > contains functions to check input data is valid or not


## Operation

> The manager have an ability to manage Employee and the Receptionist can handle Customer. Customer can booking available Room by yourself and Check In/Out, payment functions. 

### 🔸 Main menu

   ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/dccd82f9-661f-472d-ab65-a6344f0484d8)

### 🔸 As Hotel's Employee

👉** _Fist step_**

>  ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/4e326f55-2ca5-4410-9d92-e33b17d79ee7)

👉 **_Second step_**

If don't have info of Receptionist in Database, we need to add Receptionist
> ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/d1811306-8c9c-48c7-b801-600f870433c5)

If already have Receptionist
> ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/b2cf414c-0896-4d69-8e65-7a9e12ec2337)

### 🔸 As Customer

![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/c37bf5c1-8e46-4495-8dbe-87af70c2b0f2)

👉** _1. Book room_**

![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/2b96851c-e73e-451d-9fd0-2ccba65d3bd1)

👉** _2,3. Check In / Out_**

![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/8a6f7b97-c9bf-4b46-a375-9629e2a41e4e)

👉** _Pay_**

![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/9b7f048e-8d13-46de-9363-2101995abcc6)

### 🔸 Note

**1. Class Check**

 > Have the function check input data is valid or not such as input day, month, year have to > 0 and < itself limit,...

**2. Check PASSSWORD**

> If enter wrong Password over 3 times, your access wil be cancel
![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/824d3e3f-3218-4dfa-baef-4716a154ad0d)

**3. Manager Functions**

When first run program, the manager is pre-installed with default password is :  >> "admin" <<

**4. List data of Customer**

> ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/cec8d544-0f2b-4167-87a8-e485b858efe9)

**5. List data of Employee**

> ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/d60f58d0-e2da-4796-b007-7d64d8ceebfd)

**6. Clean/Booked/Available room**

The hotel is set up with 10 available room. When 1 room is Booked, it STATUS is NO ( Not available ) and when Booked has payed or deleted, it STATUS is CL (CLEANING). When cleaned, the RECEPTIONIST will change it to OK ( Available ).

> ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/e0385179-a384-4176-bf37-9ff7bfffe6d4)

> The figure show the 105 room is cleaning, and when receptionist chose 105, it will set to Ok ( available)
> 101, 102, 109 is NO ( Booked) , when chose it, it remain unchange.

> ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/9b1c9d1b-4412-4b48-bf43-2411bb1fcbba)
> ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/58d0dfe2-838f-4fd2-8d49-730d36e70704)











