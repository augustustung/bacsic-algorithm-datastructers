# Cây AVL

### Khái niệm:
Cây AVL là cây tìm kiếm nhị phân tự cân bằng, trong đó tại mỗi nút, hiệu độ cao (height) của các cây con hai bên không thể nhiều hơn 1.

#### 1. Hệ số cân bằng (balance)
- Là hiệu số giữa chiều cao của cây con trái và cây con phải.
- `balance(u) = balance(u.right) - balance(u.left)`
- Với mọi đỉnh nếu `balance(u) = 0` thì cây được gọi là cây cân bằng hoàn toàn.
- `balance(u) > 0` => cây lệch phải.
- `balance(u) < 0` => cây lệch trái.

#### 2. Cân bằng cây
Để cân bằng cây thì sử dụng 2 phương thức: xoay trái, xoay phải

#### 3. Chèn
- Giải sử nút mới là v. 
- Bốn trường hợp sau có thể phá vỡ tính cân bằng AVL tại u
	- Trước khi chèn cây con gốc u lệch trái và v làm tăng chiều cao của cây con trái.
		- Sau khi chèn cây con trái lệch trái (Case LL).
		- Sau khi chèn cây con trái lệch phải (Case LR).
	- Trước khi chèn cây con gốc u lệch phải và v làm tăng chiều cao của cây con phải.
		- Sau khi chèn cây con phải lệch phải (Case RR).
		- Sau khi chèn cây con phải lệch trái. (Case RL).


- TH1 (LL): Chỉ cần xoay phải nút đầu tiên bên trái.
- TH2 (LR): 
	- Xoay phải để đưa về TH1.
	- Xoay trái để được cây cân bằng.
- TH3 (RR): Chỉ cần xoay trái nút đầu tiên bên phải.
- TH4 (RR): 
	- Xoay trái để đưa về TH3.
	- Xoay phải để được cây cân bằng.
