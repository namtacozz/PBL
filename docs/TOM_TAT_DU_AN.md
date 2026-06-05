# 📊 TÓM TẮT DỰ ÁN - ATM SYSTEM

## 🎯 Thông tin dự án

**Tên dự án**: Hệ thống ATM Console - KNPBANK  
**Ngôn ngữ**: C++  
**Môi trường**: Windows Console Application  
**Ngày hoàn thành**: 03/04/2026  

## 👥 Thành viên nhóm

_(Ngài Vịt điền thông tin)_

## 📋 Mô tả dự án

Xây dựng hệ thống ATM mô phỏng hoạt động của máy rút tiền tự động với đầy đủ các chức năng:
- Giao dịch khách hàng (gửi, rút, chuyển khoản, kiểm tra số dư)
- Quản trị hệ thống (shutdown, đổi mã secret)
- Bảo mật PIN và khóa thẻ
- Lưu trữ dữ liệu giao dịch

## 🎨 Điểm nổi bật

### 1. Giao diện người dùng
- ✅ Menu đẹp với box drawing characters
- ✅ Sử dụng emoji icons trực quan
- ✅ Layout rộng 80 ký tự, dễ đọc
- ✅ ASCII art logo KNPBANK

### 2. Tính năng độc đáo
- ✅ **Đăng nhập thống nhất**: Admin và customer cùng 1 màn hình
- ✅ **Giới thiệu ngân hàng**: Thông tin chi tiết về KNPBANK
- ✅ **Phân quyền thông minh**: Tự động nhận diện admin/customer

### 3. Bảo mật
- ✅ PIN ẩn bằng dấu `*` khi nhập
- ✅ Khóa thẻ sau 3 lần nhập sai
- ✅ Admin menu bảo vệ bằng secret code
- ✅ Giới hạn giao dịch 20M VND/ngày

### 4. Quản lý dữ liệu
- ✅ Lưu trữ file `.dat` (accounts, transactions, secret, date)
- ✅ Tự động backup và restore
- ✅ Lịch sử giao dịch theo ngày

## 🏗️ Kiến trúc hệ thống

```
┌─────────────────────────────────────────────────────────┐
│                    MAIN PROGRAM                         │
│                     (main.cpp)                          │
└────────────────────┬────────────────────────────────────┘
                     │
        ┌────────────┼────────────┐
        │            │            │
        ▼            ▼            ▼
   ┌────────┐  ┌─────────┐  ┌──────────┐
   │ StartUp│  │   ATM   │  │ Shutdown │
   │  .cpp  │  │  .cpp   │  │   .cpp   │
   └────────┘  └─────────┘  └──────────┘
        │            │            │
        └────────────┼────────────┘
                     │
                     ▼
              ┌──────────┐
              │  Utils   │
              │  .cpp    │
              └──────────┘
                     │
        ┌────────────┼────────────┐
        ▼            ▼            ▼
   ┌─────────┐ ┌─────────┐ ┌─────────┐
   │accounts │ │ secret  │ │  date   │
   │  .dat   │ │  .dat   │ │  .dat   │
   └─────────┘ └─────────┘ └─────────┘
```

## 📁 Cấu trúc files

```
D:\PBL\
├── main.cpp              # Entry point
├── ATM.cpp / ATM.h       # Logic giao dịch chính
├── Utils.cpp / Utils.h   # Hàm tiện ích
├── Shutdown.cpp / .h     # Xử lý tắt hệ thống
├── StartUp.cpp / .h      # Khởi tạo hệ thống
├── accounts.dat          # Dữ liệu tài khoản
├── secret.dat            # Mã secret admin
├── date.dat              # Ngày hệ thống
├── transactions_*.dat    # Lịch sử giao dịch
├── atm_system_new.exe    # Executable
├── CHANGELOG.md          # Lịch sử thay đổi
└── HUONG_DAN_SU_DUNG.md  # Hướng dẫn
```

## 🔧 Công nghệ sử dụng

| Công nghệ | Mục đích |
|-----------|----------|
| C++ STL | String, iostream, fstream |
| conio.h | Hidden input (_getch) |
| File I/O | Lưu trữ dữ liệu |
| Box Drawing | UI đẹp (╔═╗║╚╝) |

## 📊 Thống kê code

```
Total Lines: ~800 lines
├── ATM.cpp:      ~500 lines (UI + Logic)
├── Utils.cpp:    ~100 lines (Utilities)
├── Shutdown.cpp: ~80 lines
├── StartUp.cpp:  ~90 lines
└── main.cpp:     ~30 lines
```

## 🎓 Kiến thức áp dụng

### 1. Lập trình hướng thủ tục
- Tổ chức code thành modules
- Tách biệt UI và logic
- Sử dụng header files

### 2. Xử lý file
- Đọc/ghi file text
- Parse dữ liệu
- Backup và restore

### 3. Bảo mật cơ bản
- Hidden input
- Authentication
- Access control

### 4. Quản lý state
- Session management
- Daily limits tracking
- Account locking

## 🐛 Xử lý lỗi

| Lỗi | Xử lý |
|-----|-------|
| Nhập sai PIN 3 lần | Khóa thẻ, lưu vào file |
| Số dư không đủ | Từ chối giao dịch |
| Vượt hạn mức | Hiển thị cảnh báo |
| File không tồn tại | Tạo giá trị mặc định |
| Số tiền không hợp lệ | Yêu cầu nhập lại |

## 🚀 Hướng phát triển

### Đã hoàn thành ✅
- [x] Giao dịch cơ bản (deposit, withdraw, transfer, balance)
- [x] Bảo mật PIN và khóa thẻ
- [x] Admin panel (shutdown, change secret)
- [x] Lưu trữ dữ liệu file
- [x] UI đẹp với box drawing
- [x] Giới thiệu ngân hàng

### Có thể mở rộng 🔮
- [ ] Hash password (SHA256, bcrypt)
- [ ] Database (SQLite)
- [ ] Multi-language support
- [ ] Transaction history viewer
- [ ] Admin dashboard (view all accounts)
- [ ] Export reports (CSV, PDF)
- [ ] OTP 2FA
- [ ] GUI version (Qt, WinForms)

## 📝 Kết luận

Dự án ATM System đã hoàn thành đầy đủ các yêu cầu:
- ✅ Chức năng giao dịch hoàn chỉnh
- ✅ Bảo mật tốt
- ✅ UI/UX chuyên nghiệp
- ✅ Code sạch, dễ maintain
- ✅ Xử lý lỗi đầy đủ

Hệ thống có thể mở rộng và nâng cấp dễ dàng trong tương lai.

---

## 📸 Screenshots (Chuẩn bị khi demo)

1. Welcome Screen
2. Bank Info Screen
3. Login Screen (Admin)
4. Admin Menu
5. Login Screen (Customer)
6. Customer Menu
7. Deposit Transaction
8. Withdraw Transaction
9. Transfer Transaction
10. Balance Check
11. Card Locked Warning
12. Shutdown Confirmation

---

**Prepared by**: Ngài Vịt  
**Date**: 03/04/2026  
**Version**: 2.0  
