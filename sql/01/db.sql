CREATE DATABASE shop;
USE shop;

CREATE TABLE shop (id INTEGER PRIMARY KEY, item TEXT, price INTEGER);
INSERT INTO shop VALUES (1, "Coat", 15);
INSERT INTO shop VALUES (2, "Socks", 150);
INSERT INTO shop VALUES (3, "T-shirt", 155);
INSERT INTO shop VALUES (4, "shirt", 151);
INSERT INTO shop VALUES (5, "boots", 152);
INSERT INTO shop VALUES (6, "shoes", 153);
INSERT INTO shop VALUES (7, "gloves", 145);
INSERT INTO shop VALUES (8, "hat", 915);
INSERT INTO shop VALUES (9, "jacket", 1115);
INSERT INTO shop VALUES (10, "hoodie", 1345);
INSERT INTO shop VALUES (11, "trousers", 15);
INSERT INTO shop VALUES (12, "pants", 165);
INSERT INTO shop VALUES (13, "jumper", 105);
INSERT INTO shop VALUES (14, "sweater", 1500);
INSERT INTO shop VALUES (15, "belt", 150);




SELECT * FROM shop;
SELECT * FROM shop ORDER BY price;

SELECT SUM(price) FROM shop;
SELECT MAX(price) FROM shop;
