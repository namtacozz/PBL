# ✅ CHECKLIST CHUẨN BỊ BÁO CÁO

## 📅 Ngày báo cáo: ___________

## 🎯 Trước buổi báo cáo (1-2 ngày)

### Code & Testing
- [ ] Compile thành công không lỗi
- [ ] Test tất cả chức năng customer
  - [ ] Deposit (gửi tiền)
  - [ ] Withdraw (rút tiền)
  - [ ] Transfer (chuyển khoản)
  - [ ] Balance (kiểm tra số dư)
- [ ] Test tất cả chức năng admin
  - [ ] Shutdown system
  - [ ] Change secret code
- [ ] Test security features
  - [ ] PIN ẩn bằng dấu *
  - [ ] Khóa thẻ sau 3 lần sai
  - [ ] Giới hạn 20M/ngày
- [ ] Test edge cases
  - [ ] Số tiền không chia hết 50k
  - [ ] Chuyển khoản cho chính mình
  - [ ] Rút tiền khi số dư không đủ

### Documentation
- [ ] Đọc kỹ CHANGELOG.md
- [ ] Đọc kỹ HUONG_DAN_SU_DUNG.md
- [ ] Đọc kỹ TOM_TAT_DU_AN.md
- [ ] Chuẩn bị câu trả lời cho 10 câu hỏi phổ biến

### Demo Preparation
- [ ] Tạo data test sẵn (2-3 accounts)
- [ ] Ghi nhớ secret code admin
- [ ] Chạy thử demo flow 2-3 lần
- [ ] Đo thời gian demo (~5-7 phút)

## 🎤 Ngày báo cáo

### Trước khi vào phòng (30 phút)
- [ ] Copy toàn bộ folder PBL sang USB backup
- [ ] Mở sẵn terminal tại D:\PBL
- [ ] Test chạy program 1 lần cuối
- [ ] Chuẩn bị giấy note (nếu cần)

### Khi báo cáo (10-15 phút)

#### 1. Giới thiệu (1-2 phút)
- [ ] Tên dự án: "Hệ thống ATM Console - KNPBANK"
- [ ] Mục đích: Mô phỏng ATM với đầy đủ chức năng
- [ ] Công nghệ: C++, File I/O, Console UI

#### 2. Demo chức năng (5-7 phút)

**A. Welcome Screen & Bank Info**
- [ ] Chạy program → Hiển thị welcome screen
- [ ] Chọn [1] → Xem giới thiệu KNPBANK
- [ ] Giải thích: "Đây là tính năng mới, cung cấp thông tin về ngân hàng"

**B. Customer Flow**
- [ ] Chọn [2] → Đăng nhập
- [ ] Nhập STK customer → Nhập PIN
- [ ] Demo Deposit: Gửi 100,000 VND
- [ ] Demo Balance: Kiểm tra số dư
- [ ] Demo Withdraw: Rút 50,000 VND
- [ ] Logout

**C. Admin Flow**
- [ ] Chọn [2] → Đăng nhập
- [ ] Nhập "admin" → Nhập secret code
- [ ] Giải thích: "Admin menu riêng biệt, chỉ truy cập bằng secret"
- [ ] Demo Change Secret Code
- [ ] Logout

**D. Security Demo**
- [ ] Đăng nhập customer
- [ ] Nhập sai PIN 3 lần
- [ ] Hiển thị: "Thẻ bị khóa"
- [ ] Giải thích: "Bảo mật chống brute-force"

#### 3. Giải thích kỹ thuật (2-3 phút)
- [ ] Kiến trúc: Module-based (ATM, Utils, Shutdown, StartUp)
- [ ] Lưu trữ: File .dat (accounts, secret, transactions)
- [ ] Bảo mật: Hidden input, account locking, daily limits
- [ ] UI: Box drawing characters, emoji icons

#### 4. Q&A (2-3 phút)
- [ ] Sẵn sàng trả lời câu hỏi
- [ ] Nếu không biết: "Em sẽ tìm hiểu thêm về vấn đề này"

## 🎯 Câu hỏi có thể bị hỏi (Top 10)

### 1. Tổng quan
**Q**: Em giới thiệu tổng quan về dự án?  
**A**: _(Xem TOM_TAT_DU_AN.md - Mô tả dự án)_

### 2. Đăng nhập chung
**Q**: Tại sao admin và customer cùng 1 màn hình đăng nhập?  
**A**: "Để UX tốt hơn, user không cần biết trước vai trò, hệ thống tự nhận diện qua input (admin/STK)"

### 3. Bảo mật PIN
**Q**: Làm sao ẩn PIN khi nhập?  
**A**: "Dùng hàm _getch() từ conio.h, đọc từng ký tự không hiển thị, in dấu * thay thế"

### 4. Khóa thẻ
**Q**: Cơ chế khóa thẻ hoạt động thế nào?  
**A**: "Sau 3 lần nhập sai PIN, set locks[index]=true, lưu vào accounts.dat, từ chối đăng nhập sau đó"

### 5. Giới hạn 20M
**Q**: Làm sao theo dõi giới hạn 20M/ngày?  
**A**: "Mỗi account có biến dailyAmts[], cộng dồn mỗi lần rút/chuyển, reset khi sang ngày mới"

### 6. File storage
**Q**: Tại sao dùng file .dat thay vì database?  
**A**: "Đơn giản, phù hợp console app nhỏ, dễ debug. Có thể nâng cấp lên SQLite sau"

### 7. Secret code
**Q**: Secret code có an toàn không?  
**A**: "Hiện tại lưu plaintext (yếu điểm), nên hash bằng SHA256/bcrypt để bảo mật hơn"

### 8. Chuyển khoản
**Q**: Giải thích hàm transferMoney()?  
**A**: "Nhận 2 account bằng reference, trừ nguồn, cộng đích, kiểm tra daily limit, ghi log"

### 9. Tham chiếu (&)
**Q**: Tại sao dùng tham chiếu trong hàm?  
**A**: "Để thay đổi trực tiếp biến gốc, không copy, tiết kiệm bộ nhớ và đồng bộ dữ liệu"

### 10. Cải tiến
**Q**: Nếu làm lại, em sẽ cải tiến gì?  
**A**: "Hash password, dùng SQLite, thêm admin dashboard, export reports, OTP 2FA, GUI"

## 📊 Điểm cộng khi trình bày

### ✅ Nên làm:
- Nói rõ ràng, tự tin
- Demo mượt mà, không lỗi
- Giải thích logic đơn giản, dễ hiểu
- Thừa nhận hạn chế và đề xuất cải tiến
- Trả lời câu hỏi ngắn gọn, đúng trọng tâm

### ❌ Tránh:
- Nói quá nhanh hoặc quá chậm
- Demo bị lỗi (test kỹ trước!)
- Không biết giải thích code của mình
- Nói dối hoặc bịa đặt
- Tranh luận với giáo viên

## 🎁 Bonus Tips

### Nếu bị hỏi khó:
1. **Dừng lại, suy nghĩ 2-3 giây**
2. **Trả lời thành thật**: "Em chưa nghĩ đến vấn đề này, nhưng em nghĩ có thể..."
3. **Đề xuất hướng giải quyết**: "Em sẽ tìm hiểu thêm về..."

### Nếu demo bị lỗi:
1. **Giữ bình tĩnh**: "Xin lỗi, em sẽ chạy lại"
2. **Có backup plan**: USB backup hoặc video demo
3. **Giải thích**: "Đây là lỗi [X], em đã test trước đó và hoạt động tốt"

### Kết thúc báo cáo:
"Em xin cảm ơn thầy/cô đã lắng nghe. Em sẵn sàng trả lời câu hỏi!"

## 📸 Checklist Screenshots (Nếu cần slide)

- [ ] Welcome Screen
- [ ] Bank Info
- [ ] Admin Login
- [ ] Admin Menu
- [ ] Customer Login
- [ ] Customer Menu
- [ ] Deposit Success
- [ ] Card Locked Warning
- [ ] Code Structure Diagram

## 🚀 Sau buổi báo cáo

- [ ] Ghi chú feedback từ giáo viên
- [ ] Cập nhật code nếu có yêu cầu
- [ ] Backup code lên GitHub/Google Drive
- [ ] Viết reflection (nếu cần)

---

**Good luck! Ngài Vịt sẽ làm tốt thôi! 🎉**

_Checklist này in ra và tick từng mục khi hoàn thành._
