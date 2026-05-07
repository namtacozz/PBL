# BÁO CÁO PBL - DỰ ÁN CƠ SỞ LẬP TRÌNH

> **Lưu ý**: File này là nội dung báo cáo dạng Markdown. Khi nộp bài, cần copy sang file Word (.docx) theo đúng mẫu `KhoaCNTT - Mau baocao PBL_Du an co so lap trinh.docx`, định dạng font Time New Roman, cỡ 13, dãn dòng 1.3.

---

## TRANG BÌA

```
TRƯỜNG ĐẠI HỌC BÁCH KHOA
KHOA CÔNG NGHỆ THÔNG TIN

[Logo Khoa]

PBL
DỰ ÁN CƠ SỞ LẬP TRÌNH

XÂY DỰNG ỨNG DỤNG THỰC HIỆN
GIAO DỊCH TRÊN MÁY ATM

Người hướng dẫn: GVC. ThS. TRẦN HỒ THUỶ TIÊN.
Sinh viên thực hiện:
    [Tên sinh viên 1]    LỚP: XXX    NHÓM: YYY
    [Tên sinh viên 2]    LỚP: XXX    NHÓM: YYY (nếu có)

Đà Nẵng, 05/2026
```

---

## MỤC LỤC

```
MỤC LỤC ..................................................... i
DANH MỤC HÌNH VẼ .......................................... ii
MỞ ĐẦU ..................................................... iii
1. TỔNG QUAN ĐỀ TÀI ........................................ 1
2. CƠ SỞ LÝ THUYẾT ......................................... 2
   2.1. Ý tưởng ............................................. 2
   2.2. Cơ sở lý thuyết ..................................... 2
3. TỔ CHỨC CẤU TRÚC DỮ LIỆU VÀ THUẬT TOÁN ................. 6
   3.1. Phát biểu bài toán .................................. 6
   3.2. Cấu trúc dữ liệu ................................... 7
   3.3. Thuật toán ........................................... 8
        3.3.1. Thuật toán đọc dữ liệu tài khoản từ file ..... 8
        3.3.2. Thuật toán tìm tài khoản ...................... 9
        3.3.3. Thuật toán xác thực tài khoản ................. 9
        3.3.4. Thuật toán gửi tiền .......................... 10
        3.3.5. Thuật toán rút tiền .......................... 10
        3.3.6. Thuật toán chuyển tiền ....................... 11
        3.3.7. Thuật toán kiểm tra số dư ................... 11
        3.3.8. Thuật toán lưu giao dịch vào file ........... 12
        3.3.9. Thuật toán đổi mã PIN ....................... 12
4. CHƯƠNG TRÌNH VÀ KẾT QUẢ ................................. 13
   4.1. Tổ chức chương trình ................................ 13
   4.2. Ngôn ngữ cài đặt ................................... 14
   4.3. Kết quả ............................................. 15
        4.3.1. Giao diện chính của chương trình ............. 15
        4.3.2. Kết quả thực thi của chương trình ............ 16
        4.3.3. Nhận xét đánh giá ............................ 19
5. KẾT LUẬN VÀ HƯỚNG PHÁT TRIỂN ............................ 20
   5.1. Kết luận ............................................ 20
   5.2. Hướng phát triển .................................... 20
TÀI LIỆU THAM KHẢO ........................................ 21
PHỤ LỤC .................................................... 22
```

---

## DANH MỤC HÌNH VẼ

```
Hình 1.  Sơ đồ tổ chức chương trình ........................ 13
Hình 2.  Nguyên mẫu hàm của chương trình ................... 14
Hình 3.  Giao diện khởi động hệ thống (System Boot) ........ 15
Hình 4.  Giao diện chính của ATM (Welcome Screen) .......... 16
Hình 5.  Giao diện đăng nhập và xác thực PIN ............... 16
Hình 6.  Giao diện menu khách hàng ......................... 17
Hình 7.  Kết quả chức năng gửi tiền ........................ 17
Hình 8.  Kết quả chức năng rút tiền ........................ 17
Hình 9.  Kết quả chức năng chuyển tiền ..................... 18
Hình 10. Kết quả chức năng kiểm tra số dư .................. 18
Hình 11. Kết quả khi nhập sai PIN 3 lần - khóa thẻ ........ 18
Hình 12. Kết quả khi vượt quá giới hạn giao dịch/ngày ...... 18
Hình 13. Giao diện Admin Control Panel ..................... 19
Hình 14. File accounts.dat sau khi lưu ..................... 19
Hình 15. File transactions sau khi lưu ..................... 19
```

---

## MỞ ĐẦU

Công nghệ thông tin trong giai đoạn hiện nay đang có những bước phát triển mạnh mẽ trên mọi lĩnh vực. Trong bối cảnh số hóa ngày càng sâu rộng, các hệ thống tự động hóa giao dịch tài chính như máy ATM (Automated Teller Machine) đóng vai trò ngày càng quan trọng trong lĩnh vực ngân hàng. ATM không chỉ giúp khách hàng thực hiện các giao dịch nhanh chóng, tiện lợi mà còn giảm tải cho nhân viên ngân hàng trong việc xử lý các nghiệp vụ thường ngày.

Với mục tiêu học tập và rèn luyện kỹ năng lập trình, đề tài **"Xây dựng ứng dụng thực hiện giao dịch trên máy ATM"** (Đề tài 701) là một bài toán thực tiễn giúp sinh viên vận dụng các kiến thức nền tảng về lập trình C/C++ vào giải quyết vấn đề cụ thể.

**Mục đích đề tài**: Xây dựng một ứng dụng phần mềm mô phỏng các chức năng cơ bản của máy ATM bao gồm: đăng nhập tài khoản, gửi tiền, rút tiền, chuyển tiền, kiểm tra số dư và đổi mã PIN; đồng thời quản lý dữ liệu tài khoản thông qua các thao tác với file.

**Mục tiêu cụ thể**:
- Sử dụng các mảng song song (parallel arrays) để lưu trữ và quản lý dữ liệu tài khoản khách hàng.
- Sử dụng các thao tác đọc/ghi file để lưu trữ và cập nhật dữ liệu.
- Áp dụng các cấu trúc điều khiển (biến, vòng lặp, rẽ nhánh) để xử lý logic nghiệp vụ.
- Tổ chức chương trình thành các hàm chức năng rõ ràng, dễ bảo trì.

**Phạm vi nghiên cứu**: Tập trung vào phần mềm console mô phỏng các thao tác giao dịch cơ bản trên máy ATM, bao gồm quy trình khởi động hệ thống, phục vụ khách hàng và tắt máy.

**Đối tượng nghiên cứu**: Quá trình giao dịch của người dùng trên hệ thống ATM, bao gồm các thao tác gửi tiền, rút tiền, chuyển tiền, kiểm tra số dư và các cơ chế bảo mật như xác thực PIN, khóa thẻ.

**Phương pháp nghiên cứu**: Tổng hợp kiến thức lập trình C/C++ đã được học, tham khảo tài liệu chuyên ngành và áp dụng vào thiết kế, cài đặt chương trình dưới dạng menu tương tác.

**Cấu trúc đồ án** gồm 5 chương:
- Chương 1: Tổng quan đề tài
- Chương 2: Cơ sở lý thuyết
- Chương 3: Tổ chức cấu trúc dữ liệu và thuật toán
- Chương 4: Chương trình và kết quả
- Chương 5: Kết luận và hướng phát triển

Trong quá trình thực hiện đồ án, do thời gian cũng như trình độ còn hạn chế nên không tránh khỏi những thiếu sót. Rất mong nhận được sự góp ý của thầy cô và các bạn để đồ án được hoàn thiện hơn. Chúng em xin chân thành cảm ơn sự hướng dẫn tận tình của cô Trần Hồ Thủy Tiên cùng các thầy cô trong Khoa Công nghệ Thông tin, Trường Đại học Bách khoa - Đại học Đà Nẵng.

---

## 1. TỔNG QUAN ĐỀ TÀI

Đề tài 701 — **"Xây dựng ứng dụng thực hiện giao dịch trên máy ATM"** thuộc lĩnh vực lập trình ứng dụng console, mô phỏng hoạt động thực tế của máy rút tiền tự động tại ngân hàng.

Trong thực tế, mỗi ngày máy ATM được khởi động bởi nhân viên IT của ngân hàng. Tại thời điểm khởi động, máy ATM đọc danh sách các số tài khoản (account numbers), mã PIN (Personal Identification Numbers) và số dư (account balances) từ một file dữ liệu. Sau khi máy bắt đầu hoạt động, khách hàng có thể sử dụng ATM để thực hiện các giao dịch bao gồm: gửi tiền, rút tiền và xem số dư tài khoản.

Mỗi giao dịch, ATM yêu cầu khách hàng xác nhận số tài khoản và mã PIN. Sau khi xác thực thành công, khách hàng có thể thực hiện các giao dịch. Mỗi giao dịch thành công sẽ được ATM ghi lại bao gồm: số tài khoản và số tiền giao dịch, đồng thời cập nhật số dư hiện tại. Máy ATM giới hạn số lần giao dịch của mỗi khách hàng trong một ngày và sẽ từ chối nếu vượt quá giới hạn.

Kết thúc một ngày, nhân viên IT nhập mã bảo mật để tắt máy ATM. Khi shutdown, hệ thống ghi danh sách giao dịch trong ngày vào file và cập nhật file dữ liệu tài khoản.

Chương trình của chúng em được đặt tên **KNPBANK ATM System**, mô phỏng đầy đủ quy trình trên với các chức năng mở rộng thêm: chuyển tiền giữa các tài khoản, đổi mã PIN, quản lý admin (đổi mã bảo mật, shutdown hệ thống), và hệ thống ngày giả lập tự động tăng sau mỗi lần tắt máy.

---

## 2. CƠ SỞ LÝ THUYẾT

### 2.1. Ý tưởng

Xây dựng chương trình mô phỏng máy ATM dưới dạng ứng dụng console C++. Dữ liệu tài khoản khách hàng được lưu trữ bằng các **mảng song song** (parallel arrays), trong đó mỗi mảng lưu một thuộc tính và các mảng chia sẻ chung chỉ số (index) để liên kết thông tin. Chương trình sử dụng file để đọc dữ liệu khi khởi động và ghi lại khi tắt máy. Các vòng lặp và cấu trúc rẽ nhánh được sử dụng để điều khiển luồng xử lý: xác thực đăng nhập, xử lý menu, kiểm tra điều kiện giao dịch.

### 2.2. Cơ sở lý thuyết

#### 1. Mảng song song (Parallel Arrays)

Mảng song song là kỹ thuật sử dụng nhiều mảng riêng biệt có cùng kích thước, trong đó phần tử tại cùng chỉ số (index) của các mảng khác nhau cùng mô tả một đối tượng. Đây là phương pháp thay thế cho struct khi cần lưu trữ dữ liệu có cấu trúc đơn giản.

Ví dụ trong chương trình, tài khoản thứ `i` sẽ có:
- Số tài khoản: `accountNumbers[i]`
- Mã PIN: `pins[i]`
- Số dư: `balances[i]`
- Trạng thái khóa: `isLocked[i]`
- Số giao dịch trong ngày: `dailyTransactionCount[i]`
- Tổng tiền rút/chuyển trong ngày: `dailyTransAmount[i]`

Ưu điểm: Đơn giản, dễ hiểu, phù hợp với yêu cầu đề tài sử dụng mảng.

#### 2. Thao tác với file (File I/O)

Chương trình sử dụng thư viện `<fstream>` của C++ để đọc và ghi file:
- **`ifstream`**: Đọc dữ liệu từ file (dùng toán tử `>>` để đọc từng trường).
- **`ofstream`**: Ghi dữ liệu ra file (dùng toán tử `<<`).

Các file dữ liệu trong chương trình:
- `accounts.dat`: Lưu số tài khoản, PIN, số dư, trạng thái khóa.
- `secret.dat`: Lưu mã bảo mật của admin.
- `date.dat`: Lưu ngày hệ thống giả lập.
- `transactions_DD_MM_YYYY.dat`: File log giao dịch theo từng ngày.

Các thao tác đọc file được thực hiện khi khởi động (`loadAccountData`, `loadSecretCode`, `loadSystemDate`). Các thao tác ghi file được thực hiện khi cập nhật dữ liệu tài khoản (`updateAccountsData`), khi thay đổi mã bảo mật (`saveSecretCode`), và khi tắt máy (`saveTransactionData`, `saveSystemDate`).

#### 3. Cấu trúc điều khiển

Chương trình sử dụng đầy đủ các cấu trúc điều khiển:
- **Cấu trúc rẽ nhánh** (`if/else`): Kiểm tra đăng nhập, xác thực PIN, phân luồng menu, kiểm tra điều kiện giao dịch (số dư, giới hạn ngày, chia hết 50.000).
- **Cấu trúc lặp** (`while`, `for`): Vòng lặp chính ATM chờ khách hàng, vòng lặp menu, vòng lặp nhập PIN (tối đa 3 lần), vòng lặp đọc file, vòng lặp nhập số tiền.
- **Cấu trúc nhảy** (`break`, `continue`, `return`): Thoát vòng lặp khi đăng nhập thành công, bỏ qua khi nhập không hợp lệ, trả về kết quả từ hàm.

#### 4. Các thư viện sử dụng

**a. `#include <iostream>`**: Thư viện nhập/xuất chuẩn của C++.
- `cout <<`: In dữ liệu ra màn hình.
- `cin >>`: Nhập dữ liệu từ bàn phím.
- `cin.ignore()`, `cin.get()`: Xử lý buffer nhập.

**b. `#include <fstream>`**: Thư viện xử lý file.
- `ifstream`: Mở file để đọc.
- `ofstream`: Mở file để ghi.
- Toán tử `>>` và `<<` để đọc/ghi dữ liệu.
- `ios::app`: Chế độ ghi thêm vào cuối file.

**c. `#include <string>`**: Thư viện xử lý chuỗi C++.
- `string`: Kiểu dữ liệu chuỗi.
- `to_string()`: Chuyển số thành chuỗi.
- `.length()`: Lấy độ dài chuỗi.
- `.pop_back()`: Xóa ký tự cuối chuỗi.
- Toán tử `==` so sánh hai chuỗi.

**d. `#include <conio.h>`**: Thư viện mở rộng cho console Windows.
- `_getch()`: Đọc một ký tự từ bàn phím mà không hiển thị ra màn hình, không cần nhấn Enter. Được sử dụng để ẩn mã PIN khi nhập (hiển thị dấu `*`).

---

## 3. TỔ CHỨC CẤU TRÚC DỮ LIỆU VÀ THUẬT TOÁN

### 3.1. Phát biểu bài toán

**Input:**
- File `accounts.dat` chứa danh sách tài khoản: số tài khoản, mã PIN, số dư, trạng thái (ACTIVE/LOCKED). Mỗi dòng chứa thông tin một tài khoản.
- File `secret.dat` chứa mã bảo mật admin.
- File `date.dat` chứa ngày hệ thống giả lập.
- Dữ liệu người dùng nhập từ bàn phím: lựa chọn menu, số tiền, mã PIN.

**Output:**
- Giao diện menu giao dịch trên console.
- Kết quả các thao tác: gửi tiền, rút tiền, chuyển tiền, kiểm tra số dư.
- Thông báo lỗi khi nhập sai PIN, số tiền không hợp lệ, vượt giới hạn.
- File `accounts.dat` được cập nhật sau mỗi thay đổi.
- File `transactions_DD_MM_YYYY.dat` lưu lịch sử giao dịch theo ngày.

### 3.2. Cấu trúc dữ liệu

Chương trình sử dụng **mảng song song** (parallel arrays) để lưu trữ dữ liệu. Tất cả mảng có cùng kích thước `MAX_ACCOUNTS = 100` và chia sẻ chỉ số chung.

**Mảng dữ liệu khách hàng** (khai báo trong `main.cpp`):

```cpp
string accountNumbers[MAX_ACCOUNTS];     // Số tài khoản
string pins[MAX_ACCOUNTS];               // Mã PIN
double balances[MAX_ACCOUNTS];           // Số dư
int dailyTransactionCount[MAX_ACCOUNTS]; // Số giao dịch trong ngày
bool isLocked[MAX_ACCOUNTS];             // Trạng thái khóa thẻ
double dailyTransAmount[MAX_ACCOUNTS];   // Tổng tiền rút/chuyển trong ngày
int totalAccounts = 0;                   // Tổng số tài khoản
```

**Mảng dữ liệu giao dịch:**

```cpp
string transAccountNumbers[MAX_TOTAL_TRANSACTIONS]; // Tài khoản giao dịch
string transTypes[MAX_TOTAL_TRANSACTIONS];           // Loại giao dịch
double transAmounts[MAX_TOTAL_TRANSACTIONS];         // Số tiền
string transTimestamps[MAX_TOTAL_TRANSACTIONS];      // Thời gian
int totalTransactions = 0;                           // Tổng số giao dịch
```

**Các hằng số:**

```cpp
const int MAX_ACCOUNTS = 100;
const int MAX_TRANS_PER_DAY = 5;          // Giới hạn giao dịch/khách/ngày
const int MAX_TOTAL_TRANSACTIONS = 1000;  // Kích thước mảng log
const double MAX_DAILY_AMOUNT = 20000000; // Giới hạn tiền rút/chuyển mỗi ngày
```

### 3.3. Thuật toán

#### 3.3.1. Thuật toán đọc dữ liệu tài khoản từ file

**Input:** File `accounts.dat`.
**Output:** Các mảng song song chứa thông tin tài khoản, số lượng tài khoản.

- Bước 1: Mở file `accounts.dat`. Nếu không mở được, tạo 5 tài khoản mặc định.
- Bước 2: Khởi tạo `totalAccs = 0`.
- Bước 3: Dùng vòng lặp `while`, đọc từng dòng: số tài khoản, PIN, số dư, trạng thái.
- Bước 4: Gán `locks[i] = true` nếu trạng thái là "LOCKED". Khởi tạo `dailyCnts[i] = 0`, `dailyAmts[i] = 0`.
- Bước 5: Tăng `totalAccs`, đóng file.

**Độ phức tạp:** O(n) với n là số tài khoản trong file.

#### 3.3.2. Thuật toán tìm tài khoản theo số tài khoản

**Input:** Mảng `accNums[]`, tổng số tài khoản, số tài khoản cần tìm.
**Output:** Chỉ số của tài khoản hoặc -1 nếu không tìm thấy.

- Bước 1: Duyệt từ `i = 0` đến `i < totalAccs`.
- Bước 2: So sánh `accNums[i]` với số tài khoản cần tìm (toán tử `==`).
- Bước 3: Nếu khớp, trả về `i`.
- Bước 4: Nếu duyệt hết, trả về `-1`.

**Độ phức tạp:** O(n) với n là số tài khoản.

#### 3.3.3. Thuật toán xác thực tài khoản

**Input:** Mảng tài khoản, dữ liệu nhập từ bàn phím.
**Output:** Số nguyên cho biết vị trí tài khoản hoặc thất bại.

- Bước 1: Yêu cầu nhập số tài khoản. Gọi `findAccount()` để tìm.
- Bước 2: Nếu không tìm thấy (`-1`), thông báo lỗi.
- Bước 3: Kiểm tra trạng thái khóa. Nếu khóa, từ chối và yêu cầu đến chi nhánh.
- Bước 4: Cho nhập PIN tối đa 3 lần. PIN nhập ẩn bằng `_getch()` hiển thị `*`.
- Bước 5: So sánh PIN nhập với `pins[index]`. Đúng → đăng nhập thành công.
- Bước 6: Sai 3 lần → đặt `isLocked[index] = true`, lưu file, thông báo khóa thẻ.

**Độ phức tạp:** O(n) cho tìm kiếm + O(1) cho xác thực PIN.

#### 3.3.4. Thuật toán gửi tiền (Deposit)

**Input:** Số tài khoản, số dư hiện tại.
**Output:** Số dư sau giao dịch.

- Bước 1: Yêu cầu nhập số tiền (0 để hủy).
- Bước 2: Kiểm tra chia hết 50.000 VND. Nếu không, yêu cầu nhập lại.
- Bước 3: Kiểm tra số tiền > 0.
- Bước 4: Cộng số tiền vào số dư: `currentBalance += amt`.
- Bước 5: Ghi log giao dịch: tài khoản, loại "DEPOSIT", số tiền, thời gian.
- Bước 6: Tăng bộ đếm giao dịch ngày.

**Độ phức tạp:** O(1).

#### 3.3.5. Thuật toán rút tiền (Withdraw)

**Input:** Số tài khoản, số dư, tổng tiền rút trong ngày.
**Output:** Số dư sau giao dịch.

- Bước 1: Yêu cầu nhập số tiền (0 để hủy).
- Bước 2: Kiểm tra chia hết 50.000 VND.
- Bước 3: Kiểm tra giới hạn ngày: `dailyAmt + amt <= 20.000.000`.
- Bước 4: Kiểm tra đủ số dư: `amt <= currentBalance`.
- Bước 5: Trừ tiền: `currentBalance -= amt`, cập nhật `dailyAmt += amt`.
- Bước 6: Ghi log "WITHDRAW", tăng bộ đếm.

**Độ phức tạp:** O(1).

#### 3.3.6. Thuật toán chuyển tiền (Transfer)

**Input:** Tài khoản nguồn, tài khoản đích, số tiền.
**Output:** Cập nhật số dư hai bên.

- Bước 1: Kiểm tra không chuyển cho chính mình.
- Bước 2: Tìm tài khoản đích bằng `findAccount()`.
- Bước 3: Kiểm tra chia hết 50.000, giới hạn ngày, đủ số dư.
- Bước 4: Trừ tiền nguồn, cộng tiền đích.
- Bước 5: Ghi log "TRANSFER" cho nguồn, "RECEIVE" cho đích.

**Độ phức tạp:** O(n) cho tìm tài khoản đích.

#### 3.3.7. Thuật toán kiểm tra số dư (Check Balance)

**Input:** Số tài khoản, số dư.
**Output:** Hiển thị số dư, ghi log.

- Bước 1: Hiển thị số dư ra màn hình.
- Bước 2: Ghi log "CHECK_BAL" với số tiền = 0.
- Bước 3: Tăng bộ đếm giao dịch ngày.

**Độ phức tạp:** O(1).

#### 3.3.8. Thuật toán lưu giao dịch vào file

**Input:** Mảng giao dịch, ngày hiện tại.
**Output:** File `transactions_DD_MM_YYYY.dat`.

- Bước 1: Tạo tên file theo ngày: `"transactions_" + DD_MM_YYYY + ".dat"`.
- Bước 2: Mở file ở chế độ ghi thêm (`ios::app`).
- Bước 3: Ghi header: `"--- LOG: timestamp ---"`.
- Bước 4: Duyệt mảng giao dịch, ghi mỗi dòng: thời gian, tài khoản, loại, số tiền.
- Bước 5: Đóng file.

**Độ phức tạp:** O(n) với n là số giao dịch.

#### 3.3.9. Thuật toán đổi mã PIN

**Input:** Mảng tài khoản, chỉ số tài khoản hiện tại.
**Output:** Mã PIN được cập nhật trong mảng và file.

- Bước 1: Yêu cầu nhập PIN hiện tại (ẩn). Xác thực.
- Bước 2: Yêu cầu nhập PIN mới. Kiểm tra độ dài >= 4.
- Bước 3: Yêu cầu xác nhận PIN mới. So khớp.
- Bước 4: Cập nhật `pins[index]`. Ghi file `accounts.dat`.

**Độ phức tạp:** O(n) cho ghi file.

---

## 4. CHƯƠNG TRÌNH VÀ KẾT QUẢ

### 4.1. Tổ chức chương trình

Chương trình được tổ chức thành 5 module (file) với chức năng riêng biệt:

```
                        ┌──────────────┐
                        │   main.cpp   │
                        │  (Entry Point)│
                        └──────┬───────┘
                   ┌───────────┼───────────┐
                   ▼           ▼           ▼
            ┌────────────┐ ┌────────┐ ┌──────────────┐
            │ StartUp.cpp│ │ATM.cpp │ │ Shutdown.cpp │
            │ (Khởi động)│ │(Giao   │ │  (Tắt máy)   │
            │            │ │ dịch)  │ │              │
            └─────┬──────┘ └───┬────┘ └──────┬───────┘
                  └────────────┼─────────────┘
                               ▼
                        ┌────────────┐
                        │  Utils.cpp │
                        │ (Tiện ích) │
                        └────────────┘
```

- **main.cpp**: Điểm khởi đầu, khai báo các mảng song song, gọi 3 giai đoạn: StartUp → runATMLoop → shutdown.
- **StartUp.cpp/h**: Xác thực mã bảo mật admin, đọc dữ liệu tài khoản từ file, tải ngày hệ thống.
- **ATM.cpp/h**: Chứa toàn bộ logic nghiệp vụ: hiển thị menu, tìm tài khoản, gửi/rút/chuyển tiền, kiểm tra số dư, đổi PIN, menu admin.
- **Shutdown.cpp/h**: Ghi file tài khoản, ghi file giao dịch theo ngày, tăng ngày hệ thống.
- **Utils.cpp/h**: Các hàm tiện ích dùng chung: xử lý ngày, xóa màn hình, nhập ẩn, xác thực, đọc/ghi mã bảo mật.

**Nguyên mẫu hàm chính:**

```cpp
// StartUp
bool authenticateSecret(string currentSecretCode);
void loadAccountData(string accNums[], string pins[], double bals[],
                     int dailyCnts[], bool locks[], double dailyAmts[],
                     int& totalAccs);
bool StartUp(...);

// ATM
int findAccount(string accNum, string accNums[], int totalAccs);
double depositMoney(string accId, double currentBalance, ...);
double withdrawMoney(string accId, double currentBalance, double& dailyAmt, ...);
void transferMoney(string srcId, double& srcBalance, double& srcDailyAmt,
                   string tgtId, double& tgtBalance, double amt, ...);
double checkBalance(string accId, double currentBalance, ...);
void changePIN(string accNums[], string pins[], ...);
void adminMenu(string& currentSecretCode, bool& shouldShutdown);
void runATMLoop(...);

// Shutdown
void updateAccountsData(string accNums[], string pins[], double bals[],
                        bool locks[], int totalAccs, bool silent = false);
void saveTransactionData(...);
void shutdown(...);

// Utils
void loadSystemDate(int& d, int& m, int& y);
void saveSystemDate(int d, int m, int y);
void incrementDate(int& d, int& m, int& y);
string getCurrentTimestamp(int d, int m, int y);
void clearScreen();
void waitForEnter();
string getHiddenInput();
bool authenticate(string inputCode, string correctCode);
void loadSecretCode(string& code);
void saveSecretCode(string code);
```

### 4.2. Ngôn ngữ cài đặt

- **Ngôn ngữ:** C++ (chuẩn C++11 trở lên)
- **Trình biên dịch:** g++ (MinGW trên Windows)
- **Lệnh biên dịch:** `g++ -o atm.exe main.cpp ATM.cpp StartUp.cpp Shutdown.cpp Utils.cpp`
- **Nền tảng:** Windows (do sử dụng `_getch()` từ `<conio.h>`)

### 4.3. Kết quả

#### 4.3.1. Giao diện chính của chương trình

*[Hình 3: Giao diện khởi động hệ thống]*
Khi chạy chương trình, nhân viên IT cần nhập mã bảo mật (Secret Code) để khởi động. Mã được nhập ẩn (hiển thị `*`).

*[Hình 4: Giao diện chính ATM]*
Sau khi khởi động, màn hình hiển thị banner KNPBANK với thông tin ngân hàng, yêu cầu khách hàng nhập số tài khoản hoặc gõ "SECRET" cho nhân viên.

#### 4.3.2. Kết quả thực thi

**Đăng nhập và xác thực:**
- Nhập số tài khoản → tìm trong mảng → nhập PIN (ẩn) → xác thực.
- Sai PIN 3 lần → khóa thẻ, lưu trạng thái "LOCKED" vào file.

**Gửi tiền (Deposit):**
- Nhập số tiền chia hết 50.000 → cộng vào số dư → hiển thị số dư mới.

**Rút tiền (Withdraw):**
- Kiểm tra chia hết 50.000, giới hạn ngày 20 triệu, đủ số dư → trừ tiền.

**Chuyển tiền (Transfer):**
- Nhập tài khoản đích (không được trùng) → kiểm tra tồn tại → nhập số tiền → trừ nguồn, cộng đích → log cả TRANSFER lẫn RECEIVE.

**Kiểm tra số dư (Balance):**
- Hiển thị số dư, ghi log CHECK_BAL.

**Giới hạn giao dịch:**
- Sau 5 giao dịch/ngày, hệ thống từ chối với thông báo "Daily transaction limit (5) reached!".

**Admin:**
- Gõ "SECRET" → nhập mã → menu admin: Shutdown, Đổi mã bảo mật, Logout.
- Shutdown: xác thực lại → ghi file giao dịch + tài khoản → tăng ngày → tắt.

**File kết quả:**

`accounts.dat` sau khi lưu:
```
1001 1234 5100000 ACTIVE
1002 2345 2800000 ACTIVE
1003 3456 10000000 ACTIVE
1005 5678 7500000 LOCKED
```

`transactions_30_05_2005.dat`:
```
--- LOG: 30/05/2005 22:00:00 ---
30/05/2005 22:00:00 | 1002 | DEPOSIT | 100000
30/05/2005 22:00:00 | 1002 | WITHDRAW | 300000
30/05/2005 22:00:00 | 1002 | TRANSFER | 1000000
30/05/2005 22:00:00 | 1003 | RECEIVE | 1000000
30/05/2005 22:00:00 | 1002 | CHECK_BAL | 0
```

#### 4.3.3. Nhận xét đánh giá

Chương trình đã đáp ứng đầy đủ các yêu cầu của đề tài:
- ✅ Sử dụng mảng song song để lưu dữ liệu (6 mảng cho khách hàng, 4 mảng cho giao dịch).
- ✅ Sử dụng thao tác file đọc/ghi (4 loại file).
- ✅ Sử dụng biến, vòng lặp và cấu trúc rẽ nhánh phong phú.
- ✅ Viết các hàm riêng biệt cho từng chức năng (20+ hàm).
- ✅ Đầy đủ gửi tiền, rút tiền, xem số dư + mở rộng chuyển tiền, đổi PIN.
- ✅ Xác thực tài khoản + PIN với cơ chế khóa thẻ.
- ✅ Giới hạn giao dịch/ngày và giới hạn số tiền/ngày.
- ✅ Lưu log giao dịch theo ngày vào file riêng.
- ✅ Khởi động bằng mã bảo mật, tắt máy ghi file.

Hạn chế: Giới hạn giao dịch/ngày reset khi khởi động lại (không lưu vào file). Timestamp cố định "22:00:00". Chỉ chạy trên Windows.

---

## 5. KẾT LUẬN VÀ HƯỚNG PHÁT TRIỂN

### 5.1. Kết luận

Đề tài "Xây dựng ứng dụng thực hiện giao dịch trên máy ATM" đã được hoàn thành với đầy đủ các chức năng theo yêu cầu. Chương trình mô phỏng thành công quy trình hoạt động của máy ATM từ khâu khởi động bởi nhân viên IT, phục vụ khách hàng giao dịch, đến khi tắt máy và lưu dữ liệu.

Thông qua đề tài, nhóm đã được rèn luyện và củng cố các kỹ năng: sử dụng mảng song song để quản lý dữ liệu có cấu trúc, thao tác đọc/ghi file, tổ chức chương trình thành các module và hàm chức năng, áp dụng các cấu trúc điều khiển để xử lý logic nghiệp vụ phức tạp.

### 5.2. Hướng phát triển

- Lưu giới hạn giao dịch/ngày vào file để không bị reset khi khởi động lại.
- Sử dụng thời gian thực thay vì timestamp cố định.
- Thêm chức năng xem lịch sử giao dịch cho khách hàng.
- Hỗ trợ đa nền tảng (thay thế `_getch()` bằng giải pháp portable).
- Thêm chức năng tạo/xóa tài khoản cho admin.
- Mã hóa mã PIN trong file thay vì lưu dạng plaintext.

---

## TÀI LIỆU THAM KHẢO

[1] Trần Hồ Thủy Tiên, Bài giảng Kỹ thuật lập trình, Khoa Công nghệ Thông tin, Trường Đại học Bách khoa Đà Nẵng.

[2] cplusplus.com, C++ Reference - fstream, https://cplusplus.com/reference/fstream/

[3] cplusplus.com, C++ Reference - string, https://cplusplus.com/reference/string/

[4] 28Tech, Đọc ghi file trong C/C++, https://blog.28tech.com.vn/c-doc-ghi-file-text

[5] Lập Trình Nhanh, Các hàm xử lý file trong C/C++, https://laptrinhnhanh.com/cac-ham-xu-ly-file-trong-c-c/

---

## PHỤ LỤC

> Sinh viên bỏ Code từng phần vào đây.
> Font: Time New Roman; thường; cỡ chữ: 12; dãn dòng: 1,3; căn lề: justified.

### A. main.cpp

*(Copy toàn bộ nội dung file main.cpp vào đây)*

### B. ATM.h + ATM.cpp

*(Copy toàn bộ nội dung file ATM.h và ATM.cpp vào đây)*

### C. StartUp.h + StartUp.cpp

*(Copy toàn bộ nội dung file StartUp.h và StartUp.cpp vào đây)*

### D. Shutdown.h + Shutdown.cpp

*(Copy toàn bộ nội dung file Shutdown.h và Shutdown.cpp vào đây)*

### E. Utils.h + Utils.cpp

*(Copy toàn bộ nội dung file Utils.h và Utils.cpp vào đây)*
