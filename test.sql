-- 建立测试表 orders
CREATE TABLE orders(  
    order_id INT NOT NULL PRIMARY KEY AUTO_INCREMENT COMMENT '编号',
    customer_name VARCHAR(255) NOT NULL COMMENT '顾客名称',
    customer_gender ENUM('male', 'female') COMMENT '顾客性别',
    product_name VARCHAR(255) COMMENT '商品',
    sell_time DATETIME NOT NULL COMMENT '销售时间'
) DEFAULT CHARSET UTF8 COMMENT 'concat学习';

-- 插入测试数据
INSERT INTO orders (customer_name, customer_gender, product_name, sell_time)
VALUES
('张三','male','笔记本','2022-04-04'),
('王五','female','短袖','2022-04-04'),
('张三','male','键盘','2022-04-05'),
('赵六','male','笔记本','2022-04-05'),
('张三','male','鼠标','2022-04-05'),
('李四',NULL,'护眼台灯','2022-04-05'),
('李四',NULL,'牛','2022-04-05'),
('王五','female','短袖','2022-04-06'),
('张三','male','键盘','2022-04-07');

SELECT * FROM orders;

-- concat
SELECT CONCAT(order_id, ': ', customer_name, '-', customer_gender) AS `customer_info`
FROM orders;

-- concat_ws
SELECT CONCAT_WS('-' , order_id, customer_name, customer_gender) AS `customer_info`
FROM orders;

-- group_concat
SELECT sell_time, GROUP_CONCAT(DISTINCT customer_name ORDER BY order_id DESC) AS `customers`
FROM orders
GROUP BY sell_time
ORDER BY sell_time;
