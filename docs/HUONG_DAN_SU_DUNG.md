# 🎮 HƯỚNG DẪN SỬ DỤNG ATM SYSTEM MỚI

## 🚀 Chạy chương trình:

```bash
cd D:\PBL
.\atm_system_new.exe
```

## 📋 Tài khoản test:

### Customer Accounts (từ accounts.dat):
- Xem file `accounts.dat` để lấy số tài khoản và PIN

### Admin Account:
- Username: `admin`
- Secret Code: Xem file `secret.dat` (mặc định: `KINAPU`)

## 🎯 Các tính năng mới:

### 1. **Màn hình chào mừng**
```
╔════════════════════════════════════════════════════════════════════════════════╗
║              ██╗  ██╗███╗   ██╗██████╗ ██████╗  █████╗ ███╗   ██╗██╗  ██╗    ║
║              ...KNPBANK ASCII LOGO...                                          ║
╠════════════════════════════════════════════════════════════════════════════════╣
║                      [1] 🏦 Giới thiệu về KNPBANK                              ║
║                      [2] 💳 Đăng nhập giao dịch                                ║
║                      [3] 🚪 Thoát                                              ║
╚════════════════════════════════════════════════════════════════════════════════╝
```

### 2. **Giới thiệu ngân hàng (Option 1)**
- Thông tin chi tiết về KNPBANK
- Địa chỉ, hotline, website
- Thành tựu và ưu đãi

### 3. **Đăng nhập chung (Option 2)**

#### A. Đăng nhập Admin:
```
[_] Số tài khoản: admin
[_] Nhập mã Secret: ******
```
→ Vào Admin Menu:
- [1] 🔒 Shutdown System
- [2] 🔑 Change Secret Code
- [3] 🚪 Logout

#### B. Đăng nhập Customer:
```
[_] Số tài khoản: 123456789
[_] Nhập mã PIN: ****
```
→ Vào Customer Menu:
- [1] 💰 Gửi tiền
- [2] 💸 Rút tiền
- [3] 🔄 Chuyển khoản
- [4] 📊 Kiểm tra số dư
- [5] 🚪 Đăng xuất

## 🔐 Bảo mật:

- ✅ PIN ẩn bằng dấu `*`
- ✅ Khóa thẻ sau 3 lần nhập sai
- ✅ Admin menu chỉ truy cập bằng secret code
- ✅ Giới hạn 20M VND/ngày
- ✅ Số tiền phải chia hết cho 50,000 VND

## 📊 So sánh với version cũ:

| Tính năng | Version Cũ | Version Mới |
|-----------|------------|-------------|
| Menu chính | 3 options riêng | Đăng nhập chung |
| Giới thiệu bank | ❌ Không có | ✅ Có |
| UI | Đơn giản | Box drawing + emoji |
| Admin access | Menu riêng | Đăng nhập "admin" |
| Logic nghiệp vụ | ✅ | ✅ Giữ nguyên |

## 🐛 Troubleshooting:

### Lỗi compile:
```bash
# Kiểm tra các file cần thiết
ls ATM.cpp Utils.cpp Shutdown.cpp StartUp.cpp main.cpp

# Compile lại
g++ -o atm_system_new.exe main.cpp ATM.cpp Utils.cpp Shutdown.cpp StartUp.cpp
```

### Không tìm thấy file data:
- Đảm bảo các file `.dat` ở cùng thư mục với `.exe`
- `accounts.dat`, `secret.dat`, `date.dat`, `transactions_*.dat`

### Secret code không đúng:
```bash
# Xem secret code hiện tại
cat secret.dat
```

## 📝 Demo flow:

1. Chạy program → Welcome screen
2. Chọn [1] → Xem giới thiệu KNPBANK → Enter
3. Chọn [2] → Đăng nhập
4. Nhập "admin" → Nhập secret → Admin menu
5. Chọn [2] → Đổi secret code → Logout
6. Chọn [2] lại → Nhập STK customer → Nhập PIN
7. Test các chức năng: Deposit, Withdraw, Transfer, Balance
8. Logout → Chọn [3] → Thoát

## 🎓 Chuẩn bị báo cáo:

### Điểm nhấn khi demo:
1. **UI đẹp hơn** - Box drawing, emoji, layout rộng
2. **Đăng nhập thống nhất** - Admin và customer cùng 1 flow
3. **Giới thiệu ngân hàng** - Thông tin chi tiết, chuyên nghiệp
4. **Logic giữ nguyên** - Tất cả tính năng cũ vẫn hoạt động
5. **Bảo mật tốt** - PIN ẩn, khóa thẻ, admin protected

### Câu hỏi có thể bị hỏi:
- **Q**: Tại sao đổi cách đăng nhập?
- **A**: Để UX tốt hơn, user không cần biết trước mình là admin hay customer, chỉ cần nhập account và hệ thống tự nhận diện.

- **Q**: Thông tin ngân hàng lấy từ đâu?
- **A**: Tham khảo các ngân hàng lớn VN như Vietcombank, Techcombank, VPBank để tạo profile giống thật.

- **Q**: Có ảnh hưởng đến logic cũ không?
- **A**: Không, tất cả hàm nghiệp vụ (deposit, withdraw, transfer, balance) giữ nguyên 100%.

---
**Good luck với báo cáo! 🚀**
