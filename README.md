# Các thành viên
- Nguyễn Minh Hiếu 21020908
- Nguyễn Việt Đức 21020904
- Nguyễn Hữu Việt Hưng 21020442

# Cách Scanner hoạt động
- Chức năng :

  - Đọc source code ở file input.txt rồi sau đó thực hiện phân tích từ vựng trên code đọc được và gửi kết quả vào file output.txt

- Các loại Token :

  - Các từ khóa(keyword) : if, then, else
  - Các biến : Chuỗi ký tự bắt đầu bằng một chữ cái và có thể chứa các chữ số
  - Số
  - Toán tử quan hệ : >
  - Toán tử gán : =
  - Dấu chấm phẩy : ;

- Các biến :

  - hasPreNumber: Lưu trữ thông tin về việc trước đó có xuất hiện 1 số hay không.
  - Biến i: đếm vị trí trong mảng id[], mảng này lưu trữ các ký tự của một từ khóa hoặc identifier.
  - Biến j: đếm vị trí trong mảng num[], mảng lưu trữ các kí tự của 1 số.
  - state: Trạng thái hiện tại của scanner.
  - test_case: đếm số lượng test case.
  - f1: Mở file input với chế độ đọc.
  - f2: Mở file output với chế độ ghi.

- Hàm :

  - isKeyword(char buff[]):
    - Chức năng : Kiểm tra xem một chuỗi buff có phải là một keyword trong ngôn ngữ không.
    - Tham số : char buff[]: Chuỗi cần kiểm tra.
    - Trả về : 1 nếu buff là một keyword, 0 nếu buff không phải là keyword.
  - isValidIden(char buff[]):
    - Chức năng : Kiểm tra xem một chuỗi buff có phải là một identifier hợp lệ trong ngôn ngữ không.
    - Tham số: char buff[]: Chuỗi cần kiểm tra.
    - Trả về : 1 nếu buff là một identifier hợp lệ, 0 nếu buff không phải là identifier hợp lệ.
  - toUpper(char buff[]):
    - Chức năng : Chuyển đổi một chuỗi buff thành chữ hoa.
    - Tham số : char buff[]: Chuỗi cần chuyển đổi.
    - Trả về : Chuỗi buff đã được chuyển thành chữ hoa.
- Trạng thái của state khi phân tích :
  - state = 0: Trạng thái ban đầu, chương trình ở trạng thái chờ để bắt đầu phân tích từ vựng.
  - state = 1: Khi chương trình gặp một chữ cái, nó ở trạng thái đọc identifier.
  - state = 2: Khi chương trình gặp một chữ số, nó ở trạng thái đọc số.
  - state = 3: Khi chương trình gặp dấu >, xử lý dấu >, In ra "<ROP, > >".
  - state = 4: Kết thúc identifier và chương trình sẽ kiểm tra xem identifier đó có phải là keyword hay identifier hợp lệ hay không.
  - state = 5: Khi sau identifier gặp một chữ cái, chương trình sẽ kiểm tra tiếp các ký tự.
  - state = 6: Kết thúc identifier không hợp lệ sau khi đã gặp một chữ cái.
  - state = 7: Kết thúc số và chương trình sẽ in ra một số hoặc chuỗi ký tự số.
  - state = 8:  Gặp dấu ";", In ra "<SEM, >" và kết thúc test case.
  - state = 9: Xử lý khi gặp dấu = và trước đó đã có một số (trạng thái không mong muốn = =).
  - state = 10: Khi gặp dấu =, chương trình ở trạng thái xử lý dấu =.
# Sơ đồ hoạt động
-  ![Image demo](demo.png)
