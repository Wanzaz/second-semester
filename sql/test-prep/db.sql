CREATE TABLE students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    surname TEXT,
    cid INTEGER,
    class INTEGER,
    city TEXT,
    girl BOOL
);
    
CREATE TABLE classes (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    teacher INTEGER,
    floor INTEGER
);
    
CREATE TABLE aprobations (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    shortcut TEXT,
    name TEXT
);

CREATE TABLE teachers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    /* COSTRAINTS*/
    /* name TEXT UNIQUE, - it must be UNIQUE*/
    /* name TEXT NOT NULL, - it cannot be a NULL*/
    /* name TEXT DEFAULT 'unknown', - default is 'unknown'*/
    surname TEXT,
    date_start DATE
);

CREATE TABLE teachers_aprobations (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    teacher TEXT,
    aprobation INTEGER
);

/*5.*/
INSERT INTO students (name, surname, cid, class, city, girl) VALUES
    ("Antonit", "Born", 16, 1, "Brno", 0);
INSERT INTO students (name, surname, cid, class, city, girl) VALUES
    ("Simona", "Roz", 15, 4, "Rajhrad", 1);
INSERT INTO students (name, surname, cid, class, city, girl) VALUES
    ("Karolina", "Roza", 15, 4, "Brno", 1);
INSERT INTO students (name, surname, cid, class, city, girl) VALUES
    ("Pepa", "John", 18, 6, "Rozdrojovice", 0);

UPDATE students
    SET city = 'Brno'
    WHERE city = 'brno';

/*DELETE FROM students
    WHERE students.ID_S = 3;*/

INSERT INTO teachers (name, surname, date_start) VALUES 
    ("jitka", "dufkova", 0);

INSERT INTO aprobations (shortcut, name) VALUES 
    ("nj", "nemcina");

INSERT INTO teachers_aprobations (teacher, aprobation) VALUES
    (1, 1);

INSERT INTO classes (name, teacher, floor) VALUES 
    ('4.G', 1, 1);

/*6.*/
SELECT * FROM students;
SELECT * FROM students WHERE city LIKE "brno";

/*7.*/
SELECT * FROM students 
    JOIN classes 
    ON students.class = classes.id
    WHERE classes.name = "4.G";

/*8*/
SELECT * 
    FROM students
    WHERE girl = true AND city LIKE "Brno";

/*9.*/
SELECT *
    FROM teachers
    JOIN teachers_aprobations
    ON teachers_aprobations.teacher = teachers.id
    JOIN aprobations
    ON teachers_aprobations.aprobation = aprobations.id
    WHERE aprobations.shortcut = 'nj';

/*10.*/
SELECT *
    FROM students
    WHERE name LIKE "A%";

/*11.*/
SELECT girl, COUNT(girl)
    FROM students
    GROUP BY girl;

/*12.*/
SELECT classes.name, COUNT(students.id)
    FROM classes
    JOIN students
    ON classes.id = students.class
    GROUP BY classes.name;
