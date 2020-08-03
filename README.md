# Mô phỏng một chiếc ô tô 4 bánh
- Chương trình sử dụng thư viện OpenGL để mô phỏng chiếc xe ô tô
- Bánh xe được mô phỏng bằng hình xuyến
- Thân xe được mô phỏng bằng hình hộp chữ nhật
- Chương trình sử dụng phép xoay và tịnh tiến để mô phỏng chuyển động tiến, lùi và lăn của bánh xe trong quá trình ô tô vận hành
- Thân xe sử dụng phép tịnh tiến đê mô phỏng chuyển động tiến về phía trước của ô tô trong quá trình bánh xe quay

# Hướng dẫn sử dụng
- Dùng chuột phải để ô tô tiến về phía bên phải theo trục Ox
- Dùng chuột trái để ô tô tiến về phía bên trái theo trục Ox
- Nhất nút chuột giữa để dừng ô tô

# Chú ý
- Tôi sử dụng Xcode trên MacOS để viết chương trình này, nếu bạn muốn chạy chương trình trên hệ điều hành Windows thì bạn cần sửa lại phần khai báo thư viện trong phần main.c như sau:
- #include <GL/gl.h>
- #include <GL/glu.h>
- #include <GL/glut.h>

# Tài liệu tham khảo
- Hướng dẫn lập trình OpenGL căn bản - Lê Phong
- Opegl Programming Guide - The red book
- https://www.khronos.org/
- https://phattrienphanmem123az.com/lap-trinh-opengl-cpp
- https://www.coders-hub.com/p/blog-page_580.html
- https://open.gl
- https://learnopengl.com
- https://www.cs.brandeis.edu/~cs155/
