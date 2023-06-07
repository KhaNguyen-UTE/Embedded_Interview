# 🔥🔥🔥Embedded_Interview_T4
-------------------------------------------------------------
## 🧾Documents
-------------------------------------------------------------

### 💊 C

<details>

<summary> 🔸 Introduce</summary>
   
> - C là một ngôn ngữ lập trình cấp trung được phát triển bởi Dennis M. Ritchie để phát triển hệ điều hành UNIX tại Bell Labs. C được thực thi lần đầu tiên trên máy tính DEC PDP-11 vào năm 1972. 
> - Năm 1978, Brian Kernighan và Dennis Ritchie đưa ra mô tả C đầu tiên công khai về C, nay được gọi là tiêu chuẩn K & R.
> - Ngôn ngữ C được phát triển để tạo ra các ứng dụng hệ thống trực tiếp tương tác với các thiết bị phần cứng như trình điều khiển, kernals vv.
> - Ngôn ngữ lập trình Java, Hệ điều hành UNIX, trình biên dịch C và tất cả các chương trình ứng dụng UNIX đều đã được viết bằng C.
> - Lập trình C được coi là cơ sở cho các ngôn ngữ lập trình khác, đó là lý do tại sao nó được biết đến như là ngôn ngữ mẹ. Hầu hết các trình biên dịch, JVMs, Kernals vv được viết bằng ngôn ngữ C và hầu hết các ngôn ngữ theo cú pháp C, như C ++, Java vv.
> - Nó cung cấp các khái niệm cốt lõi như mảng, chức năng, xử lý tập tin vv được sử dụng trong nhiều ngôn ngữ như C ++, java, C # v.v.
   
</details>

<details>

<summary>🔸 Macro, Inline and Function</summary>

###  **Macro**
   
> - Được xử lý bởi preprocessor
> - Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó
>>   ```ruby
>>   VD: #define SUM(a,b)     (a+b)
>>   ```
> - Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng (first+last)

### **Inline**
   
> - Được xử lý bởi compiler
> - Được khai báo với từ khóa inline
> - Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compile
   
### **Function**
   
> - Hàm bình thường, khi thấy hàm được gọi, chương trình lưu đia chỉ hiện tại vào ***Stack Pointer***, sau đó chỏ con trỏ PC đến phân vùng nhớ của hàm được gọi. Thực thi câu lệnh của hàm được gọi, lấy kết quả lưu vào ***Stack***. Sau đó nó quay lại vào ***Stack Pointer***, lấy địa chỉ đó ra và tiếp tục chạy tiếp chương trình.
> - Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function).
   
### 💹 Compare
> - Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch
> - Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi
> - Hàm bình thường phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình
> - Macro khiến code trở nên dài hơn rất nhiều so với bình thường nhưng thời gian chạy nhanh.
> - Hàm inline cũng khiến code dài hơn, tuy nhiên nó làm giảm thời gian chạy chương trình
> - Hàm bình thường sẽ phải gọi function call nên tốn thời gian hơn inline function nhưng code ngắn gọn hơn.

</details>   

<details>

<summary>🔸 Static</summary>
   
### Static cục bộ
   
> Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.   
   
### Stactic toàn cục   
> Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 
   
</details>   

<details>

<summary>🔸 Struct and Union</summary>  

> Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:
>> - Struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding)
>> - Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.

</details>     

<details>

<summary>🔸 Compiler</summary>
   
> Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:
>> - 	Giai đoàn tiền xử lý (Pre-processor)
>> -	Giai đoạn dịch NNBC sang Asembly (Compiler)
>> - 	Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
>> -	Giai đoạn liên kết (Linker)
   
   ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/52d3dd8f-a648-47ed-a00c-5418478a37f0)
   
1. **Giai đoạn tiền xử lý – Preprocessor**
   
> - Giai đoạn này sẽ thực hiện:
>>   - Nhận mã nguồn
>>   - Xóa bỏ tất cả chú thích, comments của chương trình
>>   - Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
> - Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
   
2. **Công đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly**
   
> - Phân tích cú pháp (syntax) của mã nguồn NNBC.
> - Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
   
3. **Công đoạn dịch Assembly**
   
> - Dich chương trình => Sang mã máy 0 và 1.
> - Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.
   
4. **Giai đoạn Linker**
   
> - Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất.
> - Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
> - Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
> - Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.
   
</details>   

<details>

<summary>🔸 Pointer</summary>    

### **Tổng quát**

> Bộ nhớ RAM chứa rất nhiều ô nhớ, mỗi ô nhớ có kích thước 1 byte.
> Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu CPU 32 bit thì có 2^32 địa chỉ có thể đánh cho các ô nhớ trong RAM.
   
![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/78254da9-8f27-4c57-b858-21ac9ae3b21d)

> Khi khai báo biến, trình biên dịch dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Trình biên dịch có nhiệm vụ liên kết địa chỉ ô nhớ đó với tên biến. Khi gọi tên biến, nó sẽ truy xuất tự động đến ô nhớ đã liên kết với tên biến để lấy dữ liệu. Các bạn phải luôn phân biệt giữa địa chỉ bộ nhớ và dữ liệu được lưu trong đó.
   
![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/083070ea-72f1-4c19-9d46-c888e2e7e642)
 
> Địa chỉ của biến bản chất cũng là một con số thường được biểu diễn ở hệ cơ số 16. Ta có thể sử dụng con trỏ (pointer) để lưu địa chỉ của các biến.
   
### **Con trỏ là gì**
   
> Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
   
![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/de60652b-39ca-484f-a139-58c742ae50f3)
 
> Trong hình trên, biến var lưu giá trị 5 có địa chỉ là 0x61ff08. Biến pointVar là biến con trỏ, lưu địa chỉ của biến var (trỏ đến vùng nhớ của biến var), tức là nó lưu giá trị 0x61ff08.
   
🔹 **Con trỏ NULL**
> Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
   
```ruby
int *p2;//con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
int *p3 = NULL;//con trỏ null không trỏ đến vùng nhớ nào
```   
🔹 **Kích thước của con trỏ**
   
Ví dụ các khai báo con trỏ sau:

```ruby   
char *p1;
int *p2;
float *p3;
double *p4;
```
   
> ❗ Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là ***như nhau***. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
>> - Môi trường Windows 32 bit: 4 bytes
>> - Môi trường Windows 64 bit: 8 bytes
   
🔹 **Một số lưu ý khi sử dụng con trỏ**
 
Khi khởi tạo con trỏ NULL -> Chữ NULL phải viết hoa, viết thường null sẽ bị lỗi

```ruby   
int *p1 = NULL;//đúng
int *p2 = null;//lỗi
```
   
Không nên sử dụng con trỏ khi chưa được khởi tạo. Kết quả tính toán có thể sẽ phát sinh những lỗi không lường trước được nếu chưa khởi tạo con trỏ.
Sử dụng biến con trỏ sai cách.
   
</details>   
   
##

### 💊 C++      
<details>

<summary>🔸 Class</summary>
   
### Khái niệm
> Class hay lớp là một mô tả trừu tượng **(abstract)** của nhóm các đối tượng **(object)** có cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể **(instance)** cho những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:  
> - Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các phương thức (hàm thành phần hay method).
> - Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
> - Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt.

   
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
   
> ***Access modifier*** là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là **public**, **private** và **protected**
> - Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể  thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc tính.
> - Các thuộc tính private thường được sử dụng khi bạn không mong muốn người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về giá trị.
> - Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.

   
### Method declaration
   
   > Phương thức cũng giống như một hàm bình thường. Nó có thể có hoặc không có tham số, không trả về giá trị và thậm chí là override hàm.
     Đối với phương thức thì có **hai cách** định nghĩa thi hành: định nghĩa thi hành trong lúc định nghĩa class và định nghĩa thi hành bên ngoài class.
 
   👉 **Định nghĩa thi hành bên trong class:**
```ruby
class Animal {
 public:
 string sound;
 void makeNoise() {
 cout << sound;
 }
};
```
   
   👉 **Định nghĩa thi hành bên ngoài class:**
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

   👉 **Tham số truyền vào phương thức:**  
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

👉 **Tính kế thừa / Inheritance**
- Có 3 loại kế thừa : public, private và protected
   
   > Có nghĩa là một Class có thể kế thừa lại Class trước đó. Class kế thừa được gọi là Class con hay còn gọi là _subclass_. Class được kế thừa gọi là class cha hay còn gọi là _superclass_. Ngoài ra còn có thể mở rộng thêm các thành phần kế thừa và bổ sung thêm các thành phần mới.
   
👉 **Tính trừu tượng / Abstraction**
- Chỉ cần biết kết quả chứ không quan tâm cách làm
   > Là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý. Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class.

👉 **Tính đa hình / Polymorphism**
- Có thể đạt được đa hình theo kiểu ghi đè phương thức (Method Overriding) hoặc nạp chồng phương thức ( Method Overloading)
   > Là một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý.
   
👉 **Tính đóng gói / Encapsulation**
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
   1. **push_back()**: Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu 
của vector thì sẽ bị ném ra.
```ruby
ten-vector.push_back(ten-cua-phan-tu);
```
   
2. **assign()**: Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các  giá trị cũ.
```ruby  
ten-vector.assign(int size, int value);
```   
   
3. **pop_back()**: Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một vector.
```ruby
ten-vector.pop_back();   
```  
   
4. **insert()**: Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ.
```ruby
ten-vector.insert(position, value);   
```    
   
5. **erase()**: Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa
```ruby
ten-vector.erase(position);

ten-vector.erase(start-position, end-position);   
```      
   
6. **emplace()**: Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào
```ruby
ten-vector.emplace(ten-vector.position, element);   
```   
   
7. **emplace_back()**: Nó được sử dụng để chèn một phần tử mới vào vùng chứa vector, phần tử mới sẽ được thêm vào cuối vector
```ruby
ten-vector.emplace_back(value);   
```    
   
8. **swap()**: Hàm được sử dụng để hoán đổi nội dung của một vector này với một vector khác cùng kiểu. Kích thước có thể khác nhau.
```ruby
ten-vector-1.swap(ten-vector-2);   
```      
   
9. **clear()**: Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector
```ruby
ten-vector.clear();  
``` 

   
</details>

