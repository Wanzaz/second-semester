/* CREATE DATABASE students; */
USE students;

/* CREATE TABLE students ( */
/*     id INTEGER PRIMARY KEY AUTO_INCREMENT, */
/*     name TEXT, */
/*     surname TEXT, */
/*     class INTEGER, */
/*     city TEXT, */
/*     girl BOOL */
/* ); */

USE students;

INSERT INTO students(id, name, surname, class, city, girl) VALUES 
    ("John", "Parker", 1, "Montreal", 0);
INSERT INTO students (id, name, surname, class, city, girl) VALUES 
    ("Hedviga", "Johnson", 1, "Barcelona", 1);

SELECT * 
    FROM students
    ORDER BY id DESC
    LIMIT 1;

-- <> = NOT EQUAL TO
