# 🔥🔥🔥Embedded_Interview_T4
-------------------------------------------------------------
## 🧾Documents

###  💊C 
### 💊C++      
<details>

<summary>🔸 Class</summary>
   
### Khái niệm
   > Class hay lớp là một mô tả trừu tượng **(abstract)** của nhóm các đối tượng **(object)** có cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể **(instance)** cho những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:
   
```  
▪ Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các phương thức (hàm thành phần hay method).
▪ Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
▪ Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt.
```
   
### Khai báo class và sử dụng class
   
```ruby
class Person {
public:
string firstName; // property
string lastName; // property
int age; // property
void fullname() { // method
cout << firstName << ' ' << lastName;
}
}
```
   
 ### Access modifiers & properties declaration
   
   > ***Access modifier*** là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là ** public**, **private** và **protected**
   
```
▪ Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực tiếp thông qua instance của class đó. 
  Các thuộc tính nên khai báo là public nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể  thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc tính.
▪ Các thuộc tính private thường được sử dụng khi bạn không mong muốn người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về giá trị.
▪ Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.
```
   
### Method declaration
   
   > Phương thức cũng giống như một hàm bình thường. Nó có thể có hoặc không có tham số, không trả về giá trị và thậm chí là override hàm.
     Đối với phương thức thì có **hai cách** định nghĩa thi hành: định nghĩa thi hành trong lúc định nghĩa class và định nghĩa thi hành bên ngoài class.
 
   👉 Định nghĩa thi hành bên trong class:
```ruby
class Animal {
 public:
 string sound;
 void makeNoise() {
 cout << sound;
 }
};
```
   
   👉 Định nghĩa thi hành bên ngoài class:
```ruby
class Animal {
 public:
 string sound;
 void makeNoise();
};
void Animal::makeNoise() {
 cout << sound;
}
```

   👉 Tham số truyền vào phương thức:   
- Cách 1: Dặt tên trùng với thuộc tính Class bằng cách kết hợp toán tử :: và con trỏ _this_\
- Cách 2: Đặt tên khác với thuộc tính ( thường thêm dấu "_" trước tên tham số giống thuộc tính private
   
🔹 ***Con trỏ this*** : đề cập đến thể hiện hay instance của class đó, thông qua con trỏ this ta có thể truy cập đến các thuộc tính và phương thức.
   
🔹 ***Toán tử phạm vi*** : dùng để xác định phương thức hoặc thuộc tính được gọi từ Class nào.
   
### Constructor
> Constructor hay hàm dựng là một hàm đặc biệt, nó sẽ được gọi ngay khi chúng ta khởi tạo một object. Công dụng chính là khởi gán các thuộc tính
   
### Static member
> Static member hay thành viên tĩnh trong class C++ cũng tương tự như với static variable (biến tĩnh) trong function. Đối với function, sau khi thực hiện xong khối lệnh và thoát thì biến tĩnh vẫn sẽ không mất đi. Đối với class, thành viên tĩnh sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static.
   
</details>

<details>

<summary>🔸 OOP</summary>

### Khái niệm
> OOP Object - Oriented Programming là cách tư duy mới tiếp cận hướng đối tượng để giải quyết các vấn đề bằng máy tính. Là một mô hình dựa trên khái niệm về Class và Object. Nó được sử dụng để tách 1 chương trình thành các phần đơn giản hơn, có thể tái sử dụng.

### Các đặc tính của lập trình hướng đối tượng
> Có 4 đặc tính: Kế thừa, Trừu tượng, Đa hình và Đóng gói

   👉 Tính kế thừa / Inheritance 
- Có 3 loại kế thừa : public, private và protected
   
   > Có nghĩa là một Class có thể kế thừa lại Class trước đó. Class kế thừa được gọi là Class con hay còn gọi là _subclass_. Class được kế thừa gọi là class cha hay còn gọi là _superclass_. Ngoài ra còn có thể mở rộng thêm các thành phần kế thừa và bổ sung thêm các thành phần mới.
   
   👉 Tính trừu tượng / Abstraction 
- Chỉ cần biết kết quả chứ không quan tâm cách làm
   > Là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý. Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class.

   👉 Tính đa hình / Polymorphism
- Có thể đạt được đa hình theo kiểu ghi đè phương thức (Method Overriding) hoặc nạp chồng phương thức ( Method Overloading)
   > Là một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý.
   
    👉 Tính đóng gói / Encapsulation
- Mỗi thuộc tính sẽ có phạm vi truy cập hay còn gọi là access modifier -> Private
   > Có ý nghĩa không cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó. Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu.

</details>

<details>

<summary>🔸 Namespacce and Templete</summary>
   
### Namespace
   > Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau. Thông thưognf ta hay dùng namespace "std" trong thư viện iostream

### Templete
   > Là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
     Template trong C++ có **2 loại** đó là _ function template_ & _class template_.
     Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.

</details>

<details>

<summary>🔸Virtual</summary>
   
> Là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất khi kế thừa cần ***phải định nghĩa lại***.
> Hàm ảo được sử dụng trong lớp cơ sở khi cần đảm bảo hàm ảo đó sẽ được định  nghĩa lại trong lớp dẫn xuất. Việc này rất cần thiết trong trường hợp con trỏ có  kiểu là lớp cơ sở trỏ đến _đối tượng của lớp dẫn xuất_ ( hàm dẫn xuất được coi là khốp với lớp cơ sở nếu có cùng tên, loại tham số 'cho dù có là const' và kiểu trả về của hàm trong lớpcơ sở. Các hàm như vậy được gọi là ghi đè (Overiding).
> Hàm ảo chỉ khác hàm thành phần thông thường khi được gọi từ một con trỏ. Sử  dụng hàm ảo khi muốn con trỏ đang trỏ tới đối tượng của lớp nào thì hàm thành phần của lớp đó sẽ được gọi mà không xem xét đến kiểu của con trỏ.
   
❗**Lưu ý**: Con trỏ của lớp cơ sở có thể chứa địa chỉ của đối tượng thuộc lớp dẫn xuất, nhưng ngược lại thì không được.
   
</details>

<details>

<summary>🔸Vector</summary>
   
> Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối  tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp  trong vector. Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể _thay đổi_ trong suốt quá trình làm việc của chương trình. 

📓 **Modifiers**
   
   
   
</details>

